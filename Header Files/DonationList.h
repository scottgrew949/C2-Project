/*
    Grew, Scott (Team Leader)
    Yoshikawa, Teppei 

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONATIONLIST_H
#define DONATIONLIST_H

#include "Donation.h"

#include <string>

struct DonationNode
{
    Donation data;
    DonationNode* next;

    DonationNode(const Donation& donation)
        : data(donation), next(nullptr) {
    }
};

class DonationList
{
public:

    DonationList()
        : first(nullptr), last(nullptr), numOfDonations(0)
        {}
    int addDonation(const Donation&);
    int getNumOfDonations() const;
    DonationNode* getFirst() const;
    DonationNode* getLast() const;
    ~DonationList();

private:
    DonationNode* first;
    DonationNode* last;
    int numOfDonations;
};

#endif