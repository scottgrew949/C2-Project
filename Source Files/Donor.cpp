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