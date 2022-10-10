#include<stdio.h>
#include<string.h>
int main()
{
    int i,len;
    char string[50];
    printf("ENTER A STRING::\n");
    scanf("%[^\n]",string);
    len=strlen(string);
    for(i=0;i<len/2;i++)
    {
        if(string[i]!=string[len-i-1])
          break;
    }
    if(i==len/2)
      printf("ITS PALINDROME STRING!!\n");
    else
      printf("NOT A PALINDROMR STRING!!\n");
    return 0;
}
