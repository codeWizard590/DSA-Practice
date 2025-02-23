// https://leetcode.com/problems/search-insert-position/description/
/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k 
(1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target,
return the index of target if it is in nums, or -1 if it is not in nums.
*/
#include<bits/stdc++.h>
using namespace std ;

int main(){
    int t;
    cout<<"enter a number : ";
    cin>>t;
    vector<int> arr;
    while(t>0){
        arr.push_back(t%10);
        t/=10;
    }
    vector<int> temp;
    int n=arr.size()-1;
    int x=2;
    for(int i=0;i<=n;i++){
        int m=arr[i]*x;
        temp.push_back(m);
        x++;
    }
    cout<<endl;
    int count=0;
    for(int i=0;i<=n;i++){
        count=temp[i]+count;
    }
    int div=count%11;
    vector<char> charvec={'A','f','h','k','l','m','n','p','w','x','y'};
    cout<<charvec[div];
} 