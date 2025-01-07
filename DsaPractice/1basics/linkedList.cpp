#include<bits/stdc++.h>
using namespace std;
// linked list is basically a chain of objects having same properties.

class Node{
    public:
        int value;
        Node* ptr;
        Node(int value1, Node* ptr1){
            value=value1;
            ptr=ptr1;
        }
        Node(int value1){
            value=value1; 
            ptr=nullptr;
        }
};
int main(){
    // using new keyword to dynamically allocate space for this object .
    // node.value is locally created will not last .
    Node* y=new Node(3);
    Node node(4);
    Node* z=new Node(4);
    cout<<node.value<<endl;
    cout<<y<<endl;
    cout<<z->value<<endl;
    int arr[5]={1,3,5,7,9};
    Node* head =new Node(arr[0]);
    for(int i=0;i<5;i++){
        Node* temp=new Node(arr[i]);
        
    }

}