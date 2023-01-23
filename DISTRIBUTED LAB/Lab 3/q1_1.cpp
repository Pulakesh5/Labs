#include<bits/stdc++.h>

using namespace std;

struct Node{
    vector<int> data;
    vector<int> adj_list;
    bool visited;
};

Node* newNode(vector<int> val)
{
    Node* tmp = new Node;
    tmp->data = val;
    tmp->adj_list={};
    tmp->data=val;
    tmp->visited=false;
    return tmp;
}

bool distributedSearch(vector<Node*> &graph, int key, int root)
{
    if(graph[root]->visited) return false;

    graph[root]->visited=true;
    //cout<<"visiting "<<root<<" checked ";
    for(auto val:graph[root]->data)
    {
        //cout<<val<<" ";
        if(val==key){
            cout<<"found at node "<<root<<endl;
            return true;
        }
    }
    //cout<<endl;
    // for(auto it:root)
    // {
    //     if(!(it->visited) && distributedSearch(graph,key,it));
    //         return true;
    // }
    for(int i=0;i<graph[root]->adj_list.size();i++)
    {
        if(distributedSearch(graph,key,graph[root]->adj_list[i]))
            return true;
    }
    return false;
}

int main()
{

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int nodeCount;
    cin>>nodeCount;

    vector<Node*> graph(nodeCount+1,NULL);
    int size,val;

    for(int i=1;i<=nodeCount;i++)
    {
        if(graph[i]==NULL)
            graph[i] = newNode({});
        cin>>size;
        for(int j=0;j<size;j++)
        {
            cin>>val;
            graph[i]->data.push_back(val);
        }
    }

    for(int node=1;node<=nodeCount;node++)
    {
        for(int adjNode=1;adjNode<=nodeCount;adjNode++)
        {
            if(node==adjNode) continue;

            graph[node]->adj_list.push_back(adjNode);

        }
    }

    int key, root;
    cin>>key;
    root=1;

    if(distributedSearch(graph,key,1))
        cout<<"Found the value in the distributed network\n";
    else
        cout<<"Not Found the value in the distributed network\n";

}
