#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        stack <char> s;
        string str;
        cin>>str;
        s.push('$');
        int n = str.size(), flag = 0;
        for(int i=0; i<n; i++)
        {
            if(str[i] == '|')
            {
                if(s.top() == '|') s.pop();
                else s.push(str[i]);
            }
            if(str[i] == ')')
            {
                if(s.top() == '(') s.pop();
                else
                {
                    flag++;
                    i = n;
                }
            }
            if(str[i] == '}')
            {
                if(s.top() == '{') s.pop();
                else
                {
                    flag++;
                    i = n;
                }
            }
            if(str[i] == ']')
            {
                if(s.top() == '[') s.pop();
                else
                {
                    flag++;
                    i = n;
                }
            }
            if(str[i] == '>')
            {
                if(s.top() == '<') s.pop();
                else
                {
                    flag++;
                    i = n;
                }
            }
            if(str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<') s.push(str[i]);
        }
        if(s.top() == '$' && flag == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
