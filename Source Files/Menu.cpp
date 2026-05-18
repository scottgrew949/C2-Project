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
    cout << "\n" << string(13, '=') << " DONATION MENU " 
         << string(13, '=') << "\n\n";
    cout << "\t1. Add college\n"
         << "\t2. Add donation\n"
         << "\t3. Print colleges\n"
         << "\t4. Print donations by college\n"
         << "\t5. Print donations by donor\n"
         << "\t6. Print totals by college\n"
         << "\t7. Print totals by donor\n"
         << "\t8. Print statistics\n"
         << "\t9. Print highest donor\n"
         << "\t10. Print highest-funded college\n"
         << "\t0. Exit\n" << endl;
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

        if(choice == 1) 
        {
            string collegeCode, collegeName;
            cout << "Enter college code: ";
            cin >> collegeCode;
            cout << "Enter college name: ";
            cin.ignore();
            getline(cin, collegeName);
            manager.addCollege(collegeCode, collegeName);

            cout << "\n\t>>> College added.\n" << endl;
        }
        else if (choice == 2) 
        {
            int donationAmount = 0;
            string newDonorName, collegeName, collegeCode;
            cout << "Enter new donor name: ";
            cin.ignore();
            getline(cin, newDonorName);
            int tempID = manager.addDonor(newDonorName);
            cout << "\n\t>>> New donor ID: " << tempID << endl;

            cout << "\nEnter college code: ";
            cin >> collegeCode;

            cout << "Enter donation amount: ";
            cin >> donationAmount;
            manager.addDonation(tempID, collegeCode, donationAmount);
            cout << "\n\t>>> Donation added.\n" << endl;
        }
        else if (choice == 3) 
        {
            manager.printColleges();
            system("Pause");
        }
        else if(choice == 4)
        {
            manager.printDonationsByCollege();
            system("Pause");
        }
        else if(choice == 5)
        {
            manager.printDonationsByDonor();
            system("Pause");
        }
        else if (choice == 6)
        {
            manager.printTotalsByCollege();
            system("Pause");
        }
        else if (choice == 7)
        {
            manager.printTotalsByDonor();
            system("Pause");
        }
        else if (choice == 8)
        {
            manager.printStatistics();
            system("Pause");
        }
        else if (choice == 9)
        {
            manager.printHighestDonor();
            system("Pause");
        }
        else if (choice == 10)
        {
            manager.printCollegeWithHighestTotal();
            system("Pause");
        }
        else if (choice == 0)
        {
            cout << ">>>Logging out...";
        }
    }
}
