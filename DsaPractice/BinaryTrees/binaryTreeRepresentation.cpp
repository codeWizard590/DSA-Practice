#include<bits/stdc++.h>
using namespace std;

//level order traversal using queue DS
class Node{
    public:
    int data ;
    Node *left;
    Node *right;
    Node(int data1){
        data=data1;
        left=right=nullptr;
    }
};

// out task is to traverse through a binary tree
vector<vector<int>> levelOrderTraversal(Node* root0){
    // the order of traversal is simple we just need to traverse level by level using queues 
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root0);
    while(!q.empty()){
        int n=q.size();
        vector<int> levels;
        for(int i=0;i<n;i++){
            Node* node=q.front();
            q.pop();
            levels.push_back(node->data);
            if(node->left !=NULL){q.push(node->left);}
            if(node->right !=NULL){q.push(node->right);}
        }
        ans.push_back(levels);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<vector<int>> arr=levelOrderTraversal(root);
    int n=arr.size();
    cout<<"hii";
    for(int i=0;i<n;i++){
        int m=arr[i].size();
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}