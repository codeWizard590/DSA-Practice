#include<bits/stdc++.h>
using namespace std;

// the intution behind this is turtoise hare method ..
// will have two cases for even and odd 
// we need to reach the end of ll 
// hare take 2 steps and turtoise takes 1 step 
// when hare reaches the end of ll we point out the mid where the turtoise is at 1 step forward for turtoise and 2 steps forward for hare 
// this method is also used to find if there is a repetiotion in the linked list .
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
     
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                // this means a cycle is detected 
                // after detecting the cycle we need to iterate 1 by 1 resetting slow to head 
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
int main(){

}