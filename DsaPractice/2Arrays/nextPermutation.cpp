// https://leetcode.com/problems/next-permutation/description/

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

// finding permutations through recursion is not yet understood fully as i am not able to draw the map in my mind 
// but now my mind has memorized this algorithm i ma not sure whether i have understood this or remembered this 
// will try these things when fall into recursion 
// the question is how do we find permutations 
// after finding all the permutations just select the first permutation whih will happen
#include<bits/stdc++.h>
using namespace std;
void permut_BF(vector<int> nums,int start,vector<vector<int>> &temp){
    int n=nums.size();
    if(start==n){
        temp.push_back(nums);
        return;
    }
    for(int i=start;i<n;i++){
        
        swap(nums[i],nums[start]);
        permut_BF(nums,start+1,temp);
        swap(nums[i],nums[start]);

    }
} 
int main(){
    vector<int> nums={1,2,2};
    int start=0;
    vector<vector<int>> temp;
    permut_BF(nums,start,temp);
    for (const auto& perm : temp) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
}