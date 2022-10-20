#include<stdio.h>
void convert(int i)
{
    i = i/2;
    if(i>1)
    {
        convert(i);
    }
    printf("%d",i%2);
}
void main()
{
    int i;
    printf("Enter\n");
    scanf("%d",&i);
    printf("The binary number is:\n");
    convert(i);
    printf("%d",i%2);
}