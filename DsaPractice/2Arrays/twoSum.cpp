/*
Problem - >
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
/*

*/

#include <bits/stdc++.h>
using namespace std;
// always start with a brute force solution ..
/*
we take arr[i] from th outer loop , try to see the combinations for two numbers 
it makes with the array .
we add them in the inner loop .
check whether the sum is equal to the target .
*/
vector<int> twoSum_BF(vector<int> arr, int k)
{
    // {3,2,4} t=6
    int n = arr.size();
    int i = 0;int maxcount=0;
    vector<int> output;
    int initialCount=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            initialCount=arr[i]+arr[j];
            if(initialCount==k){
                output.push_back(i);
                output.push_back(j);
                break;
            }
        } 
    }
    return output;
}

// using hashmap
/*
while calculating the two sum we know that sum of two numbers results to the target given 
so we need to calculate a+b=target , where a is the number we are iterating on and b is the number 
we have already iterated and it is stored in the hashtable 
*/
vector<int> twoSum_Hash(vector<int> arr,int k){
    // {2, 6, 5, 8, 11} t=14 ;
    map<int,int> mpp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int requiredFill=k-arr[i];
        if(mpp.find(requiredFill)!=mpp.end()){
            return {mpp[requiredFill],i};
        }
        mpp[arr[i]]=i; // at index 2 we have value 0 for the map.
    }
    return {-1,-1}; 

}

/*
Using sliding window / two pointers .
the goal is to do this in complexity < O(n^2)
now the intution is to sort the array first 
1. After sorting we will check if the arr[i]+arr[j] < or > the targeted sum
   if the arr sum is greater than the target we will know the cause as the larger element is causing the array sum to go up
   if it is smaller we know that the smaller elment needs to be increment ed 
   

                                 DRY RUN 
    first sort -> [2,5,6,8,11] -> i at 0 and j at 4 -> sum =13 -> < target increment i ++ ;
    -> i at 1 j at 4  -> sum 16 > target  -- > decrement j -- ;
    ->i at 1 j at 3 -> sum 13 < target --> increment i ++;
    -> i at 2 and j at 3 sum 14 == target return i and j .
    run these iterators until i<j ;                             
*/

/* in this approach the indexes of the sorted array are passed so different from other solutions */

vector<int> twoSum_window(vector<int> arr, int k){
    //  N = 5, arr[] = { 2,6,5,8,11}, target = 15
    // -> 
    vector<int> response;
    int n=arr.size(),i=0,j=n-1;
    sort(arr.begin(),arr.end());
    while(i<j){
        int sum=0;
        sum=arr[i]+arr[j];
        if(sum==k){
            return{i,j};
            break;
        }
        else if(sum>k){
            j--;
        }
        else{
            i++;
        }
    }
    return {-1,1};
}


// cpoied from leetcode with least runtime 
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> sorted_nums = nums;
//         sort(sorted_nums.begin(), sorted_nums.end());
//         int si = 0;
//         int sj = nums.size() - 1;
//         while (si < sj) {
//             if (sorted_nums[si] + sorted_nums[sj] > target) {
//                 sj--;
//             }
//             if (sorted_nums[si] + sorted_nums[sj] < target) {
//                 si++;
//             }
//             if (sorted_nums[si] + sorted_nums[sj] == target) {
//                 break;
//             }
//         }
//         int i = distance(nums.begin(),find(nums.begin(),nums.end(),sorted_nums[si]));
//         int j = distance(find(nums.rbegin(),nums.rend(),sorted_nums[sj]),nums.rend()-1);
//         return {i,j};
//     }
// };

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> BF_output = twoSum_BF(arr, target);
    vector<int> hash_output = twoSum_Hash(arr, target);
    vector<int> twoSum_pointer = twoSum_window(arr, target);
    cout<<"brute force solution :" << BF_output[0] << " "<<BF_output[1]<<" "<<endl;
    cout<<"hash table solution :"<< hash_output[0] << " "<<hash_output[1]<<" "<<endl;
    cout<<"pointer solution :"<< twoSum_pointer[0] << " "<<twoSum_pointer[1]<<" "<<endl;
    
}