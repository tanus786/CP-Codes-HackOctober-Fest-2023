#include<stdio.h>
#include<math.h>
void main(){
    int i,a,b=0,c,d,e,sum=0;
    printf("Enter a no.");
    scanf("%d",&i);
    a=i;e=i;
    while(a){
        a=a/10;
        b++;
    }
    while(e){
        c=e%10;
        e=e/10;
        d=pow(c,b);
        sum=sum+d;
    }


    if(sum==i){
        printf("No. is armstrong");}
    else{
        printf("No. is not armstong");
    }
    
}