#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int isLarger(string a, string b) {
    int na = a.size(), nb = b.size();
    if(na < nb) return 0;
    if(na > nb) return 1;
    
    for(int i=0; i<na; i++)
    {
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return 0;
    }

    return 0;
}

string subtract(string a, string b) {
    string s;
    int na = a.size(), nb = b.size(), k=0, i;
    if( isLarger(b, a) )
    {
        k = 1;
        swap(a, b);
        swap(na, nb);
    }
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    int n = 0;

    for(i=0; i<nb; i++)
    {
        int xa = a[i]-'0', xb = b[i]-'0';
        int x = (xa-xb+10-n) % 10;
        s.pb(x+'0');
        if(xa-n < xb) n = 1;
        else n = 0;
    }

    for(i=nb; i<na; i++)
    {
        if(n == 0)
        {
            for(int j=i; j<na; j++) s.pb(a[j]);
            goto L;
        }
        else
        {
            int xa = a[i]-'0';
            int x = (xa-n+10) % 10;
            s.pb(x+'0');
            if(xa-n >= 0) n = 0;
            else n = 1;
        }
    }
    
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


    L: if(k) s.pb('-');
    reverse(s.begin(), s.end());
	return s;
}

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
    string a, b, q="0";
    cin>>a>>b;
    int na = a.size(), nb = b.size(), i;

    string ta = a, tb, temp, x, y;
    x = subtract(a, b);
    if(x[0] == '-') cout<<"q: "<<0<<' '<<"r: "<<a<<endl;
    else
    {
        while(x[0] != '-')
        {
            tb = b;
            int nta = ta.size();
            y = "1";
            for(i=0; i<nta-nb; i++)
            {
                tb.pb('0');
                y.pb('0');
            }
            temp = subtract(ta, tb);
            if(temp[0] == '-')
            {
                tb.pop_back();
                y.pop_back();
            }
            q = add(q, y);
            ta = subtract(ta, tb);
            x = subtract(ta, b);
        }
        cout<<q<<'\n'<<ta<<endl;
    }
    }
	return 0;
}
