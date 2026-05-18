/*
    Grew, Scott (Team Leader)
    Teppei Yoshikawa

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "FileLoader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void loadCollegesFromFile(const string& fileName, 
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        string line;
        while(getline(inFile, line))
        {
            if (!line.empty() && line.back() == '\r')
                line.pop_back();

            stringstream ss(line);
            string code, name;
            getline(ss, code, ',');
            getline(ss, name, ',');
            manager.addCollege(code, name);
        }


        inFile.close();
        cout << "=> College data loaded...\n";
    }
    else
    {
        cout << "=> Could not open " << fileName << "." << endl;
    }
}

void loadDonationsFromFile(const string& fileName, 
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        string line;
        while (getline(inFile, line))
        {
            if (!line.empty() && line.back() == '\r')
                line.pop_back();

            stringstream ss(line);
            string donorName, collegeCode, amountStr;
            getline(ss, donorName, ',');
            getline(ss, collegeCode, ',');
            getline(ss, amountStr, ',');
            double amount = stod(amountStr);
            manager.addDonor(donorName);
            manager.addDonation(donorName, collegeCode, amount);
        }

        inFile.close();
        cout << "=> Donation data loaded...\n"; 
    }
    else
    {
        cout << "=> Could not open " << fileName << "." << endl;
    }
}