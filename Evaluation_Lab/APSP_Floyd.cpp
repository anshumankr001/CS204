#include <bits/stdc++.h>
#define f(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int main()
{
	int V, e;
	cin>>V>>e;
	int adj[V][V];

	f(i, 0, V)
	{
		f(p, 0, V)
		{
			if(i != p) adj[i][p] = 100000;
			else adj[i][p] = 0;
		}
	}

	f(i, 0, e)
	{
		int x, y;
		cin>>x>>y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	f(k, 0, V)
    {
        f(i, 0, V)
        {
            f(j, 0, V)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    f(i, 0, V)
    {
    	f(p, 0, V) cout<<adj[i][p]<<" ";    		
    	cout<<"\n";
    }

    return 0;
}
