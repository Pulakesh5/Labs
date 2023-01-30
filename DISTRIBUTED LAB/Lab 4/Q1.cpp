#include<bits/stdc++.h>

using namespace std;


void makeRandomGraph(vector<vector<int>> &adjMatrix, int nodeCount)
{
    int degree = 3, node =0, nd, next, weight;
    queue<int> q;
    q.push(node);
    nodeCount--;
    while(nodeCount)
    {
        int qs = q.size();
        for(int i=1;i<=qs && nodeCount;i++)
        {
            nd = q.front();
            q.pop();
            for(int j=1;j<=degree && nodeCount;j++,nodeCount--)
            {
                weight = rand()%101;
                adjMatrix[nd][node++]=weight;
            }
            if(i<qs)
            {
                weight = rand()%101;
                next  = q.front();
                adjMatrix[nd][next] = weight;
            }
        }
    }
}

int NO_PARENT = -1;
 

void printPath(int currentVertex, vector<int> parents)
{
 
    // Base case : Source node has
    // been processed
    if (currentVertex == NO_PARENT) {
        return;
    }
    printPath(parents[currentVertex], parents);
    cout << currentVertex << " ";
}
 
// A utility function to print
// the constructed distances
// array and shortest paths
void printSolution(int startVertex, int destVertex,  vector<int> distances,
                   vector<int> parents)
{

    int nVertices = distances.size();
    cout << "Distance\t\tPath\n";
    
    cout<<distances[destVertex]<<"\t\t\t";
    printPath(destVertex, parents);
    cout<<endl;

}
 
void dijkstra(vector<vector<int> > adjacencyMatrix, int startVertex, int destVertex)
{
    int nVertices = adjacencyMatrix[0].size();
 

    vector<int> shortestDistances(nVertices);
 

    vector<bool> added(nVertices);
 

    for (int vertexIndex = 0; vertexIndex < nVertices;
         vertexIndex++) {
        shortestDistances[vertexIndex] = INT_MAX;
        added[vertexIndex] = false;
    }
 
    // Distance of source vertex from
    // itself is always 0
    shortestDistances[startVertex] = 0;
 
    // Parent array to store shortest
    // path tree
    vector<int> parents(nVertices);
 
    // The starting vertex does not
    // have a parent
    parents[startVertex] = NO_PARENT;
 
    // Find shortest path for all
    // vertices
    for (int i = 1; i < nVertices; i++) {
 

        int nearestVertex = -1;
        int shortestDistance = INT_MAX;
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            if (!added[vertexIndex]
                && shortestDistances[vertexIndex]
                       < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance
                    = shortestDistances[vertexIndex];
            }
        }
 
        // Mark the picked vertex as
        // processed
        added[nearestVertex] = true;
 

        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            int edgeDistance
                = adjacencyMatrix[nearestVertex]
                                 [vertexIndex];
 
            if (edgeDistance > 0
                && ((shortestDistance + edgeDistance)
                    < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex]
                    = shortestDistance + edgeDistance;
            }
        }
    }
 
    printSolution(startVertex, destVertex, shortestDistances, parents);
}


void print(vector<vector<int>> &adjMatrix)
{
    for(auto v:adjMatrix)
    {
        for(auto it: v)
            cout<<it<<" ";
        cout<<endl;
    }
}

int main()
{

    freopen("input.txt", "r", stdin);

    int nodeCount, edgeCount, weight;
    cin>>nodeCount>>edgeCount;

    if(nodeCount==0)
        cout<<"Count of nodes in network is 0\nSo No network is created";
    else
    {   
        int level=1,nc=0, node1, node2;
        int degree=3;

        vector<vector<int>> adjMatrix(nodeCount,vector<int>(nodeCount,0));

        for(int i=0;i<edgeCount;i++)
        {
            cin>>node1>>node2;
            weight=rand()%101;
            adjMatrix[node1][node2]=weight;
            adjMatrix[node2][node1]=weight;
        }
        //makeRandomGraph(adjMatrix, nodeCount);

        int src = rand()%nodeCount, dest=rand()%nodeCount;

        cout<<"randomly generated source\t"<<src<<endl;
        cout<<"randomly generated destination\t"<<dest<<endl;
        // cout<<"Enter source and destination \n";

        dijkstra(adjMatrix, src, dest);
        //print(adjMatrix);
        
    }   
    

}
