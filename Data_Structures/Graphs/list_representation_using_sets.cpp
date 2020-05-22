/**
 * Graph representaion using sets
 * advantages - 
 *      operations like wheater there is an edge from vertex u to vertex v can be done in O(log V)
 * diadvantages - 
 *      Graphs contaning parallel edges cannot be represented using this technique
 *      Adding an edge from vertex u to vertex v takes O(log V) 
 *          (as internal implementation of sets and multisets is somewhat like balanced binary trees the C++ Standard library does not
 *              mention this but it follows from the time complexity of operations of sets and multisets)
 * 
 * operations like wheather there is an edge form vertex u to vertex v can be further optimised using unordered sets
 * thus the time complexity of this operation reduces to O(1) form O(log V)
 * but the disadvantage is that sorted order of vertex is lost
 ***/
#include <iostream> 
#include <set>

using namespace std;

class list_representation_using_sets
{
private:
    int V;
    set<int,greater<int>> * adj;
public:
    list_representation_using_sets(int);
    ~list_representation_using_sets();
    void addEdge(int, int);
    void printGraph();
};

list_representation_using_sets::list_representation_using_sets(int v)
{
    this->V = v;
    adj = new set<int,greater<int>> [V];
}

list_representation_using_sets::~list_representation_using_sets()
{
    delete [] adj;
}

void list_representation_using_sets::addEdge(int u, int v)
{
    // undirected graph
    adj[u].insert(v);
    adj[v].insert(u);
}

void list_representation_using_sets::printGraph()
{
    cout<<"Adjacency list representaion using sets - \n";
    for(int i = 0;i<V;i++)
    {
        cout<<"Vertex "<<i<<"-->";
        for(auto x : adj[i])
            cout<<x<<" ";
        cout<<"\n";
    }
}

typedef list_representation_using_sets Graph;

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.printGraph();
    // Explicit destructor call
    g.~Graph();
    return 0;
}