#include<bits/stdc++.h>
using namespace std;

int main(){
    // to do inplace modification only move the index pointer which keeps track of which element to put 
    vector<int> arr={0,1,0,3,12,0,9,0,0,1,0,6};
    int n=arr.size();int zero=0;int ptr=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zero++;
        }
        else{
            int temp=arr[ptr];
            arr[ptr]=arr[i];
            arr[i]=temp;
            ptr++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}