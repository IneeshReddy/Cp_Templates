#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
					 
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
 
const int N = 2e5 + 10;
vector<int> par(N), adj[N];
vector<int> ans(N);
set<int> s[N];
 
 
int get(int x){
	 return x == par[x] ? x : par[x] = get(par[x]);
}
 
void merge(int x, int y){
	 x = get(x), y = get(y);
	 if(x == y){
		 return;
	 }
	 if(s[x].size() > s[y].size()){
		 swap(x, y);
	 }
	 for(auto i : s[x]){
		 s[y].insert(i);
	 }
	 s[x].clear();
	 par[x] = y;
}
 
 
void dfs(int x,int c = -1){
	for(auto i : adj[x]){
		 if(i == c){
			 continue;
		 }
		 dfs(i, x);
		 merge(i, x);
	}
	ans[x] = s[get(x)].size();
}
 
 
					 
void Solve(){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			par[i] = i;
			s[i].insert(x);
		}			 
     
	   for(int i = 0; i + 1 < n; i++){
		 int x, y;
		 cin >> x >> y;
		 adj[x].push_back(y);
		 adj[y].push_back(x);
	   }
 
	   dfs(1);
	   for(int i = 1; i <= n; i++){
		 cout << ans[i] << ' ';
	   }
}
					 
					 
int32_t main(){
   auto begin = std::chrono::high_resolution_clock::now();
   ios_base::sync_with_stdio(0);
   cin.tie(0);
							 
							 
   int T = 1;
//    cin >> T;
   for(int i = 1; i <= T; i++) {
	   //std::cout << "Case #" << i << ": ";
	   Solve();
   }
							 
							 
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	//std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
	return 0;
}