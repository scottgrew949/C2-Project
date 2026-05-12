#include"CollegeList.h"
#include<string>
#include<map>
#include<iostream>
using namespace std;

void CollegeList::addCollege(const string& code, const string& name)
{
	colleges.insert(make_pair(code, name));
}

string CollegeList::getCollegeName(const string& code) const
{
	return colleges.at(code);
}

void CollegeList::printColleges() const
{
	for (const auto& elem : colleges)
	{
		cout << colleges.second << " ";
	}
}

const map<string, string>& CollegeList::getColleges() const
{
	return colleges;
}