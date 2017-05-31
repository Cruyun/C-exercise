//铁路托运行李规定：行李重不超过50公斤的，托运费按每公斤0.15元计费；如超50公斤，超过部分每公斤加收0.10元。编一程序完成自动计费工作。

#include <stdio.h>

int main()
{
    float weight;
    float money;

    printf("输入行李重量：");
    scanf("%f", &weight);

    if(weight <= 50) money = weight * 0.15;
    else money = (weight-50.00) * 0.10 + 7.50;

    printf("行李托运费为：%f", money);
    return 0;
}
