/** 判断是否链表有环且返回该节点位置，不得改变链表
 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : NULL;
            
            if (!slow || !fast) {
                return NULL;
            }
            if (slow == fast) {
                break;
            }
        }
        
        ListNode* node = head;
        while (node != slow) {
            slow = slow->next;
            if (slow == fast) {
                node = node->next;
            }
        }
        return node;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (slow && fast) {
            if (!fast || !fast->next) {
                return NULL;
            }
            
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                slow = head;
                
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};