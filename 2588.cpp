#include <iostream>

using namespace std;

int main()
{
    int first, second, onesDgt, tensDgt, hdrsDgt;

    cin >> first; cin >> second;
    hdrsDgt = (second) / 100;
    tensDgt = (second % 100) / 10;
    onesDgt = (second % 10);
    cout << first * onesDgt << endl
    << first * tensDgt << endl
    << first * hdrsDgt << endl
    << first * second << endl;
    return 0;
}