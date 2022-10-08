#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node*next;
}node;

int main()
{
  int n,i,t;
  node *a,*head=NULL;
  printf("Enter the number of nodes:");
  scanf("%d",&n);
   printf("\n Enter element of node:");
  for(i=1;i<=n;i++)
  {
    if(head==NULL)
      {
        a=(node*)malloc(sizeof(node));
        head=a;
        
        scanf("%d",&head->data);
        a->next=NULL;
      }
    else
    {
      a->next=(node*)malloc(sizeof(node));
      a=a->next;
      
      scanf("%d",&a->data);
      a->next=NULL;
     
    }
  }
  a=head;
  int f,count=1;
  printf("Enter the element you want to find:");
  scanf("%d",&f);
  while(a!=NULL)
  {
    if(f==a->data)
     { printf("element is found at block:%d",count);
       break;
     }
    a=a->next;
    count++;
  }
  
  return 0;
}