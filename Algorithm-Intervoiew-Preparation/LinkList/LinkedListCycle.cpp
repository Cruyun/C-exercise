/* 判断链表是否有环 
  方法一：使用快慢指针，若指针相遇则判断有环
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

/* 判断链表是否有环 
  方法二：算法思想就是每遍历一个节点之后，就把这个节点的next指向head，如果不成环，遇到null值就返回false，如果成环，那么必然会访问已经访问过的结点，而此时访问过的结点的next已经换成head了，所以判断是否和head相等即可。 
  该方法会改变链表。
*/