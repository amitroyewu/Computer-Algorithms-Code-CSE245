#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int p[100000];
int r;


int f(int l){

    if(l==0)return 0;
    if(dp[l]!=-1)return dp[l];
    int max = p[l], val;
    if(l==r){
        max=0;
    }
    for(int i=1; i<=(l-1); i++){
        if(i==r) continue;
        val = p[i] + f(l-i);
        if(max<val){
            max=val;
        }
    }
    return dp[l]=max;
}
int main(){
    int length;
    cout<<"Enter the length of a Rod: "<<endl;
    cin>>length;
    cout<<"Enter the price range of every inch:"<<endl;
    for(int i=1; i<=length; i++){
        cin>>p[i];
    }
    cout<<"Enter your restricted inch:"<<endl;
    cin>>r;
    for(int i=1; i<=length; i++){
        dp[i]=-1;
    }
    cout<<"The maximum price of N length rod is: "<<f(length);
}

