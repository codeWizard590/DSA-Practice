#include<bits/stdc++.h>
using namespace std;
// properties of a linked list 
/*
---> class -> two properties 
              value -> which will contain the value
              node -> which will contain the memory address for the next 
*/

// class representation of the linked list 
class Node{
    public:
    int value ;
    Node* next ;
    Node(int value1,Node* next1){
        value =value1;
        next=next1;
    }
    Node(int value1){
        value =value1;
        next=nullptr;
    }
};

Node* arrtoLL(int arr[]){
    Node* head=new Node(arr[0]);
    // head->next will have null ptr. 
    // head has some memory location.
    cout<<head<<endl;
    // now i am putting iterator on head's location .
    Node* iterator=head;
    cout<<iterator;
    for(int i=1;i<5;i++){
        Node* temp=new Node(arr[i]);
        iterator->next=temp;
        iterator=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}

// deleting a node without having access to the head of ll' 
Node* delNode(int arr[]){
    Node* delNode3=new Node(arr[1]);
    return delNode3;
}

Node* del(Node* delNode){
    // inforamtion required -> memory address of node to be deleted - > value inside the next node
    // retrieved the node's memory address from delnode . -> wil give us next and val  
    Node* nextVal=delNode->next;
    // now i want to update the value of delnode to the value of the nextval .. and continue it till i reach null ptr for nextval 
    delNode->value=nextVal->value;
    delNode->next=nextVal->next;
    delete nextVal;
}

int main(){
    int arr[5]={1,3,5,7,3};
    Node* head = arrtoLL(arr);
    print(head);
    Node* delNodes = delNode(arr);
    del(delNodes);
}