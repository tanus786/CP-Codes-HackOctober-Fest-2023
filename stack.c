#include<stdio.h>
#include<stdlib.h>
#define max 15
void main()
{
    int stack[max],top,ch,ele,x,ch1;
    top=-1;
    printf("\n 1-PUSH,2-POP,\n3-DISPLAY");
  
    do
    {
         printf("\nENTER the your choice:");
         scanf("%d",&ch);
        switch(ch)
        {
         case 1:
             if (top==max-1)
             {
            printf("insertion cannot be perferfom.");

             }
             else{
                printf("\nenter the new element:");
                scanf("%d",&ele);
                top++;
               stack[top]=ele;
                printf("element pushed succusesfully");
             }
             

            break;
            case 2:
             if (top==-1)
             {
            printf("pop cannot be perferfom.");

             }
             else{
                x=stack[top];
                printf("%d \nis the pop:",x);
                
                top--;
             }
             

            break;
        case 3:
             if (top==-1)
             {
            printf("stack is empyty.");

             }
             else{
                for (int i = top; i >=0 ; i--)                
                {
                    printf("%d\t",stack[i]);
                }
                }
        
            break;
         default:
          printf("\nenter the correct choice");
         
        
        }
        
        printf("\ndo you want to repeat? press");
        scanf("%d",&ch1);
      }while(ch1==1);
      
   }
