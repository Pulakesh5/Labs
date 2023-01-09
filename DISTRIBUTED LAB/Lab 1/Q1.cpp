#include<bits/stdc++.h>

using namespace std;

bool isConnected(vector<vector<int> > &adjacency_list)
{
    int nodes=adjacency_list.size();

    vector<bool> seen(nodes+1,0);
    queue<int> q;
    q.push(1);
    

    while(!q.empty())
    {
        int node = q.front();
        seen[node]=1;
        q.pop();
        for(int i=0; i<adjacency_list[node].size();i++)
        {
            if(seen[adjacency_list[node][i]]==0)
                q.push(adjacency_list[node][i]);
        }
    }


    // for(int i=0;i<=nodes;i++)
    //     cout<<i<<" : "<<seen[i]<<endl;



    bool allSeen=1;
    for(int i=1;i<nodes;i++)
    {
        allSeen=allSeen & seen[i];
    }
    return allSeen;
}

int  main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nodes;
    cin>>nodes;

    vector<vector<int> > adjacency_list(nodes+1);
    vector<vector<int> > adjacency_matrix(nodes+1,vector<int>(nodes+1,0));
    int edges, node1, node2;
    cin>>edges;
    
    for(int i=0;i<edges;i++)
    {
        cin>>node1>>node2;
        adjacency_list[node1].push_back(node2);
        adjacency_list[node2].push_back(node1);
        adjacency_matrix[node1][node2]=1;
        adjacency_matrix[node1][node2]=1;
    }
    if(isConnected(adjacency_list))
        cout<<"Thegiven network is connected\n";
    else
        cout<<"The given network is not connected\n";
    cout<<"\nAdjacency list of the network:\nNode\t:\t Adjacenct Nodes"<<endl;

    for(int i=1;i<=nodes;i++)
    {
        cout<<i<<"\t:\t";
        if(adjacency_list[i].size()==0)
            cout<<"NULL ";
        else
        {
            int n=adjacency_list[i].size();
            for(int j=0;j<n;j++)
            {
                if(j==n-1)
                    cout<<adjacency_list[i][j]<<endl;
                else    
                    cout<<adjacency_list[i][j]<<" ";
            }
        }
    }

    cout<<"\nAdjacency Matrix of the network\t \n \t";
    for(int i=1;i<=nodes;i++)
        cout<<i<<' ';
    cout<<endl;
    for(int i=1;i<=nodes;i++)
    {   
        cout<<i<<"\t";
        for(int j=1;j<=nodes;j++)
            cout<<adjacency_matrix[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nShowing degree of every node in the network\n";
    cout<<"\n================================\n";
    cout<<"node \t:\t degree\n";
    for(int i=1;i<=nodes;i++)
        cout<<i<<"\t:\t"<<adjacency_list[i].size()<<'\n';

}


//                             16 -- 15
//                             |     |
//       1 ---------   8 ----- 13 -- 14
//     /   \         /   \
//    2     3       9     10
//   / \   / \      |      |
//  4  5   6  7     11----12

