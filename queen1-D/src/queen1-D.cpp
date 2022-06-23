#include <iostream>
#include <cmath>
using namespace std;


struct Board {
    // create an array of all zeros
    int board[8] = { 0 };
    int solution = 0;
    bool done = false;
    // Print the board
    void printBoard() {
        cout << "solution " << ++solution << endl;
        for (int i = 0; i < 8; ++i) {
            cout << board[i] << "  ";
        }
        cout << endl << endl;
    }
    bool checkLeft(int c) {
        for (int i = 0; i < c; ++i) {
            // Queens are on the same row

            if (board[i] == board[c]) {
                return false;
            }
        }
        return true;
    }
    bool checkDiagonalUp(int c) {
        int row = board[c];
        for (int i = 1; (board[c] - i >= 0) && (c - i >= 0); i++) {
            if (board[c] - i == board[c - i]) {
                return false;
            }
        }
        return true;
    }
    bool checkDiagonalDown(int c) {
        int row = board[c];
        for (int i = 1; (board[c] + i < 8) && (c - i >= 0); i++) {
            if (board[c] + i == board[c - i]) {
                return false;
            }
        }
        return true;
    }
    bool ok(int c) {
        // c represents the row of the observed queen.
        if (checkLeft(c) && checkDiagonalUp(c) && checkDiagonalDown(c)) {
            return true;
        }
        else {
            return false;
        }
    }
    void solve() {
        int c = 0;

        // if we backtrack beyond the first col, we are done
        while (c >= 0) {

            //cout << "board[" << c << "] = " << board[c] << endl;
            if (c > 7) {
                // print the board
                printBoard();
                // backtrack
                --c;
                ++board[c];
                continue;

            }
            // If we have moved bey the last row 
            if (board[c] > 7) {
                
                // reset queen
                board[c] = 0;
                // backtrack
                --c;
                ++board[c];
                continue;
            }
            // Check if the placed queen is ok.
            else if (ok(c)) {
                // move to next column if ok
                ++c;
            }

            else
                ++board[c];
            

        }

    }
};

int main() {
    // Note: Correct algorithm will give you 92 solutions
    Board b;
    b.solve();

    // Check Left
    for (int i = 0; i < 8; ++i)
        cout << b.checkLeft(i) << endl;
    cout << endl;
    // Check Diag Up
    for (int i = 0; i < 8; ++i)
        cout << b.checkDiagonalUp(i) << endl;
    cout << endl;
    // Check Diag Down
    for (int i = 0; i < 8; ++i)
        cout << b.checkDiagonalDown(i) << endl;
    cout << endl;

    cout << "finished";
    return 0;
}