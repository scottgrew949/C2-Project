/*
    Grew, Scott (Team Leader)
    Yoshikawa, Teppei 

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "DonationManager.h"
#include "FileLoader.h"

using namespace std;

int main()
{
    DonationManager manager;

    loadCollegesFromFile("Resource Files/colleges.csv", manager);
    loadDonationsFromFile("Resource Files/donations.csv", manager);

    cout << fixed << setprecision(2);

    processUserChoices(manager);

    cout << endl;
    system("Pause");
    return 0;
}