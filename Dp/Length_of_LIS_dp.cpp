#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
void solve(){
  int n; cin>>n;
  vector<int> v(n); for(auto &a:v)cin>>a;
  vector<int> p;
  for(int i=0;i<n;i++){
    if(p.empty()){p.push_back(v[i]); continue;}
    int x=lower_bound(p.begin(),p.end(),v[i])-p.begin();
    if(x<p.size())p[x]=v[i];
    else p.push_back(v[i]);
  }
  cout<<(int)p.size()<<endl;
}
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}