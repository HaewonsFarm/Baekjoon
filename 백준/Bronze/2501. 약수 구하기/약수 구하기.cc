#include <iostream>

using namespace std;

int main() {
    // 두 개의 자연수 n과 k가 주어졌을 때, N의 약수들 중 K번째로 작은 수를 출력하는 프로그램을 작성하시오.
    int n, k;
    cin >> n >> k;
    
    int flag = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            flag++;
            if (flag == k)
                cout << i << endl;
        }
    }

    if (flag < k)
        cout << 0 << endl;

    return 0;
}