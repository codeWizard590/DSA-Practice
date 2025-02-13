#include<bits/stdc++.h>
using namespace std;
// we need to do a premitive composition of strings 
// just need to remove the outer paranthesis of each part 
string removeParanthesis(string s){
    int n=s.size();
    string str="";int count=0;
    // to check valid paranthesis we can check where we have () in array
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(count>0){
                str=str+s[i];
            }
            count++;
        }
        else{
            if(count>1){
                str=str+s[i];
            }
            count--;
        }

    }
    return str;
}
int main(){
    string s="(()())(())(()(()))";
    string l=removeParanthesis(s);
    cout<<"removed string is : "<<l;
    // after primitve composition -> (( -> (
    int count=0;
    if(s[0]=='('&&count++>0){
        cout<<"yes";
    }
    cout<<count++;
    if(s[1]=='('&&count>0){
        cout<<"yes"<<count;
    }
}