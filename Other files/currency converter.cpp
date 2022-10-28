#include<iostream>
using namespace std;
void main()
{      //Declaration of varibles
       int dollars;
       float B,M,J,P;
       //input American dollars
       cout<<"Enter currency in American Dollars"<<endl;
       cin>>dollars;
       //Calculations
       B=dollars*0.571505;
       M=dollars*10.7956;
       J=dollars*112.212;
       P=dollars*102.243;
       cout<<dollars<<"American dollars are equal to "<<B<<" British pounds"<<endl;
       cout<<dollars<<"American dollars are equal to "<<M<<" Mexican pesos"<<endl;
       cout<<dollars<<"American dollars are equal to "<<J<<" Japanese yen"<<endl;
       cout<<dollars<<"American dollars are equal to "<<P<<" Pakistani rupees"<<endl;

       system("pause");
}
