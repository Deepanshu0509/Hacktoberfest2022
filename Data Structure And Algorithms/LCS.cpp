#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int longestCommonSubsequence(string s, string x) {
      int n = s.size();
      int m = x.size();
      if(!n || !m) return 0;
      s = " " + s;
      x = " " + x;
      int ret = 0;
      vector < vector <int> > dp(n + 1, vector <int>(m + 1));
      for(int i = 1; i <= n; i++){
         for(int j = 1; j <= m ; j++){
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(s[i] == x[j]) {
               dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
         }
      }
      return dp[n][m];
   }
};
main(){
   Solution ob;
   cout << (ob.longestCommonSubsequence("abcde", "ace"));
}
