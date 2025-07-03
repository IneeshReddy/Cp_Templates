#include <bits/stdc++.h>
using namespace std;


void kmp(string s, string p){
  //string s--> given string
  //string p--> pattern to match
   string z=p+"&"+s;
      int m=p.size();
      int n=z.size();
      vector<int> lps(n);
      for(int i=1;i<n;i++){
         int j=lps[i-1];
         while(j && z[j]!=z[i]){
             j=lps[j-1];
         }
         if(z[i]==z[j]){
            j++;
         }
         lps[i]=j;
      }
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main () {
    
}