#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(int i=a; i<b; i++)

void pairsort(string a[], string b[], int n)
{
    pair<string,string> v[n];
    f(i, 0, n)
    {
        v[i].first=a[i];
        v[i].second=b[i];
    }
    sort(v, v+n);
    f(i,0,n)
    {
        a[i]=v[i].first;
        b[i]=v[i].second;
    }
}

int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string a[n], b[n];
        int l = 0;
        f(i, 0, n)
        {
        	cin>>a[i];
        	if(a[i].size() > l) l = a[i].size();
        }
        f(i, 0, n)
        {
        	while(b[i].size() < l+1) b[i] += a[i];
        	b[i] = b[i].substr(0, l+1);
        }
        pairsort(b, a, n);
        reverse(a, a+n);
        f(i, 0, n) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
