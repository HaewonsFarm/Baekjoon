#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int angle[3];
    for (int i = 0; i < 3; i++) {
        cin >> angle[i];
    }

    int sum = angle[0] + angle[1] + angle[2];
    if (sum != 180) {
        cout << "Error" << '\n';
        return 0;
    } else if (angle[0] == 60 && angle[1] == 60 && angle[2] == 60) {
        cout << "Equilateral" << '\n';
        return 0;
    } else if (angle[0] == angle[1] || angle[1] == angle[2] || angle[0] == angle[2]) {
        cout << "Isosceles" << '\n';
        return 0;
    } else {
        cout << "Scalene" << '\n';
    }

    return 0;
}