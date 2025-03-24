#include<bits/stdc++.h>
using namespace std;

class Node{
    // contains a node class having value and memory addresses of its children 
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val1){
        val=val1;
        left=right=NULL; 
    }

    
};

void PrintInOrder(Node* root){
    // 10 -> left Root-> 100-> leftRoot
                        //  -> rightRoot
    //    -> right 90
    if(root==nullptr){
        return;
    }
    PrintInOrder(root->left);
    cout<<root->val<<" ";
    PrintInOrder(root->right);
}
int main(){
    // inorder traversal;

    
    int n=4;
    Node* root=new Node(4);
    Node* left1 =new Node(3);
    Node* left3 =new Node(8);
    Node* left2 = new Node(7);
    root->left = left1;
    root->right=left2;
    left1->left = left3;
    PrintInOrder(root);

    
    
}