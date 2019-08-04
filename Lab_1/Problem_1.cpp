#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
    string a, b, s;
    cin>>a>>b;
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
    cout<<s<<endl;
    }
    return 0;
}
