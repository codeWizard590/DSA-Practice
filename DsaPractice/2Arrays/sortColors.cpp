#include<bits/stdc++.h>
using namespace std;


/*
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 
*/
class SortColors{
    public:
        void printArr(vector<int> arr,string sortedWith){
            int n=arr.size();
            cout<<sortedWith<<" : ";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

    // first intution is to use brute force adn iterating two times over the array 
    // the problem is time complexity takes O(n^2) time .....
        void colorSort_BF(vector<int> arr){
            int n=arr.size();
            // [2,0,2,1,1,0]
            for(int i=0;i<n-1;i++){
                int minIdx=i;
                for(int j=i+1;j<n;j++){
                    if(arr[minIdx]>arr[j]){
                        minIdx=j;
                    }
                }
                swap(arr[minIdx],arr[i]);
            }
            printArr(arr,"Brute Force");
        }

        /*
        one approach is direct approach 
        since only 3 values are concerned 
        we can manage  counter for each value i.e 0 ,1 and 2 -> count0 ,c1 ,c2  
        we count their frequency in the array  and print 
        */
        void colorSort_BA(vector<int> arr){
            int n=arr.size();
            int c0=0,c1=0,c2=0;
            for(int i=0;i<n;i++){
                if(arr[i]==0){c0++;}
                else if(arr[i]==1){c1++;}
                else{c2++;}
            }
            cout<<c0<<" "<<c1<<" "<<c2<<" "<<endl;
            for(int i=0;i<c0;i++){
                arr[i]=0;
            }
            for(int i=c0;i<c1+c0;i++){
                arr[i]=1;
            }
            for(int i=c1+c0;i<n;i++){
                arr[i]=2;
            }
            printArr(arr,"Better Approach / Direct Approach");
        }

        // dutch national flag algorithm 
        /*
        in this approach we want to take three pointers .. 
        1   left will hold 0 
        2   mid will hold 1
        3   right will hold 2
            we want to iterate in this till our mid reaches high mid < high
            we will start left and mid from index 0 . high at the end 
            if we find 0 at mid we give it to left . increment left by 1 and swap the elements .
            in the same way if we find 
        */
        void colorSort_DNF(vector<int> arr){
            // v{2,0,2,1,1,0};
            int n=arr.size();
            int low=0,mid=0,high=n-1;
            while(mid<=high){
                if(arr[mid]==0){
                    swap(arr[low],arr[mid]); 
                    low++;
                    mid++;
                    /*
                    You swap arr[mid] and arr[low].
                    Then, you increment low without moving  mid.
                    mid now points to the newly swapped value, which could also be 0.
                    This causes the algorithm to process 0 again, repeatedly pushing it to the beginning.
                    */
                    // essential as mid ++ will not increment and will stay at the same position 
                }
                else if(arr[mid]==2){
                    swap(arr[mid],arr[high]);
                    high--; 
                }
                else{
                    mid++;
                }
            }
            printArr(arr,"Dutch National Flag");
        }
};
int main(){
    SortColors sorts;
    vector<int> arr={2,0,2,1,1,0};
    sorts.colorSort_BF(arr);
    sorts.colorSort_BA(arr);
    sorts.colorSort_DNF(arr);
}