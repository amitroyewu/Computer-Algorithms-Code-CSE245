#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int p[100000];
int f(int l){
    int  value;
    if(l==0)return 0;
    if(dp[l]!=-1)return dp[l];
    int max = p[l];
    for(int i=1; i<=(l-1); i++){
         value = p[i] + f(l-i);
        if(max< value){
            max=value;
        }
    }
    return dp[l]=max;
    //return max; Two lines are same!
}
int main(){
    int length;
    cout<<"Enter the length of a Rod: "<<endl;
    cin>>length;
    cout<<"Enter the price range of every inch:"<<endl;
    for(int i=1; i<=length; i++){
        cin>>p[i];
    }
    for(int i=1; i<=length; i++){
        dp[i]=-1;
    }
    cout<<"The maximum price of N length rod is: "<<f(length);
}
//Time complixity O(n^2)
