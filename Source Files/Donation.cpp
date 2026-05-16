/*
    Grew, Scott (Team Leader)
    Yoshikawa, Teppei
	
    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include"Donation.h"
#include<string>
using namespace std;

string Donation::getDonorName() const
{
	return donorName;
}

string Donation::getCollegeCode()const 
{
	return collegeCode;
}

double Donation::getAmount() const 
{
	return amount;
}