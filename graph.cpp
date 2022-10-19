#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    unordered_map<int, list<int> > mp;

    void insertintograph(int u, int v, int direction)
    {
        //direction is for the thing that we are making the directed or undirected graph
        if(direction)
        mp[u].push_back(v);
        else
        {
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    }

    void printlist()
    {
        for(auto i: mp)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void breadfirstsearch()
    {
        //now we need to print the data in the bread first search way manner
        queue<int> q;
        //for the bfs traversal we need to maintain a visited array of nodes so that we can make a node that which node has been already visited and which are need to be visited yet
        unordered_map<int, bool> visited;
        q.push(1);
        visited[1]= true;
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            cout<<node<<" ";
                for(auto i: mp[node])
                {
                    if(!visited[i])
                    {
                        q.push(i);
                        visited[i]= true;
                    }
                }
            }
    }

    void dfs()
    {
        stack<int> s;
        unordered_map<int, bool> visited;
        s.push(1);
        visited[1]= true;
        while(!s.empty())
        {
            int node= s.top();
            s.pop();
            cout<<node<<" ";
            for(auto i: mp[node])
            {
                if(!visited[i])
                {
                    s.push(i);
                    visited[i]= true;
                }
            }
        }
    }
};
int main()
{
    Graph g;
    int nodes;
    cout<<"Enter the number of nodes in graph"<<endl;
    cin>>nodes;
    int edges;
    cout<<"Enter the number of edges in graph"<<endl;
    cin>>edges;
    cout<<"enter the connected edges"<<endl;
    //for the undirected graph
    int direction=0;
    for(int i=1;i<=edges;i++)
    {
        int u, v;
        cin>>u>>v;
        g.insertintograph(u,v,direction);
    }
    g.printlist();
    cout<<"Breadth First search in the Graph"<<endl;
    g.breadfirstsearch();
    cout<<"Depth first search for the grapgh is: "<<endl;
    g.dfs();
}
