#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void swapll(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

ll partition(ll arr[], ll l, ll r, ll x)
{
    ll i;
    for (i=l; i<r; i++) if (arr[i] == x) break; 
    swapll(&arr[i], &arr[r]);
    i = l;
    for (ll j = l; j <= r - 1; j++)
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

ll findMedian(ll arr[], ll n)
{
    sort(arr, arr+n);
    return arr[n/2];
}

ll kthSmallest(ll arr[], ll l, ll r, ll k)
{
    if (k > 0 && k <= r - l + 1)
    {
        ll n = r-l+1;
        ll i, median[(n+4)/5];
        for (i=0; i<n/5; i++) median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }
        ll medOfMed = (i == 1)? median[i-1]: kthSmallest(median, 0, i-1, i/2);
        ll pos = partition(arr, l, r, medOfMed);
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
        printf("%.15lf\n", sqrtdis);
    }
    return 0;
}
