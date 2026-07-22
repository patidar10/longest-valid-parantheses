#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int n = s.length();

    stack<int> st;

    int len = 0;

    for(int i=0;i<s.length();i++) {
        if(s[i] == '(')
            st.push(i);

        else {
            if(!st.empty()) {
                if(s[st.top()] == '(') {
                    st.pop();
                }
                else 
                    st.push(i);
                }
            else {
                    st.push(i);
                }           
            }
        }

        if(st.empty())
        return n;

        int temp = n;

        while(!st.empty()) {
            len = max(len,temp-st.top()-1);
            temp = st.top();
            st.pop();
        }


        len = max(len,temp);
        
        cout<<len;

        return 0;
}