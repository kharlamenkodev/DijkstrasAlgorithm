#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
    //! Name of node
    string name;
    //! Cost of node relative to the begin point
    uint8_t cost;
    //! Vector of the neighbors of this node
    vector <node*> neighbors;
    //! A sign that the node is checked
    bool checked;

    node()
    {
        name    = "";
        cost    = 0;
        checked = false;
        neighbors.clear();
    }
};

//! main graph
vector <node*> graph;

//! find the shortest path
//! return - shortest path
vector <node*> process(vector <node*> _graph)
{
    bool processed = false;

    while (!processed)
    {

    }
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

    // nodes costs initializing

    begin->cost  = 0;
    a->cost      = 5;
    b->cost      = 2;
    c->cost      = INT_MAX;
    d->cost      = INT_MAX;
    finish->cost = INT_MAX;

    // node neighbors specifying
    begin->neighbors.push_back(a);
    begin->neighbors.push_back(b);
    a->neighbors.push_back(c);
    a->neighbors.push_back(d);
    b->neighbors.push_back(a);
    b->neighbors.push_back(d);
    c->neighbors.push_back(d);
    c->neighbors.push_back(finish);
    d->neighbors.push_back(finish);

    // initializing graph
    graph.push_back(begin);
    graph.push_back(a);
    graph.push_back(b);
    graph.push_back(c);
    graph.push_back(d);
    graph.push_back(finish);

    // find the shortest path
    vector <node*> result = process(graph);

    // display result
    cout << "The shortest path is: ";
    
    auto it = result.begin();

    while (it != result.end())
    {
        node* instance = *it;

        cout << instance->name << "; ";

        it++;
    }
}