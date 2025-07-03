#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int inf=1e9;
 
void solve(){
      string s,t; cin>>s>>t;
      int n=s.size(),m=t.size();
      vector<vector<int>> dp(n+1,vector<int> (m+1,inf));
      //dp[i][j] min no of opetations req to change sting 1 to i to 1 to j
      for(int i=0;i<=n;i++){
         dp[i][0]=i;
      }
      for(int j=0;j<=m;j++){
         dp[0][j]=j;
      }
      for(int i=1;i<=n;++i){
         for(int j=1;j<=m;j++){
             if(s[i-1]==t[j-1]){
                 dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
             }
             else{
                 dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
             }
         }
      }
      cout<<dp[n][m]<<endl;
}
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}