#include"Donation.h"
#include<string>
using namespace std;

string Donation::getDonorName() const{
	return donorName;
}

string Donation::getCollegeCode()const {
	return collegeCode;
}

double Donation::getAmount() const {
	return amount;
}