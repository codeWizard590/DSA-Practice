#include<bits/stdc++.h>
using namespace std;
class BinarySearch{
    public:
        // treat binary search like searching in a dictionary .
        // we need to return 
        int findX_iterative(vector<int> arr,int low,int high,int target){
            int n=arr.size();
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]==target){
                    return mid;
                }
                else if(arr[mid]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            return -1;
        }

        int findX_recursion(vector<int> arr,int low,int high,int target){
            int mid=(low+high)/2;
            if(low>=high){
                return -1;
            }
            else if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                return findX_recursion(arr,mid+1,high,target) ;
            }
            return findX_recursion(arr,low,mid-1,target);
        }

        // lower bound -> the smallest index such that arr[index]>=target value ;
        // if the arr[index] is not present we take the next hypothetical index as the index value ..
        int lower_Bound(vector<int> arr,int low ,int high,int target){  
            //{} -> target -> 9 {}
            int n=arr.size();
            int ans=n;
            // initially we have ans as ans=n
            // 1, 3, 4, 5, 6, 7, 8, 9 find =4 ;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]>=target){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return ans;
        }

        // higher bound -> the only difference between lower and highet bound is >= and > 
        // so to implement this 
        int higher_bound(vector<int> arr, int low,int high,int target){
            int n=arr.size();
            int ans=n;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]>target){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return ans;
        }
};
int main(){
    vector<int> arr={2,3, 5, 6};
    BinarySearch binarysearch;
    int n=arr.size();
    int serachIndex=binarysearch.findX_iterative(arr,0,n-1,3);
    cout<<"using iterations : "<<serachIndex<<endl;
    int searchRecurse=binarysearch.findX_recursion(arr,0,n-1,7);
    cout<<"using recursion : "<<searchRecurse<<endl;
    int lower_bound=binarysearch.lower_Bound(arr,0,n-1,1);
    cout<<"lower bound is : "<<lower_bound<<endl;
    int higher_bound=binarysearch.higher_bound(arr,0,n-1,3);
    cout<<"higher bound is : "<<higher_bound<<endl;
}