#include<bits/stdc++.h>
#define f(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
using namespace std;

class graph
{
private:
	int n;
	list<int> *adj;
	int *colour;
public:
	graph(int n);
	void addedge(int v, int w);
	bool isbipartite(int v);
	bool disconGraph();
};

graph::graph(int n)
{
	this->n = n;
	adj = new list<int>[n];
	colour = new int[n];
}

void graph::addedge(int v, int w)
{
	adj[v].pb(w);
	adj[w].pb(v);
}

bool graph::isbipartite(int v)
{
	colour[v] = 2;
	list<int> q;
	q.pb(v);
	while(!q.empty())
	{
		int s = q.front();
		q.pop_front();
		for(auto i:adj[s])
		{
			if(colour[i] == colour[s]) return false;
			else if(!colour[i])
			{
				if(colour[s] == 2) colour[i] = 1;
				else colour[i] = 2;
				q.pb(i);
			}
		}
	}
	return true;
}

bool graph::disconGraph()
{
	f(i, 0 ,n)
	{
		if(!colour[i] && !isbipartite(i)) return false;
	}
	return true;
}

int main()
{
	int n, m, v, w, x;
	cin>>n>>m;
	int y = n;
	graph g(n+m+1);
	f(i, 0, m)
	{
		cin>>v>>w>>x;
		if(x%2 == 1) g.addedge(v, w);
		else
		{
			g.addedge(v, y);
			g.addedge(y, w);
			y++;
		}
	}
	if(g.disconGraph()) cout<<"NO\n";
	else cout<<"YES\n";
}
