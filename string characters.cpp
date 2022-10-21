#include<iostream>
#include<string.h>
#include<string>
using namespace std;
char *left(char *a, int c);
void destructor(char* p)
{
	delete []p;
	p = nullptr;

}
int main()
{
	char arr[30];
	cout << " Enter the string : " << endl;
	cin.getline(arr, 30);
	int count;
	cout << " now give the count of letters to dispaly: " << endl;
	cin >> count;
	cout<<left(arr, count);
	return 0;
}
char *left(char *a, int c)
{
	char *newarray=new char[30] ;
	int i=0;
	if (c < 30)
	{
		cout << " Displaying the substring asked by user: " << endl;
		for (i = 0; i <c; i++)
		{
			newarray[i] = a[i];
			
		}
		newarray[i] = '\0';
	}
	
	else
		cout << " Count is greater than size of string ";
	return newarray;
	destructor(newarray);
}