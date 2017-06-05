#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAXNUM	100
void AdminLogin();
void CheckAdmin(int password);
void StudentLogin();

int main() {
    int password;

    printf("欢迎来到学生管理系统--by 夏玮蔚&蔡茹芸&李雪莹\n");
    printf("******管理员登录 输入1******\n");
    printf("******学生登录 输入2*******\n");
    scanf("%d", &login);
    switch (login){
        case 1:
            CheckAdmin(password);
//            AdminLogin();
            break;
        case 2:
            StudentLogin();
            break;
        default:
            printf("管理员身份请输入 1\n");
            printf("学生身份请输入 2\n");
            break;
    }
    return 0;
}
void CheckAdmin(int password) {
    int check;

    printf("请输入管理员密码：");
    scanf("%d",&password);
    if(password == 1234)
        AdminLogin();
    else {
        printf("密码错误！\n");
        printf("退出系统：0\n");
        printf("或重新输入管理员密码：");
        scanf("%d",&check);
        switch(check){
            case 0:
                return;
            case 1234:
                AdminLogin();
                break;
            default:
                CheckAdmin(password);

        }
    }
}
void AdminLogin() {
    SystemSet();
    AdminInterface();

    int n;

    while (1) {
        n = ScanSet();
        {
            if (n == 1 || n == 15 || SWITCH[1]) {
                switch (n) {
                    /* 执行初始化 */
                    case 1:
                        head = Init();
                        printf("初始化成功\n");
                        returnUserFace();
                        break;
                        /* 创建链表 */
                    case 2:
                        nodeList();
                        break;
                        /* 删除记录 */
                    case 3:
                        SearchDeleteNode();
                        returnUserFace();
                        break;
                        /* 显示全部记录 */
                    case 4:
                        system("cls");
                        OutList();
                        returnUserFace();
                        break;
                        /* 查找记录 */
                    case 5:
                        PrintName();
                        returnUserFace();
                        break;
                        /* 计算总分和均分 */
                    case 6:
                        Compute();
                        SWITCH[8] = 1;
                        printf("计算完毕\n");
                        returnUserFace();
                        break;
                        /* 插入记录 */
                    case 7:
                        InsertBefore();
                        SWITCH[6] = 0;
                        SWITCH[8] = 0;
                        returnUserFace();
                        break;
                        /* 排序 */
                    case 8:
                        if (SWITCH[8]) {
                            head = Sort(CmpSum, 0);
                            system("cls");
                            OutList();
                            returnUserFace();
                        }
                        else {
                            printf("请先计算总分!\n");
                        }
                        break;
                        /* 索引 */
                    case 9:
                        if (SWITCH[8]) {
                            head = Sort(CmpID, 0);
                            system("cls");
                            OutList();
                            returnUserFace();
                        }
                        else {
                            printf("请先计算总分!\n");
                            returnUserFace();
                        }
                        break;
                        /* 分类合计 */
                    case 10:
                        system("cls");
                        Stat();
                        returnUserFace();
                        break;
                        /* 结束 */
                    case 11:
                        exit(0);
                    default:
                        printf("无效命令!\n");
                        fflush(stdin);
                }
                system("pause");
            }
            else
            {
                printf("你必须首先初始化!\n");
                system("pause");
            }
        }
    }
}

void StudentLogin() {
    SystemSet();
    StudentInterface();
    int n;

    while (1)
    {
        n = ScanSet();
        {
            if (n == 1 || n == 15 || SWITCH[1]) {
                switch (n) {
                    /* 执行初始化 */
                    case 1:
                        head = Init();
                        printf("初始化成功\n");
                        returnUserFace();
                        break;
                        /* 创建链表 */
                    case 2:
                        nodeList();
                        break;
                    case 3:
                        /* 显示全部记录 */
                        system("cls");
                        OutList();
                        returnUserFace();
                        break;
                        /* 查找记录 */
                    case 4:
                        PrintName();
                        returnUserFace();
                        break;
                        /* 计算总分和均分 */
                    case 5:
                        Compute();
                        SWITCH[8] = 1;
                        printf("计算完毕\n");
                        returnUserFace();
                        break;
                        /* 插入记录 */
                    case 6:
                        /* 排序 */
                        if (SWITCH[8])
                        {
                            head = Sort(CmpSum, 0);
                            system("cls");
                            OutList();
                            returnUserFace();
                        }
                        else
                        {
                            printf("请先计算总分!\n");
                            returnUserFace();
                        }
                        break;
                        /* 索引 */
                    case 7:
                        if (SWITCH[8]) {
                            head = Sort(CmpID, 0);
                            system("cls");
                            OutList();
                            returnUserFace();
                        }
                        else {
                            printf("请先计算总分!\n");
                            returnUserFace();
                        }
                        break;
                        /* 分类合计 */
                    case 8:
                        system("cls");
                        Stat();
                        returnUserFace();
                        break;
                        /* 结束 */
                    case 9:
                        exit(0);
                    default:
                        printf("无效命令!\n");
                        fflush(stdin);
                        returnUserFace();
                }
                system("pause");
            }
            else {
                printf("你必须首先初始化!\n");
                system("pause");
            }
        }
    }
}