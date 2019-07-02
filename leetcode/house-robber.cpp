/*
   dynamic programming | maximum non-adjacent sum
   problem: house-robber
*/
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
   int memo[1000000];

   int dp(vector<int> v, int i) {
      if (memo[i] != -1)
         return memo[i];

      if (i >= v.size())
         return memo[i] = 0;

      return memo[i] = max(
         v[i] + dp(v, i + 2), //rouba a casa atual e vai para a próxima não adjacente
         dp(v, i + 1)         //não rouba a atual e vai para a próxima adjacente
      );
   }

   int rob(vector<int> &nums) {
      memset(memo, -1, sizeof(memo));
      return dp(nums, 0);
   }
};