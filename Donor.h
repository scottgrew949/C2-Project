#ifndef DONOR_H
#define DONOR_H
#include <string>


class Donor
{
	public:
		Donor(std::string aDonorName, int aDonorID) :donorName(aDonorName), donorID(aDonorID) {};

		std::string getDonorName() const;
		int getDonorID() const;


	private:
		std::string donorName;
		int donorID;

};


#endif