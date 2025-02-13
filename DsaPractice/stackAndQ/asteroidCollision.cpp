#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidColl(vector<int> arr){
    int n=arr.size();
    vector<int> ans;
    // 5,10,-5,2
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans.push_back(arr[i]);
        }
        else{
            while(!ans.empty()&&ans.back()>0&&ans.back()<abs(arr[i])){
                ans.pop_back();
            }
            if(!ans.empty()&&ans.back()==abs(arr[i])){
                ans.pop_back();
            }
            else if(ans.empty()||ans.back()<0){
                ans.push_back(arr[i]);
            }

        }
    }
    
    return ans;
}
int main(){
    vector<int> arr={5,10,-5,-2};
    vector<int> ans=asteroidColl(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}