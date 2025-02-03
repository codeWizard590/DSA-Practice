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

// deleting using head and remove head 
Node* deleteHead(Node* head){
    if(head==NULL){return head;}
    Node* temp=head;
    head=head->ptr;
    free(temp);
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->ptr; // represents next pointer for traversal
    }
    cout<<endl;
}

// deletion in a linked list -> tail ..
Node* deleteTail(Node* head){
    Node* temp = head;
    if(head==NULL||head->ptr==NULL){return NULL;}
    while(temp->ptr->ptr!=NULL){
        temp=temp->ptr;
    }
    delete temp->ptr;
    temp->ptr=nullptr;
    return head;
}

// deleting a node at int target index 
Node* deleteAtk(Node* head,int k){
    // need a counter to get when to delete.
    if(head==NULL){return head;}
    if(k==1){
        Node* temp=head;
        head=head->ptr;
        delete head ;
        return head;
    }
    Node* temp = head;
    Node* prev=NULL;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k){
          prev->ptr=temp->ptr;  
        }
        temp=temp->ptr;
    }
    return head;
}

int main(){
    int arr[5]={1,3,5,7,9};
    // getting or calling a value in a linked list 
    Node* head=arrToLL(arr);
    //cout<<head->ptr<<endl; 
    // traversing through a linked list.
    cout<<"traversing through a linked list : ";
    print(head);
    
    // // deleting a node in linked list
    // // cout<<deleteHead(head)<<endl;
    // Node* temps=deleteHead(head);
    // cout<<"deletions : ";
    // print(temps);
    
    // // deleting tail // taking new starting pointer a sthe head is now deleted.
    // Node* tail=deleteTail(temps);
    // cout<<"deleted tail : ";
    // print(tail);

    // kth element 
    Node* tail=deleteAtk(head,3);
    cout<<"deleted tail : ";
    print(tail);
    
}