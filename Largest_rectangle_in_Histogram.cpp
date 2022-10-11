/*Problem statement:
Given an array of integers heights representing the histogram's bar height where the 
width of each bar is 1, return the area of the largest rectangle in the histogram.

Input: 
heights = [2,1,5,6,2,3]
Output: 10
*/


#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    vector<int> v;
    stack<pair<int,pair<int,int>>> s;
    v.push_back(heights[0]);
    s.push({heights[0],{1,0}});
    for(int i=1;i<n;i++){
        int count =0;
        while(s.size()!=0){
            auto it=s.top();
            if(it.first<=heights[i]){
                break;
            }
            else{
                auto at=it.second;
                count=count+at.first;
                v.push_back(it.first*(at.first+(i-at.second)-1));
                s.pop();
            }
        }
        v.push_back(heights[i]);
        s.push({heights[i],{count+1,i}});
    }
    int x=0;
    while(s.size()!=0){
        auto it=s.top();
        x=it.first;
        auto at=it.second;
        v.push_back(x*(at.first+(n-at.second)-1));
        s.pop();
    }

    int max=0;
    for(int j=0;j<v.size();j++){
        if(max<v[j]){
            max=v[j];
        }
    }
        return max;
    }

int main(){
    // taking input
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<largestRectangleArea(v);

}