#include <iostream>
#include <set>
using namespace std;

class Student {
public:
    int id;
    int morality;
    int ability;
    int sum;
    int level;

    Student(int id, int morality, int ability) {
        this->id = id;
        this->morality = morality;
        this->ability = ability;
        this->sum = morality + ability;
        this->level = 1;
    }
    bool operator <(const Student& another)const {
        if (level != another.level)
            return level > another.level;
        else if (sum != another.sum)
            return  sum < another.sum;
        else if (morality != another.morality)
            return morality < another.morality;
        else
            return id > another.id;
    }
};
int main() {
    int N, L, H;
    cin >> N >> L >> H;

    set<Student> student;

    for (int i = 0; i < N; i++) {
        int id, morality, ability;
        cin >> id >> morality >> ability;
        Student stu(id, morality, ability);

        if (stu.morality < L || stu.ability < L)
            continue;
        else if (stu.morality >= H && stu.ability >= H)
            stu.level = 1;
        else if (stu.morality >= H && stu.ability < H)
            stu.level = 2;
        else if (stu.morality < H && stu.ability < H && stu.morality >= stu.ability)
            stu.level = 3;
        else
            stu.level = 4;
        student.insert(stu);
    }

    set<Student>::iterator iterator1;
    cout << student.size() << endl;
    for (iterator1 = student.rbegin(); iterator1 != student.rend(); iterator1++) {
        cout << (*iterator1).id << " " << (*iterator1).morality << " " << (*iterator1).ability << endl;
    }
    return 0;
}