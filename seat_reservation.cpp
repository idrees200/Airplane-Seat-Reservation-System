#include <iostream>
using namespace std;

char seats[13][6];

void logo() {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<   AIRPLANE SEAT RESERVATION   >>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
}

void displaySeats() {
    for (int i = 0; i < 13; i++) {
        cout << "ROW" << i << '\t';
        for (int j = 0; j < 6; j++) {
            cout << seats[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    logo();
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 6; j++) {
            seats[i][j] = '.';
        }
    }

    displaySeats();

    int count;
    do {
        int option;
        do {
            cout << "ENTER TICKET TYPE" << endl;
            cout << "1. FIRST CLASS " << endl;
            cout << "2. BUSINESS CLASS" << endl;
            cout << "3. ECONOMY CLASS" << endl;
            cin >> option;
        } while (option != 1 && option != 2 && option != 3);

        if (option == 1) {
            do {
                cout << "CHOOSE ANY SEAT BETWEEN 1-12 (ROW 0 - ROW 1)" << endl;
                cout << "ENTER DESIRED SEAT NO :" << endl;
                cin >> count;
                if (count < 1 || count > 12) {
                    cout << "TRY AGAIN AND ENTER FIRST CLASS SEAT NO !!!" << endl;
                }
            } while (count < 1 || count > 12);
        } else if (option == 2) {
            do {
                cout << "CHOOSE ANY SEAT BETWEEN 1-36 (ROW 2 - ROW 7)" << endl;
                cout << "ENTER DESIRED SEAT NO :" << endl;
                cin >> count;
                if (count < 1 || count > 36) {
                    cout << "TRY AGAIN AND ENTER BUSINESS CLASS SEAT NO !!!" << endl;
                } else {
                    count += 12;
                }
            } while (count < 13 || count > 48);
        } else if (option == 3) {
            do {
                cout << "CHOOSE ANY SEAT BETWEEN 1-30 (ROW 8 - ROW 12)" << endl;
                cout << "ENTER DESIRED SEAT NO :" << endl;
                cin >> count;
                if (count < 1 || count > 30) {
                    cout << "TRY AGAIN AND ENTER ECONOMY CLASS SEAT NO !!!" << endl;
                } else {
                    count += 48;
                }
            } while (count < 49 || count > 78);
        }

        int seatNumber = 0;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 6; j++) {
                seatNumber++;
                if (seatNumber == count) {
                    if (seats[i][j] == 'X') {
                        cout << "SEAT IS ALREADY OCCUPIED" << endl;
                    } else {
                        seats[i][j] = 'X';
                        cout << "YOUR SEAT IS RESERVED <<<<<    THANK YOU :)      >>>>>>>" << endl;
                    }
                }
            }
        }

        displaySeats();

    } while (count > 0 && count < 79);

    return 0;
}
