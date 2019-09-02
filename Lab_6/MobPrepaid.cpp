#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, max = 0, a, b, c, user;
    cin >> n >> q;
    int x[n+1] = {0};
    while(q--)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> b >> c;
            x[b] += c;
            if(max < x[b])
            {
            	max = x[b];
            	user = b;
            }
        }
        else if(a == 2 && max == 0) cout << "No data available." << endl;
        else cout << user << endl;
    }
    return 0;
}
