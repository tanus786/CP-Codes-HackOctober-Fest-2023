#include<iostream>
using namespace std;

class Node{
public:
int val;
Node *next;
Node(int val)
{
    this->val=val;
    this->next=nullptr;
}
};

class customlinkedlist {
public:
Node *head , *tail;
int size=0;
customlinkedlist(){
    size=0;
    head=nullptr;
    tail=nullptr;
}


void addlast(int value){
Node *node=new Node(value);
if(size==0){
    size++;
     head=node;
     tail=node;
     return;
}
    tail->next=node;
    tail=node;
    size++;
}

void addfirst(int value){
    Node *node=new Node(value);
    if(size==0){
        addlast(value);
        return;
    }
    node->next=head;
    head=node;
    size++;
}

void removelast(){
    if(size==0){
    cout<<"linked list is empty"<<endl;
    return;
    }
    if(size==1)
    {
        size--;
        head=nullptr;
        tail=nullptr;
        return;
    }
    size--;
    Node *p=head;
    while (p->next!=tail)
    {
        p=p->next;
    }
    p->next=nullptr;
    tail=p;
    
}

void removefirst(){
    if(size==0){
        removelast();
        return;
    }
    if(size==1){
        removelast();
    }
    size--;
    head=head->next;
}

void display(){
    Node *p=head;
    while (p!=nullptr)
    {
       cout<<p->val<<" ";
       p=p->next;
    }
    cout<<endl;
}
};

int main(){
    customlinkedlist *c1=new customlinkedlist();
    c1->addlast(10);
    c1->addlast(20);
    c1->addlast(30);
    c1->addlast(50);
    c1->display();
    c1->addfirst(80);
    c1->display();
    c1->removelast();
    c1->display();
    c1->removefirst();
    c1->display();

}
