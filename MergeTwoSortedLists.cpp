// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* tmp = dummy;
        while (l1&&l2) {
            if (l1->val<l2->val) {
                tmp->next = l1;
                l1=l1->next;
            }
            else {
                tmp->next = l2;
                l2=l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1?l1:l2;
        return dummy->next;
    }
};