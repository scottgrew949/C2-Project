/*
    Grew, Scott (Team Leader)
    Teppei Yoshikawa

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include <iostream>
#include "Donor.h"
#include "CollegeList.h"
#include "Donation.h"
#include "DonationList.h"
#include "DonationManager.h"
#include "FileLoader.h"

using namespace std;



int main()
{
    // IMPORTANT TESTING RULES:
    //
    // 1. DO NOT delete or change any of the provided test comments.
    // 2. Each test must PRODUCE OUTPUT--silent or skipped tests will lose points.
    // 3. If a test fails, fix YOUR implementation, not the test.
    // 4. You may add additional tests for clarity, but do not remove any required ones.
    auto check = [](const string& label, auto expected, auto actual) {
      cout << "-- Testing: " << label << " --\n";
      cout << "Expected: " << expected << "\n";
      cout << "Actual:   " << actual << "\n\n";
    };

    cout << "===== PHASE 1: Testing Donor =====\n\n";

    // Test parameterized constructor + all accessors.
    // Your code here...

    // Test Donor::operator<.
    // Your code here...


    cout << "\n===== PHASE 2: Testing CollegeList =====\n\n";

    // Create CollegeList object.
    // Your code here...

    // Test CollegeList::addCollege.
    // Your code here...

    // Test CollegeList::getCollegeName with an existing college code.
    // Your code here...

    // Test CollegeList::printColleges.
    // Your code here...

    // Test CollegeList::getColleges.
    // Your code here...


    cout << "\n===== PHASE 3: Testing Donation =====\n\n";

    // Test parameterized constructor + all accessors.
    // Your code here...

    // >> Scott Begin -----------------------------------------------
    cout << "\n===== PHASE 4: Testing DonationList =====\n\n";

    // Create DonationList object.
    DonationList donationList;

    // Test DonationList::getNumOfDonations on an empty list.
    check("DonationList::getNumOfDonations()", 0, 
                            donationList.getNumOfDonations());

    // Test DonationList::getFirst and DonationList::getLast on an empty list.
    cout << "-- Testing: getFirst() and getLast() on empty list --\n";
    cout << "Expected: nullptr\n";
    cout << "getFirst(): " << (donationList.getFirst() == nullptr ? 
                            "nullptr" : "not null") << "\n";
    cout << "getLast():  " << (donationList.getLast()  == nullptr ? 
                            "nullptr" : "not null") << "\n\n";

    // Create and add a few Donation objects to the list.
    donationList.addDonation(Donation("Odysseus", "OCC", 50000));
    donationList.addDonation(Donation("Athena", "Stanford", 99990));
    donationList.addDonation(Donation("Damon", "U Toronto", 5000));
    donationList.addDonation(Donation("Theron", "UCI", 89800));
    donationList.addDonation(Donation("Lyra", "UCLA", 67000));
    
    // Test DonationList::addDonation empty test.
    DonationList singleList;
    check("addDonation() returns 1 on first insert", 1,
    singleList.addDonation(Donation("Test", "OCC", 100)));

    // Test getFirst and getLast point to same node when list has one element
    cout << "-- Single node: getFirst == getLast --\n";
    cout << "Expected: same\n";
    cout << "Actual:   " << (singleList.getFirst() == singleList.getLast() ? "same" : "different") << "\n\n";

    // Test DonationList::getNumOfDonations after adding donations.
    donationList.addDonation(Donation("Zeus", "Berkeley", 999999));
    check("DonationList::getNumOfDonations()", 6, 
                                donationList.getNumOfDonations());

    // Test DonationList::getFirst.
    // Print the data stored in the first node.
    DonationNode* firstNode = donationList.getFirst();
    cout << "-- Testing: DonationList::getFirst() --\n";
    cout << "Expected: Odysseus, OCC, 50000\n";
    cout << "Actual:   " << firstNode->data.getDonorName() << ", "
                       << firstNode->data.getCollegeCode() << ", "
                       << firstNode->data.getAmount() << "\n\n";

    // Test DonationList::getLast.
    // Print the data stored in the last node.
    DonationNode* lastNode = donationList.getLast();
    cout << "-- Testing: DonationList::getLast() --\n";
    cout << "Expected: Zeus, Berkeley, 999999\n";
    cout << "Actual:   " << lastNode->data.getDonorName() << ", "
                       << lastNode->data.getCollegeCode() << ", "
                       << lastNode->data.getAmount() << "\n\n";

    // Test DonationList last validity.
    cout << "-- Testing: getLast()->next is nullptr --\n";
    cout << "Expected: nullptr\n";
    cout << "Actual:   " << (donationList.getLast()->next == nullptr ?
                            "nullptr" : "not null") << "\n\n";

    // Traverse the DonationList manually using getFirst and next.
    // Print all donations in the list.
    cout << "-- Testing: Manual List Print --\n";
    int count = 0;
    DonationNode* current = donationList.getFirst();
    while(current != nullptr)
    {
        cout << current->data.getDonorName() << ", "
                       << current->data.getCollegeCode() << ", "
                       << current->data.getAmount() << "\n\n";
        current = current->next;
        ++count;
    }

    // Test traversal count / loop hits every node
    check("Traversal node count matches getNumOfDonations()",
      donationList.getNumOfDonations(), count);


    cout << "\n===== PHASE 5: Testing DonationManager with manual data =====\n\n";

    // Create DonationManager object.
    DonationManager Manager;

    // Test DonationManager::addCollege by adding several colleges.
    Manager.addCollege("OCC", "Orange Coast College");
    Manager.addCollege("UCLA", "Univ of California Los Angeles");
    Manager.addCollege("UCI", "Univ of California Irvine");
    Manager.addCollege("UCB", "Univ of California Berkeley");
    Manager.addCollege("GWC", "Golden West College");

    // Test DonationManager::printColleges.
    cout << "-- Testing: DonationManager::printColleges() --\n";
    Manager.printColleges();
    cout << "\n\n";

    // Test DonationManager::addDonor by adding several donors.
    // Print the ID returned for each donor.
    check("addDonor(\"Achilles\") ID", 3000, Manager.addDonor("Achilles"));
    check("addDonor(\"Castor\") ID", 3001, Manager.addDonor("Castor"));
    check("addDonor(\"Grimus\") ID", 3002, Manager.addDonor("Grimus"));
    check("addDonor(\"Odessa\") ID", 3003, Manager.addDonor("Odessa"));

    // Test DonationManager::addDonation by adding several donations.
    Manager.addDonation("Achilles", "UCLA", 4444);
    Manager.addDonation("Castor", "UCB", 3333);
    Manager.addDonation("Grimus", "UCI", 2222);
    Manager.addDonation("Odessa", "OCC", 1111);

    // Test DonationManager::printDonationsByCollege.
    cout << "-- Testing: DonationManager::printDonationsByCollege() --\n";
    Manager.printDonationsByCollege();
    cout << "\n";

    // Test DonationManager::printDonationsByDonor.
    cout << "-- Testing: DonationManager::printDonationsByDonor() --\n";
    Manager.printDonationsByDonor();
    cout << "\n";

    // Test DonationManager::printTotalsByCollege.
    cout << "-- Testing: DonationManager::printTotalsByCollege() --\n";
    Manager.printTotalsByCollege();
    cout << "\n";

    // Test DonationManager::printTotalsByDonor.
    cout << "-- Testing: DonationManager::printTotalsByDonor() --\n";
    Manager.printTotalsByDonor();
    cout << "\n";

    // Test DonationManager::printStatistics.
    cout << "-- Testing: DonationManager::printStatistics() --\n";
    cout << "Expected: 4 donors, 5 colleges, 4 donations\n";
    Manager.printStatistics();
    cout << "\n";

    // Test printDonationsByCollege with a college that has no donations.
    cout << "-- Testing: printDonationsByCollege() college with no donations (GWC) --\n";
    cout << "Expected: GWC listed with no donor entries\n";
    Manager.printDonationsByCollege();
    cout << "\n";

    // Test DonationManager::printHighestDonor.
    cout << "-- Testing: DonationManager::printHighestDonor() --\n";
    cout << "Expected: Achilles: 4444\n";
    cout << "Actual:   ";
    Manager.printHighestDonor();
    cout << "\n";

    // Test DonationManager::printCollegeWithHighestTotal.
    cout << "-- Testing: DonationManager::printCollegeWithHighestTotal() --\n";
    cout << "Expected: UCLA (Univ of California Los Angeles): 4444\n";
    cout << "Actual:   ";
    Manager.printCollegeWithHighestTotal();
    cout << "\n";

    // >> Scott End -------------------------------------------------

    cout << "\n\n===== PHASE 6: Testing FileLoader with colleges.csv and donations.csv =====\n\n";

    // Create DonationManager object.
    // Your code here...

    // Test loadCollegesFromFile.
    // Your code here...

    // After calling loadCollegesFromFile, test DonationManager::printColleges.
    // Your code here...

    // Test loadDonationsFromFile.
    // Your code here...

    // After calling loadDonationsFromFile, test all report functions:
    // printDonationsByCollege
    // printDonationsByDonor
    // printTotalsByCollege
    // printTotalsByDonor
    // printStatistics
    // printHighestDonor
    // printCollegeWithHighestTotal
    // Your code here...


    cout << "\n===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}