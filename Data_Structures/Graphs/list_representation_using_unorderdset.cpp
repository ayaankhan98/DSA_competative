#include <iostream>
#include <unordered_set>

using namespace std;

class list_representation_using_unorderdset
{
private:
    int V;
    unordered_set<int>* adj; 
public:
    list_representation_using_unorderdset(int);
    ~list_representation_using_unorderdset();
    void addEdge(int, int);
    void printGraph();
    bool isEdge(int, int);
};

list_representation_using_unorderdset::list_representation_using_unorderdset(int v)
{
    this->V = v;
    adj = new unordered_set<int> [V]; 
}

list_representation_using_unorderdset::~list_representation_using_unorderdset()
{
    delete [] adj;
}

void list_representation_using_unorderdset::addEdge(int u, int v)
{
    //undirected graph
    adj[u].insert(v);
    adj[v].insert(u);
}

void list_representation_using_unorderdset::printGraph()
{
    cout<<"Adjacency list representaion -\n";
    for(int i = 0;i<V;i++)
    {
        cout<<"Vextex "<<i<<"-->";
        for(auto x : adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
}

bool list_representation_using_unorderdset::isEdge(int u,int v)
{
    auto i1 = adj[u].find(v);
    auto i2 = adj[v].find(u);
    if(i1 == adj[u].end() || i2 == adj[v].end())
        return false;
    else
        return true;   
}

typedef list_representation_using_unorderdset Graph;

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.printGraph();

    if (g.isEdge(2,3))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
    
    g.~Graph();
    return 0;
}