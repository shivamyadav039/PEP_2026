#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int postfixEval(string s){
    stack<int> st;

    for(int i = 0; i < s.length(); i++){

        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int res;
            if(s[i]=='+') res = a+b;
            else if(s[i]=='-') res = a-b;
            else if(s[i]=='*') res = a*b;
            else if(s[i]=='/') res = a/b;
            else if(s[i]=='^') res = pow(a,b);

            st.push(res);
        }
    }
    return st.top();
}

int main(){
    string s = "23^54*+9-"; 
    cout << postfixEval(s);
}
