#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();
    stack<string> st;
    string tempString;
    int i=0;
    while(i<n){
        if(s[i]!=' '){
            tempString+=s[i];
        }
        else 
            if(!tempString.empty())
            {
            st.push(tempString);
            tempString="";
            }
        i++;
    }
    if(tempString!=""){
        st.push(tempString);
    }
    tempString="";
    cout<<st.size();
    while(!st.empty()){
        tempString+=st.top();
        cout<<st.top()<<" ";
        st.pop();
        //tempString+=' ';
    }
    return tempString;
}

void inPlace(string &str){
     reverse(str.begin(), str.end());

    int n = str.size();
    int i = 0;
    for (int l = 0; l < n; ++l) {
        if (str[l] != ' ') {
          
            // go to the beginning of the word
            cout<<i<<endl;
            if (i != 0) str[i++] = '.';
            
            // go to the end of the word
            int r = l;
            while (r < n && str[r] != ' ') str[i++] = str[r++];

            // reverse the word
            reverse(str.begin() + i - (r - l), str.begin() + i);

            // move to the next word
            l = r;
        }
    }
    str.erase(str.begin() + i, str.end());
    // return str;
}

int main()
{

    string s = "$ hello    world        $and  ";
    // string chs = reverseWords(s);
    // cout<<endl;
    // cout << chs<<endl;
    // string sub=chs.substr(4,7-4);
    // cout<<sub<<endl;
    inPlace(s);
    cout<<s<<endl;
    // string test="chandig";
    // int i=1;
    // test[i++]='x';
    // cout<<test;
    // cout<<i;
}