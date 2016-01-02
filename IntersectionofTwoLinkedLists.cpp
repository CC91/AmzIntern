// 160. Intersection of Two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA ||!headB) return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        int lA = 0, lB = 0;
        while (pA) {
            lA++;
            pA = pA->next;
        }
        
        while (pB) {
            lB++;
            pB = pB->next;
        }
        
        if (lA>lB) {
            for (int i=0; i<lA-lB; i++) headA = headA->next;
        }
        else for (int i=0; i<lB-lA; i++) headB = headB->next;
        
        while (headA) {
            if (headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};

// sol2: 2 traversal pointers
class Solution {
public: // http://www.cnblogs.com/yuzhangcmu/p/4128794.html
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA && pB) {
            if (pA==pB) return pA;
            pA = pA->next;
            pB = pB->next;
            if (!pA && !pB) return NULL; // no intersection, pA & pB are both at the end of the linked lists
            if (!pA) pA = headB;
            if (!pB) pB = headA;
        }
        return NULL;
    }
};