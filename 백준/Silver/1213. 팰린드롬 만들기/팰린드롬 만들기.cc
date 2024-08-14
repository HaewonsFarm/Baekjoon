#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  string name, palindrome;
  cin >> name;

  int alphabet[26] = {0,};
  for (int i = 0; i < name.size(); i++) {
    alphabet[name[i] - 'A']++;
  }

  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] % 2 == 1)
      cnt++;
  }
  if (cnt > 1) {
    cout << "I'm Sorry Hansoo";
    return 0;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < alphabet[i] / 2; j++) {
      palindrome += i + 'A';
    }
  }
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] % 2)
      palindrome += i + 'A';
  }
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < alphabet[i] / 2; j++) {
      palindrome += i + 'A';
    }
  }

  cout << palindrome << endl;

  return 0;
}
