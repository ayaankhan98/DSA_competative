#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// directed Graph
class Graph
{
private:
    int V;
    vector<int> *adj;

public:
    Graph(int v)
    {
        V = v;
        adj = new vector<int>[v];
    }
    void addEdge(int, int);
    void printGraph();
    void BFS(int);
    void DFS(int);
    bool detectCycle();
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        cout << "Adjacency List of vertex" << i << "\n";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
}

void Graph::BFS(int start_vertex)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    visited[start_vertex] = true;
    q.push(start_vertex);

    while (!q.empty())
    {
        int ele = q.front();
        cout << ele<< " ";
        q.pop();
        for (auto x : adj[ele])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void Graph::DFS(int start_vertex)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    stack<int> s;
    visited[start_vertex] = true;
    s.push(start_vertex);

    while (!s.empty())
    {
        int ele = s.top();
        cout << ele << " ";
        s.pop();
        for (auto x : adj[ele])
        {
            if (!visited[x])
            {
                visited[x] = true;
                s.push(x);
            }
        }
    }
}

bool Graph::detectCycle()
{
    bool visited[V];
    for(int i =0; i<V;i++)
        visited[i] = false;

    stack<int> s;
    visited[0] = true;
    s.push(0);
    while(!s.empty())
    {
        int ele = s.top();
        s.pop();
        for(auto x : adj[ele])
        {
            if(visited[x])
                return true;
            else
            {
                visited[x] = true;
                s.push(x);
            }
            
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);

    g.BFS(0);
    cout<<endl;
    g.DFS(0);
    cout<<endl;
   // g.printGraph();
    if (g.detectCycle())
        cout<<"\nCycle Found\n";
    else
    {
        cout<<"No cycle Found\n";
    }
    
    return 0;
}