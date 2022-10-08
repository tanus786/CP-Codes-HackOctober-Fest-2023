#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node*next;
}node;
int insertion( node*head){
  int n,loc;
  node *p,*q;
  q=head;
  printf("Enter the location of node:");
  scanf("%d",&loc);
  p=(node*)malloc(sizeof(node));
  printf("Enter data:");
  scanf("%d",&n);
  for(int i=1;i<=loc-2;i++)
  {
    q=q->next;
  }
  p->next=q->next;
  q->next=p;
  p->data=n;
  printf("New linklist is:");
  p=head;
  while(p!=NULL)
  {
    printf("%d\t",p->data);
    p=p->next;
  }
 

  return 0;
}
int main()
{
  int n,i,t;
  node *a,*head=NULL;
  printf("Enter the number of nodes:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    if(head==NULL)
      {
        a=(node*)malloc(sizeof(node));
        head=a;
        printf("\n Enter element of node:");
        scanf("%d",&head->data);
        a->next=NULL;
      }
    else
    {
      a->next=(node*)malloc(sizeof(node));
      a=a->next;
      printf("Enter the data:");
      scanf("%d",&a->data);
      a->next=NULL;
     
    }
  }
  a=head;
  printf("Linked list:");
  while(a!=NULL)
  {
    printf("%d\t",a->data);
    a=a->next;
  }
  printf("Do you want to insert a node(if yes type1):");
  scanf("%d",&t);
  if(t==1)
    {insertion(head);}
  return 0;
}
