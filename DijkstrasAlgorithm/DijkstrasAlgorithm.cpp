#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    //! Name of node
    string name;
    //! Cost of node relative to the begin point
    int cost;
    //! msp of the neighbors of this node
    map <node*, int> neighbors;
    //! A sign that the node is checked
    bool checked;

    node()
    {
        name       = "";
        cost       = INT_MAX;
        checked    = false;

        neighbors.clear();
    }
};

//! main graph
vector <node*> graph;

//! find the lowest cost node
//! return - lowest cost node instance pointer
node* lowestCostNode(vector <node*> _graph)
{
    node* nodeInstance = nullptr;
    int cost           = INT_MAX;

    auto i = _graph.begin();

    while (i != _graph.end())
    {
        node* graphInstance = *i;

        if (!graphInstance->checked)
        {
            if (graphInstance->cost < cost)
            {
                nodeInstance = graphInstance;
                cost = graphInstance->cost;
            }
        }

        i++;
    }

    return nodeInstance;
}

//! Dijkstra algorithm implimentation
//! return - lowest path cost from begin to finish
int process(vector <node*> _graph)
{
    while (true)
    {
        // Stage 1: find node with lowest cost
        node* graphInstance = lowestCostNode(_graph);

        // if returned value is nullptr - break processing and return result
        if (graphInstance == nullptr)
        {
            break;
        }

        // Stage 3: check the node neighbors and calculate neighbors costs

        auto j = graphInstance->neighbors.begin();

        while (j != graphInstance->neighbors.end())
        {
            node* neighborInstance = j->first;
            int neightborWeight    = j->second;

            int sum = graphInstance->cost + neightborWeight;

            if (sum < neighborInstance->cost)
            {
                neighborInstance->cost = sum;
            }

            j++;
        }

        graphInstance->checked = true;
    }

    return _graph.back()->cost;
}

int main()
{
    // node instances
    node* begin  = new node;
    node* finish = new node;
    node* a      = new node;
    node* b      = new node;
    node* c      = new node;
    node* d      = new node;

    // nodes names initializing
    begin->name  = "begin";
    finish->name = "finish";
    a->name      = "a";
    b->name      = "b";
    c->name      = "c";
    d->name      = "d";

    // begin node cost initializing
    begin->cost  = 0;

    // node neighbors specifying
    begin->neighbors[a]  = 5;
    begin->neighbors[b]  = 2;
    a->neighbors[c]      = 4;
    a->neighbors[d]      = 2;
    b->neighbors[a]      = 8;
    b->neighbors[d]      = 7;
    c->neighbors[d]      = 6;
    c->neighbors[finish] = 3;
    d->neighbors[finish] = 1;

    // initializing graph
    graph.push_back(begin);
    graph.push_back(a);
    graph.push_back(b);
    graph.push_back(c);
    graph.push_back(d);
    graph.push_back(finish);

    // find the shortest path
    int result = process(graph);

    // display result
    cout << "The shortest path is: " << result << endl;
}