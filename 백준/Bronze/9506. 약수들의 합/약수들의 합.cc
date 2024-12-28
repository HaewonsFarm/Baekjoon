#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 어떤 숫자 n이 자신을 제외한 모든 약수들의 합과 같으면 완전수
    int n = 0;

    while (true) {
        cin >> n;
        if (n == -1) break;

        vector<int> factors;  // 각 숫자마다 새로 약수 목록 초기화
        int sum = 0;

        // 약수 구하기
        for (int i = 1; i <= n/2; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                sum += i;  // 동시에 합 계산
            }
        }

        // 완전수 검사
        if (sum == n) {
            cout << n << " = ";
            for (size_t i = 0; i < factors.size(); i++) {
                cout << factors[i];
                if (i < factors.size() - 1) {
                    cout << " + ";
                }
            }
            cout << endl;
        } else {
            cout << n << " is NOT perfect." << endl;
        }
    }

    return 0;
}