#include <iostream>

using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int daysInMonth(int y, int m) {
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) {
        return 29;
    }
    return month[m - 1];
}

int calculateDates(int y0, int m0, int d0, int y1, int m1, int d1) {
    int dayCount = 0;

    // 현재 연도와 D-day 연도가 같은 경우
    if (y0 == y1) {
        if (m0 == m1) {
            // 같은 월인 경우
            dayCount = d1 - d0;
        } else {
            // 다른 월인 경우
            dayCount += daysInMonth(y0, m0) - d0;
            for (int m = m0 + 1; m < m1; m++) {
                dayCount += daysInMonth(y0, m);
            }
            dayCount += d1;
        }
    } else {
        // 연도가 다른 경우
        dayCount += daysInMonth(y0, m0) - d0;
        for (int m = m0 + 1; m <= 12; m++) {
            dayCount += daysInMonth(y0, m);
        }

        for (int y = y0 + 1; y < y1; y++) {
            dayCount += isLeap(y) ? 366 : 365;
        }

        for (int m = 1; m < m1; m++) {
            dayCount += daysInMonth(y1, m);
        }
        dayCount += d1;
    }

    return dayCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y0, y1, m0, m1, d0, d1;
    cin >> y0 >> m0 >> d0
        >> y1 >> m1 >> d1;

    if (y1 - y0 > 1000 || (y1 - y0 == 1000 && (m1 > m0 || (m1 == m0 && d1 >= d0))))
        cout << "gg";
    else
        cout << "D-" << calculateDates(y0, m0, d0, y1, m1, d1);

    return 0;
}
