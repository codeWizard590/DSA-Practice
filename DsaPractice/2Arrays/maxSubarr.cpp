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
            cout<<"Brute force Solution : "<<recordedSum<<endl;
        }
        void maxSubarr_KA(vector<int> nums){
            // [-2,1,-3,4,-1,2,1,-5,4]
            // first i want to check if the sum i am getting is less than zero 
            // if it is there is no point in taking it forward as we donot take negatives into the future
            // if sum is greater than the maxSum till that iteration we will replace the maxSum with the sum 
            // now if i want to find out the indexes of the subarr ;
            int n=nums.size();
            int sum=0,maxSum=INT_MIN,itrStart=0,itrEnd=0;
            for(int i=0;i<n;i++){
                if(sum==0){
                    itrStart=i;
                }
                sum+=nums[i];
                // now one thing is sure that when sum ==0 this means that it is our starting index
                //  of the new subarr iteration
                if(sum>maxSum){
                    maxSum=sum;
                   
                    itrEnd=i;
                }
                if(sum<0){
                    // reinitalize the sum to zero
                    sum=0;
                    // maxSum=max(maxSum,sum);
                }
            }
            cout<<"Using kadane's Algorithm : "<<maxSum<<endl;
            for(int i=itrStart;i<=itrEnd;i++){
                cout<<nums[i]<<" ";
            }
        }
};
int main(){
    MaxSubarr maxSubarr;
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    maxSubarr.maxsubarr_BF(arr);
    maxSubarr.maxSubarr_KA(arr);
}