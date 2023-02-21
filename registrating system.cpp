/*               REGISTRATING AND LOGIN SYSTEM
In lines 14 and 34 you can change the place for saving usernames and passwords  */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool IsLoggedIn() {
    string yourName, yourPword, realName, realPword;

    cout << "Enter username: "; cin >> yourName;
    cout << "Enter password: "; cin >> yourPword;

    ifstream read("D:" + yourName + ".txt");        // Storage for the data can be changed. I use a flesh drive (for testing).
    getline(read, realName);
    getline(read, realPword);

    if (yourName==realName && yourPword==realPword) {return true;}
    else {return false;}}

    int main() {
        int choice;
        cout << "                                  BEGINNING" << endl;
        cout << "Choose an option." << endl << "1: Register" << endl << "2: Login" << endl << "3: Finish" << endl << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
                cout << endl << "                                  REGISTRATION" << endl;
                string yourName, yourPword;
                cout << "Select a name: "; cin >> yourName;
                cout << "Select a password: "; cin >> yourPword;

                ofstream file;
                file.open("D:" + yourName + ".txt");
                file << yourName << endl << yourPword;
                file.close();

                cout << endl << "You're registrated! Now log in." << endl << endl;

                main();
        }
        else if (choice==2) {
                cout << endl << "                                  AUTORISATION" << endl;

                bool status = IsLoggedIn();

                if (!status) {
                        cout << endl << "False Login!" << endl << endl;
                        main();
                }
                else {cout << endl << "Successfully logged in!" << endl; return 0;}
        }
        else if (choice==3) {cout << endl << "Have a good day!" << endl;}
        else {cout << "                                    ERROR" << endl; main();}
        return 0;}
