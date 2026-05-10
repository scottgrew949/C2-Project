/*
    Grew, Scott (Team Leader)
    Teppei Yoshikawa

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationList.h"
#include <iostream>

// Controler --------------------------------------------------------
int DonationList::addDonation(const Donation& toAdd)
{
    DonationNode* newNode = new DonationNode(toAdd);
    if (first == nullptr)
        first = last = newNode;
    else 
    {
        last->next = newNode;
        last = newNode; 
    }
    ++numOfDonations;
    return numOfDonations;
}

// Getters ----------------------------------------------------------
int DonationList::getNumOfDonations() const
{
    return numOfDonations;
}

DonationNode* DonationList::getFirst() const
{
    return first;
}

DonationNode* DonationList::getLast() const
{
    return last;
}

// Destructor -------------------------------------------------------
DonationList::~DonationList()
{
    DonationNode* current = first;
    while(current != nullptr)
    {
        DonationNode* next = current->next;
        delete current;
        current = next;
    }

    first = last = nullptr;
    numOfDonations = 0;
}