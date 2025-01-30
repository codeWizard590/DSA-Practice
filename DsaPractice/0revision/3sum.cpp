// https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums){
    int n=nums.size();
    int target=0;
    int a,b,c;
    // a+b+c=0
    // my approach is to find a first and then find the pairs which fits with a to get a sum 0;
    for(int i=0;i<n;i++){
        int a=nums[i];
        
    }
}
int main(){

}