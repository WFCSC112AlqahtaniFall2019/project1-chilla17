#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main() {

    // declare and initialize 2D vectors (vector of vector)
    int row = 3; // initialize column and row for vector size
    int col = 3;
    vector <int> vec(col, 0); // first vector 3 columns
    vector <vector<int>> matrix(row, vec); // second vector 3 rows

    //produce random ship coordinates
    int x, y;
    srand(time(nullptr));

    x = (rand() % 3) + 1; // random row position
    y = (rand() % 3) + 1; // random column position

    // clear matrix, set all values to 0
    int i, j;
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            matrix.at(j).at(i) = 0;
        }
    }

    // set ship
    matrix.at(y-1).at(x-1) = 1; // subtract 1 from both the x and y coordinate because vector elements indexed from 0

    int tries = 1; // initialize number of tries/ guesses

    // game loop
    while (true) { // game loop to run until it is broken

        // user enter location guess
        int a, b;
        cout << "Guess location of battleship" << endl;
        cout << "Row (1-3): "; // prompt user to enter row
        cin >> a; // user input row value
        cout << "Column (1-3): "; // prompt user to enter column
        cin >> b; // user input column value

        // winning statement
        if (matrix.at(b-1).at(a-1) == 1) {
            cout << "You sunk my battleship!" << endl;

            // print matrix w/ correct guess
            for (i = 0; i < col; i++) {
                for (j = 0; j < row; j++) {
                    if (matrix.at(j).at(i) == 1) { // shows correct/ winning guess
                        cout << "| X |";
                    }
                    else if (matrix.at(j).at(i) == 2) { // shows past incorrect guesses
                        cout << "| o |";
                    }
                    else {
                        cout << "|   |"; // space not guessed
                    }
                }
                cout << endl;
            }
            cout << "(" << tries << " guesses)" << endl; // prints number of user guesses to screen
            break;
        }
        // lose - try again
        else {
            cout << "Miss! Try again." << endl;
            tries = tries + 1; // adds 1 to user's try count

            matrix.at(b-1).at(a-1) = 2; // sets incorrect coordinates to value 2

            // print matrix w/ incorrect guess(es)
            for (i = 0; i < col; i++) {
                for (j = 0; j < row; j++) {
                    if (matrix.at(j).at(i) == 2) {
                        cout << "| o |";
                    }
                    else {
                        cout << "|   |";
                    }
                }
                cout << endl;
            }

        }
    }


    return 0;
}