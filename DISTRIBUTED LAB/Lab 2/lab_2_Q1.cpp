#include<bits/stdc++.h>

using namespace std;

int neighbour(int node, int d)
{
    if(node&(1<<d))
        return node&~(1<<d);
    else
        return node|(1<<d);
}



int  main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    auto start = chrono::system_clock::now();
    int degree=5;
    int nodes=1<<degree;
    //cin>>nodes;

    vector<vector<int>> adjacency_list(nodes+1);
    vector<vector<int>> adjacency_matrix(nodes+1,vector<int>(nodes+1,0));
    
    int next;
    //cin>>edges;
    
    for(int node=0;node<nodes;node++)
    {
        cout<<node<<" : ";
        for(int d=0;d<degree;d++)
        {
            next=neighbour(node,d);
            cout<<next<<" ";
            adjacency_list[node].push_back(next);
            adjacency_matrix[node][next]=1;
        }
        cout<<endl;
    }

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed =  (end - start);
    
    
    cout<<"\n\nAdjacency list of the network:\n Node\t:\t Adjacenct Nodes\n"<<endl;

    for(int i=0;i<nodes;i++)
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

    cout<<"\n\nAdjacency Matrix of the network\t \n  ";
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

    cout<<"Showing degree of every node in the network\n";
    cout<<"================================";
    cout<<"node \t:\t degree\n";
    for(int i=1;i<=nodes;i++)
        cout<<i<<"\t:\t"<<adjacency_list[i].size()<<'\n';
    
    
        cout << "Time : " << std::setw(9)<< elapsed.count()<< " s\n";

}

/*

Output:



Adjacency list of the network:
 Node:	 Adjacenct Nodes

0	:	1 2 4 8 16
1	:	0 3 5 9 17
2	:	3 0 6 10 18
3	:	2 1 7 11 19
4	:	5 6 0 12 20
5	:	4 7 1 13 21
6	:	7 4 2 14 22
7	:	6 5 3 15 23
8	:	9 10 12 0 24
9	:	8 11 13 1 25
10	:	11 8 14 2 26
11	:	10 9 15 3 27
12	:	13 14 8 4 28
13	:	12 15 9 5 29
14	:	15 12 10 6 30
15	:	14 13 11 7 31
16	:	17 18 20 24 0
17	:	16 19 21 25 1
18	:	19 16 22 26 2
19	:	18 17 23 27 3
20	:	21 22 16 28 4
21	:	20 23 17 29 5
22	:	23 20 18 30 6
23	:	22 21 19 31 7
24	:	25 26 28 16 8
25	:	24 27 29 17 9
26	:	27 24 30 18 10
27	:	26 25 31 19 11
28	:	29 30 24 20 12
29	:	28 31 25 21 13
30	:	31 28 26 22 14
31	:	30 29 27 23 15


Adjacency Matrix of the network	 
  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 
1	0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
2	0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
3	1 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 
4	0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 
5	1 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 
6	0 1 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 
7	0 0 1 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 
8	0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 
9	1 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 
10	0 1 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 
11	0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 
12	0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 
13	0 0 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 
14	0 0 0 0 0 1 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 
15	0 0 0 0 0 0 1 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 
16	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 
17	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 
18	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 
19	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 
20	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 
21	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 
22	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 1 0 0 
23	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 1 0 
24	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 
25	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 
26	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 1 0 0 
27	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 
28	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 
29	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 1 0 
30	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 1 0 
31	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1 1 0 0 
32	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 


Showing degree of every node in the network
================================node 	:	 degree
1	:	5
2	:	5
3	:	5
4	:	5
5	:	5
6	:	5
7	:	5
8	:	5
9	:	5
10	:	5
11	:	5
12	:	5
13	:	5
14	:	5
15	:	5
16	:	5
17	:	5
18	:	5
19	:	5
20	:	5
21	:	5
22	:	5
23	:	5
24	:	5
25	:	5
26	:	5
27	:	5
28	:	5
29	:	5
30	:	5
31	:	5
32	:	0












*/
