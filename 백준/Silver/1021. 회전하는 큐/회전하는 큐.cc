#include <iostream>
#include <deque>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  deque<int> dq;
  int index;
  int result = 0;

  int n, m, x;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  while (m--) {
    cin >> x;
    for (int i = 0; i < dq.size(); i++) {
      if(dq[i] == x) {
        index = i;
        break;
      }
    }

    if (index <= dq.size() / 2) {
      while(1) {
        if (dq.front() == x) {
          dq.pop_front();
          break;
        }
        ++result;
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      while(1) {
        if (dq.front() == x) {
          dq.pop_front();
          break;
        }
        ++result;
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }

  cout << result;
  return 0;
}