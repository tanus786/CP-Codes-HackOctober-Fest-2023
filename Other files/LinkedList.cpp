
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head=0;
void createCLL()
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    cout<<"enterdata"<<endl;
    cin>>newnode->data;
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;

    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    temp->next=head;
}

void display()
{
    struct node *temp;
    if(head== 0)
    {
        cout<<"head empty"<<endl;
    }
    else{
        temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
}
int main()
{
    int ch;
    do
    { cout<<"enter choice 1:insert 2:display"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: createCLL();
               break;
        case 2: display();
                break;
        default: cout<<"Invalid choice"<<endl;
    }
    } while (ch!=0);


}

