#include <bits/stdc++.h>
using namespace std;
const int MOD =1e9 + 7;
class MinSum
{
public:
    int subArrmin_B_F(vector<int> arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int minsub = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                minsub = min(minsub, arr[j]);
                sum = sum + minsub;
            }
        }
        return sum;
    }

    int subArrmin_O_A(vector<int> arr){
        int n=arr.size();
        vector<int> l(n),r(n);
        stack<pair<int,int>> st1,st2;
        // idetify the min values to the left 
        for(int i=0;i<n;i++){
            int sum=1;
            while(!st1.empty()&&st1.top().first>arr[i]){
                sum=sum+st1.top().second;
                st1.pop(); 
            }
            l[i]=sum;
            st1.push({arr[i],sum});
        }
        for(int i=n-1;i>=0;i--){
            int sum=1;
            while(!st2.empty()&&st2.top().first>=arr[i]){
                sum=sum+st2.top().second;
                st2.pop();
            }
            r[i]=sum;
            st2.push({arr[i],sum});
        }
        long long result=0;
        for(int i=0;i<n;i++){
            long long occurence=(long long)l[i]*r[i]*arr[i];
            result=(result+occurence) % MOD;
        }
        return result;
    }

};

int main()
{
    vector<int> arr = {11, 81, 94, 43, 3};
    MinSum minsum;
    int val=minsum.subArrmin_B_F(arr);
    cout<<"using Brute force : "<<val<<endl;
    int val_OA=minsum.subArrmin_O_A(arr);
    cout<<"using optimized approach :" <<val_OA<<endl;
}