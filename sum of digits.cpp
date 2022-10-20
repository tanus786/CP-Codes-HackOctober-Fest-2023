#include<iostream>
using namespace std;
//function for sum of digits 
int sum_of_digits(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum =sum+( n % 10);
		n = n / 10;
	}
	return sum;

}
//function for digit count
int count(int n)
{
	int count=0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}
int main()
{
	int num;
	cout << "Enter the number you want sum of : ";
	cin >> num;
	int sum=0;
	//function call
	sum=sum_of_digits(num);
	cout << "SUM OF DIGITS : " << sum << endl;
	//function call
	
	int no_of_digits = 0;
	no_of_digits=count(num);
	cout << " Number of digits are : " << no_of_digits << endl;
	return 0;
	
}