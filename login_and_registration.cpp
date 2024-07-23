#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if a username already exists
bool isUsernameTaken(const string& user) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        if (line.find(user) == 0) {
            return true;
        }
    }
    return false;
}

// Function to register a new user
void registerUser() {
    string user, pass;
    cout << "Enter username: ";
    cin >> user;

    if (isUsernameTaken(user)) {
        cout << "Username is already taken. Please choose another one." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> pass;

    ofstream file;
    file.open("users.txt", ios::app);
    if (file.is_open()) {
        file << user << " " << pass << endl;
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Function to login a user
bool loginUser() {
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    ifstream file("users.txt");
    string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == user && storedPass == pass) {
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Invalid username or password." << endl;
    return false;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
