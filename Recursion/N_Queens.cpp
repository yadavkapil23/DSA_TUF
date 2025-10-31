#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
    // check column
    for (int i = 0; i < row; i++) //This checks if any Queen is already placed in the same column above this row
        if (board[i][col] == 'Q') return false;

    // check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) //Move up-left (↖️ direction)., Decrease both row and col each time.
        if (board[i][j] == 'Q') return false;

    // check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) //Move up-right (↗️ direction).,Decrease row, increase col.
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, int n, vector<string> &board) { //to place queen in each row
    if (row == n) {
        for (auto &i : board)
            cout << i << endl;
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';   // place queen
            solve(row + 1, n, board); // move to next row , recursive call
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
