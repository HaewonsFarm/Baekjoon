#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int arr[9][9] = {0};

    int max_row, max_col, max = 0, max_arr[9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] >= max) {
                max = arr[i][j];
                max_row = i + 1;
                max_col = j + 1;
            }
        }
        max_arr[i] = max;
    }

    max = 0;

    for (int i = 0; i < 9; i++) {
        if (max_arr[i] >= max)
            max = max_arr[i];
    }

    cout << max << endl;
    cout << max_row << " " << max_col << endl;

    return 0;
}