#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data1,Node* prev1,Node* next1){
            data=data1;
            prev=prev1;
            next=next1;
        }
        Node(int data1){
            data=data1;
            prev=nullptr;
            next=nullptr;
        }
};

Node* arrToDll(int arr[]){
    // for head  previous of a doubly linked list will have prev pointing to nullptr 
    // next will point to the next memory location 
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<5;i++){
        Node* temp=new Node(arr[i]);
        temp->prev=mover;
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// accessing any element in between 
Node* access5(int arr[]){
    Node* temp=new Node(arr[2]);
    return temp;
}

void elInBw(Node* access5){
    Node* temp=access5;
    cout<<" value before 5 : "<<temp->prev->data<<endl;
    cout<<"value after 5 : "<<temp->next->data<<endl;
}


// arr to dll 
int main(){
    int arr[5] = {1,3,5,2,4};
    Node* dll=arrToDll(arr);
    print(dll);
    cout<<endl;
    Node* aal =access5(arr);
    elInBw(aal);

}