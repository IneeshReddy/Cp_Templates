#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
                     
void Solve(){
    int n, m; cin >> n >> m;
    vector<int> d(n + 1, INF);
 
    vector<array<int, 3>> e(m);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        e[i][0] = x;
        e[i][1] = y;
        e[i][2] = z;
    }
    int j;
 
    vector<int> p(n + 1, -1);
    d[1] = 0;
    for(int i = 0; i < n; i++){
        j = -1;
        for(auto it : e){
             int x = it[0], y = it[1], z = it[2];
             if(d[x] + z < d[y]){
                d[y] = d[x] + z;
                p[y] = x;
                j = y;
             }
        }
    }
 
    if(j == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            j = p[j];
 
        vector<int> cycle;
        for (int v = j;; v = p[v]) {
            cycle.push_back(v);
            if (v == j && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
 
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