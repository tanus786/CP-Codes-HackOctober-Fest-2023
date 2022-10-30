#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

 

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node* &head, int val)
{

    node* n=new node(val);
    if(head==NULL)
        {
            head=n;
            return;
        }

    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int val)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
            return true;
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;
}

node* ireverse(node* &head)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* rreverse(node* &head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    node* newhead=rreverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* reversek(node* &head, int k)
{
    node* prev=NULL;
    node* curr=head;
    node* next;
    int count=0;

    while(curr!=NULL&&count<k)
    {
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
    head->next=reversek(next,k);
    }
    return prev;
}

void deletion(node* &head,int val)
{
    if(head==NULL)
        return;
    if(head->next==NULL)
        {
            deleteAtHead;
            return;
        }
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    // deletion(head,3);
    // deleteAtHead(head);
    // display(head);
    // node* newhead=rreverse(head);
    // display(newhead);

    node* newhead=reversek(head,2);
    display(newhead);

    
}
