#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "benchmark.cpp"
using namespace std;

int generation;  //current generation no
int cur_best;  //best individual
int func_num = 0;  //the number of the function you choose
FILE *galog; //an output file

double result[30];
int r = 0;

void initialize(void);
double randval(double,double);
void evaluate(void);
void keep_the_best(void);
void elitist(void);
void select(void);
void crossover(void);
void Xover(int,int);
void swap(double *,double *);
void mutate(void);
void report(void);

void test_func();

//initialize all the variables
void initialize(void){
    int i,j;
    double lbound,ubound;
    for(i = 0;i < NVARS;i++){
        lbound = -5.0;
        ubound = 5.0;
        for(j = 0;j < POPSIZE;j++){
            population[j].fitness = 0;
            population[j].rfitness = 0;
            population[j].cfitness = 0;
            population[j].lower[i] = lbound;
            population[j].upper[i] = ubound;
            population[j].gene[i] = randval(population[j].lower[i],population[j].upper[i]);
        }
    }
}

//generates a variable
double randval(double low,double high){
    double val;
    val = ((double)(rand()%10000)/10000.0) * (high - low) + low;
    return (val);
}

//evaluate the individual's fitness
void evaluate(void){
    int mem;
    for(mem = 0;mem < POPSIZE;mem++){
        benchmark(population[mem],func_num);
    }
}

//keep track of the best member of the population
void keep_the_best(){
    int mem;
    int i;
    cur_best = 0;
    for(mem = 0;mem < POPSIZE;mem++){
        if(population[mem].fitness > population[POPSIZE].fitness){
            cur_best = mem;
            population[POPSIZE].fitness = population[mem].fitness;
        }
    }
    //put the best one in the last of the population array
    for(i = 0;i < NVARS;i++)
        population[POPSIZE].gene[i] = population[cur_best].gene[i];
}

//
void elitist(){
    int i;
    double best,worst;
    int best_mem,worst_mem;

    best = population[0].fitness;
    worst = population[0].fitness;

    //找出 新一代 population数组中最好的个体与最差的个体存入best和worst中
    for(i = 0;i < POPSIZE;i++){
        if(population[i].fitness > population[i+1].fitness){
            if(population[i].fitness >= best){
                best = population[i].fitness;
                best_mem = i;
            }
            if(population[i+1].fitness <= worst){
                worst = population[i+1].fitness;
                worst_mem = i+1;
            }
        }else{
            if(population[i].fitness <= worst){
                worst = population[i].fitness;
                worst_mem = i;
            }
            if(population[i+1].fitness <= best){
                best = population[i+1].fitness;
                best_mem = i+1;
            }
        }
    }
    //比较新一代最好的个体与当前一代最好个体之间的大小
    //若新一代的个体更好，则用其取代当前的最好个体population[POPSIZE]
    //否则使用当前代最好的个体取代新一代最差的个体
    if(best >= population[POPSIZE].fitness){
        for(i = 0;i < NVARS;i++)
            population[POPSIZE].gene[i] = population[best_mem].gene[i];
        population[POPSIZE].fitness = population[best_mem].fitness;
    } else{
        for(i = 0;i < NVARS;i++)
            population[worst_mem].gene[i] = population[POPSIZE].gene[i];
        population[worst_mem].fitness = population[POPSIZE].fitness;
    }
}

//select function: standard proportional selection for maximization problems——make sure the best member survives
void select(void){
    int mem,i,j;
    double sum = 0;
    double p;
    //计算相对适应度
    for(mem = 0;mem < POPSIZE;mem++){
        sum += population[mem].fitness;
    }
    for(mem = 0;mem < POPSIZE;mem++){
        population[mem].rfitness = population[mem].fitness / sum;
    }
    //计算累积适应度
    population[0].cfitness = population[0].rfitness;
    for(mem = 1;mem < POPSIZE;mem++){
        population[mem].cfitness = population[mem - 1].cfitness + population[mem].rfitness;
    }
    //第i个新个体产生的随机数的大小小于第0个个体的累积适应度rfitness时，将个体0赋给第i个新个体
    //否则将离随机数大小最近最大的累积适应度对应的个体j+1赋值给第i个新个体
    for(i = 0;i < POPSIZE;i++){
        p = rand()%1000/1000.0;
        if(p < population[0].cfitness){
            newpopulation[i] = population[0];
        }else{
            for(j = 0;j < POPSIZE;j++){
                if(p >= population[j].cfitness && p < population[j+1].cfitness){
                    newpopulation[i] = population[j+1];
                }
            }   
        }
    }
    //迭代将新个体赋值给当前个体
    for(i = 0;i < POPSIZE;i++){
        population[i] = newpopulation[i];
    }
}

//crossover function: implement a single point crossover
void crossover(void){
    int mem,one;
    int first = 0;
    double x;
    //当随机产生数的大小小于杂交的概率时，单数个基因与偶数个基因交换（杂交）
    for(mem = 0;mem < POPSIZE;++mem){
        x = rand()%1000/1000.0;
        if(x < PXOVER){
            ++first;
            if(first % 2 == 0)
                Xover(one,mem);
            else
                one = mem;
        }
    }
}

//perform crossover of the two selected parents
void Xover(int one,int two){
    int i;
    int point;
    if(NVARS > 1){
        if(NVARS == 2)
            point = 1;
        else{
            //两点交叉
            for(int j = 0;j < 2;j++){
                 point = (rand()%(NVARS-1))+1;
                //随机生成一个点，将从0到该点之间的基因交换
                for(i = 0;i < point;i++)
                    swap(&population[one].gene[i],&population[two].gene[i]);
            }
        }
           
    }
}

//swap: a function to help swap 2 variables
void swap(double *x,double *y){
    double temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

//Random uniform mutation: A variable selected for mutation is replaced
// by a random value between lower and upper bounds of the variable.
//基因突变
void mutate(void){
    int i,j,y;
    double lbound,hbound;
    double x;

    for(i = 0;i < POPSIZE;i++){
        y = rand()%NVARS;
        //对于每一位个体产生k位基因发生突变
        for(int k = 0;k < y;k++){
            for(j = 0;j < NVARS;j++){
                x = rand()%1000/1000.0;
                //当随机数比发生基因突变概率小时
                //使该个体的每一个基因在[lbound,hbound]之间随机突变
                if(x < PMUTATION){
                    lbound = population[i].lower[j];
                    hbound = population[i].upper[j];
                    population[i].gene[j] = randval(lbound,hbound);
                }
            }
        }
        
    }
}

//report progress of the simulation
void report(void){
    int i;
    double best_val;
    double avg;
    double stddev;
    double sum_square;
    double square_sum;
    double sum;

    sum = 0.0;
    sum_square = 0.0;

    for(i = 0;i < POPSIZE;i++){
        sum += population[i].fitness;
        sum_square += population[i].fitness * population[i].fitness;
    }
    //计算标准差作为评判标准
    avg = sum / (double)POPSIZE;
    square_sum = avg * avg * (double)POPSIZE;
    stddev = sqrt((sum_square - square_sum)/(POPSIZE - 1));
    best_val = population[POPSIZE].fitness;
    fprintf(galog,"\n%5d,    %6.3f,%6.3f,%6.3f\n\n",generation,best_val,avg,stddev);
}

//main
int main(int argc, char *argv[]) {
    int i;
    if((galog = fopen("./galog.txt","w")) == NULL){
       exit(1);
    }
    printf("Please choose a function from 1 to 13:\n");
    // scanf("%d",&func_num);
    func_num = stoi(argv[1]);
    fprintf(galog,"number     value fitness deviation\n");
    printf("\n generation best average standard\n");
    generation = 0;
    srand(time(NULL));
    initialize();
    evaluate();
    keep_the_best();
    while(generation < MAXGENS){
        generation++;
        select();
        crossover();
        mutate();
        report();
        evaluate();
        elitist();
    }
    fprintf(galog,"\n\n Simulation completed\n");
    fprintf(galog,"\n Best member:\n");
    printf("\n Best member:\n");

    // for(i = 0;i < NVARS;i++){
    //     fprintf(galog,"\n var(%d) = %3.3f",i ,population[POPSIZE].gene[i]);
    //     printf("\n var(%d) = %3.3f",i,population[POPSIZE].gene[i]);
    // }
    fprintf(galog,"\n\n Best fitness = %3.10f",population[POPSIZE].fitness);
    printf("\n\n Best member = %3.10f\n",population[POPSIZE].fitness);
    fclose(galog);
    printf("Success\n");

    return 0;
}
