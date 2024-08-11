#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, T, ent, out, px, py, r, x1, x2, y1, y2;
  cin >> T;

  while (T--) {
    cin >> x1 >> y1 >> x2 >> y2;

    cin >> n;

    ent = 0;
    out = 0;

    while (n--) {
      cin >> px >> py >> r;
      if (pow(px - x1, 2) + pow(py - y1, 2) > pow(r, 2)) {
        if (pow(px - x2, 2) + pow(py - y2, 2) < pow(r, 2)) {
          ent++;
        }
      }
      if (pow(px - x1, 2) + pow(py - y1, 2) < pow(r, 2)) {
        if (pow(px - x2, 2) + pow(py - y2, 2) > pow(r, 2)) {
          out++;
        }
      }
    }
    
  cout << ent + out << endl;

  }

  return 0;
}
