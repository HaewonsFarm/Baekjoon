#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  
  // Initialize a single vector of integers size n+1 with all elements set to 0.
  vector<int> dp(n + 1, 0);
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  for (int i = 4; i < n + 1; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 == 0)
      dp[i] = min(dp[i], dp[i/2] + 1);
    if (i % 3 == 0)
      dp[i] = min(dp[i], dp[i/3] + 1);
  }
  
  cout << dp[n] << endl;

  return 0;
}
