#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t, cnt = 0;
  cin >> t;
  int n, m, imp;
  for (int i = 0; i < t; i++) {
    cnt = 0;
    cin >> n >> m;

    queue<pair<int, int>> Q;
    priority_queue<int> PQ;

    for (int j = 0; j < n; ++j) {
      cin >> imp;
      Q.push({j, imp});
      PQ.push(imp);
    }

    while (!Q.empty()) {
      int idx = Q.front().first;
      int value = Q.front().second;
      Q.pop();

      if (PQ.top() == value) {
        PQ.pop();
        ++cnt;

        if (idx == m) {
          if (idx == m)
          cout << cnt << endl;
          break;
        }
      }
      
      else Q.push({idx, value});
    }
  }

  return 0;
}
