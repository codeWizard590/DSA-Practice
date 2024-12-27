// //https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
#include<bits/stdc++.h>
using namespace std;
// [3,1,-2,-5,2,-4] rearrange these in order 
bool isEven(int i){
    if(i%2==0){
        return true;
    }
    else{
        return false;
    }
}

// this method only passes half of the test cases hence discarded 
void swap_BF(vector<int> nums){
    int n=nums.size();
    // find even and odd of the array
    // intution is 
    // arr[even index] should be greater than 0
    // if arr[odd] >0   i will swap with i-1;
    for(int i=0;i<n-1;i++){
        // [3,1,-2,-5,2,-4]
        if(isEven(i)&&nums[i]<0){
            
                swap(nums[i],nums[i+1]);
            
        }
        if(!isEven(i)&&nums[i]>0){
            swap(nums[i],nums[i+1]);
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    
}

void swap_OA(vector<int> nums){
    //  [28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31]
    // intution is  i will maintain two pointers i and j
    // i will hold even and j will hold odd value s
    // i will put every negative number i come across in the array in the odd indexes of the array
    // same with the even indexes i will put positive numbers 
    // learnings from this we need to defien the size of the array when we start else solution won't work.
    // push_back will not work as we will be pushing at the next index which will give incorrect answer .
    // i was stuck on pushing _back using one pass so need to define temparr size and initialize every element to 0
    int n =nums.size();
    int pos=0,neg=1;
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            temp[neg]=nums[i];
            neg=neg+2;
        }
        else{
            temp[pos]=nums[i];
            pos=pos+2;
        }
       
    }
    cout<<" OA is :";
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
    
}
int main(){
    // [28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31]
    vector<int> nums={28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    // temparr -> [28,-41 ,22 ,46]
    // swap_BF(nums);
    swap_OA(nums);
}
