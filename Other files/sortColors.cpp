#include <iostream>
#include <vector>
using namespace std;

vector<int> sortColors(vector<int>& nums) {
    for (int i=0;i<nums.size();i++){
        bool a=true;
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]>nums[j+1]){
                a=false;
                swap(nums[j],nums[j+1]);
            }

        }
        if(a){
            break;
        }
    }
    return nums;
}

int main(){
    vector<int> nums={3,6,9,1,6,2,0};
    sortColors(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

}
