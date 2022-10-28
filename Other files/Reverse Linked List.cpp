// C++ implementation of reversing a Linked list given its Head pointer
#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *p1, *p2, *p3;

    p1 = nullptr;
    p2 = head;
    p3 = head->next;

    while (p3)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }

    p2->next = p1;
    return p2;
}

int main()
{
    ListNode *head = new ListNode();
    ListNode *node2 = new ListNode();
    ListNode *node3 = new ListNode();
    ListNode *node4 = new ListNode();
    ListNode *node5 = new ListNode();

    head->val = 1;
    head->next = node2;

    node2->val = 2;
    node2->next = node3;

    node3->val = 4;
    node3->next = node4;

    node4->val = 4;
    node4->next = node5;

    node5->val = 5;
    node5->next = nullptr;

    ListNode *temp = head;

    cout << "Initial Linked List: \n";
    while (temp != nullptr)
    {
        cout << temp->val << "->";

        temp = temp->next;
    }
    cout << "NULL";

    head = reverseList(head);

    temp = head;

    cout << "\n\nReversed Linked List: \n";
    while (temp != nullptr)
    {
        cout << temp->val << "->";

        temp = temp->next;
    }
    cout << "NULL";
}

// This code is contributed by Omkar Jahagirdar (Github: omkar3602)