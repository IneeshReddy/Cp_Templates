#include <bits/stdc++.h>
using namespace std;

class HASH
{
private:
   long long mod;
   long long prime;
   vector<int> dp, prime_powers, inv_powers;

   long long modExpo(long long a, long long b, long long mod)
   {
      long long res = 1;
      while (b > 0)
      {
         if (b & 1)
            res = (res * a) % mod;
         a = (a * a) % mod;
         b >>= 1;
      }
      return res;
   }

public:
   HASH(long long prime, long long mod) : prime(prime), mod(mod) {}

   void calc(const string &s)
   {
      int n = s.length();
      dp.resize(n);
      prime_powers.resize(n);
      inv_powers.resize(n);

      dp[0] = s[0] - 'a' + 1;
      prime_powers[0] = 1;
      inv_powers[0] = 1; 

      long long inv_prime = modExpo(prime, mod - 2, mod); 

      for (int i = 1; i < n; i++)
      {
         prime_powers[i] = (prime_powers[i - 1] * prime) % mod;
         inv_powers[i] = (inv_powers[i - 1] * inv_prime) % mod; 
         dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * prime_powers[i]) % mod;
      }
   }

   int qry(int l, int r)
   {
      int result = dp[r];
      if (l > 0)
      {
         result = (result - dp[l - 1] + mod) % mod;
      }
      return (result * inv_powers[l]) % mod; 
   }
};



int main () {

}