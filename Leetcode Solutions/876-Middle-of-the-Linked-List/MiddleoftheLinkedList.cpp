/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head,*p = head;
        long long int f=0,t=0,i=0;
        while(temp!= NULL)
        {
            t++;
            temp = temp->next;
        }
        if(t == 1)
            return head;
        
        f = t/2;
        while(i<f-1)
        {
          p = p->next;
          i++;  
            
        }
        p = p->next;
        head = p;   
        return head;
    }
};
