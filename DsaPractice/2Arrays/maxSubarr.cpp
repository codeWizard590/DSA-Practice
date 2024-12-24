/*
    MaxSubArr --- > kadanae's Algorithm
    Given an integer array nums, find the 
    subarray
    with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/
//https://leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
using namespace std;
class MaxSubarr{
    public:
        /*
            brute force approach :
            we find every subarray in the given vector .
            we check their sum 
            replace sum with any max sum given by the arr
        */
        void maxsubarr_BF(vector<int> nums){
            // [-2,1,-3,4,-1,2,1,-5,4]
            int n=nums.size();
            int recordedSum=INT_MIN;
            for(int i=0;i<n;i++){
                int maxSum=0;
                for(int j=i;j<n;j++){
                    maxSum=maxSum+nums[j];
                    recordedSum=max(maxSum,recordedSum);
                }  
            }
            cout<<recordedSum;
        }
        void maxSubarr_KA(vector<int> arr){
            
        }
};
int main(){
    MaxSubarr maxSubarr;
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    maxSubarr.maxsubarr_BF(arr);
}