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
    ListNode* getnode_middle(ListNode* slow,ListNode* fast)
    {
        ListNode* temp=nullptr;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next->next;
            temp=slow;
            slow=slow->next;

        }
        return temp;
    }


    void inplacereverse(ListNode* last)
    {
        ListNode* prev=last->next;
        ListNode* present=prev->next;
        ListNode* f;
        if(present!=nullptr)
        {
            f=present->next;
        }
        while(present!=nullptr)
        {
            present->next=prev;
            prev=present;
            present=f;
            if(f!=nullptr)
                f=f->next;
        }
        last->next->next=nullptr;
        last->next=prev;
    }


    bool check(ListNode* start,ListNode*secondliststart)
    {
        ListNode* breaknode=secondliststart;
        while(start!=breaknode)
           { if(start==nullptr||start->val!=secondliststart->val)
                {return false;}
            start=start->next;
            secondliststart=secondliststart->next;}
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr)
            return false;
        if(head->next==nullptr)
            return true;
        ListNode* mid=getnode_middle(head,head);
        inplacereverse(mid);
        bool ans=check(head,mid->next);
        inplacereverse(mid);
        return ans;
    }
};