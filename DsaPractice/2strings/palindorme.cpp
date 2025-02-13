#include <bits/stdc++.h>
using namespace std;
bool isAlpha(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    int n = s.size();
    string temp = "";
     
        int l=0;int r=n-1;
        
        while(l<=r){
            while(l<r&&!isAlpha(s[l])) l++;
            while(l<r&&!isAlpha(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])){
                cout<<s[l]<<s[r]<<" ";
            } 
            l++;r--;
           
        }
        
}