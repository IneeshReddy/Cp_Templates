#include <bits/stdc++.h>
using namespace std;


struct tree {
    int n, T, root;
    vector<vector<int>> g, up;
    vector<int> tin, tout, d;

    // For the initialisation part
    void in_it(int nn, int rr){
        n = nn;
        root = rr;
        g = vector<vector<int>> (n + 1);
        up = vector<vector<int>> (n + 1, vector<int> (20));
        tin = vector<int> (n + 1);
        tout = vector<int> (n + 1);
        d = vector<int> (n + 1);
        T = 0;
    }

    // For pre computing
    void dfs(int x, int c){
         tin[x] = T++;
         up[x][0] = c;
         for(auto i : g[x]){
             if(i == c) continue;
             d[i] = d[x] + 1;
             dfs(i, x);
         }
         tout[x] = T;
    }

    
    void build(){
         dfs(root, root);
         for(int j = 1; j < 20; j++){
            for(int i = 1; i <= n; i++){
                 up[i][j] = up[up[i][j - 1]][j - 1];
            }
         }
    }

    void add(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool isanc(int x, int y){
        return tin[x] <= tin[y] && tout[x] >= tout[y];
    }

    // Binary lifting
    int lift(int x, int y){
        for(int i = 0; i < 20; i++){
             if(y >> i & 1)
             x = up[x][i];
        }
        return x;
    }

    // Caluculating LCA
    int lca(int x, int y){
        if (isanc(x, y)) {
            return x;
        }
        if (isanc(y, x)) {
            return y;
        }

        for(int i = 19; i >= 0; i--){
             int nw = up[x][i];
             if(!isanc(nw, y)) x = nw;
        }
        return up[x][0];
    }

    // Distance between Two nodes x and y
    int dis(int x, int y){
        int z = lca(x, y);
        return d[x] + d[y] - 2 * d[z];
    }
};

int main () {

}