// a program to print numbers using recursion 
#include<bits/stdc++.h>
using namespace std;

class Recursion{
    public :
        void printNos(int n){
            if(n==1){
                cout<<1<<" ";
                return;
            }
            cout<<n<<" ";
            printNos(n-1);
        }
        // 4! -> 4*3! -> n =3 -> 3*2! -> n=2 -> 2*1! -> n=1 1*0! ->return 1; 
    // backtrack after return / base case        // let us understand the call stack for this  -> 
        // \|/       // |factorial(0) | -> n=0 -> return -> 1 -> factorial(0) -> 1;
        // \|/       // |factorial(1) | -> n=1 -> return -> 1*factorial(0); -> factorial(1) -> 1 ->1*1 ->1 ;
        // \|/       // |factorial(2) | -> n=2 -> return -> 2*factorial(1); -> factorial(2) -> 1*2 -> 2;
        // \|/       // |factorial(3) | -> n=3 -> return -> 3*factorial(2); -> factorial(3) -> 3*2->6;
        // \|/       // |factorial(4) | -> n=4 -> return -> 4*factorial(3); -> factorial(4) -> 4*6 ->24;
        // \|/       // |main()       | -> 24 
        /////        // ---------------
        int factorial(int n){
            if(n==0){
                return 1;
            }
            return n*factorial(n-1);
        }

        int sum(int n){
            if(n==0){
                return 0;
            }
            return n+sum(n-1);
        }
        // 0,1,1,2,3,5,8
        int fibonacci(int n){
            if(n==0||n==1){
                return n;
            }
            return fibonacci(n-1)+fibonacci(n-2);
        }
        bool isSorted(vector<int> arr,int n){
            //[1,2,3,4,5] // it is progressively increasing
            if(n==1 || n==0){
                return true;
            } 
            // condition to check 
            // arr[n-1]>=arr[n-2];
            return arr[n-1]>=arr[n-2] && isSorted(arr,n-1);
            
        }

       
};

class Backtracking{
    public :
        void subsets(vector<int> arr){
           
        }
};

int main(){
    Recursion recursion;
    int n;
    cout<<"enter numbers to print using recursion : ";
    cin>>n;
    recursion.printNos(n);
    int factorial  =recursion.factorial(n);
    cout<<endl<<"factorial is : "<<factorial<<endl;
    int sum=recursion.sum(n);
    cout<<"sum is :"<<sum<<endl;
    int fib=recursion.fibonacci(n);
    cout<<"fibonacci number is "<<fib<<" "<<endl;
    vector<int> arr={1,2,9,7,8};
    bool isSorted=recursion.isSorted(arr,arr.size());
    cout<<"is array sorted : "<<isSorted<<endl;
    
}