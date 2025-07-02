#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
const int mxN=5e2+10,inf=1e17;
int dp[mxN][mxN];
int n,m,q;
void solve(){
        cin>>n>>m>>q;
        for(int i=0;i<m;i++){
            int x,y,z; cin>>x>>y>>z;
            dp[x][y]=min(z,dp[x][y]);
            dp[y][x]=min(z,dp[y][x]);
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                 for(int j=1;j<=n;j++){
                     if(i==j)
                     dp[i][j]=0;
                     dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                 }
            }
        }
        while(q--){
             int x,y; cin>>x>>y;
             cout<<(dp[x][y]==inf?-1:dp[x][y])<<endl;
        }
}
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<mxN;i++){
         for(int j=0;j<mxN;j++){
             dp[i][j]=inf;
         }
    }
    // int t; cin>>t;
    // while(t--)
    solve();
}