/*
  Leetcode Question: Intersection of Two Linked Lists
  Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1 = headA;
        ListNode *tmp2 = headB;

        while(tmp1 != tmp2){
            tmp1 = tmp1 == NULL ? headB : tmp1->next; ;
            tmp2 = tmp2 == NULL ? headA : tmp2->next; ;
        }
        return tmp1;
    }
};
