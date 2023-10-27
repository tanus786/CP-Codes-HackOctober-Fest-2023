#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int queries, size;
    cin>>queries>>size;
    
    vector<int>vec[size];
    
    for (int i=0; i< queries; i++)
    {
        int sub_array_size;
        cin>>sub_array_size;
        
        for(int j=0; j< sub_array_size; j++)
        {
            int value;
            cin>>value;
            vec[i].push_back(value);
        }
    }
    
    for(int index = 0; index < size; index++)
    {
        int index_i, index_j;
        cin>>index_i>>index_j;
        cout<<vec[index_i][index_j]<<endl;
    }
    
    return 0;
}
