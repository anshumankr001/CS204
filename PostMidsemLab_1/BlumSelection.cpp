#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void swapll(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

ll partition(ll arr[], ll l, ll r)
{
    ll x = arr[r], i = l;
    for (ll j=l; j <= r-1; j++)
    {
        if (arr[j] <= x)
        {
            swapll(&arr[i], &arr[j]);
            i++;
        }
    }
    swapll(&arr[i], &arr[r]);
    return i;
}

ll kthSmallest(ll arr[], ll l, ll r, ll k)
{
    if (k > 0 && k <= r-l+1)
    {
        ll pos = partition(arr, l, r);
        if (pos-l == k-1) return arr[pos]; 
        if (pos-l > k-1) return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, a, b, k;
        cin>>n;
        ll dis[n];
        for(ll i=0; i<n; i++)
        {
            cin>>a>>b;
            dis[i] = a*a + b*b;
        }
        if(n%2 == 0) k = n/2;
        else k = n/2 + 1;
        double sqrtdis = sqrt((double)kthSmallest(dis, 0, n-1, k));
        cout<<sqrtdis<<endl;
    }
    return 0;
}
