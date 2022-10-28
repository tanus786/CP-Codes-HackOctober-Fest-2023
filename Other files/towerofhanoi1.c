#include<stdio.h>
int main(void){
int n=3;
char source='a',dest='c',temp='b';
toh(n,'a','b','c');
//tofh(n,source,temp,dest);
return 0;
}
void toh(int n,char startpin,char endpin,char workpin)
{
    if(n>0)
    {
        toh(n-1,startpin,workpin,endpin);
        printf("move disk from %c to %c\n",startpin,endpin);
        toh(n-1,workpin,endpin,startpin);

    }
}
void tofh(int ndisk,char source ,char temp, char dest)
{
    if(ndisk==1){
        printf("move disk %d from %c\n",ndisk,source,dest);

}
else{
    tofh(ndisk-1,source,dest,temp);
    printf("move disk %d to %c\n",ndisk,source,dest);
    tofh(ndisk-1,temp,source,dest);
}
}
