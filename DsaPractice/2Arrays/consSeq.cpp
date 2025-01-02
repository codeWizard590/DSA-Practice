// https://leetcode.com/problems/longest-consecutive-sequence/description/
        /*
            Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
            You must write an algorithm that runs in O(n) time.
            Example 1:
            Input: nums = [100,4,200,1,3,2]
            Output: 4
            Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
            Example 2:
            Input: nums = [0,3,7,2,5,8,4,6,0,1]
            Output: 9
        */
#include<bits/stdc++.h>
using namespace std;
class ConsSequence{
    public:
    // [100,4,200,1,3,2] // 1,2,3,4,100,400
    // 0,3,7,2,5,8,4,6,0,1 // 0,0,1,2,3,4,5,6,7,8
    // 9,1,4,7,3,-1,0,5,8,-1,6 --> -1 -1 0 1 3 4 5 6 7 8 9 
        int longestSeq_BF(vector<int> nums){
            int n=nums.size();
            sort(nums.begin(),nums.end());
            int lowestArr=INT_MIN,count=0,longest=1;
            // we want to iterate through the array check if the nextItem-1 = the lowest element we have found in the current sequence
            // -1 -1 0 1 3 4 5 6 7 8 9 
            // so i want to check if what ever element i am at is it giving me the elemnt i just passed through
            // over here we want to kind of store the max count we will encounter during our iteration --> this is important 
            if(nums.size()==0){return 0;}
            for(int i=0;i<n;i++){
                if(nums[i]-1==lowestArr){
                    lowestArr=nums[i];
                    count+=1;
                }
                else if(nums[i]!=lowestArr){
                    count=1;
                    lowestArr=nums[i];
                }
                longest=max(longest,count);
            }
            return longest;
        }

        // using set solution ---
        int longestSeq_Set(vector<int> nums){
            // our intution is to use an unordered set .. check the outermost stack ->
            // if there exists any number smaller than that in the set -> we ignore it 
            // if there is noone smaller than that element we will try to find elements which are larger than that number 
            unordered_set<int> st;
            int n=nums.size();
            int longest=1;
            // i am iterating through the array and putting my elements inside this set .
            if(nums.size()==0){
                return 0;
            }
            for(int i=0;i<n;i++){
                st.insert(nums[i]);
            }
            // - > now i will  be removing duplicates and i will have direct access to the elements inside the map index
            for(auto it:st){
                // this will tell us whether the element is present inside the map // returns true if not present // false if present 
                if(st.find(it-1)==st.end()){
                    int count=1;
                    int x=it;
                    while(st.find(x+1)!=st.end()){
                        x=x+1;
                        count+=1;
                    }
                    longest=max(longest,count);
                }
            }
            return longest;
        }
};
int main(){
    ConsSequence conSeq;
    vector<int> arr={9,1,4,7,3,-1,0,5,8,-1,6};
    int cons=conSeq.longestSeq_BF(arr);
    cout<<"using sorting in the beginning : "<<cons<<endl;
    int consec_set=conSeq.longestSeq_Set(arr);
    cout<<"using unordered set : "<<consec_set;

}