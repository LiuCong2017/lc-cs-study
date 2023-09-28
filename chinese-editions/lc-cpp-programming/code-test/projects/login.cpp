

#include <iostream>
using namespace std;

int main ()
{
    string name;
    string password;
    int login_Attempt = 0;

    while (login_Attempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> name;
        cout << "Please enter your user password: ";
        cin >> password;

        if (name == "Kavin" && password == "Kavin")
        {
            cout << "Welcome Kavin!\n";
            break;
        }
        else if (name == "Cody" && password == "Cody")
        {
            cout << "Welcome Cody!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            login_Attempt++;
        }
    }
    if (login_Attempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Thank you for logging in.\n";
}
