#include<bits/stdc++.h>
using namespace std;
int dp[1000000];
int f(int n){

    if(n==1)dp[n]= 1;
    if(n==2)dp[n]= 2;
    if(n==3)dp[n]= 3;
    if(dp[n]!=0) return dp[n];
    else{
        return dp[n]=f(n-1)+f(n-2)+f(n-3);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<"We can color in "<<f(n)<<" ways!"<<endl;
    cout<<"The Series is: ";
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }
}


