/*
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
示例 1:

输入: "()"
输出: True
示例 2:

输入: "(*)"
输出: True
示例 3:

输入: "(*))"
输出: True

Stack<Pair<Char,int>>left; Stack<Pair<Char,int>>star; 
分别建立左括号栈和*栈 存放左括号和*，及其位置

2.遍历字符串 如果是左括号和*，则入栈 如果是右括号，则优先选择左括号出栈，如果左括号栈为空，则选择*出栈。如果左括号栈和*栈都为空，则返回false

3.循环判断左括号栈和*栈的位置 因为有可能存在*（或者（比*还要多的情况，出现这些情况都是false
*/


class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int, char>> left;
        stack<pair<int, int>> star;
        
        for (int i = 0; i < s.size(); i++) {
            if (left.empty() && star.empty() && s[i] == ')') {
                return false;
            } else {
                if (s[i] == ')') {
                    if (left.empty()) {
                        star.pop();
                    } else {
                        left.pop();
                    }
                } else {
                    if (s[i] == '(') {
                        left.emplace(i, '(');
                    } else {
                        star.emplace(i, '*');
                    }
                }
            }
        }
        if (left.size() > star.size()) {
            return false;
        } else {
            while (!left.empty()) {
                if (star.top().first > left.top().first) {
                    left.pop();
                    star.pop();
            } else {
                return false;
                }
            }
        }
        return true;
    }
};