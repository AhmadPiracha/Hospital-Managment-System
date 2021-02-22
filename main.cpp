#include"Header.h"

int main() {

    int choice = 0;
    Admin A;
    Patient Pat;
    string pass1 = "Ahmad";
    string pass2 = "Ali";
    string password;
    string name;
    Doctor Doc;

    do {

        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t***********************************************************************************\n";
        cout << "\t\t\t\t\t***********************************************************************************\n";
        cout << "\t\t\t\t\t***********************************************************************************\n";
        cout << "\t\t\t\t\t=====================> WELCOME <===================================================\n";
        cout << "\t\t\t\t\t==============================> TO <===============================================\n";
        cout << "\t\t\t\t\t==================================> HOSPITAL <=====================================\n";
        cout << "\t\t\t\t\t============================================> MANAGEMENT <=========================\n";
        cout << "\t\t\t\t\t========================================================> SYSTEM <=================\n";
        cout << "\t\t\t\t\t***********************************************************************************\n";
        cout << "\t\t\t\t\t***********************************************************************************\n";
        cout << "\t\t\t\t\t***********************************************************************************\n";

        cout << "\n\n\t\t\t\t\tPress 1 to Enter HOSPITAL MANAGEMENT SYSTEM" << endl << endl;
        cin >> choice;
        cout << "\a" << endl;
        system("cls");
        switch (choice) {

        case 1:
            cout << "\n\n\t\t====================>  HOSPITAL MANAGEMENT SYSTEM <====================\n\n";

            cout << "1) ADMIN-MODULE\n";
            cout << "2) PATIENT-MODULE\n";
            cout << "3) DOCTOR-MODULE\n";
            cout << "4) EXIT\n\n";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Enter Your Name: ";
                cin >> name;
                cout << "Enter Your Password: ";
                cin >> password;
                if (password == pass1 || password == pass2) {
                    system("cls");

                    AdminModule(A);
                }
                else {
                    cout << "ERROR!!!!  Password is incorrect " << endl;
                }
                break;
            case 2:
                cout << "Enter Your Name: ";
                cin >> name;
                cout << "Enter Your Password: ";
                cin >> password;
                if (password == pass1 || password == pass2) {
                    system("cls");

                    PatientModule(Pat, A);
                }
                else {
                    cout << "ERROR!!!!  Password is incorrect " << endl;
                }
                break;
            case 3:
                cout << "Enter Your Name: ";
                cin >> name;
                cout << "Enter Your Password: ";
                cin >> password;
                if (password == pass1 || password == pass2) {
                    system("cls");

                    DoctorModule(Doc, A);
                }
                else {
                    cout << "ERROR!!!!  Password is incorrect " << endl;
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid Input................" << endl;
            }
            cout << "HMS Loging Out........................." << endl;
            system("pause");
            break;
        default:
            cout << "\t\t\t ERROR!!!   InValid Output\n\n";
            break;
        }
        cout << " Press 1 to go back to MAIN MENU or Press 0 to EXIT :" << endl;
        cin >> choice;
    } while (choice != 0);

}