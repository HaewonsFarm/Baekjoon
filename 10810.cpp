#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int N, M, i, j, k;
    cin >> N >> M;
    int arr[N];

    for (int l = 0; l < N; l++)
        arr[l] = 0;

    for (int l = 0; l < M; l++) {
        cin >> i >> j >> k;
        for (int t = i - 1; t < j; t++) {
            arr[t] = k;
        }
    }

    for (int l = 0; l < N; l++) {
        cout << arr[l] << " ";
    }


    return 0;
}