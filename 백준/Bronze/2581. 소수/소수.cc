#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int m, n, sum = 0;
    cin >> m >> n;
    vector<int> primes;

    for (int i = m; i <= n; i++) {
        if (i < 2) continue;

        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }

    if (!primes.empty()) {
        for (size_t i = 0; i < primes.size(); i++) {
            sum += primes[i];
        }
        cout << sum << endl << primes[0] << endl;
    } else {
        cout << -1 << endl;
    }
        
    return 0;
}