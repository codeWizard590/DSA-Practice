#include<bits/stdc++.h>
using namespace std;
class PascalsTriangle{
    public:
        void triangle(int n){
            vector<vector<int>> arr;
            for(int i=0;i<n;i++){
                vector<int> tempArr;
                for(int j=0;j<=i;j++){
                    if(j==0 || j==i){
                        tempArr.push_back(1);
                    }
                    else{
                        int sum=arr[i-1][j-1] + arr[i-1][j];
                        tempArr.push_back(sum);
                    }
                }
                arr.push_back(tempArr);
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<=i;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
int main(){
    PascalsTriangle tri;
    tri.triangle(9);
}