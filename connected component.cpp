#include<bits/stdc++.h>
using namespace std;

long long int n, e;
int u,v;
vector<int>adj[100001];
int dis[100001], par[100001];
queue<int>q;


void bfs(int source){
    for(int i=1; i<=n; i++){
        dis[i]=INT_MAX;
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
                par[v]=u;
                q.push(v);
            }
        }
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
   int cnt=0;
   for(int i=1; i<=n; i++){
    if(dis[i]!=INT_MAX){
        bfs(i);
        cnt++;
    }
   }
   cout<<"The number of connected components are: "<<cnt;
   return 0;
}

