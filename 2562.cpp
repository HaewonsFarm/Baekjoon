#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int arr[9];
    for (int i = 0; i < 9; i++)
        cin >> arr[i];

    int max_index, max = -1;
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i + 1;
        }
    }
    cout << max << endl << max_index << endl;

    return 0;
}