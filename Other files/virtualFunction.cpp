#include<iostream>
using namespace std;
class rs{
    public :
    float rupees;
    virtual void conv()=0;
    void display(){
        cout<<"is equivalent to "<<rupees<<" indian ruppes"<<endl;
    }
};
class dollar:public rs{
    float dol;
    public:
    void conv(){
        cout<<"Enter currency in dollar\n";
        cin>>dol;
        rupees=54.3*dol;
        cout<<""<<dol<<"dollar is equal to";
        display();
    }
};
int main(){
    dollar d;
    int a;
   d.conv();
}