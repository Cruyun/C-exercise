#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    int score;            // 题目分数
    int num_Of_Correct;   // 正确答案数目
    char choices[5];      // 正确答案列表
}Multi_Choice_Question;

int main()
{
    char ch, ans[250];
    int num, score, wrong_list[101] = {0}, max = 0, n, m, answer_wrong = 0;

    scanf("%d %d", &n, &m);
    Multi_Choice_Question qlist[m];
    memset(qlist, 0, sizeof(Multi_Choice_Question)*m);

    for (int i = 0; i < m; i++) {
        scanf("%d %*d %d %[^\n]", &qlist[i].score, &qlist[i].num_Of_Correct, ans);
        for (int j = 0; ans[j] != 0; j++) {
            if ('a' <= ans[j] && ans[j] <= 'e')
                qlist[i].choices[ans[j] - 'a'] = 1;
        }
    }


    for (int i = 0; i < n; i++) {
        score = 0;
        for (int j = 0; j < m; j++, answer_wrong = 0, num = 0) {
            while ((ch = getchar()) != '(');
            scanf("%d %[^)]", &num, ans);

            if (num != qlist[j].num_Of_Correct)
                answer_wrong = 1;
            else {
                for (int k = 0; ans[k] != 0; k++) {
                    if ('a' <= ans[k] && ans[k] <= 'e')
                        if ((answer_wrong = !qlist[j].choices[ans[k] - 'a']))
                            break;
                }
            }

            if (answer_wrong)
                wrong_list[j] += 1;
            else
                score += qlist[j].score;
        }
        printf("%d\n", score);
    }

    for (int i = 0; i < m; i++)
        if (wrong_list[i] > max)
            max = wrong_list[i];

    if (max != 0) {
        printf("%d", max);
        for (int i = 0; i < m; i++)
            if (wrong_list[i] == max)
                printf(" %d", i+1);
    }
    else
        printf("Too simple");

    return 0;
}