#include<bits/stdc++.h>
using namespace std;

class FibonacciSeries{
    public :
        int findUsingRecursion(int n){
            if(n<=1){
                return n;
            }
            return findUsingRecursion(n-1)+findUsingRecursion(n-2);
        }
}; 



int main(){
    int n=4;
    FibonacciSeries series;
    int x=series.findUsingRecursion(n);
    cout<<"result  using recursion is : "<<x;
}