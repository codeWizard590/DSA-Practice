#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums1 = {1,2,2,1};vector<int>  nums2 = {2,2};
    int m=min(nums1.size(),nums2.size());
    int n=max(nums1.size(),nums2.size());
    vector<int> temp;
    set<int> st;
    for(int i=0;i<m;i++){
        int currEl=nums1[i];
        for(int j=0;j<n;j++){
            if(st.find(nums2[j])==st.end()&&currEl==nums2[j]){
                temp.push_back(currEl);
            st.insert(nums2[j]);
            }
        }
    }
    cout<<temp[0];
}