#include <iostream>
#include <stack>
using namespace std;

int prefixEval(string s){
    // create a stack
    stack<int> st;

    // traverse from right to left (for prefix)
    for(int i = s.length()-1; i >= 0; i--){
        
        // if(s[i] is operand -> push in the stack)
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        
        // else if it is operator
        else{
            // create two variables to store top two elements
            int a = st.top(); 
            st.pop();
            int b = st.top(); 
            st.pop();
            
            // evaluate with operator
            int res;
            if(s[i] == '+') res = a + b;
            else if(s[i] == '-') res = a - b;
            else if(s[i] == '*') res = a * b;
            else if(s[i] == '/') res = a / b;
            
            // push the result back in stack
            st.push(res);
        }
    }
    
    // return the last remaining element from stack -> it is answer
    return st.top();
}

int main(){
    string s = "-+7*45+20";
    cout << prefixEval(s);
}

    