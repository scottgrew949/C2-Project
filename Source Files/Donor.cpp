/*
    Grew, Scott (Team Leader)
    Yoshikawa, Teppei 

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include"Donor.h"
#include<string>

using namespace std;


string Donor::getDonorName() const
{
	return donorName;
}

int Donor::getDonorID() const
{
	return donorID;
}

bool Donor::operator<(const Donor& other) const
{
	return donorID < other.donorID;
}