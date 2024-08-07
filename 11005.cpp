#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, b;
    cin  >> n >> b;

    string converted_n;

    while(n != 0) {
        int temp = n % b;
        if (temp > 9) {
            temp = temp - 10 + 'A';
            converted_n += temp;
        }
        else {
            converted_n += ('0' + temp);
        }
        n /= b;
    }

    reverse(converted_n.begin(), converted_n.end());

    cout << converted_n << endl;

    return 0;
}