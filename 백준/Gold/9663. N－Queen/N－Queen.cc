#include <iostream>
#include <vector>
using namespace std;

int solCount = 0; // 가능한 배치의 수를 저장

// 현재 위치에 퀸을 놓아도 안전한지 확인하는 함수
bool isSafe(const vector<int>& board, int row, int col, int N) {
    for (int i = 0; i < row; ++i) {
        // 같은 열에 있거나 대각선에 있으면 false
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Backtracking 함수
void solveNQueens(vector<int>& board, int row, int N) {
    if (row == N) {
        // 모든 퀸을 배치한 경우
        ++solCount;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row] = col;       // 퀸을 배치
            solveNQueens(board, row + 1, N); // 다음 행으로 이동
            board[row] = -1;       // 백트래킹 (배치 취소)
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 체스판을 나타내는 배열 초기화
    vector<int> board(N, -1);

    // N-Queens 문제 해결
    solveNQueens(board, 0, N);

    // 가능한 배치의 수 출력
    cout << solCount << endl;
    return 0;
}