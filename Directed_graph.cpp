#include<bits/stdc++.h>
using namespace std;
/**  5 5
     1 2
     2 3
     3 4
     4 5
     5 2
     */
int n, e;
vector<int>adj[100001];

int main()
{
    int u,v;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    int x;
    cout<<"Enter the array number to see the connected edge to it: "<<endl;
    cin>>x;
    for(int i=0; i<adj[x].size(); i++){
        cout<<" "<<adj[x][i];
    }
    return 0;

}

