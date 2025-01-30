// this is the mock test i asked chatgpt to prepare for me 
/*
    the first question is to find the second largest element in an array 
*/
#include<bits/stdc++.h>
using namespace std;

// using better approach solution one pass is also included in this solution

int secLarge_BF(vector<int> arr){
    int n=arr.size();
    int maxf=INT_MAX;
    int maxs=0;
    maxf=arr[0];
    if(n<2)
        return -1;
    for(int i=1;i<n;i++){
        maxf=max(maxf,arr[i]);
        if(maxf!=arr[i])
            maxs=max(maxs,arr[i]);
    }
    // for(int i=0;i<n;i++){
    // }
    return maxs;
}



int main(){
    vector<int> arr={2,6,1,9,8};
    int result=secLarge_BF(arr);
    cout<<result;
}
