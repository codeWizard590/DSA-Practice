#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
        int value;
        Node* ptr;
        Node(int value1,Node* ptr1){
            value=value1;
            ptr=ptr1;
        }
        Node(int value1){
            value=value1;
            ptr=nullptr;
        }
};

Node* arrToLL(int arr[]){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<5;i++){
        Node* tempNode=new Node(arr[i]);
        mover->ptr=tempNode;
        // increment mover to next  mem address
        mover=tempNode;
    }
    return head;
}

int main(){
    int arr[5]={1,3,5,7,9};
    // getting or calling a value in a linked list 
    Node* head=arrToLL(arr);
    cout<<head->ptr<<endl; 
    // traversing through a linked list.
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->ptr; // represents next pointer for traversal
    }

}