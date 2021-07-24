#include<bits/stdc++.h>
using namespace std;

int coins[10000][10000];
int dp[10000][10000];
int r, c, n;

int max_coin(int r, int c){
   if(r==n-1 && c==n-1) return coins[r][c];
   if(dp[r][c]!=-1)return dp[r][c];
   int maximum=0;
   if(r<n-1){
    maximum=max(maximum, coins[r][c]+max_coin(r+1, c));
   }
   if(c<n-1){
    maximum=max(maximum, coins[r][c]+max_coin(r, c+1));
   }
   return dp[r][c]=maximum;
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
   cout<<"The maximum coins a Robot can earn: "<<max_coin(r, c)<<endl;
   return 0;
}
