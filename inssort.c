#include<stdio.h>
void inssort(int a[],int n)
{
    int i,j,s;
    for(i=1;i<n;i++)
    {
        j=i-1;
        s=a[i];
        while((j>=0) && (a[j]>s))
        {
          a[j+1]=a[j];
          j--;
        }
        a[j+1]=s;

    }
    printf("\nsorted array is:");
  for(int i=0;i<n;i++)
   {
     printf("%d\t",a[i]);
   }
}
int main()
{
   int a[20],n;
   printf("Enter the size of array:");
   scanf("%d",&n);
   printf("Enter the array elements:");
   for(int i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
   printf("Sorted array:");
   inssort(a,n);
   
   return 0;
}