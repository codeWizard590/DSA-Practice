#include<bits/stdc++.h>
using namespace std;
int main(){
    //1,2,3,4,5,
    //7,6,4,3,1
    vector<int> arr={3,3,5,0,0,3,1,4};
    int n=arr.size();
    int i=1;int j = n-1;
    int buyAtmin;
    int sellAtmax=arr[n-1];
    buyAtmin=arr[0];
    int profit=0;
    while(i<j){
        if(arr[i]>buyAtmin&&sellAtmax<arr[i]){
            profit+=arr[i]-buyAtmin;
            i++;
            buyAtmin=arr[i];
        }
    }
}