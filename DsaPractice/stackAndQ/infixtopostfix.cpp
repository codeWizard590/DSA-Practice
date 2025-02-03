#include<bits/stdc++.h>
using namespace std;
class infix2postfix{
    public :
        int precedence(char a){
            if(a=='^'){
                return 3;
            }
            else if(a=='*'||a=='/'){
                return 2;
            }
            else if(a=='+'||a=='-'){
                return 1;
            }

            else{
                return -1;
            }

        }
        // infix to postfix 
        string postFix(string infix){
            // ex  -- >  a+b*(c^d-e)
            int n=infix.size();int i=0; stack<char> st;
            string answer="";
            while(i!=n){
                if((infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='a'&&infix[i]<='z')||(infix[i]>='0'&&infix[i]<='9')){
                    answer=answer+infix[i];
                }
                // check for operators;
                else if(infix[i]=='('){
                    st.push(infix[i]);
                }
                else if(infix[i]==')'){
                    while(!st.empty()&&st.top()!='('){
                        answer=answer+st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty()&&precedence(infix[i])<=precedence(st.top())){
                        answer=answer+st.top();
                        st.pop();
                    }   
                    st.push(infix[i]);
                }
                i++;
            }

            while(!st.empty()){
                answer=answer+st.top();
                st.pop();
            }
            return answer;
        }
};
int main(){
    string infix="a+b*(c^d-e)";
    cout<<infix.size();
    infix2postfix convert;
    string answer = convert.postFix(infix);
    cout<<"converted infix expression is infix to postfix : "<<answer<<endl;
}