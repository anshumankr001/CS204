#include <bits/stdc++.h>
using namespace std;

int k1 = 24379;
int k2 = 23293;
int k3 = 28687;

bool h1[24379];
bool h2[23293];
bool h3[28687];
bool Hash(string, int);

int main()
{
	int n;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		string s, srev;
		cin >> s;
		srev = s;
		reverse(s.begin(), s.end());

		if (s == srev)
			continue;

		Hash(s,1);

		if (Hash(srev,0))
		{
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

bool Hash(string s, int f)
{
	int len = s.length();
	long long f1=0, f2=0, f3=0, f4=0, f5=0;
	int ctr = 0;
	for (int i=0; i<len; i++)
	{
		f1 = (f1 + (i+1)*(i+1)*(s[i]-'a')) % k1 ; 
		f2 = (f2 + (i+1)*(i+1)*(s[i]-'a')) % k2 ; 
		f3 = (f3 + (i+1)*(i+1)*(s[i]-'a')) % k3 ;  
	}
	if (h1[f1]) ctr++;
	else if (f) h1[f1]=1;
	if (h2[f2]) ctr++;
	else if (f) h2[f2]=1;
	if (h3[f3]) ctr++;
	else if (f) h3[f3]=1;
	return (ctr==3)?1:0;
}
