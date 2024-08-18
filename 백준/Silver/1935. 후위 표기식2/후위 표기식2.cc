#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  string postfix;  // 길이 100 이하의 A-Z의 영대문자
  cin >> postfix;

  double values[26];
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  stack<double> operandStk;

  for (char ch: postfix) {
    if (isalpha(ch)) {
      operandStk.push(values[ch - 'A']);
    } else {
      double operand2 = operandStk.top(); operandStk.pop();
      double operand1 = operandStk.top(); operandStk.pop();
      double result = 0.0;

      switch (ch) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          result = operand1 / operand2;
          break;
      }
      operandStk.push(result);
    }
  }

  cout << fixed;
  cout.precision(2);
  cout << operandStk.top() << endl;

  return 0;
}
