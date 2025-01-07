/*
PROBLEM STATEMENT :
https://leetcode.com/problems/subarray-sum-equals-k/description/ 
*/
/*
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

10,5,2,7,1,9 k=15
*/

/*
Mistakes i made -> cannot use break in between loop items will fail for many test cases 
[1,1,-2,0] : as 1 ,1 will not come into context but 1,1,-2 will give 0 which is required for the count.
*/
#include<bits/stdc++.h>
using namespace std;
class SubarrSumEqualsK{
    public:
        int sum_BF(vector<int> arr,int k){
            int n=arr.size();
            int count=0;
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=i;j<n;j++){
                    sum+=arr[j];
                    if(sum==k){
                        count++;
                        // break; -> this is incorrect as 0 might affect ..
                    }
                    // this is incorrect 
                    // if(sum>k){
                    //     break;
                    // }
                }
            }
        }
        /*
        Variation of longest subarr problem .
        using hashing again and taking a presum ..
        -> take presum and store presum indexes against the count it  occurs.
        -> check if presum-k -> is found anywhere in hashtable if found means we found the index 
        */

       /*
       Mistakes i made -- > algorithm 
       */
        int sum_HA_MISTAKES(vector<int> arr,int k){
            int n=arr.size();
            int sum=0;
            int maxlength=0;
            int count=0;
            map<int,int> mp;
            for(int i=0;i<n;i++){
                // [1,-1,0]     // 1,0,0;
                sum+=arr[i];
                if(sum==k){
                    // if i need to find the longest subarr 
                    maxlength=max(maxlength,i+1);
                    count++;
                }
                int rem=sum-k;
                if(mp.find(sum)==mp.end()){
                    mp[sum]=i;
                }
                if(mp.find(rem)!=mp.end()){
                    int length=i-mp[rem];
                    maxlength=max(maxlength,length);
                    count++;
                }
            }
            return count;
        }

        /*
        this is a basic run for this kind of question we need to revise this thing not able to digest presum fully
        //
        revised ->
        do the sum , check it inside hasmap ->if occurs increase the count by mapvalue ;-> add mapindex to hashtable 
        return count    
        */
        int sum_OA(vector<int> arr , int k){
            int n=arr.size();
            int count=0;
            map<int,int> mpp;
            mpp[0]=1;
            int sum=0;
            for(int i=0;i<n;i++){
               sum+=arr[i];
               int rem=sum-k;
               count=count+mpp[rem];
               mpp[sum]=mpp[sum]+1;
            }
            return count;
        }
};
int main(){
    SubarrSumEqualsK sum;
    vector<int> arr ={1,2,1,2,1};
    int k=3;
    int output_BF=sum.sum_BF(arr,k);
    cout<<"using brute force : "<<output_BF<<endl;
    int output_OA=sum.sum_OA(arr,k);
    cout<<"using pointers : "<<output_OA<<endl;

}