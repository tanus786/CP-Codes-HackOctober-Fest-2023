#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtTail(Node *&head, int val)
{
    Node *temp = head;
    Node *n = new Node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

 

void sort(Node *&head)
{
    Node *ptr, *cptr;
    int temp;
    ptr = head;
    while (ptr->next != NULL)
    {
        cptr = ptr->next;
        while (cptr != NULL)
        {
            if (ptr->data > cptr->data)
            {
                temp = ptr->data;
                ptr->data = cptr->data;
                cptr->data = temp;
            }
            cptr = cptr->next;
        }
        ptr = ptr->next;
    }
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 5);
    insertAtTail(head, 1);
    insertAtTail(head, 4);

    insertAtTail(head, 2);
    insertAtTail(head, 6);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    cout<<"Given Lined list"<<endl;
    display(head);
    sort(head);
    cout<<"Sorted Lined list"<<endl;
    display(head);

    return 0;
}
