#include <iostream>
using namespace std;

int main() {
    int q[8][8] = { 1 }, r, c = 0;

nextCol:
    ++c;
    if (c == 8)
        goto print;
    r = -1;

nextRow:
    ++r;
    if (r == 8)
        goto backtrack;

    // ok
    for (int i = 0; i < c; ++i)                    // row test
        if (q[r][i] == 1)
            goto nextRow;
    for (int i = 1; r - i >= 0 && c - i >= 0; ++i) // up-diagonal test
        if (q[r - i][c - i] == 1)
            goto nextRow;
    for (int i = 1; r + i < 8 && c - i >= 0; ++i)  // down-diagonal test
        if (q[r + i][c - i] == 1)
            goto nextRow;
    q[r][c] = 1;
    goto nextCol;

backtrack:
    --c;
    if (c < 0)
        return 0;
    for (r = 0; q[r][c] != 1; ++r);
    q[r][c] = 0;
    goto nextRow;

print:
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ":\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << q[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;
    goto backtrack;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
