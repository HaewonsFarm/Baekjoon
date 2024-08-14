#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, cnt = 99;;
  cin >> n;

  if (n < 100) {
    cout << n;
    return 0;
  } else {

    for (int i = 100; i <= n; i++) {
      int hd = i / 100;
      int td = (i - hd*100) / 10;
      int od = (i - hd*100 - td*10);

      if ((hd - td) == (td - od)) {
        cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
