#include <iostream>
using namespace std;

int main() {
	// your code goes here
   int T;
   cout<<"Enter the test cases";
   cin>>T;
   int A,B;
   while(T>0){
      cout<<"Enter the coordinates of king:";
       cin>>A>>B;
       for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
        if(((i==A-1)||(i==A+1))&&((j==B-2)||(j==B+2))){
            cout<<"2 ";
        } 
        else{if((i==A)&&(j==B))
              cout<<"1 ";
              else
              cout<<"0 ";
        }   
           } cout<<"\n";
       }
       T--;
     
   }
	return 0;

}
