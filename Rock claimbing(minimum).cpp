#include<bits/stdc++.h>
using namespace std;

int coins[10000][10000];
int dp[10000][10000];
int r, c, n;

int min_coin(int r, int c){
   if(r==n-1 && c==n-1) return coins[r][c];
   if(dp[r][c]!=-1)return dp[r][c];
   int minimum=INT_MAX;
   if(r<n-1){
    minimum=min(minimum, coins[r][c]+min_coin(r+1, c));
   }
   if(c<n-1){
    minimum=min(minimum, coins[r][c]+min_coin(r, c+1));
   }
   return dp[r][c]=minimum;
}
int main(){
   cout<<"Enter the path number: "<<endl;
   cin>>n;
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cin>>coins[i][j];
    }
   }
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        dp[i][j]=-1;
    }
   }
   cout<<"The minimum coins a Robot can earn: "<<min_coin(r, c)<<endl;
   return 0;
}

