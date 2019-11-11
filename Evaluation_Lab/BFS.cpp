#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public: 
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    while(!queue.empty()) 
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(auto i:adj[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(4, 2);
    g.addEdge(4, 1);

    cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
