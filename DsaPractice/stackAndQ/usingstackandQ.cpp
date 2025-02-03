#include<bits/stdc++.h>
using namespace std;

// design a stack st the stack supports push pop & retriveing the min element in a constant time 
/*
Approach 1 : which  uses extra space in order to retain the min value as a keyvalue pair inside stack.
consider -> push(1)
i will maintain a key value pair for each key having the min element prior to the index we are iterating on // or the top is at 
*/
class stackUsingQmin{
    public :
        stack<pair<int,int>> st;
        
        void push(int val){
            
            if(st.empty()){
                st.push({val,val});
            }
            else{
                int mini=min(st.top().second,val);
                st.push({val,mini});
            }
        }
        void pop(){
            st.pop();
        }
        int top(){
            return st.top().first;
        }
        int getMin(){
            return st.top().second;
        }

};

class stackwoPairs{
    public :
        void push(){

        }
        void pop(){

        }
        int top(){

        }
        int getmin(){
            
        }
};


int main(){
    stackUsingQmin stack;
    stack.push(-9);
    stack.push(9);
    stack.push(8);
    stack.push(-1);
    stack.push(-3);
    int minst=stack.getMin();
    cout<<"minimum value of stack is : "<<minst<<endl;
    stack.pop();
    int minst1=stack.getMin();
    cout<<"minimum value of stack after popping out -1 is  : "<<minst1;

}