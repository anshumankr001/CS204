#include <bits/stdc++.h>
using namespace std;
struct node
{
	struct node *left, *right;
	int value, val;
};

node *cn(int v)
{
	node *temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->value = v;
	temp->val = 0;
	return temp;
}
node *cno(int v)
{
	node *temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->val = v;
	return temp;
}
node *build(vector<string> op)
{
	stack<node *> st;
	for (auto s : op)
	{
		if (s[0] == '+' || s[0] == '/' || s[0] == '*' || s[0] == '-' || s[0] == '^')
		{
			node *l, *r;
			r = st.top();
			st.pop();
			l = st.top();
			st.pop();
			node *p = cno(s[0]);
			p->left = l;
			p->right = r;
			st.push(p);
		}
		else if (s[0] == '|' || s[0] == '}')
		{
			int value=st.top()->value;
			st.pop();
			if (s[0] == '|')
				st.push(cn(-value));
			else
				st.push(cn(value));
		}
		else
		{
			st.push(cn(strtod(&s[0], NULL)));
		}
	}
	return st.top();
}

long long int eval(node *ptr)
{
	switch (ptr->val)
	{
	case '+':
		return eval(ptr->left) + eval(ptr->right);
	case '*':
		return eval(ptr->left) * eval(ptr->right);
	case '-':
		return eval(ptr->left) - eval(ptr->right);
	case '/':
		return eval(ptr->left) / eval(ptr->right);
	case '^':
		return (long long int)pow(eval(ptr->left), eval(ptr->right));
	default:
		return ptr->value;
	}
}

int pro(string c)
{
	if (c.compare("(") == 0 || c.compare(")") == 0)
		return 1;
	if (c.compare("*") == 0 || c.compare("/") == 0)
		return 4;
	if (c.compare("+") == 0 || c.compare("-") == 0)
		return 3;
	if (c.compare("^") == 0)
		return 5;
	if (c.compare("|") == 0 || c.compare("}") == 0)
		return 6;
	return 0;
}
vector<string> cpostfix(vector<string> v)
{
	vector<string> ans;
	stack<string> st;
	for (auto c : v)
	{
		if (!c.compare("+") || !c.compare("-") || !c.compare("*") || !c.compare("/") || !c.compare("^") || !c.compare("(") || !c.compare(")") || c.compare("|") == 0 || c.compare("}") == 0)
		{
			if (st.empty())
				st.push(c);
			else
			{
				if (!c.compare("(") || !c.compare("|") || !c.compare("}"))
					st.push(c);
				else if (!c.compare(")"))
				{
					while ((st.top()).compare("(") != 0)
					{
						ans.push_back(st.top());
						st.pop();
					}
					st.pop();
				}
				else if (!c.compare("+") || !c.compare("-") || !c.compare("*") || !c.compare("/"))
				{
					while (!st.empty() && pro(c) <= pro(st.top()))
					{
						ans.push_back(st.top());
						st.pop();
					}
					st.push(c);
				}
				else if (!c.compare("^"))
				{
					while (!st.empty() && pro(c) < pro(st.top()))
					{
						ans.push_back(st.top());
						st.pop();
					}
					st.push(c);
				}
			}
		}
		else
		{
			ans.push_back(c);
		}
	}
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s, cur;
			cin >> s;
			vector<string> ip, op;
			for (auto c : s)
			{
				if (c == '+' || c == '-' || c == '*' || c == '(' || c == ')' || c == '/' || c == '^')
				{
					if (cur.compare("") != 0)
						ip.push_back(cur);
					cur = "";
					cur.push_back(c);
					ip.push_back(cur);
					cur = "";
				}
				else
					cur.push_back(c);
			}
			if (cur.compare("") != 0)
				ip.push_back(cur);
			for (int i = 0; i < ip.size(); i++)
			{
				if (ip[i][0] == '-')
				{
					if (i == 0 || ip[i - 1][0] == '(')
						ip[i]="|";
				}
				if (ip[i][0] == '+')
				{
					if (i == 0 || ip[i - 1][0] == '(')
						ip[i] = "}";
				}
			}
			op = cpostfix(ip);
			node *tree = build(op);
			cout << eval(tree)<<endl;
		}
	}
}
