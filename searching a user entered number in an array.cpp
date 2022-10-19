#include <iostream>
using namespace std;
int main ()
{
	const int y=10;
	int array [y] ={1,88,65,44,55,174,5,4,3,62};
	 int search ;
	 cout<<" enter the number u wanted to search ";
	 cin>>search;
	 for (int i=0;i<y;i++)
	 {
	 	if( array[i]==search)
	 	{
	 		cout<<"number is founded  at the index "<<i+1;
	 		break;
		 }
	 }
	
}
