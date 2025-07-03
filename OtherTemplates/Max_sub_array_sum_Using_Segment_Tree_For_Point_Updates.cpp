#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct node{
    int sum, pre, suf, seg; 
};

struct SegTree{
     int size;
     vector<node> tree;

     node merge(node a, node b){
       node ans;
       ans.sum = a.sum + b.sum;
       ans.pre = max(a.pre, a.sum + b.pre);
       ans.suf = max(b.suf,b.sum + a.suf);
       ans.seg = max({a.seg, b.seg, a.suf + b.pre});
       return ans;
     }

     void set(int pos, int val, int i, int l, int r){
         if(l > pos || r < pos) return;
         if(l == r){
           tree[i].pre = val;
           tree[i].seg = val;
           tree[i].suf = val;
           tree[i].sum = val;
           return;          
          }
         int m = (l + r) / 2;
         set(pos, val, 2 * i, l, m);
         set(pos, val, 2 * i + 1, m + 1, r);
         tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
     }

     node query(int lx, int rx, int i, int l, int r){
          if(lx > r || rx < l) return {0,0, 0, 0};
          if(l >= lx && r <= rx) return tree[i];
          int m = (l + r) / 2;
          node left = query(lx, rx, 2 * i, l, m);
          node right = query(lx, rx, 2 * i + 1, m + 1, r);
          return merge(left, right);
     }


     SegTree(int n){
       tree.resize(4 * n);
       size = n - 1;
     }

     void set(int pos, int val) {set(pos, val, 1, 0, size); }
     node query(int lx, int rx) {return query(lx, rx, 1, 0, size); }
};
                     
                     
void Solve(){
        int n, q;
        cin >> n >> q;
        SegTree st(n);
        vector<int> v(n);
        for(int i = 0; i < n; i++){
           cin >> v[i];
           st.set(i, v[i]);
        }     
        cout << max(0ll,st.query(0, n - 1).seg) << '\n';        
        while(q--){
          int i, val;
          cin >> i >> val;
          st.set(i, val);
          cout << max(0ll,st.query(0, n - 1).seg) << '\n';
        }

}
                     
                     
int32_t main(){
   auto begin = std::chrono::high_resolution_clock::now();
   ios_base::sync_with_stdio(0);
   cin.tie(0);
                             
                             
   int T = 1;
  //  cin >> T;
   for(int i = 1; i <= T; i++) {
       //std::cout << "Case #" << i << ": ";
       Solve();
   }
                             
                             
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}