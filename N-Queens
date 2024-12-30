#include <iostream>
#include <vector>
using namespace std;

// 퀸이 board[row][col]에 놓일 수 있는지 체크하는 함수
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // 위쪽 행에서 같은 열이 있는지 체크
    for (int i = 0; i < row; ++i) {
        if  (board[i][col] == 1)
            return false;
    }

    // 왼쪽 대각선 체크
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) 
            return false;
    }

    // 오른쪽 대각선 체크
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// N-Queens 문제를 풀기 위한 백트래킹 함수
bool solveNQueenUtil(vector<vector<int>>& board, int row, int N) {
    // 베이스 케이스: 모든 퀸들이 배치되었을 경우, true 반환
    if (row >= N)
        return true;

    // 현재 행의 각 열에 퀸 배치 시도
    for (int col = 0; col < N; ++col) {
        // board[row][col]에 퀸을 배치하는 게 안전한지 체크
        if (isSafe(board, row, col, N)) {
            // 퀸 배치
            board[row][col] = 1;

            // 남은 행에 퀸을 배치하도록 재귀
            if (solveNQueenUtil(board, row + 1, N))
                return true;
            
            // 퀸을 여기에 배치하는 것이 해에 도달하지 않으면, 백트래킹
            board[row][col] = 0;  // 퀸 제거
        }
    }

    // 어떤 열도 안되면 false 반환
    return false;
}

// N-Queens 문제를 푸는 함수
void solveNQueens(int N) {
    // 체스보드를 0으로 초기화
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueenUtil(board, 0, N)) {
        cout << "Solution for " << N << "-Queens:\n";
        for (const auto& row: board) {
            for (int cell: row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for " << N << "-Queens.\n";
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
