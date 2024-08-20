#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  // 1. 0으로 시작하지 않으며
  // 2. 1이 연속으로 나타나지 않는다.

  int n;
  cin >> n;

  long long dp[91] = {0, 1, 1};
  for (long long i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n];
  
  return 0;
}
