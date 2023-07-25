#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool isLoggedIn(){

    string user, password, un, pw;

    cout << "Enter your username : ";
    cin >> user;

    cout << "Enter your password : ";
    cin >> password;

    ifstream file(user + ".txt");

    getline(file,un);
    getline(file,pw);

    if( user == un && password == pw ){
        return true;
    }
    
    return false;
}

int main(){
    int option;

    cout << "1. Register a user\n2. Login to account\nCurrent Option : ";
    cin >> option;

    if(option == 1){
        string user, password;

        cout << "Enter a username : "; cin >> user;
        cout << "Enter a password : "; cin >> password;

        ofstream file(user + ".txt");

        if(file.is_open()){
            file << user << endl << password << endl;
            file.close();
            cout << "User registered successfully!" << endl;

        }


        main();

    }else if(option == 2){
        bool state = isLoggedIn();

        if(state == false){
            cout << "Invalid Login!" << endl;

        }else{
            cout << "Successfully Logged In!" << endl;
        }

    }else{
        cout << "Invalid Option, Try Again!" << endl;
        main();
    }

    return 0;
}