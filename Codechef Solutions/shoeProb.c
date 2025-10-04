//Shoe Problem of codeChef

#include<stdio.h>
int main(){
    int testcases;
    scanf("%d" , testcases);
    
    while(testcases--){
        int n , m;
        scanf("%d" "%d" , &n , &m);
        
        int extra_shoe = (n>m) ? n-m : 0;
        extra_shoe = n+extra_shoe;
        
    printf("%d" , extra_shoe);
    }
}
