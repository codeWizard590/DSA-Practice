#include<bits/stdc++.h>
using namespace std;
/*
stacks .. the objective of this file is to implement stack methods i.e. push pop top size .
-- stack uses LiFo -> last in first out ..

*/

class stacks{
    public :
    int top =-1;int st[5];
    void push(int x){
        top+=1;
        st[top]=x;
    }
    void pop(){
        top-=1;
    }
    int tops(){
        return top;
    }
    int size(){
        return top+1;
    }
    void values(){
        cout<<"stack size is : "<<size()<<endl;
        if(size()==0){
            cout<<"nothing exists"<<endl;
        }
        for(int i=0;i<size();i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
    }
};
/*
what happens in queue is FIFO ...
the intuition is to maintain two pointers -> one will have 
*/
class q{
    public : 
        int start=-1,end=-1,currSize=0;
        int size=5;
        int que[5];
        void push(int x){
            if(currSize==0){
                start+=1;
                end+=1;
            }
            else{
                end=(end+1)%size;
            }
            que[end]=x;
            currSize+=1;
        }
        void pop(){
            if(currSize==0){
                cout<<"nothing to pop ";
            }
            if(currSize==1){
                start=-1;end=-1;
            }
            else{
                start=(start+1)%size;
                currSize-=1;
            }
        }
        int top(){
            // returning index instead of returning index we have to return 
            if(currSize!=0){
                return que[start];
            }
            else{
                return -1;
            }
        }
        int sizes(){
            return currSize;
        }
        void display(){
            for(int i=0;i<currSize;i++){
                cout<<que[i]<<" ";
            }
        }
};

int main(){
    stacks stack;
    stack.push(2);
    stack.values();
    stack.pop();
    stack.values();
    stack.push(4);
    stack.values();
    int top = stack.tops();
    cout<<"top at index : "<<top<<endl;
    q queues;
    queues.push(3);
    queues.push(9);
    queues.pop();
    int tops = queues.top();
    cout<<tops;
}