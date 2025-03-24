#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *addTwoNumbers_BF(Node *head1, Node *head2)
    {
        stack<int> st1;
        stack<int> st2;
        Node *mover1 = head1;
        Node *mover2 = head2;
        vector<int> arr;
        while (mover1 != NULL)
        {
            int val = mover1->data;
            st1.push(val);
        }
        while (mover2 != NULL)
        {
            int val = mover2->data;
            st2.push(val);
        }
        int size1 = st1.size();
        int size2 = st2.size();
        int carrysum = 0;
        Node* head3=NULL;
        while (!st1.empty() && !st2.empty())
        {
            
            int sum = 0;
            if (st1.empty())
            {
                sum = st2.top() + carrysum;
                st2.pop();
            }
            else if (st2.empty())
            {
                sum = st1.top() + carrysum;
                st1.pop();
            }
            else if (!st1.empty() && !st2.empty())
            {
                sum = st1.top() + st2.top() + carrysum;
                st1.pop();
                st2.pop();
            }
            if (sum > 9)
            {
                carrysum = sum / 10;
                sum = sum % 10;
            }
            else
            {
                carrysum = 0;
            }
            // try to push this into a linked list .
            
            head3=new Node(sum,head3);
            
            
        }
        return head3;
    }
};
int main()
{
}