/*   PROBLEM STATEMENT 
Given an array arr[] containing integers and an integer k, 
your task is to find the length of the longest subarray 
where the sum of its elements is equal to the given value k.
It is guaranteed that a valid subarray exists.
*/

#include<bits/stdc++.h>
using namespace std;
// here we need to find the longest subarr .
// intuitions -> 1. brute force approach
/*                                      README  Before jumping to solution ... .....

while using brute force i can loop this in two for loops .
outer loop will start from i=0 -> n-1 .n is the size of the array 
inner loop will start from j=i -> n-1 .
we want to set a count add the current element into the count to find out the sum of inner loop 
when the loop hits value of k -> we break the loop and store the longest length / max of the length retrieved.
*/
/*
PROBLEMS WITH BRUTE FORCE 
The time complexity -> O(n^2)
*/

int longestSubarrBF(vector<int> nums, int k){
    int n=nums.size();
    int length=0;
    for(int i=0;i<n;i++){
        int count=0;
        for (int j=i;j<n;j++){
            count+=nums[j];
            // checking at nums[j+1] because if nect elements are zero sum will not be affected and test case fails
            if(count==k&&nums[j+1]!=0){
                // we need to skip the number of outer iterations done by the loop 
                // skipping because we need to start from the index of i itself to find out the length using j
                // we are adding 1 to j because of the indexing starts from 0 , length needs to be natural nums
                //  i.e. -> j-i+1
                length=max(length,j-i+1);
            }

        }
    }
    return length;
}
// intuition 2. hashing 
/*
will create a hash map with hash indexes as 0->n
//  arr : {10,5,2,7,1,9}
                   ->hashmap ->[0 ,1, 2, 3, 4, 5]
                                |  |  |  |  |  |
                                10,15,17,24,25,34  -> prefix sums against each index 
    if(hashmap[i]>=sum){} -> hashmap[sumIndex] ->> find subarrays that become k after using  
    i will take a prefix sum -> map[i] -> counter -> counter+arr[i];               
*/
/*
   working of finding keys in the hashmap . cannot find if map.end() is not specified
*/
void longestHash(){
    map<string, int> mp;

}

int main(){
    vector<int> nums={10,5,2,7,1,9};
    int k=15;
    int BF_output= longestSubarrBF(nums,k);
    cout<<BF_output<<endl;
    longestHash();
}

