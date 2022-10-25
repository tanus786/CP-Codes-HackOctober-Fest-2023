#include<iostream>
using namespace std;
int main(){
class node{
   public:
      int data;
      node*next;
      node(int d){
         data=d;
         node*next=NULL;
      }
};
void insertAtFirstNode(node*&head, int data){
   node*n= new node(data);
   n->next= head;
   head=n;
}
void print(node*head){
   while(head!=NULL){
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}
void deleteAtFirst(node*&head){
   if(head==NULL){
      return;
   }
   node*temp=head;
   head= head->next;
   delete temp;
   return;
}
int main(){
   node*head= NULL;
   insertAtFirstNode(head,1);
   insertAtFirstNode(head,2);
   insertAtFirstNode(head,3);
   insertAtFirstNode(head,4);
   deleteAtFirst(head);
   print(head);
}
