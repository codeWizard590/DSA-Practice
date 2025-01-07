#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        void pointers(int &n){
            cout<<"the integer value is : "<<n<<endl;
            int*y=&n; // y referencing n.
            cout<<"pointer address for n is : "<<y;
        }
};
int main(){
    Node node;
    int n=2;
    node.pointers(n);
}