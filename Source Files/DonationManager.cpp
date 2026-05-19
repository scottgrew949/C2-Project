/*
    Grew, Scott (Team Leader)
    Yoshikawa, Teppei 

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"
#include <iostream>
#include <string>
#include<list>

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
            donations.addDonation(Donation(donor.getDonorName(), 
                                        collegeCode, anAmount));
            break;
        }    
    }

}

// Printers -----------------------------------------------------
void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    double maxTotal = 0.0;
    list<string> maxCollege;
    list<string> maxCollegeName;
    double total = 0.00;

    
    for (auto& college : collegeMap) 
    {
        total = getCollegeTotal(college.first);
        if (total > maxTotal) {
            maxTotal = total;
            maxCollege.clear();
            maxCollegeName.clear();
            maxCollege.push_back(college.first);
            maxCollegeName.push_back(college.second);
        }
        else if (total == maxTotal)
        {
            maxCollege.push_back(college.first);
            maxCollegeName.push_back(college.second);
        }
    }
    
    cout << "\tCollege(s) with highest total donation:" << endl;
    auto collegeEnd = maxCollege.end();
    auto collegeNameEnd = maxCollegeName.end();
    auto collegeIter = maxCollege.begin();
    auto collegeNameIter = maxCollegeName.begin();

    while (collegeIter != collegeEnd && collegeNameIter != collegeNameEnd)
    {
        cout << "\t    " << *collegeNameIter << " (" << *collegeIter 
            << ")" << endl;
        ++collegeIter;
        ++collegeNameIter;
    }

    cout << "\t    Highest total recieved: $" << maxTotal << endl;
}

void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    
    for (auto& college : collegeMap) 
    {
        bool isFound = false;
        cout << "\t" << college.first << " - " << college.second 
            << endl;
        
        DonationNode* current = donations.getFirst();
        while (current != nullptr) 
        {
            if (current->data.getCollegeCode() == college.first) 
            {
                isFound = true;
                cout << "\t    " << current->data.getDonorName() 
                    << " | $" << current->data.getAmount() << endl;
            }
            current = current->next;
        }

        if (!isFound)
            cout << "\t    (no donation)" << endl;
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
        cout << "\t" << college.first << " - " << college.second 
            << "\n\t    " << "Total donation amount: $" << total 
            << endl;
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const auto& donor : donors) 
    {
        double total = getDonorTotal(donor.getDonorName());
        cout << "\t(ID " << donor.getDonorID() << ") " 
             << donor.getDonorName() << " | $" << total << endl;
    }
}

void DonationManager::printHighestDonor() const
{
    double maxTotal = 0.0;
    list<string> maxDonor;
    
    for (const auto& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > maxTotal) {
            maxTotal = total;
            maxDonor.clear();
            maxDonor.push_back(donor.getDonorName());
        }
        else if (total == maxTotal)
        {
            maxDonor.push_back(donor.getDonorName());
        }
    }
    
    
    cout << "\tHighest donor(s):\n";
        for (const string& name : maxDonor)
        {
            cout << "\t    " << name << endl;
        }
    cout << "\t    Highest amount donated: $" << maxTotal << endl;
}

void DonationManager::printStatistics() const
{
    cout << "\tNumber of Donors: " << donors.size() << endl;
    cout << "\tNumber of Colleges: " << colleges.getColleges().size() 
            << endl;
    cout << "\tNumber of Donations: " << donations.getNumOfDonations() 
            << endl;
}

void DonationManager::printColleges() const
{    
    for (const auto& college : this->colleges.getColleges()) 
    {
        cout << "\t" << college.first << " - " << college.second 
            << endl;
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

