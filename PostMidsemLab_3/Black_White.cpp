#include <bits/stdc++.h>
#define f(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int visited[10000][10000];
int input[10000][10000];
int COUNT;

bool is_valid(int, int, int, int, int);
void BFS(int, int, int, int, int, int);
void reset_visited(int, int);
void func(int, int);

int main()
{
    int n, m, k, a, b;
    cin>>n>>m>>k;

    while(k--)
    {
        cin>>a>>b;
        input[a-1][b-1] = 1;
    }

    func(n, m);

    return 0;
}

bool is_valid(int x, int y, int c, int n, int m)
{
    if (x < n && y < m && x >= 0 && y >= 0)
    {
        if (visited[x][y] == false && input[x][y] == c) return true;
        else return false;
    }
    else return false;
}

void BFS(int x, int y, int i, int j, int n, int m)
{
    if (x != y) return;
    visited[i][j] = 1;
    COUNT++;
    int x_move[] = { 0, 0, 1, -1 };
    int y_move[] = { 1, -1, 0, 0 };
    f(u, 0, 4)
        if (is_valid(i + y_move[u], j + x_move[u], x, n, m))
            BFS(x, y, i + y_move[u], j + x_move[u], n, m);
}

void reset_visited(int n, int m)
{
    f(i, 0, n)
    {
        f(j, 0, m) visited[i][j] = 0;
    }
}

void func(int n, int m)
{
    int current_max = INT_MIN, x;
    f(i, 0, n)
    {
        f(j, 0, m)
        {
            if(input[i][j] == 1)
            {
                reset_visited(n, m);
                COUNT = 0;
                if (j + 1 < m) BFS(input[i][j], input[i][j + 1], i, j, n, m);
                if (COUNT >= current_max)
                {
                    current_max = COUNT;
                    x = input[i][j];
                }
                reset_visited(n, m);
                COUNT = 0;
                if (i + 1 < n) BFS(input[i][j], input[i + 1][j], i, j, n, m);
                if (COUNT >= current_max)
                {
                    current_max = COUNT;
                    x = input[i][j];
                }
            }
        }
    }
    if(current_max == 0) current_max++;
    cout<<current_max<<endl;
}
