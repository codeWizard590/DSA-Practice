#include<bits/stdc++.h>
using namespace std;
class RangeSum{
    public :
        int sumB_F(vector<int> arr){
            int n=arr.size();int sum=0;
            for(int i=0;i<n;i++){
                int mini=INT_MAX,maxi=INT_MIN;
                for(int j=i;j<n;j++){
                    mini=min(mini,arr[j]);
                    maxi=max(maxi,arr[j]);
                    sum=sum+maxi-mini;
                }
            }
            return sum;
        }

        int sumO_A(vector<int> arr){
            int n=arr.size();
            vector<int> l(n),r(n);
            stack<pair<int,int>> st;
            // finding the min subarr sum
            for(int i=0;i<n;i++){
                int count=1;
                while(!st.empty()&&st.top().first>arr[i]){
                    count=count+st.top().second;
                    st.pop();
                }
                l[i]=count;
                st.push({arr[i],count});
            }
            while(!st.empty()){
                st.pop();
            }
            for(int i=n-1;i>=0;i--){
                int count=1;
                while(!st.empty()&&st.top().first>=arr[i]){
                    count=count+st.top().second;
                    st.pop();
                }
                r[i]=count;
                st.push({arr[i],count});
            }
            while(!st.empty()){
                st.pop();
            }
            int resultmax=0;int resultmin=0;
            for(int i=0;i<n;i++){
                int c=arr[i]*(l[i]*r[i]);
                resultmin+=c;
            }
            vector<int> l1(n),r1(n);
            for(int i=0;i<n;i++){
                int count=1;
                while(!st.empty()&&st.top().first<arr[i]){
                    count=count+st.top().second;
                    st.pop();
                }
                l1[i]=count;
                st.push({arr[i],count});
            }
            while(!st.empty()){
                st.pop();
            }
            for(int i=n-1;i>=0;i--){
                int count=1;
                while(!st.empty()&&st.top().first<=arr[i]){
                    count=count+st.top().second;
                    st.pop();
                }
                r1[i]=count;
                st.push({arr[i],count});
            }
            while(!st.empty()){
                st.pop();
            }
            for(int i=0;i<n;i++){
                int c=arr[i]*(l1[i]*r1[i]);
                resultmax+=c;
            }
            int response=resultmax-resultmin;
            return response;
        }
};
int main(){
    vector<int> arr={1,3,3};
    RangeSum rangesum;
    int ans=rangesum.sumO_A(arr);
    cout<<ans;
}