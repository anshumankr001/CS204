#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x[1000] = {0}, max = 0, a, b, c, user;
    cin >> n;
    for(int i=0; i<n; i++)
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
