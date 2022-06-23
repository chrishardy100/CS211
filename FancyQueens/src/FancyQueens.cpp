/*
* 
* This program finds every solution to the following problem:
*   Place eight queens on a board in such a way that none can attack each other.
*   No queen is in the diagonal, horizontal, or vertical path of another queen.
* and uses a graphic to display the solution.
* 
* Notes before starting:
* Empty spaces are denoted by ' '
* Spaces occupied by a queen are denoted by '='.
* 
* 
* @author Christopher Hardy
*/


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:


    // board is our old board
    vector<vector<int>> board;
    int boardSize = 8;
    int count = 0;

    typedef char box[5][7];
    box blackSpace, whiteSpace, * fancyBoard[8][8];

    box wq = { {' ',' ',' ',' ',' ',' ',' '},
                     {' ','=',' ','=',' ','=',' '},
                     {' ','=','=','=','=','=',' '},
                     {' ','=','=','=','=','=',' '},
                     {' ',' ',' ',' ',' ',' ',' '} };

    box bq = { {'=','=','=','=','=','=','='},
                    {'=',' ','=',' ','=',' ','='},
                    {'=',' ',' ',' ',' ',' ','='},
                    {'=',' ',' ',' ',' ',' ','='},
                    {'=','=','=','=','=','=','='} };


    Solution() {
        setupFancyPrint();
        board = createBoard(boardSize);
    }


    void setupFancyPrint() {
        //create the blackspace and white space in memory

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 7; j++) {
                blackSpace[i][j] = ' ';
                whiteSpace[i][j] = '=';
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0)
                    fancyBoard[i][j] = &whiteSpace;
                else
                    fancyBoard[i][j] = &blackSpace;
            }
        }

        //for (int i = 0; i < 8; i++) {
        //    for (int j = 0; j < 8; j++) {
        //        if (board[i][j] == 1) {
        //            if ((i + j) % 2 == 0)
        //                fancyBoard[i][j] = &bq;
        //            else
        //                fancyBoard[i][j] = &wq;
        //        }

        //    }
        //}

    }



    void showFancyBoard() {
        cout << "solution #: " << count << endl;
        count += 1;


        cout << " ";
        for (int i = 0; i < 7 * 8; i++)
            cout << '_';
        cout << endl;

        for (int i = 0; i < 8; i++) {          // for each board row
            for (int k = 0; k < 5; k++) {     // for each box row
                //cout << "";
                for (int j = 0; j < 8; j++) {   // for each board column
                    for (int l = 0; l < 7; l++) { // for each box column
                       // board[i][j] is the box pointer in the ith row, jth column of the board.
                       // *board[i][j] is the box being pointed to.
                       // (*board[i][j])[k][l] is the kth row, lth column of the box.

                        if (board[i][j] == 1) {
                            if ((i + j) % 2 == 0) {
                                cout << bq[k][l];
                            }
                            else cout << wq[k][l];

                        }

                        else cout << (*fancyBoard[i][j])[k][l];
                    }
                }
                cout << "" << "\n";
            }
        }

        cout << " ";
        for (int i = 0; i < 7 * 8; i++)
            cout << '~';
        cout << endl;


    }



    // Do not touch code below this line and above (look below)...

    vector<vector<int>> createBoard(int n) {
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }


        }
        return arr;
    }

    void showBoard() {
        cout << count++ << "\n";
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                cout << board[i][j] << "   ";
            }
            cout << "\n \n";
        }
        cout << "\n";
    }

    bool checkRow(int row, int currCol) {
        for (int i = 0; i < currCol; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }
        return true;
    }

    bool checkDiagonalUp(int row, int currCol) {
        for (int i = 1; (row - i > -1) and (currCol - i > -1); i++) {
            if (board[row - i][currCol - i] == 1) {
                return false;
            }
        }
        return true;
    }

    bool checkDiagonalDown(int row, int currCol) {

        for (int i = 0; (row + i < boardSize) and (currCol - i > -1); i++) {
            if (board[row + i][currCol - i] == 1) {
                return false;
            }
        }
        return true;
    }

    bool checkAll(int row, int currCol) {
        if (checkDiagonalDown(row, currCol) and checkRow(row, currCol) and checkDiagonalUp(row, currCol)) {
            return true;
        }
        else {
            return false;
        }
    }

    void helper(int currCol) {

        if (currCol >= boardSize) {
            //showBoard();
            showFancyBoard();
            cout << endl;
            return;
        }

        for (int i = 0; i < boardSize; i++) {
            if (checkAll(i, currCol)) {
                board[i][currCol] = 1;
                helper(currCol + 1);
                board[i][currCol] = 0;
            }
        }
    }

    void solveQueens() {
        helper(0);
    }


    //...and above this line EXCEPT FOR REPLACING showboard WITH showFancyBoard.



};

int main() {
    Solution s; // do not modify this line
    s.solveQueens();   // uncomment this line when you are ready to check final solution

    // use the rest of main to test your functions as you progrss.

    // s.showFancyBoard();



    cout << "finished";
    return 0;
}