#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // M 이상 N 이하 소수 모두 출력하기

  int n, m;
  cin >> m >> n;

  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;


  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      for (long long j = (long long)i*i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (int i = m; i <= n; i++) {
    if (isPrime[i])
      cout << i << endl;
  }

  return 0;
}
