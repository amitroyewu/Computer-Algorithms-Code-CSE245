#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int f(int n){
    if(n==1)arr[n]=1;
    if(n==2)arr[n]=2;
    if(arr[n]!=0)return arr[n];
    else{
        return arr[n]=f(n-1)+f(n-2);
    }
}
int main(){
   int n, k;
   cin>>n>>k;
   f(n);
   for(int i=1; i<=n; i++){
    cout<<arr[i]<<" ";
   }
}
