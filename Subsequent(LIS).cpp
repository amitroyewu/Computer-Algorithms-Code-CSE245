#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100000], dp[100000];

int f(int p){
   if(p==n-1)return 1;
   if(dp[p]!=-1)return dp[p];
   int mx=1, val;
   for(int i=p+1; i<n; i++){
    if(arr[i]>arr[p]){
        val=f(i);
        if(val+1>mx){
        mx=1+val;
    }
      }
   }
   return dp[p]=mx;
}

int main(){
     cout<<"Enter the number: "<<endl;
     cin>>n;
     cout<<"Enter the values:"<<endl;
     for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i]=-1;
     }
     int mx=0, i;
     for( i=0; i<n; i++){
        mx=max(mx, f(i));
     }
     cout<<"The maximum Subsequent is: "<<mx<<endl;
     return 0;
}
