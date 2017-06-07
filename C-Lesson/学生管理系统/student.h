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
    char id[11];
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
int CheckScore(float score);
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
void level(Student *p);
void WriteFile(FILE *fp, Student *p, int lastInfo);
void ReadFile();
void SaveToFile();
void InsertToFile();
void CopyFile();

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
    for (i = 1; i < 16; i++) {
        SWITCH[i] = 0;
    }

    SWITCH[1] = 1;
    SWITCH[6] = 1;
    return head;
}

// 管理员身份登录-界面
void AdminInterface() {
    printf("\n\n");
    printf("\t\t\t                            管理员，欢迎你！\n");
    printf("\t\t\t******************************************************************************\n");
    printf("\t\t\t*                                                                            *\n");
    printf("\t\t\t*                     1.  初始化                                             *\n");
    printf("\t\t\t*                     2.  录入数据                                           *\n");
    printf("\t\t\t*                     3.  查找学号或姓名删除信息                             *\n");
    printf("\t\t\t*                     4.  打印全部学生信息                                   *\n");
    printf("\t\t\t*                     5.  按姓名查找学生信息                                 *\n");
    printf("\t\t\t*                     6.  计算所有学生的总分和平均分                         *\n");
    printf("\t\t\t*                     7.  插入一个学生信息到链表中                           *\n");
    printf("\t\t\t*                     8.  按总分排序并打印学生信息                           *\n");
    printf("\t\t\t*                     9.  按学号索引学生信息                                 *\n");
    printf("\t\t\t*                     10. 分类汇总                                           *\n");
    printf("\t\t\t*                     11. 按等级百分比统计                                   *\n");
    printf("\t\t\t*                     12. 写入文件                                           *\n");
    printf("\t\t\t*                     13. 读取文件                                           *\n");
    printf("\t\t\t*                     14. 退出                                               *\n");
    printf("\t\t\t*                                                                            *\n");
    printf("\t\t\t******************************************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t*****************Please Input your choice:");
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
    printf("\n\n");
    printf("\t\t\t                               同学，你好\n");
    printf("\t\t\t******************************************************************************\n");
    printf("\t\t\t*                                                                            *\n");
    printf("\t\t\t*                     1.  初始化                                             *\n");
    printf("\t\t\t*                     2.  录入数据                                           *\n");
    printf("\t\t\t*                     3.  打印全部学生信息                                   *\n");
    printf("\t\t\t*                     4.  按姓名查找学生信息                                 *\n");
    printf("\t\t\t*                     5.  计算所有学生的总分和平均分                         *\n");
    printf("\t\t\t*                     6.  按总分排序并打印学生信息                           *\n");
    printf("\t\t\t*                     7.  按学号索引学生信息                                 *\n");
    printf("\t\t\t*                     8.  分类汇总                                           *\n");
    printf("\t\t\t*                     9.  按等级百分比统计                                   *\n");
    printf("\t\t\t*                     10. 退出                                               *\n");
    printf("\t\t\t*                                                                            *\n");
    printf("\t\t\t******************************************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t*****************Please Input your choice:");

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

    for (i = 0; i < strlen(s); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
            return 0;
    }

    return 1;
}

int CheckID(char* s) {
    int i;

    if (strlen(s) == 0 || strlen(s) > 10) return 0;

    for (i = 0; i < strlen(s); i++) {
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
    printf("\t\t\t请输入学生的数目: \n");
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

    printf("\n\t\t\t==请输入学生的学号== \n");
    printf("\t\t\t学号：");
    do {
        scanf("%s", p->id);

        if (!CheckID(p->id)) {
            printf("\t\t\t数据违法，请重新输入学号: ");
        }
        else if (isUniqueID(p->id)) {
            printf("\t\t\t已存在此学号，请重新输入: ");
        }
    }while (!(CheckID(p->id) && !isUniqueID(p->id)));

    fflush(stdin);

    printf("\n\t\t\t==请输入学号为%s的学生信息== \n", p->id);
    printf("\t\t\t姓名:");
    scanf("%s", p->name);
    fflush(stdin);

    printf("\t\t\t年龄: ");
    scanf("%d", &p->age);
    fflush(stdin);

    printf("\t\t\t班级: ");
    scanf("%d", &p->classno);
    for( ;p->classno < 1 || p->classno > 8 ; ){
        fflush(stdin);
        printf("\t\t\tInput error!\n");
        printf("\t\t\t请重新输入：");
        scanf("%d", &p->classno);
    }
    fflush(stdin);

    for (int i = 0; i<3; i++) {
        if (i == 0)
            printf("\t\t\t数学: ");
        else if(i == 1)
            printf("\t\t\tC语言: ");
        else if (i==2)
            printf("\t\t\t英语: ");
        do {
            fflush(stdin);
            scanf("%f", &p->score[i]);
            if (!CheckScore(p->score[i])) {
                printf("\t\t\t成绩为0-100！请重新输入");
            }
        } while (!CheckScore(p->score[i]));
    }

    p->sum = -1;
    p->ave = -1;

}

int CheckScore(float score) {
    if (score< 0 || score > 100)
        return 0;
    return 1;
}

void showData(Student* p) {
    int i;

    printf("\n");
    printf("\t\t\t学号: %s\n", p->id);
    printf("\t\t\t姓名: %s\n", p->name);
    printf("\t\t\t年龄: %d\n", p->age);
    printf("\t\t\t班级: %d\n", p->classno);

    printf("\t\t\t数学: %.2f\n", p->score[0]);
    printf("\t\t\tC语言: %.2f\n", p->score[1]);
    printf("\t\t\t英语: %.2f\n", p->score[2]);

    if (SWITCH[8]) printf("\t\t\t总分: %.2f\n", p->sum);
    if (SWITCH[8]) printf("\t\t\t平均分: %.2lf\n", p->ave);

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
    printf("\t\t\t请输入你要删除的学生的 姓名 或 学号: ");
    do {
        gets(str);

        if (!(CheckID(str) || CheckName(str))) {
            printf("\t\t\t数据违法，请重新输入姓名或学号: ");
        }
    }
    while (!(CheckID(str) || CheckName(str)));

    // 判断是姓名还是学号
    if (str[0] >= '0' && str[0] <= '9') {
        p = SearchID(str);

        if (p == NULL) {
            printf("\t\t\t对不起，找不到这个学号\n");
        }
        else {
            showData(p);
            printf("\t\t\t确认删除? (输入\"y\"确认，任意键取消): ");
            if (strcmp(gets(sure), "y") == 0) {
                DeleteNode(p);
                printf("\t\t\t删除成功\n");
                SWITCH[6] = 0;
            }
            fflush(stdin);
        }
    }
    else {
        p = SearchName(str);

        if (p == NULL) {
            printf("\t\t\t对不起，找不到这个姓名\n");
        }
        else {
            showData(p);
            printf("\t\t\t确认删除? (输入\"y\"确认，任意键取消): ");
            if (strcmp(gets(sure), "y") == 0) {
                DeleteNode(p);
                printf("\t\t\t删除成功!\n");
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
    if (p == NULL) {
        printf("\t\t\t暂无学生信息!\n");
    }

    while (p != NULL) {
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
    printf("\t\t\t请输入你要查找的学生姓名: ");
    do {
        gets(name);
        if (!CheckName(name)) {
            printf("\t\t\t数据违法，请重新输入姓名: ");
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
        printf("\t\t\t对不起，找不到这个姓名\n");
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

// 计算等级百分比
void level() {
    Student *p = head->next;

    struct Level subject[3]={0};
    int num=0; //学生人数

    while (p != NULL) {
        num++;
        for (int i = 0; i < 3; i++) {
            if (p->score[i] >= 90 && p->score[i] <= 100) {
                subject[i].Excellent++;
            } else if (p->score[i] >= 80 && p->score[i] < 90) {
                subject[i].Fine++;
            } else if (p->score[i] >= 70 && p->score[i] < 80) {
                subject[i].Medium++;
            } else if (p->score[i] >= 60 && p->score[i] < 70) {
                subject[i].Pass++;
            } else {
                subject[i].Failed++;
            }
        }
        p = p->next;
    }

        for (int i = 0; i < 3; i++) {
            switch (i) {
                case 0:
                    printf("\t\t\t数学: \n");
                    break;
                case 1:
                    printf("C\t\t\t语言: \n");
                    break;
                case 2:
                    printf("\t\t\t英语: \n");
                    break;
                default:
                    break;
            }
            printf("\t\t\t优秀(90-100) %2d %-5.2f%%\n", subject[i].Excellent, 1.0 * subject[i].Excellent / num * 100);
            printf("\t\t\t良好(80-89)  %2d %-5.2f%%\n", subject[i].Fine, 1.0 * subject[i].Fine / num * 100);
            printf("\t\t\t中等(70-79)  %2d %-5.2f%%\n", subject[i].Medium, 1.0 * subject[i].Medium / num * 100);
            printf("\t\t\t及格(60-69)  %2d %-5.2f%%\n", subject[i].Pass, 1.0 * subject[i].Pass / num * 100);
            printf("\t\t\t不及格(0-59) %2d %-5.2f%%\n", subject[i].Failed, 1.0 * subject[i].Failed / num * 100);
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

    // 表尾处理
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
        printf("\t\t\t暂无学生信息，无法统计\n");
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
            printf("\t\t\t数学");
        else if (i==1)
            printf("\t\t\tC语言");
        else if (i==2)
            printf("\t\t\t英语");
        printf("\t\t\t总分: %.2f, 总均分: %.2lf\n", sum[i], sum[i] * 1.0 / n);
        head = Sort(CmpScore, i);
        j = 0;
        p = head->next;

        while (p != NULL) {
            j++;
            printf("\t\t\tNO %d %s %.2f\n", j, p->name, p->score[i]);
            p = p->next;
        }
        printf("\n");
    }
}

// 比较各科分数
int CmpScore(Student* a, Student* b, int k) {
    return b->score[k] - a->score[k];
}

// 释放链表
void FreeList(Student* p) {
    if (p->next != NULL) {
        FreeList(p->next);
    }
    free(p);
}

void WriteFile(){
    int num;

    FILE *fp;
    Student *p;
    int lastInfo;
    int i = 0, j;
    char flag;
    printf("\t\t\t请输入你要写入的文件： \n");
    scanf("%d", &i);
    switch (i) {
        case 1:
            printf("\t\t\t该文件不存在，是否要创建新文件？\n");
            printf("\t\t\t输入\"n\"结束或者输入\"y\"继续\n");
            scanf("%c", &flag);
            if (flag == 'n') {
                break;
            } else if (flag == 'y') {
                fp = fopen("class01.dat", "w");
            }
            break;
        case 2:
            fp = fopen("class02.dat", "a");
            break;
        case 3:
            fp = fopen("class03.dat", "a");
            break;
        case 4:
            fp = fopen("class04.dat", "a");
            break;
        case 5:
            fp = fopen("class05.dat", "a");
            break;
        case 6:
            printf("\t\t\t该文件不存在，是否要创建新文件？\n");
            printf("\t\t\t输入\"n\"结束或者输入\"y\"继续\n");
            scanf("%c", &flag);
            if (flag == 'n') {
                break;
            } else if (flag == 'y') {
                fp = fopen("class06.dat", "w");
            }
            break;
        case 7:
            fp = fopen("class07.dat", "a");
            break;
        default:
            printf("\t\t\t请输入合法的班级名称\n");
            break;
    }

    if (fp == NULL) {
        printf("\t\t\t打开文件失败\n");
        exit(0);
    } else {
        int i;
        fprintf(fp, "%s\n", p->id);
        fprintf(fp, "%s\n", p->name);
        fprintf(fp, "%d\n", p->classno);
        for (i=0; i<3; i++){
            fprintf(fp, "%f\n", p->score[i]);
        }
        if (lastInfo) {
            fprintf(fp, "%f\n", p->score[i]);
        } else {
            fprintf(fp, "%f", p->score[i]);
        }
        fclose(fp);
        printf("\t\t\t写入成功\n");
        returnUserFace();
    }
}

// 追加记录到文件中
void InsertToFile()
{
    tmp = LEN;
    readData(tmp);
    SWITCH[12] = 1;
}
void ReadFile() {
    FILE *p;
    int i = 0;
    printf("\t\t\t请输入你要读取的文件: \n");
    scanf("%d", &i);
    switch (i) {
        case 2:
            p = fopen("class02.dat", "r");
            break;
        case 3:
            p = fopen("class03.dat", "r");
            break;
        case 4:
            p = fopen("class04.dat", "r");
            break;
        case 5:
            p = fopen("class05.dat", "r");
            break;
        case 7:
            p = fopen("class07.dat", "r");
            break;
        default:
            printf("\t\t\t找不到该文件\n");
            break;
    }
    if (p == NULL) {
        printf("\t\t\t打开文件失败\n");
        exit(0);
    } else {
        int num = 0;
        Student *r = head->next;
        while (r != NULL) {
            num++;
            fprintf(p, "%s %s ", r->id, r->name);
            for (int j = 0; j < 3; j++) {
                fprintf(p, "%.2f", r->score[j]);
            }
            fprintf(p, " %.2f %.2f", r->sum, (r->sum) / 3);
            fprintf(p, "\n");

            fscanf(p, "%s %s ", r->id, r->name);
            printf("%s %s ", r->id, r->name);
            for (int j = 0; j < 3; j++) {
                printf("%.2f ", r->score[j]);
            }
            printf(" %.2f %.2f\n", r->sum, (r->sum) / 3);
            r = r->next;
        }
    }
        fclose(p);
        returnUserFace();
}
