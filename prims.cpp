#include<bits/stdc++.h>
using namespace std;

void Prims(vector<vector<int>> adj,int n){
vector<bool>visited(n,false);
visited[0]=true;
int edge=0,x,y,cost=0;
while (edge<n-1)
{
    x=0;y=0;
    int mini = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(visited[i])
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[j]&&adj[i][j])
                {
                    if(mini>adj[i][j])
                    {
                        mini = adj[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
    }
    cout<<x<<" --> "<<y<<"    "<<adj[x][y]<<endl;
    cost+=adj[x][y];
    edge++;
    visited[y]=true;
}


cout<<"\nTotal cost : "<<cost;

}

int main()
{
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
       vector<int>temp;
       for(int j=0;j<n;j++)
       {
        int x;
        cout<<"Enter edge between "<<i<<" & "<<j<<" ";
        cin>>x;
        temp.push_back(x);
       }
       adj.push_back(temp);
    }
    
    Prims(adj,n);
}