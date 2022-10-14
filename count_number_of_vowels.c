#include<stdio.h>
#include<string.h>
//count number of vowels
void vowels(char arr[])
{
    int count=0;
    for(int i=0;arr[i]!='\0';i++)
    {
        if(arr[i]=='a'|| arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')
        {count++;}
    }
    printf("Number of vowels is %d",count);
}
int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    vowels(str);
    return 0;
}
/*
Input: I live in India
Output: Number of vowels is 7
*/
