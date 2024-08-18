#include <iostream>
using namespace std;

int GCD(int num, int denom) {
  while (denom != 0) {
    int temp = denom;
    denom = num % denom;
    num = temp;
  }
  return num;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n1, n2, d1, d2, result = 1;
  cin >> n1 >> d1
      >> n2 >> d2;

  int numerator = n1*d2 + n2*d1;
  int denominator = d1 * d2;

  int commonFactor = GCD(numerator, denominator);

  numerator /= commonFactor;
  denominator /= commonFactor;

  cout << numerator << " " << denominator << endl;

  return 0;
}
