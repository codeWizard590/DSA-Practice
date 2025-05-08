#include<bits/stdc++.h>
using namespace std;
class Preorder{
    public:
        int data;
        Preorder* left;
        Preorder* right;
        Preorder(int data1){
            data=data1;
            left=right=nullptr;
        }
};

//[1,2,3,4,5,6,7] --> to construct a binary tree using dfs
Preorder* traversal(Preorder* root0,vector<int> arr){
    // [1] -> push in q 
    // forloop -> size() of q ;
    // in for loop [1] -> node* level=q.front(); q.pop() -> 1  
    // check for left and right members 
    // 
    int i=1;
    queue<Preorder*> q;
    q.push(root0);
    while(i<arr.size()){
        Preorder *node=q.front();
        q.pop();
        if(i<arr.size()){
            node->left=new Preorder(arr[i++]);
            q.push(node->left);
        }
        if(i<arr.size()){
            node->right=new Preorder(arr[i++]);
            q.push(node->right);
        }
    }
}

int main(){

}