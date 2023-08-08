#include<iostream>
#include<fstream>
#include<string> // Include this header for using string data type
using namespace std;

void LOGIN();
void REGISTRATION();
void FORGOT();

int main(){
    int c ;
    cout<<"\t\t\t_______________________________________________\n\n\n";
    cout<<"\t\t\t              WELCOME TO THE LOGIN PAGE         \n\n\n";
    cout<<"\t\t\t______________       MENU              __________\n\n\n";
    cout<<"                                                        \n\n\n";
    cout<<"\t|PRESS 1 TO LOGIN                      |"<<endl;
    cout<<"\t|PRESS 2 TO REGISTRATION               |"<<endl;
    cout<<"\t|PRESS 3 TO FORGOT                     |"<<endl;
    cout<<"\t|PRESS 4 TO EXIT                       |"<<endl;
    cout<<"\n\t\t PLEASE ENTER YOUR CHOICE : ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            LOGIN();
            break;
        case 2:
            REGISTRATION();
            break;
        case 3:
            FORGOT();
            break;
        case 4:
            cout<<"\t\t\t  THANK YOU! \n\n\n";
            break;
        default :
            system("cls");
            cout<<"\t\t\t PLEASE SELECT FROM THE GIVEN OPTIONS ABOVE \n";
            main();
    }
    return 0; // Added return statement
}

void LOGIN(){
    int count = 0; // Initialize count to 0
    string userId, password, Id, pass;
    system("cls");
    cout<<"\t\t\t PLEASE ENTER THE USER NAME AND PASSWORD : "<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;

    ifstream input("records.txt");
    while(input >> Id >> pass){
        if(Id == userId && pass == password){
            count = 1;
            break; // Break the loop once the match is found
        }
    }
    input.close();
    if(count == 1){
        ofstream output("login_history.txt", ios::app); // Corrected the ofstream object name
        output << userId << "\n Your LOGIN is Successful \n Thanks for logging in !\n";
        output.close();
        cout << userId << "\n Your LOGIN is Successful \n Thanks for logging in !\n";
    }
    else{
        cout << "\n LOGIN Error \n Please Check Your Username And Password \n";
    }
}

void REGISTRATION(){
    string ruserId, rpassword; // Corrected variable names
    system("cls");
    cout << "\t\t\t ENTER THE USERNAME : ";
    cin >> ruserId;
    cout << "\t\t\t ENTER THE PASSWORD :  ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close(); // Close the ofstream object
    system("cls");
    cout << "\n\t\t\t Registration is successful!  \n";
}

void FORGOT(){
    int option;
    system("cls");
    cout << "\t\t\t FORGOT PASSWORD? NO WORRIES \n";
    cout << "PRESS 1 TO SEARCH YOUR ID BY USERNAME" << endl;
    cout << "PRESS 2 TO GO BACK TO THE MAIN MENU" << endl;
    cout << "\t\t\t  ENTER YOUR CHOICE : ";
    cin >> option;
    switch(option){
        case 1:
            {
                int count = 0;
                string suserId, sId, spass;
                cout << "\n\t\t\t ENTER THE USERNAME WHICH YOU REMEMBERED ";
                cin >> suserId;
                ifstream f2("records.txt");
                while(f2 >> sId >> spass){
                    if(sId == suserId){
                        count = 1;
                        break; // Break the loop once the match is found
                    }
                }
                f2.close();
                if(count == 1){
                    cout << "\n\n Your account is found! \n";
                    cout << "\n\n Your password is: " << spass << endl;
                }
                else{
                    cout << "\n\t Sorry! Your account is not found!\n";
                }
                break;
            }
        default:
            cout << "\n\t Invalid option!\n";
            break;
    }
}

