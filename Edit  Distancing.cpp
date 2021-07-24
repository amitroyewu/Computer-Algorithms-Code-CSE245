#include<bits/stdc++.h>
using namespace std;

char s1[100000], s2[100000];
int l1, l2, p1, p2;
int dp[100][100];

int edit(int p1, int p2){
   if(p1==l1)return l2-p2;
   if(p2==l2)return l1-p1;
   if(dp[p1][p2]!=-1) return dp[p1][p2];
   if(s1[p1]==s2[p2]){
    return dp[p1][p2]=edit(p1+1, p2+1);
   }
   int mn=edit(p1, p2+1);
   mn = min(mn, edit(p1+1, p2+2));
   mn = min(mn, edit(p1+1, p2));
   return dp[p1][p2]=1+mn;
}

int main(){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dp[i][j]=-1;
        }
    }
   cout<<"Enter the First word: "<<endl;
   cin>>s1;
   cout<<"Enter the second word: "<<endl;
   cin>>s2;

   l1=strlen(s1);
   l2=strlen(s2);
   cout<<"The minimum number is: "<<edit(p1, p2)<<endl;
   return 0;
}
