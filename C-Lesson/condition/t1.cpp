//输入两门课的成绩，如果两门成绩都在60分以上。则输出“it is pass.”只要有一门低于60分就输出“it is not pass.”如果输入的任何一门成绩不在0-100范围内则输出“it is error.”。(要求用switch语句来编程)

#include <stdio.h>
int main()
{
    int score1, score2;
    printf("输入两门课的成绩（用空格隔开）：");
    scanf("%d %d",&score1,&score2);
    if( (score1<0||score1>100) || (score2<0||score2>100))
        printf("it is error.\n");
    else
    {
        switch(score1/10)
        {
            case 10:
            case 9:
            case 8:
            case 7:
            case 6:
                switch(score2/10)
                {
                    case 10:
                    case 9:
                    case 8:
                    case 7:
                    case 6:
                        printf("it is pass.\n");
                        break;
                    default:
                        printf("it is not pass.\n");
                        break;
                }
                break;
            default:
                printf("it is not pass.\n");
                break;
        }
    }
}
