#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, count = 0;
    cin >> n;

    int num[n];
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++) {
        int current = num[i];
        if (current < 2) {
            continue;
        }

        bool isPrime = true;
        
        for (int j = 2; j <= sqrt(current); j++) {
            if (current % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) count++;
    }

    cout << count << endl;

    return 0;
}