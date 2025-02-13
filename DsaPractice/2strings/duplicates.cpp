#include<bits/stdc++.h>
using namespace std;
class Duplicates{
    // need to remove duplicates lexicographically
    public :
        string removeDuplicates(string s){
            int n =s.size();
            
            for(int i=0;i<n;i++){
                int l=i+1;int charint=s[i];
                while(i<n){
                    // check if i encounter somethign which is lesser than that char 
                    
                    if(s[i]==s[l]){
                       
                    }
                }
            }
        }
};
int main(){
    string s = "bcabc";
    Duplicates duplicates;
    string answer= duplicates.removeDuplicates(s);
    cout<<answer;
}