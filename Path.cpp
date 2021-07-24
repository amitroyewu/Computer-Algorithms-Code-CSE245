#include<bits/stdc++.h>
using namespace std;

long long int n, e;
int u,v,mx;
vector<int>adj[100001];
int dis[100001], par[100001];
queue<int>q;

void bfs(int source){
    for(int i=1; i<=n; i++){
        dis[i]=100000000;
    }
    dis[source]=0;
    par[source]=source;
    q.push(source);
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            v=adj[u][i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                //mx=max(mx, dis[v]);
                par[v]=u;
                q.push(v);
            }
        }
    }
    //cout<<"The maximum path is: "<<mx<<endl;
    cout<<"The distance values are: ";
    for(int i=1; i<n+1; i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n"<<"The parents values are: ";
    for(int i=1; i<n+1; i++){
        cout<<par[i]<<" ";
    }
}
int main(){
   cout<<"Enter the number of Node and Edge: "<<endl;
   cin>>n>>e;
   cout<<"Enter the value of U and V: "<<endl;
   for(int i=1; i<=e; i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   cout<<"Enter the source: "<<endl;
   int src;
   cin>>src;
   bfs(src);
   return 0;
}

