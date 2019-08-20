#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a; i<b; i++)
#define pb push_back

bool isOperator(string c)
{ 
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^") return true;
    return false;
}

struct tree
{
    string str;
    tree* left;
    tree* right;
};

tree* newNode(string s)
{
    tree* temp = new tree;
    temp->left = NULL;
    temp->right = NULL;
    temp->str = s;
    return temp;
}

bool isInt(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]) == false) return false;
    }
    return true;
}

int prec(string c)
{
    if(c == "^") return 5;
    else if(c == "/") return 4;
    else if(c == "*") return 3;
    else if(c == "+") return 2;
    else if(c == "-") return 1;
    else return -1;
}

vector<string> inToPost(string str)
{
    stack<string> st;
    st.push("N");
    vector<string> ans, s;
    string t;
    int x = str.size();
    f(i, 0, x)
    {
        if(str[i] >= '0' && str[i] <= '9') t += str[i];
        else
        {
            if(!t.empty()) s.pb(t);
            t.clear();
            t += str[i];
            s.pb(t);
            t.clear();
        }
        if(i == x-1) s.pb(t);
    }
    int l = s.size();
    for(int i=0; i<l; i++)
    {
        if(isInt(s[i])) ans.pb(s[i]);
        else if(s[i] == "(") st.push("(");
        else if(s[i] == ")")
        {
            while(st.top() != "N" && st.top() != "(")
            {
                string c = st.top();
                st.pop();
                ans.pb(c);
            }
            if(st.top() == "(") st.pop();
        }
        else
        {
            while(st.top() != "N" && prec(s[i]) <= prec(st.top()))
            {
                string c = st.top();
                st.pop();
                ans.pb(c);
            }
            st.push(s[i]);
        }
    }
    while(st.top() != "N")
    {
        string c = st.top();
        st.pop();
        ans.pb(c);
    }
    return ans;
}

tree* makeTree(string s)
{
    vector<string> vs = inToPost(s);
    stack<tree *> st;
    tree *t, *t1, *t2;
    int n = vs.size();
    for (int i=0; i<n; i++)
    {
        if (isInt(vs[i]))
        {
            t = newNode(vs[i]);
            st.push(t);
        }
        else
        {
            t = newNode(vs[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->right = t1;
            t->left = t2;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}

int eval(tree* a)
{
	if(a->left==NULL && a->right==NULL) return stoi(a->str);
	int A = eval(a->left);
	int B = eval(a->right);
	if(a->str == "+") return A+B;
	else if(a->str == "-") return A-B;
	else if(a->str == "*") return A*B;
	else if(a->str == "%") return A%B;
	else if(a->str == "/") return A/B;
	else if(a->str == "^") return pow(A,B);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        while(n--)
        {
            vector<string> vs;
            string s;
            cin>>s;
            tree* t = makeTree(s);
            cout<<eval(t);
        }
    }
    return 0;
}
