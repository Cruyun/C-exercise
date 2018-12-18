#define POPSIZE 500 //population size
#define MAXGENS 1000  //max number of generation
#define NVARS 40  // length of the gene
#define PXOVER 0.75  //probability of crossover
#define PMUTATION 0.015  //probability of mutation
#define TRUE 1
#define FALSE 0
#define D 40
#define NP 40  //length of the gene

struct genotype{
    double gene[NVARS];
    double fitness;//适应度，评判标准
    double upper[NVARS];
    double lower[NVARS];
    double rfitness;//相对适应度 relative fitness
    double cfitness;//累积适应度 cumulation fitness
};

struct genotype population[POPSIZE+1];
struct genotype newpopulation[POPSIZE+1];