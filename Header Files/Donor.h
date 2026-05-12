#ifndef DONOR_H
#define DONOR_H
#include <string>


class Donor
{
	public:
		Donor(const std::string& aDonorName, int aDonorID) :donorName(aDonorName), donorID(aDonorID) {};

		std::string getDonorName() const;
		int getDonorID() const;

		bool Donor::operator<(const Donor& other) const;
		


	private:
		std::string donorName;
		int donorID;

};


#endif