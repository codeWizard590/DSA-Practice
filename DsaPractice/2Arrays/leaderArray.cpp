#include<bits/stdc++.h>
using namespace std;
// You are given an array arr of positive integers.
// Your task is to find all the leaders in the array. 
// An element is considered a leader if it is greater than or equal to all elements to its right.
// The rightmost element is always a leader.
// Examples:
// Input: arr = [16, 17, 4, 3, 5, 2]
// Output: [17, 5, 2]
// Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
// Input: arr = [10, 4, 2, 4, 1]
// Output: [10, 4, 4, 1]
// Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
class Leader{

    public :
    // no intution as such just compare outer element against all the elements in the inner loop .
        void leaderArray_BF(vector<int> arr){

            int n=arr.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                bool isValid=true;
                for(int j=i+1;j<n;j++){
                    if(arr[i]<arr[j]){
                        isValid=false;
                        break;
                    }
                    // if(j==n-1){
                    //     temp.push_back(arr[j]);
                    // }
                }
                
                if(isValid){
                    temp.push_back(arr[i]);
                }
            }
            // we always have last index as a leader element 
            // temp.push_back(arr[n-1]);
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" ";
            }
        }

        void leaderArray_OA(vector<int> arr){
            // [16, 17, 4, 3, 5, 2]
            // we will have a greatest member encountered so far and we will use that member to check where next elemnt in 
            // the iteration is leader or not 
            // -> n-1 -> 0 :greatest - > 2 :-> 5>2 pushback -> 5 greater if(3>5){false} -> 4>5 {false} -> 17>5 {pushback .. //  gratest} 
            int n=arr.size()-1;
            vector<int> temp;
            int greatest=0;
            while(n>=0){
                if(arr[n]>=greatest){
                    temp.push_back(arr[n]);
                    greatest=arr[n];
                }
                n--;
            }
            cout<<endl;
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" ";
            }
        }
};

int main(){
    Leader leader;
    vector<int> arr ={10, 4, 2, 4, 1};
    leader.leaderArray_BF(arr);
    leader.leaderArray_OA(arr);
} 