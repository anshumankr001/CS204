#include <bits/stdc++.h>
#define pb push_back
using namespace std;

string add(string a, string b) {
    string s;
	int na = a.size(), nb = b.size();
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    int n = 0;

    if(na < nb)
    {
        swap(a, b);
        swap(na, nb);
    }

    for(int i=0; i<nb; i++)
    {
        int xa = a[i]-'0', xb = b[i]-'0';
        int x = (xa+xb+n) % 10;
        s.pb(x+'0');
        n = (xa+xb+n) / 10;
    }

    for(int i=nb; i<na; i++)
    {
        if(n == 0)
        {
            for(int j=i; j<na; j++) s.pb(a[j]);
            goto L;
        }
        else
        {
            int xa = a[i]-'0';
            int x = (xa+n) % 10;
            s.pb(x+'0');
            n = (xa+n) / 10;
        }
    }
    if(n != 0) s.pb(n+'0');

    L: reverse(s.begin(), s.end());
	return s;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
    string a, b, s;
    cin>>a>>b;
    int na = a.size(), nb = b.size(), i, j, k;
    string x[na];

    for(i=0; i<na; i++)
    {
        int n = 0;
        for(j=nb-1; j>=0; j--)
        {
            int xa = a[i]-'0', xb = b[j]-'0';
            int ab = xa*xb + n;
            n = ab/10;
            ab = ab%10;
            x[i].pb(ab+'0');
        }
        if(n != 0) x[i].pb(n+'0');
        reverse(x[i].begin(), x[i].end());
        if(nb-1-j > 0) 
        {
            for(k=0; k<na-1-i; k++) x[i].pb('0');
        }
    }

    s = x[0];
    for(int i=1; i<na; i++) s = add(s, x[i]);
    reverse(s.begin(), s.end());
    i = s.size()-1;
    while(s.size() > 1)
    {
        if(s[i] == '0')
        {
            s.pop_back();
            i--;
        }
        else break;
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    }
	return 0;
}
