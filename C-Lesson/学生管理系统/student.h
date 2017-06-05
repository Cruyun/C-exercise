#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//#ifndef UNTITLED_STUDENT_H
//#define UNTITLED_STUDENT_H

#define IdLen 10
#define NameLen 10
#define LEN (Student*) malloc(sizeof(Student))

static int login;

struct Level{
    int Excellent;
    int Fine;
    int Medium;
    int Pass;
    int Failed;
};

typedef struct Student_Info{
    char id[10];
    char name[10];
    int age;
    int classno;
    float score[3];
    float sum, ave;

    struct Student_Info *next;
} Student;

int SWITCH[16] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// 头指针
Student *head = NULL;
// 临时指针
Student *tmp = NULL;

void SystemSet();
int ScanSet();
Student* Init();
void AdminInterface();
void StudentInterface();
void returnAdminFace();
void returnStudentFace();
void returnUserFace();
int CheckName (char *s);
int CheckID(char* s);
int isUniqueID(char* s);
void readData(Student *p);
void InsertBefore();
void CheckScore(float score);
void showData(Student* p);
Student* SearchFrontNode(Student* r);
void DeleteNode(Student* r);
void InsertBefore();
Student* SearchID(char* id);
Student* SearchName(char* name);
void SearchDeleteNode();
void OutList();
void PrintName();
void Compute();
int CmpID(Student* a, Student* b, int k);
int CmpSum(Student* a, Student* b, int k);
Student* SearchMaxNode(int (*cmp)(Student* a, Student* b, int k), int k);
int CmpScore(Student* a, Student* b, int k);
void Stat();
void InsertAfter(Student* s);
void FreeList(Student* p);
Student* Sort(int (*cmp)(Student* a, Student* b, int k), int k);

// 系统设置
void SystemSet() {
    system("title  学生管理系统");
}

// 读取选项
int ScanSet() {
    int n;
    scanf("%d", &n);
    return n;
}

Student* Init() {
    int i;
    Student *head;
    head = LEN;
    head->next = NULL;

    // 命令开关初始化
    for (i = 1; i < 16; i++)
    {
        SWITCH[i] = 0;
    }

    SWITCH[1] = 1;
    SWITCH[6] = 1;
    return head;
}

// 管理员身份登录-界面
void AdminInterface() {
    printf("管理员，欢迎你！\n");
    printf("【1】 初始化\n");
    printf("【2】 录入数据\n");
    printf("【3】 查找学号或姓名删除信息\n");
    printf("【4】 打印全部学生信息\n");
    printf("【5】 按姓名查找学生信息\n");
    printf("【6】 计算所有学生的总分和平均分\n");
    printf("【7】 插入一个学生信息到链表中\n");
    printf("【8】 按总分排序并打印学生信息\n");
    printf("【9】 按学号索引学生信息\n");
    printf("【10】 分类汇总\n");
    printf("【11】 退出\n");
    printf("请输入命令编号: ");
}
// 返回用户界面
void returnAdminFace() {
    while(getchar() != '\n');
    system("pause");  // 按任意键继续
    system("cls");    // 清除屏幕
    AdminInterface();
}
//学生身份登录-界面
void StudentInterface() {
    printf("同学，你好\n");
    printf("【1】 初始化\n");
    printf("【2】 录入数据\n");
    printf("【3】 打印全部学生信息\n");
    printf("【4】 按姓名查找学生信息\n");
    printf("【5】 计算所有学生的总分和平均分\n");
    printf("【6】 按总分排序并打印学生信息\n");
    printf("【7】 按学号索引学生信息\n");
    printf("【8】 分类汇总\n");
    printf("【9】 退出\n");
    printf("请输入命令编号: ");

}
// 返回用户界面
void returnStudentFace() {
    while(getchar() != '\n');
    system("pause");  // 按任意键继续
    system("cls");    // 清除屏幕
    StudentInterface();
}

void returnUserFace() {
    if(login == 1)
        returnAdminFace();
    else if (login == 2)
        returnStudentFace();
}

int CheckName (char *s) {
    int i;

    if (strlen(s) == 0 || strlen(s) > NameLen)
        return 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
            return 0;
    }

    return 1;
}

int CheckID(char* s) {
    int i;

    if (strlen(s) == 0 || strlen(s) > 10) return 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] < '0' || s[i] > '9') return 0;
    }

    return 1;
}

int isUniqueID(char* s) {
    Student *p = head->next;
    while(p != NULL) {
        if (strcmp(s, p->id) == 0) return 1;
        p = p->next;
    }
    return 0;
}

//输入链表，学生数目
void nodeList() {
    int num;
    printf("请输入学生的数目: \n");
    scanf("%d", &num);

    while (num--) {
        InsertBefore();
        if(num==0)
            returnUserFace();
    }
}

void readData(Student *p) {
    int i;
    fflush(stdin);

    printf("\n==请输入学生的学号== \n");
    do {
        scanf("%s", p->id);

        if (!CheckID(p->id))
        {
            printf("数据违法，请重新输入学号: ");
        }
        else if (isUniqueID(p->id))
        {
            printf("已存在此学号，请重新输入: ");
        }
    }while (!(CheckID(p->id) && !isUniqueID(p->id)));


    fflush(stdin);

    printf("\n==请输入学号为%s的学生信息== \n", p->id);
    printf("姓名:");
    scanf("%s", p->name);
    fflush(stdin);

    printf("年龄: ");
    scanf("%d", &p->age);
    fflush(stdin);

    printf("班级: ");
    scanf("%d", &p->classno);
    for( ;p->classno < 1 || p->classno > 8 ; ){
        printf("Input error!\n");
        printf("请重新输入：");
        scanf("%d", &p->classno);
    }
    fflush(stdin);

    printf("数学: ");
    scanf("%f", &p->score[0]);
    CheckScore(p->score[0]);
    fflush(stdin);

    printf("C语言: ");
    scanf("%f", &p->score[1]);
    CheckScore(p->score[1]);
    fflush(stdin);

    printf("英语: ");
    scanf("%f", &p->score[2]);
    CheckScore(p->score[2]);
    fflush(stdin);

    p->sum = -1;
    p->ave = -1;

}

void CheckScore(float score) {
    for (;score< 0 || score > 100;){
        printf("Input error!\n");
        printf("请重新输入:");
        scanf("%f",&score);
    }
}

void showData(Student* p) {
    int i;

    printf("\n");
    printf("学号: %s\n", p->id);
    printf("姓名: %s\n", p->name);
    printf("年龄: %d\n", p->age);
    printf("班级: %d\n", p->classno);

    printf("数学: %.2f\n", p->score[0]);
    printf("C语言: %.2f\n", p->score[1]);
    printf("英语: %.2f\n", p->score[2]);

    if (SWITCH[8]) printf("总分: %.2f\n", p->sum);
    if (SWITCH[8]) printf("平均分: %.2lf\n", p->ave);

}

// 返回r的前一个节点
Student* SearchFrontNode(Student* r) {
    Student *p = head;
    while (p->next != r) p = p->next;
    return p;
}

// 删除r指向的节点
void DeleteNode(Student* r) {
    Student *p = SearchFrontNode(r);
    p->next = r->next;
}

// 插入节点
void InsertBefore() {
    Student *s = LEN;
    readData(s);
    s->next = head->next;
    head->next = s;
}

// 按学号查找
Student* SearchID(char* id) {
    Student *p = head->next;

    while (p != NULL) {
        if (strcmp(p->id, id) == 0)
            break;
        p = p->next;
    }

    return p;
}

// 按姓名查找
Student* SearchName(char* name) {
    Student *p = head->next;

    while (p != NULL) {
        if (strcmp(p->name, name) == 0)
            break;
        p = p->next;
    }

    return p;
}

// 按学号或姓名查找删除节点
void SearchDeleteNode() {
    Student *p;
    fflush(stdin);
    char str[20];
    char sure[20];

    // 输入合法性判断
    printf("请输入你要删除的学生的 姓名 或 学号: ");
    do {
        gets(str);

        if (!(CheckID(str) || CheckName(str))) {
            printf("数据违法，请重新输入姓名或学号: ");
        }
    }
    while (!(CheckID(str) || CheckName(str)));

    // 判断是姓名还是学号
    if (str[0] >= '0' && str[0] <= '9') {
        p = SearchID(str);

        if (p == NULL) {
            printf("对不起，找不到这个学号\n");
        }
        else {
            showData(p);
            printf("确认删除? (输入\"y\"确认，任意键取消): ");
            if (strcmp(gets(sure), "y") == 0) {
                DeleteNode(p);
                printf("删除成功\n");
                SWITCH[6] = 0;
            }
            fflush(stdin);
        }
    }
    else {
        p = SearchName(str);

        if (p == NULL) {
            printf("对不起，找不到这个姓名\n");
        }
        else {
            showData(p);
            printf("确认删除? (输入\"y\"确认，任意键取消): ");
            if (strcmp(gets(sure), "y") == 0) {
                DeleteNode(p);
                printf("删除成功!\n");
                SWITCH[6] = 0;
            }
            fflush(stdin);
        }
    }
    returnUserFace();
}

// 输出链表
void OutList() {
    Student *p = head->next;

    // 空表处理
    if (p == NULL)
    {
        printf("暂无学生信息!\n");
    }

    while (p != NULL)
    {
        showData(p);
        p = p->next;
    }
}

// 查找姓名打印信息
void PrintName() {
    Student *p = head->next;
    int flag = 1;
    char name[20];
    fflush(stdin);

    // 姓名合法性判断
    printf("请输入你要查找的学生姓名: ");
    do {
        gets(name);
        if (!CheckName(name)) {
            printf("数据违法，请重新输入姓名: ");
        }
    }
    while (!CheckName(name));

    // 按姓名查找节点
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {
            flag = 0;
            showData(p);
        }
        p = p->next;
    }

    if (flag) {
        printf("对不起，找不到这个姓名\n");
    }
    returnUserFace();
}


// 计算总分和均分
void Compute() {
    Student *p = head->next;
    int i;

    while (p != NULL) {
        float sum = 0;
        for (i=0; i<3; i++) {
            sum += p->score[i];
        }
            p->sum = sum;
            p->ave = sum * 1.0 / 3;
            p = p->next;
    }
}

// 比较学号
int CmpID(Student* a, Student* b, int k) {
    return strcmp(a->id, b->id);
}

// 比较总分
int CmpSum(Student* a, Student* b, int k) {
    return b->sum - a->sum;
}


// 选择最大元素
Student* SearchMaxNode(int (*cmp)(Student* a, Student* b, int k), int k) {
    Student *p = head->next;
    Student *max = p;

    while (p != NULL) {
        if (cmp(p, max, k) < 0) {
            max = p;
        }
        p = p->next;
    }

    return max;
}

// 排序
Student* Sort(int (*cmp)(Student* a, Student* b, int k), int k) {
    Student *newhead = LEN;
    Student *p = newhead;
    Student *max;

    while (head->next != NULL)
    {
        max = SearchMaxNode(cmp, k);
        p->next = max;
        DeleteNode(max);
        p = p->next;
    }

    /* 表尾处理 */
    p->next = NULL;
    return newhead;
}

// 将s插入链表尾部
void InsertAfter(Student* s) {
    Student *p = head;

    while (p->next != NULL) p = p->next;

    s->next = NULL;
    p->next = s;
}

// 分类统计
void Stat() {
    int i, j, n = 0;
    float sum[3] = {0};
    Student *p = head->next;

    if (p == NULL) {
        printf("暂无学生信息，无法统计\n");
        return;
    }

    // 统计各科总分
    while (p != NULL) {
        n++;
        for(i=0; i<3; i++) {
            sum[i] += p->score[i];
        }
        p = p->next;
    }

    // 各科分别输出
    for (i = 0; i < 3; i++) {
        if (i==0)
            printf("数学");
        if (i==1)
            printf("C语言");
        if (i==2)
            printf("英语");
        printf("总分: %.2f, 总均分: %.2lf\n", sum[i], sum[i] * 1.0 / n);
        head = Sort(CmpScore, i);
        j = 0;
        p = head->next;

        while (p != NULL) {
            j++;
            printf("NO.%d %s %.2f\n", j, p->name, p->score[i]);
            p = p->next;
        }
        printf("\n");
    }
}

/* 比较各科分数 */
int CmpScore(Student* a, Student* b, int k) {
    return b->score[k] - a->score[k];
}

// 释放链表
void FreeList(Student* p) {
    if (p->next != NULL)
    {
        FreeList(p->next);
    }
    free(p);
}
