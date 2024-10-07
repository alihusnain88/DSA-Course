#include <iostream>
#include <vector>

using namespace std;

const int N = 3;

char board[N][N];

void initializeBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = ' '; 
        }
    }
}

bool checkWin(char player) {
    // Checking rows, columns, and diagonals
    for (int i = 0; i < N; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "-";
        }
        cout << endl;
    }
        cout <<"---------------------\n";
}

pair<int, int> findBestMove() {
    // Checking for center
    if (board[1][1] == ' ') {
        return make_pair(1, 1);
    }

    // Checking for empty corners
    for (int i = 0; i < N; i += 2) {
        for (int j = 0; j < N; j += 2) {
            if (board[i][j] == ' ') {
                return make_pair(i, j);
            }
        }
    }

    // Checking for empty sides
    for (int i = 0; i < N; i++) {
        if (board[i][1] == ' ') {
            return make_pair(i, 1);
        }
        if (board[1][i] == ' ') {
            return make_pair(1, i);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == ' ') {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1); 
}

int main() {
    vector<pair<int, int>> georgeMoves = {{1, 1}, {2, 2}, {3, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 1},{3, 1},{3, 2}};

    initializeBoard();

    char currentPlayer = 'O'; 

    while (true) {
        printBoard();

        if (currentPlayer == 'O') {
            int row = georgeMoves.back().first - 1;
            int col = georgeMoves.back().second - 1;
            georgeMoves.pop_back();

            if (board[row][col] != ' ') {
                cout << "Invalid move!" << endl;
                continue;
            }

            board[row][col] = 'O';
        } else {
            pair<int, int> bestMove = findBestMove();
            board[bestMove.first][bestMove.second] = 'X';
        }

        if (checkWin(currentPlayer)) {
            printBoard();
            cout << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "It's a tie!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
        
    }

    return 0;
}
