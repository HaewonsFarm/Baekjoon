#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int edges[3];
        for (int i = 0; i < 3; i++) {
            cin >> edges[i];
        }

        sort(edges, edges + 3);

        if (edges[0] == 0 && edges[1] == 0 && edges[2] == 0) break;

        if (edges[2] >= edges[0] + edges[1]) {
            cout << "Invalid" << '\n';
        } else if (edges[0] == edges[1] && edges[1] == edges[2]) {
            cout << "Equilateral" << '\n';
        } else if (edges[0] == edges[1] || edges[1] == edges[2] || edges[0] == edges[2]) {
            cout << "Isosceles" << '\n';
        } else {
            cout << "Scalene" << '\n';
        }
    }

    return 0;
}