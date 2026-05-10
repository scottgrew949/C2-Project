#include"CollegeList.h"
#include<string>
#include<map>
#include<iostream>
using namespace std;

void CollegeList::addCollege(string code, string name)
{
	colleges.insert(make_pair(code, name));
}

string CollegeList::getCollegeName(string code) const
{
	return colleges.at(code);
}

void CollegeList::printColleges() const
{
	auto iterEnd = colleges.end();

	for (auto iter = colleges.begin(); iter != iterEnd; ++iter)
	{
		cout << iter->second << " ";
	}
}

const map<string, string>& CollegeList::getColleges() const
{
	return colleges;
}