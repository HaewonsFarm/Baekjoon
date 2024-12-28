#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> factors;

    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
                factors.push_back(i);
                n /= i;
        }
    }
    
    if (n > 1) {
        factors.push_back(n);
    }

    for (size_t i = 0; i < factors.size(); i++) {
        cout << factors[i] << endl;
    }
        
    return 0;
}