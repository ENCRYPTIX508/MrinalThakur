#include <iostream>
#include <string>
using namespace std;

char arr[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int choice;
int row, column;
char chance = 'X';
bool draw = false;
string name1;
string name2;
int number;
void start(){
	cout << "Enter the name of player 1:\n";
    cin >> name1;
    cout << "Enter the name of player 2:\n";
    cin >> name2;
    cout << name1 << " will play first with X\n";
    cout << name2 << " will play with O\n";
}

void setup() {
	cout<<"tt     |     |     n";
    cout<<"tt  "<<arr[0][0]<<"  | "<<arr[0][1]<<"  |  "<<arr[0][2]<<" n";
    cout<<"tt_____|_____|_____n";
    cout<<"tt     |     |     n";
    cout<<"tt  "<<arr[1][0]<<"  | "<<arr[1][1]<<"  |  "<<arr[1][2]<<" n";
    cout<<"tt_____|_____|_____n";
    cout<<"tt     |     |     n";
    cout<<"tt  "<<arr[2][0]<<"  | "<<arr[2][1]<<"  |  "<<arr[2][2]<<" n";
    cout<<"tt     |     |     n";         
    
}

void game() {
    if (chance == 'X') {
        cout << name1 << " it is your chance:\n";
    }
    else if (chance == 'O') {
        cout << name2 << " it is your chance:\n";
    }
    cout << "Enter the place:\n";
    cin >> number;

    switch (number) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
        return;
    }

    if (chance == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        arr[row][column] = 'X';
        chance = 'O';
    }
    else if (chance == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        arr[row][column] = 'O';
        chance = 'X';
    }
    else {
        // if input position already filled
        cout << "Box already filled! Please choose another!!\n";
        game();
    }
    setup();
}

bool result() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
            return false;
        }
    }
    if ((arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 'X' && arr[i][j] != 'O') {
                return true;
            }
        }
    }
    draw = true;
    return false;
}

int main() {
    cout << "************* TIC TAC TOE *************\n";
    cout << "WELCOME TO THE GAME\n";
    start();
    setup();
    while (result()) {
        game();
    }
    if (chance == 'O' && draw == false) {
        cout << name1 << " you won the game!\n";
    }
    else if (chance == 'X' && draw == false) {
        cout << name2 << " you won the game!\n";
    }
    else {
        cout << "Game is a draw!\n";
    }

    return 0;
}
