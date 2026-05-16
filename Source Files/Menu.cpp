/*
	(name header)
*/


#include "Menu.h"
#include "DonationManager.h"


#include <iostream>
#include <string>


using namespace std;


// Definition of function displayMenu
// Your code here…
void displayMenu()
{
    cout << string(13, '=') << " DONATION MENU " << string(13, '=') 
        << "\n\n";
    cout << "\t\t1. Add college\n"
         << "\t\t2. Add donation\n"
         << "\t\t3. Print colleges\n"
         << "\t\t4. Print donations by college\n"
         << "\t\t5. Print donations by donor\n"
         << "\t\t6. Print totals by college\n"
         << "\t\t7. Print totals by donor\n"
         << "\t\t8. Print statistics\n"
         << "\t\t9. Print highest donor\n"
         << "\t\t10. Print highest-funded college\n"
         << "\t\t0. Exit\n" << endl;
}


// Definition of function processUserChoices
// Your code here...
void processUserChoices(DonationManager& manager)
{
    int choice = -1;
    while(choice != 0)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (cin.fail())
        {
            // Check? Error not necessary for now?
        }

        if(choice == 1) 
        {
            string collegeCode, collegeName;
            cout << "\nEnter college code: ";
            cin >> collegeCode;
            cout << "\nEnter college name: ";
            getline(cin, collegeName);
            manager.addCollege(collegeCode, collegeName);

            cout << "\t\t>>> College added.\n" << endl;
            system("pause");
            // Need to handle the output here for waiting and pressign any key
            // Error handling?

        }
        else if (choice == 2) 
        {
            int donationAmount = 0;
            string newDonorName, collegeName, collegeCode;
            cout << "\nEnter new donor name: ";
            getline(cin, newDonorName);
            cout << "\t\t>>> New donor ID: " << manager.addDonor(newDonorName) << endl;

            cout << "\nEnter college code: ";
            cin >> collegeCode;

            cout << "\n\nEnter donation amount: ";
            cin >> donationAmount;
            cout << "\n\n\t\t>>> College added.\n" << endl;

            system("pause");
            // Need to handle the output here for waiting and pressign any key
            // Error handling?
        }
        else if (choice == 3) 
        {
            manager.printColleges();

            system("pause");
            // Need to handle the output here for waiting and pressign any key
            // Error handling?
        }
        else if (choice == 4) 
        {
            manager.printDonationsByDonor();

            system("pause");
            // Need to handle the output here for waiting and pressign any key
            // Error handling?
        }
        else if (choice == 5) 
        {
            manager.printDonationsByDonor();

            system("pause");
            // Need to handle the output here for waiting and pressign any key
            // Error handling?
        }
        else if (choice == 6) 
        {

        }
        else if (choice == 7) 
        {

        }
        else if (choice == 8) 
        {

        }
        else if (choice == 9) 
        {

        }
        else if (choice == 10) 
        {

        }
        else if (choice == 0) 
        { break; }

    }
}
