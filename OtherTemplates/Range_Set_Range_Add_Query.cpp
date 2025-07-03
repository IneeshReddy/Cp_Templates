#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
    int size;
    vector<int> tree, lazy;

    int merge(int x, int y){
       return x + y;
    }

    void push(int i, int l, int r){
        if(lazy[i] != -1){
        tree[i] = (r - l + 1) * lazy[i];         

         if(l != r){
             lazy[2 * i] = lazy[i];
             lazy[2 * i + 1] = lazy[i];
         }

        }

         lazy[i] = -1;
    }

    
    void set(int lx, int rx, int i, int l, int r, int val){
        push(i, l, r);

        if(l > rx || r < lx){
            return;
        }
        
        if(l >= lx && r <= rx){
             tree[i] = (r - l + 1) * val;

             if(l != r){
                 lazy[2 * i] = val;
                 lazy[2 * i + 1] = val;
             }

             return;
        }

        int m = (l + r) / 2;

        set(lx, rx, 2 * i, l, m, val);
        set(lx, rx, 2 * i + 1, m + 1, r, val);

        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    int query(int lx, int rx, int i, int l, int r){
         push(i, l, r);

         if(l > rx || r < lx) return 0;

         if(l >= lx && r <= rx){
             return tree[i];
         }

         int m = (l + r) / 2;

         int left = query(lx, rx, 2 * i, l, m);
         int right = query(lx, rx, 2 * i + 1, m + 1, r);

         return merge(left, right);
    }

    SegTree(int n){
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, -1);
        size = n - 1;
    }

    int query(int l, int r) { return query(l, r, 1, 0, size); };
    void set(int l, int r, int val){ set(l, r, 1, 0, size, val); };
};
                     
void Solve(){
     int n, m;
     cin >> n >> m;
     SegTree st(n);

     while(m--){
        int type; cin >> type;
        if(type == 1){
             int l, r, v;
             cin >> l >> r >> v;
             r--;

             st.set(l, r, v);
        }

        else{
            int l, r;
            cin >> l >> r;
            r--;

            cout << st.query(l, r) << '\n';
        }
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