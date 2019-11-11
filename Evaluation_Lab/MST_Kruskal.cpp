#include <bits/stdc++.h>
#define f(i, a, b) for(int i=a; i<b; i++)
using namespace std;

class Edge
{
    public:
    int src, dest, weight;
};

class Graph
{
    public:
    int V, E;
    Edge* edge;
    Graph(int V, int E);
};

Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
  	edge = new Edge[E];
}

class subset
{
    public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
   	if (subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KMST(Graph g )
{
    int V = g.V, i = 0, e = 0;
    Edge result[V];

    qsort(g.edge, g.E, sizeof(g.edge[0]), myComp);

    subset *subsets = new subset[( V * sizeof(subset) )];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < g.E)
    {
        Edge next_edge = g.edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout<<"Edges in the MST are:\n";
    for (i = 0; i < e; ++i)
        cout<<result[i].src<<" - "<<result[i].dest<<"\tWeight: "<<result[i].weight<<endl;
    return;
}

int main()
{
	int v, e;
	cin>>v>>e;

	Graph g(v, e);

	f(i, 0, e)
	{
		int x, y, w;
		cin>>x>>y>>w;

		g.edge[i].src = x;
		g.edge[i].dest = y;
		g.edge[i].weight = w;
	}

	KMST(g);

	return 0;
}
