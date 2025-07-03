#include <bits/stdc++.h>
using namespace std;

struct RMQ{
    vector<vector<int>> dp;
    // dp[i][j] from index i and length of 2 ^ j what is the value

    void in_it(int n, vector<int> v){
        dp = vector<vector<int>> (n, vector<int> (20));
        for(int i = 0; i < n; i++){
            dp[i][0] = v[i];
         }

         for(int j = 1; j < 20; j++){
             for(int i = 0; i + (1 << j) <= n; i++){
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
             }
         }
    }    

    int qry(int i, int j) {
        int len = j - i + 1;
        int d = log2(len);
        
        return max(dp[i][d], dp[j - (1 << d) + 1][d]);
    }
};


int main () {
  // For range min you can convert all "max" to "min" and then
  // It will become min_rmq
}