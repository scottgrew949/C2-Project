#ifndef COLLEGELIST_H
#define COLLEGELIST_H

#include<string>
#include<map>

class CollegeList
{
	public:
		void addCollege(const std::string& code, const std::string& name);

		std::string getCollegeName(const std::string&) const;

		void printColleges() const;

		const std::map<std::string, std::string>& getColleges() const;

	private:
		std::map<std::string, std::string> colleges;

};




#endif