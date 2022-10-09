#include<stdio.h>
void main(){
    int a[50],b,i,j,c;
    printf("Enter no. of elements");
    scanf("%d",&b);
    printf("Enter elements");
    for(i=0;i<b;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<b-1;i++){
        for(j=0;j<b-1;j++){
            if(a[j]>a[j+1]){
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
  printf("ordered series is:");
  for(i=0;i<b;i++)
  printf("%d,",a[i]);
}