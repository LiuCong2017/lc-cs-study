/**
 * 1 - login
 * 2 - registration
 * 3 - forgot password
 * 5 - exit
 */

#include <iostream>
#include <fstream>

using namespace std;

// call functions
void login();
void registration();
void forgotPassword();

int main()
{
    int choice;

    cout << "-------------- WELCOME --------------\n";
    cout << "::Select Action::\n\n";

    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Forgot Password\n";
    cout << "4. Exit\n\n";

    cout << "Enter your choice: ";
    cin >> choice;

    cout << endl;


    //handle choice
    switch (choice) {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            system("cls");
            forgotPassword();
            break;

        case 4:
            system("cls");
            cout << "Thank you for using this app." << endl;
            break;

        default:
            system("cls");
            cout << "-- Invalid number " << choice << " --" << endl;
            main();
    }
    return 0;
}

//login function
void login() {
    int count = 0;
    string userId, password, id, pass;

    system("cls");

    cout << "::Enter the username and password::\n\n" << endl;

    cout << "Username: ";
    cin >> userId;

    cout << "Password: ";
    cin >> password;

    ifstream input("users.txt");

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1) {
        cout << "Login Successful!\n\n" << userId << endl;
        main();
    }
    else {
        cout << "\n-- Username or password is invalid. --" << endl;
    }
}

//register function
void registration() {
    string userId, password, id, pass;
    system("cls");

    cout << "::Enter the username and password::\n\n" << endl;

    cout << "Username: ";
    cin >> userId;

    cout << "Password: ";
    cin >> password;

    ofstream newUser("users.txt", ios::app);

    newUser << userId << ' ' << password << endl;
    system("cls");

    cout << "-- Registration Successful! --\n\n" << endl;
    main();
}

//forgot password function
void forgotPassword() {
    int option;

    cout << "::Forgot Password::\n\n" << endl;

    cout << "1. Search by username" << endl;
    cout << "2. Go Back\n" << endl;

    cout << "Select option: ";
    cin >> option;


    switch (option) {
        case 1 : {
            int count = 0;
            string userId, password, id, pass;

            cout << "Enter your username: ";
            cin >> userId;

            ifstream users("users.txt");

            while (users >> id >> pass) {
                if (id == userId) {
                    count = 1;
                }
            }

            users.close();

            if (count == 1) {
                system("cls");
                cout << "-- User Found --\n" << endl;
                cout << "Username: " << userId << endl;
                cout << "Password: " << pass << endl;
            }
            else {
                system("cls");
                cout << "Account doesn't exist!\n" << endl;
                main();
            }

            break;
        }

        case 2: {
            system("cls");
            main();
        }

        default:
            system("cls");
            cout << "-- Invalid number " << option << " --" << endl;
            forgotPassword();
    }
}