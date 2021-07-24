#include<bits/stdc++.h>
using namespace std;
int n;
int p[100000], w[100000];
int lim;
int dp[10000][10000];

int max_tk(int pos, int rem){
    if(pos==n)return 0;
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int maximum=0;
    maximum=max_tk(pos+1, rem);   // if we don't take any weight;
    if(w[pos]<=rem){
        maximum=max(maximum, p[pos]+max_tk(pos+1, rem-w[pos]));   // if we take any weight;
    }
    return dp[pos][rem]=maximum;
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
        dp[i][j]=-1;
    }
   }
   cout<<"The maximum TK you can get: "<<max_tk(0, lim)<<endl;
}
