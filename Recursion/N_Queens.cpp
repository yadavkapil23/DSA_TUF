#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
    // check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, int n, vector<string> &board) {
    if (row == n) {
        // print the board
        for (auto &r : board)
            cout << r << endl;
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';   // place queen
            solve(row + 1, n, board); // move to next row
            board[row][col] = '.';   // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    solve(0, n, board);
}
