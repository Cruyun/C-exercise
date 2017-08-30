//读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
//输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
//
//输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
//
//输入样例：
//1234567890987654321123456789
//输出样例：
//yi san wu

//输出的和一定小于1000，注意数字的第一位不能为零
#include<stdio.h>
#include<string.h>

int main(){
     char s[1000];
         scanf("%s",s);
        int n = strlen(s);
        int sum=0;
        int i = 0, j = 0;

        while(n--)
        {
            sum += s[i]-'0';
            i++;
        }

        int a[1000];
        while(sum)
        {
            a[j] = sum % 10;
            sum = sum / 10;
            j++;
        }

        char c[][9] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    //第一位输出拼音
        j--;
        printf("%s",c[a[j]]);
    //剩下位输出拼音
        while(j--)
        {
            printf(" %s",c[a[j]]);
        }
     }
