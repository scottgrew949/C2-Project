/*
    Grew, Scott (Team Leader)
    Teppei Yoshikawa

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"
#include <iostream>
#include <string>

using namespace std;

// Controlers ---------------------------------------------------
int DonationManager::addDonor(const string& donorName)
{
    Donor newDonor(donorName, nextDonorID);
    donors.insert(newDonor);
    return nextDonorID++;
}

void DonationManager::addCollege(const string& collegeCode, 
                                 const string& collegeName)
{
    colleges.addCollege(collegeCode, collegeName);
}

void DonationManager::addDonation(const string& donorName, 
                        const string& collegeCode, double anAmount)
{
    donations.addDonation(Donation(donorName, collegeCode, anAmount));
}

void DonationManager::addDonation(const int donorID, 
                    const std::string& collegeCode, double anAmount)
{
    for (const auto& donor : donors) 
    {
        if(donor.getDonorID() == donorID)
        {
            donations.addDonation(Donation(donor.getDonorName(), collegeCode, anAmount));
            break;
        }    
    }

}

// Printers -----------------------------------------------------
void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    double maxTotal = 0.0;
    string maxCollege = "";
    string maxCollegeName = "";
    
    for (auto& college : collegeMap) 
    {
        double total = getCollegeTotal(college.first);
        if (total > maxTotal) {
            maxTotal = total;
            maxCollege = college.first;
            maxCollegeName = college.second;
        }
    }
    
    cout << maxCollege << " (" << maxCollegeName << "): $" 
                        << maxTotal << endl;
}

void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    
    for (auto& college : collegeMap) 
    {
        bool isFound = false;
        cout << "\t" << college.first << " - " << college.second << endl;
        
        DonationNode* current = donations.getFirst();
        while (current != nullptr) 
        {
            if (current->data.getCollegeCode() == college.first) 
            {
                isFound = true;
                cout << "\t\t" << current->data.getDonorName() << " | $"
                                    << current->data.getAmount() << endl;
            }
            current = current->next;
        }

        if (!isFound)
            cout << "\t\t(no donation)" << endl;
    }
}

void DonationManager::printDonationsByDonor() const
{
      for (const auto& donor : donors) 
      {
        cout << "\tID " << donor.getDonorID() 
             << " - " << donor.getDonorName() << endl;
        
        DonationNode* current = donations.getFirst();
        while (current != nullptr) 
        {
            if (current->data.getDonorName() == donor.getDonorName()) 
            {
                string collegeCode = current->data.getCollegeCode();
                cout << "\t\t" << colleges.getCollegeName(collegeCode) 
                    << " (" << collegeCode << ")\n\t\tAmount: $"
                    << current->data.getAmount() << endl;
            }
            current = current->next;
        }
      }
}


void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    
    for (const auto& college : collegeMap) 
    {
        double total = getCollegeTotal(college.first);
        cout << college.first << " (" << college.second << "): " 
             << total << endl;
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const auto& donor : donors) 
    {
        double total = getDonorTotal(donor.getDonorName());
        cout << "ID: " << donor.getDonorID() << ", " 
             << donor.getDonorName() << ": " << total << endl;
    }
}

void DonationManager::printHighestDonor() const
{
    double maxTotal = 0.0;
    string maxDonor = "";
    
    for (const auto& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > maxTotal) {
            maxTotal = total;
            maxDonor = donor.getDonorName();
        }
    }
    
    cout << maxDonor << ": " << maxTotal << endl;
}

void DonationManager::printStatistics() const
{
    cout << "Number of Donors: " << donors.size() << endl;
    cout << "Number of Colleges: " << colleges.getColleges().size() 
            << endl;
    cout << "Number of Donations: " << donations.getNumOfDonations() 
            << endl;
}

void DonationManager::printColleges() const
{    
    for (const auto& college : this->colleges.getColleges()) 
    {
        cout << "\t" << college.first << " - " << college.second << endl;
    }
}

// Private ------------------------------------------------------
double DonationManager::getDonorTotal(const string& donorName) const
{
    DonationNode* current = donations.getFirst();
    
    while (current != nullptr) 
    {
        if (current->data.getDonorName() == donorName) 
        {
            return current->data.getAmount();
        }
        current = current->next;
    }
    
    return 0;
}

double DonationManager::getCollegeTotal(const string& collegeCode) const
{
    double total = 0.0;
    DonationNode* current = donations.getFirst();
    
    while (current != nullptr) 
    {
        if (current->data.getCollegeCode() == collegeCode) {
            total += current->data.getAmount();
        }
        current = current->next;
    }
    
    return total;
}

