#include<bits/stdc++.h>
using namespace std;

int n;
int p[100000], w[100000];
int lim;
int dp[1000][1000][2];

int min_tk(int pos, int rem, int t){
    if(pos==n &&t==0)return INT_MAX;
    if(pos==n && t==1) return 0;
    if(dp[pos][rem][t]!=-1) return dp[pos][rem][t];
    int minimum=INT_MAX;
    minimum=min_tk(pos+1, rem, t);
    if(w[pos]<=rem){
        minimum=min(minimum,p[pos]+min_tk(pos+1, rem-w[pos], 1));
    }
    return dp[pos][rem][t]=minimum;
}
int main(){

   cout<<"Enter the number of Box:"<<endl;
   cin>>n;
   cout<<"Enter the price of Boxes:"<<endl;
   for(int i=0; i<n; i++){
    cin>>p[i];
   }
   cout<<"Enter the wight of Boxes:"<<endl;
   for(int i=0; i<n; i++){
    cin>>w[i];
   }
   cout<<"Enter your Limit(kg):"<<endl;
   cin>>lim;
   for(int i=0; i<n; i++){
    for(int j=0; j<lim+1; j++){
        dp[i][j][0]=-1;
        dp[i][j][1]=-1;
    }
   }
   cout<<"The minimum TK you can get: "<<min_tk(0, lim, 0)<<endl;
}

