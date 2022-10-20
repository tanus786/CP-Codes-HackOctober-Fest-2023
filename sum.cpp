#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr {1,2 ,3 ,4 , 7, 9, 10};
    int sum=0;
    for(int i=0; i<arr.size(); i++)
        sum+=arr[i];
        
    cout<<"Sum of array : "<<sum<<endl;

    return 0;
}
