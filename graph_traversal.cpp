#include<bits/stdc++.h>
using namespace std;
#define MAX 20

class Graph{
    int adj[MAX][MAX];
    int n;

public:
    Graph(int x)                    //Initialization of graph
    {
        n=x;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<x;j++)
            {
                adj[i][j]=0;
            }
        }
    }

     void addEdge(int a,int b)
    {
        adj[a][b]=1;
        adj[b][a]=1;
        cout<<"Edge added successfully!"<<endl;
    }

    void show()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

   

    void DFS(int src,vector<bool> &visit)
    {
        visit[src]=true;
        cout<<src<<" ";
        for(int i=0;i<n;i++)
        {
            if((adj[src][i]==1)&&(!visit[i]))
            {
                DFS(i,visit);
            }
        }
    }

    void BFS(queue<int> q,vector<bool> &visit)
    {
        if(q.empty()){
            return;
        }
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int i=0;i<n;i++)
        {
            if((adj[v][i]==1)&& !visit[i])
            {
                visit[i]=true;
                q.push(i);
            }
        }
        BFS(q,visit);
    }
};

int main()
{
    int n,choice,v1,v2,src;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    vector<bool> visitedDFS(n,false);
    vector<bool>visitedBFS(n,false);
    Graph g(n);
    while(true)
    {
        cout<<"\n--------------------Menu--------------------\n";
        cout<<"1.Add Edge \n 2.Adjacency List \n 3.DFS \n 4.BFS \n 5.Exit \n Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter first vertex between 0-"<<n-1<<" ";
            cin>>v1;
             cout<<"Enter second vertex between 0-"<<n-1<<" ";
            cin>>v2;
            g.addEdge(v1,v2);
            break;

        case 2:
            g.show();
            break;

        case 3:
        for(int i=0;i<n;i++)
        {
            visitedDFS[i] = false;
        }
            cout<<"Enter the source node : ";
            cin>>src;    
            cout<<"DFS is : "; 
            g.DFS(src,visitedDFS);
            break;
        
        case 4:
            for(int i=0;i<n;i++)
            {
                visitedBFS[i]=false;
            }
            queue<int> q;
            cout<<"Enter source node : ";
            cin>>src;
            cout<<"BFS is : ";
            visitedBFS[src]=true;
            q.push(src);
            g.BFS(q,visitedBFS);
            break;

    

        }   

        
    }

    return 0;
}