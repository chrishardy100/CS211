

// EightNumbersInACross.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;



    int checkArray[8][5] = { {-1},                  // 0
                            {0, -1},                // 1
                            {0, -1},                // 2
                            {0, 1, 2, -1},          // 3
                            {0, 1, 3, -1},          // 4
                            {1, 4, -1},             // 5
                            {2, 3, 4, -1},          // 6
                            {3, 4, 5, 6, -1}        // 7
    };
    void printCross(int *cross) {
        cout << "   " << cross[0] << "  " << cross[1] << endl;
        cout << cross[2] << "  " << cross[3] << "  " << cross[4] << "  " << cross[5] << endl;
        cout << "   " << cross[6] << "  " << cross[7] << endl;
        cout << endl;
        return;
    }
    bool alreadyPlaced(int *cross, int place) {
        for (int i = 0; i < place; i++) {
            if (cross[i] == cross[place])
                return true;
        }
        return false;
    }
    bool okAdjacent(int *cross, int place) {
        for (int i = 0; checkArray[place][i] != -1; ++i)
            if (abs(cross[checkArray[place][i]] - cross[place]) == 1)
                return false;
        return true;
    }
    bool ok(int * cross, int place) {
        if (!alreadyPlaced(cross, place) && okAdjacent(cross, place)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void solve(int *cross, int c) {
       
        if (c == 8) {
            printCross(cross);
            return;
        }

        // Recusion
        for (int j = 0; j < 8; j++) {
            
            cross[c] = j;
            if (ok(cross, c)) 
                solve(cross, c+1);
            
        }
    }


int main() {
    int cross[8] = { 1,1,1,1,1,1,1,1 };

    
    solve(cross, 0);

    cout << "finished" << endl;
}