#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int N, M, i, j, temp;
    cin >> N >> M;

    int arr[N];

    for (int l = 0; l < N; l++) {
        arr[l] = l + 1;
    }

    for (int l = 0; l < M; l++) {
        cin >> i >> j;
        temp = arr[i-1];
        arr[i-1] = arr[j-1];
        arr[j-1] = temp;
    }

    for (int l = 0; l < N; l++) {
        cout << arr[l] << " ";
    }


    return 0;
}