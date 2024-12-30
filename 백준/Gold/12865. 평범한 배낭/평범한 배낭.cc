#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsackDP(int n, int capacity, vector<pair<int, int>>& items) {
    // DP 테이블 초기화 (capacity + 1 크기)
    vector<int> dp(capacity + 1, 0);

    // DP 계산
    for (int i = 0; i < n; ++i) {
        int weight = items[i].first;
        int value = items[i].second;
        // 배낭의 용량을 거꾸로 탐색하여 물건을 담는 경우를 처리
        for (int j = capacity; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    return dp[capacity]; // 최대 가치 반환
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second; // 물건의 무게와 가치 입력
    }

    cout << knapsackDP(n, capacity, items) << endl;

    return 0;
}