#include<stdio.h>
void display(int arr[],int n){
for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int main(){
int arr[100]={1, 2, 5, 75};
display(arr, 4);
return 0;
}
