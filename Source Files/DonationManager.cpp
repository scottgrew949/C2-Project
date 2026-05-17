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
#include<list>

using namespace std;

// Controlers ---------------------------------------------------
int DonationManager::addDonor(const string & donorName)
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

// Printers -----------------------------------------------------
void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    double maxTotal = 0.0;
    list<string> maxCollege;
    list<string> maxCollegeName;
    
    for (auto& college : collegeMap) {
        double total = getCollegeTotal(college.first);
        if (total > maxTotal) {
            maxTotal = total;
            maxCollege.clear();
            maxCollegeName.clear();
            maxCollege.push_back(college.first);
            maxCollegeName.push_back(college.second);
        }
        else if (toal == maxTotal)
        {
            maxCollege.push_back(college.first);
            maxCollegeName.push_back(college.second);
        }
    }
    
    cout << "College(s) with highest total donation:" << endl;
    auto collegeEnd = maxCollege.end();
    auto collegeNameEnd = maxCollegeName.end();
    auto collegeIter = maxCollege.begin();
    auto collegeNameIter = maxCollegeName.begin();

    while (collegeIter != collegeEnd && collegeNameIter != collegeNameEnd)
    {
        cout << *collegeNameIter << "(" << *collegeIter << ")" << endl;
        ++collegeIter;
        ++collegeNameIter;
    }
}

void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    
    for (auto& college : collegeMap) {
        cout << college.first << " - " << college.second << endl;
        
        DonationNode* current = donations.getFirst();
        while (current != nullptr) {
            if (current->data.getCollegeCode() == college.first) {
                cout << "  " << current->data.getDonorName() << ": " 
                     << current->data.getAmount() << endl;
            }
            current = current->next;
        }
    }
}

void DonationManager::printDonationsByDonor() const
{
    for (const auto& donor : donors) {
        cout << "Donor ID: " << donor.getDonorID() 
             << ", Name: " << donor.getDonorName() << endl;
        
        DonationNode* current = donations.getFirst();
        while (current != nullptr) {
            if (current->data.getDonorName() == donor.getDonorName()) {
                cout << "  " << current->data.getCollegeCode() << ": " 
                     << current->data.getAmount() << endl;
            }
            current = current->next;
        }
    }
}

void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    
    for (const auto& college : collegeMap) {
        double total = getCollegeTotal(college.first);
        cout << college.first << " - " << college.second << "\n"
             << "   Total donaiton amount: $" << total << endl;
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const auto& donor : donors) {
        double total = getDonorTotal(donor.getDonorName());
        cout << "(ID " << donor.getDonorID() << ")  " 
             << donor.getDonorName() << " | " << total << endl;
    }
}

void DonationManager::printHighestDonor() const
{
    double maxTotal = 0.0;
    list<string> maxDonor;
    
    for (const auto& donor : donors) {
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
    
    
    cout << "Highest donor(s): \n    ";
        for (const string& name : maxDonor)
        {
            cout << "   " << name << endl;
        }
    cout << "   Highest amount donated: $" << maxTotal << endl;
}

void DonationManager::printStatistics() const
{
    cout << "Number of Donors: " << donors.size() << endl;
    cout << "Number of Colleges: " << colleges.getColleges().size() << endl;
    cout << "Number of Donations: " << donations.getNumOfDonations() << endl;
}

void DonationManager::printColleges() const
{
    colleges.printColleges();
}

// Private ------------------------------------------------------
double DonationManager::getDonorTotal(const string& donorName) const
{
    DonationNode* current = donations.getFirst;

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
    
    while (current != nullptr) {
        if (current->data.getCollegeCode() == collegeCode) {
            total += current->data.getAmount();
        }
        current = current->next;
    }
    
    return total;
}

