#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int f, s, t, prize = 0;
    cin >> f >> s >> t;

    if (f == s && s == t) {
        prize = 10000 + f * 1000;
    } else if (f == s) {
        prize = 1000 + f * 100;
    } else if (s == t) {
        prize = 1000 + s * 100;
    } else if (f == t) {
        prize = 1000 + f * 100;
    } else {
        if (f >= s && f >= t)
            prize = f * 100;
        else if (s >= f && s >= t)
            prize = s * 100;
        else
            prize = t * 100;
    }

    cout << prize << endl;

    return 0;
}