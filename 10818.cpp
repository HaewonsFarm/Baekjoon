#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int min_value = numeric_limits<int>::max();  // min_value == 2,147,483,647
    int max_value = numeric_limits<int>::min();  // max_value == -2,147,483,647

    for (int i = 0; i < n; ++i) {
        if (numbers[i] < min_value) {
            min_value = numbers[i];  // 더 작은 값으로 min_value 계속 갱신.
        }
        if (numbers[i] > max_value) {
            max_value = numbers[i];  // 더 큰 값으로 max_value 계속 갱신.
        };
    }

    cout << min_value << " " << max_value << endl;

    return 0;
}