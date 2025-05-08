#include<bits/stdc++.h>

using namespace std;
// this file holds information about how to find height dia and basics about binary trees .
// find the height of a binary tree 


class NodeTree{
    public:
        int data;
        NodeTree* left;
        NodeTree* right;
        NodeTree(int data1){
            data=data1;
            left=nullptr;
            right=nullptr;
        }
};

// function to calculate the height of binary tree

int binaryTreeHeight(NodeTree* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=binaryTreeHeight(root->left);
    int rightHeight=binaryTreeHeight(root->right);
    return max(leftHeight,rightHeight)+1;
}

// function to claculate the diameter of binary tree 
// approach and instinct 
// // // ----------------------------> the basic rule for recursion < --------------------------------

// what works for the base case will work for every branch ..
// imagine  a binary tree the smallest branch contains structure like this 
//       1 
//      / \
//     2   3
//    / \
//   5   6
// now in this we can count the response edges // 4-2-1-3 // which contains three edges   

// first we need to find the height of each subtree 
// then we need to check the diameter how it is branched out 
// always pass the diameter of the subtree as reference . 

int getDia(NodeTree* root,int &res){
    if(root==NULL){
        return 0;
    }
    int lHeight=getDia(root->left,res);
    int rHeight=getDia(root->right,res);
    res=max(res,lHeight+rHeight);
    return max(lHeight,rHeight)+1;
}
void binaryTreeDia(NodeTree* root){
    int res=0;
    int result=getDia(root,res);
    cout<<"the diameter of binary tree is : "<<res<<endl;
}

int main(){
    NodeTree* node = new NodeTree(1);
    node->left=new NodeTree(2);
    node->right=new NodeTree(3);
    node->left->left=new NodeTree(5);
    node->left->right=new NodeTree(6);
    node->left->right->right=new NodeTree(4);

    int height=binaryTreeHeight(node);
    cout<<"the height of binary tree is : "<<height<<endl;

    binaryTreeDia(node);
    // cout<<"the diameter of binary tree is : "<<dia<<endl;


}