#ifndef DONATION_H
#define DONATION_H
#include<string>

class Donation
{
	public:
		Donation(const std::string& aDonorName, const std::string& aCollegeCode, double anAmount) :donorName(aDonorName), collegeCode(aCollegeCode),amount(anAmount){}

		std::string getDonorName() const;
		std::string getCollegeCode() const;
		double getAmount() const;

	private:
		std::string donorName;
		std::string collegeCode;
		double amount;


};



#endif#pragma once
