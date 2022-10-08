#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct dnode 
{
    int data;
    struct dnode *prev,*next;
    
    
}dnode;

int main()
{ int n,i;
  dnode *head,*p,*q;
  printf("enter the no. of nodes:  ");
  scanf("%d",&n);

  head=(dnode*)malloc(sizeof(dnode));
 head->data=2;
 head->prev=NULL;
 head->next=NULL;
 q=head;
 for(i=1;i<=(n-1);i++)
 {
    p=(dnode*)malloc(sizeof(dnode));
    printf("enter the value of new node:");
    scanf("%d",&p->data);
    p->next=NULL;
    p->prev=q;
    q->next=p;
    q=q->next;
 }
 p=head;
 while(p!=NULL){
    printf("%d\t",p->data);
    p=p->next;

 }
 p=head;
 printf("\n");
 while(p->next!=NULL)
 {
    p=p->next;

 }
  while (p!=NULL)
  {
    printf("%d\t",p->data);
    p=p->prev;
  }
 return 0;
}