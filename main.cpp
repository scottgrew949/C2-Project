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
    Donor donor1("Sam", 100);
    Donor donor2("Amy", 200);

    check("Donor constructor and accessors", "Sam, 100",
      donor1.getDonorName() + ", " + to_string(donor1.getDonorID()));

    check("Donor constructor and accessors", "Amy, 200",
      donor2.getDonorName() + ", " + to_string(donor2.getDonorID()));

    // Test Donor::operator<.
    cout << "-- Testing: Donor::operator< --\n";
    cout << "Expected: true if donor1 is less than donor2 according to your operator< definition\n";
    cout << "Actual:   " << (donor1 < donor2 ? "true" : "false") << "\n\n";


    cout << "\n===== PHASE 2: Testing CollegeList =====\n\n";

    // Create CollegeList object.
    CollegeList collegeList;

    // Test CollegeList::addCollege.
    cout << "-- Testing: CollegeList::addCollege --\n";
    cout << "Expected: OCC, GWC, and CCC are added to the college list.\n";

    collegeList.addCollege("OCC", "Orange Coast College");
    collegeList.addCollege("GWC", "Golden West College");
    collegeList.addCollege("CCC", "Coastline Community College");

    cout << "Actual:   addCollege was called for OCC, GWC, and CCC.\n\n";

    // Test CollegeList::getCollegeName with existing college codes.
    cout << "-- Testing: CollegeList::getCollegeName with existing college code OCC --\n";
    cout << "Expected: Orange Coast College\n";
    cout << "Actual:   " << collegeList.getCollegeName("OCC") << "\n\n";

    cout << "-- Testing: CollegeList::getCollegeName with existing college code GWC --\n";
    cout << "Expected: Golden West College\n";
    cout << "Actual:   " << collegeList.getCollegeName("GWC") << "\n\n";

    // Test CollegeList::printColleges.
    cout << "-- Testing: CollegeList::printColleges --\n";
    cout << "Expected:\n";
    cout << "OCC - Orange Coast College\n";
    cout << "GWC - Golden West College\n";
    cout << "CCC - Coastline Community College\n";
    cout << "Actual:\n";
    collegeList.printColleges();
    cout << "\n\n";

    // Test CollegeList::getColleges.
    cout << "-- Testing: CollegeList::getColleges --\n";
    cout << "Expected: A collection containing 3 colleges.\n";
    cout << "Actual:   Number of colleges = "
        << collegeList.getColleges().size() << "\n\n";


    cout << "\n===== PHASE 3: Testing Donation =====\n\n";

    // Test parameterized constructor + all accessors.
    Donation donation1("Sam", "OCC", 500.00);

    cout << "-- Testing: Donation parameterized constructor and accessors --\n";
    cout << "Expected: Sam, OCC, 500\n";
    cout << "Actual:   " << donation1.getDonorName() << ", "
        << donation1.getCollegeCode() << ", "
        << donation1.getAmount() << "\n\n";

    // Test another Donation object with a zero amount.
    Donation donation3("Test Donor", "GWC", 0.00);

    cout << "-- Testing: Donation with zero amount --\n";
    cout << "Expected: Test Donor, GWC, 0\n";
    cout << "Actual:   " << donation3.getDonorName() << ", "
        << donation3.getCollegeCode() << ", "
        << donation3.getAmount() << "\n\n";

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
    cout << "getLast():  " << (donationList.getLast() == nullptr ?
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
    cout << "Actual:   " << (singleList.getFirst() == 
                        singleList.getLast() ? "same" : "different") << "\n\n";

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
    while (current != nullptr)
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

    cout << "\n\n===== PHASE 6: Testing FileLoader with colleges.csv and donations.csv =====\n\n";

    // Create DonationManager object.
    DonationManager donationManagerTest;

    // Test loadCollegesFromFile.
    cout << "-- Testing: loadCollegesFromFile(\"colleges.csv\", donationManagerTest) --\n";
    cout << "Expected: colleges.csv is opened and all colleges are loaded into donationManagerTest.\n";
    cout << "Actual:   ";
    loadCollegesFromFile("Resource/colleges.csv", donationManagerTest);
    cout << "Finished loadCollegesFromFile.\n\n";

    // After calling loadCollegesFromFile, test DonationManager::printColleges.
    cout << "-- Testing: DonationManager::printColleges() after loading colleges.csv --\n";
    cout << "Expected: All colleges from colleges.csv are printed.\n";
    cout << "Actual:\n";
    donationManagerTest.printColleges();
    cout << "\n\n";

    // Test loadDonationsFromFile.
    cout << "-- Testing: loadDonationsFromFile(\"donations.csv\", donationManagerTest) --\n";
    cout << "Expected: donations.csv is opened and all donations are loaded into donationManagerTest.\n";
    cout << "Actual:   ";
    loadDonationsFromFile("Resource/donations.csv", donationManagerTest);
    cout << "Finished loadDonationsFromFile.\n\n";

    // After calling loadDonationsFromFile, test all report functions.

    // Test DonationManager::printDonationsByCollege.
    cout << "-- Testing: DonationManager::printDonationsByCollege() after file load --\n";
    cout << "Expected: Donations grouped by college from donations.csv.\n";
    cout << "Actual:\n";
    donationManagerTest.printDonationsByCollege();
    cout << "\n\n";

    // Test DonationManager::printDonationsByDonor.
    cout << "-- Testing: DonationManager::printDonationsByDonor() after file load --\n";
    cout << "Expected: Donations grouped by donor from donations.csv.\n";
    cout << "Actual:\n";
    donationManagerTest.printDonationsByDonor();
    cout << "\n\n";

    // Test DonationManager::printTotalsByCollege.
    cout << "-- Testing: DonationManager::printTotalsByCollege() after file load --\n";
    cout << "Expected: Total donation amount for each college.\n";
    cout << "Actual:\n";
    donationManagerTest.printTotalsByCollege();
    cout << "\n\n";

    // Test DonationManager::printTotalsByDonor.
    cout << "-- Testing: DonationManager::printTotalsByDonor() after file load --\n";
    cout << "Expected: Total donation amount for each donor.\n";
    cout << "Actual:\n";
    donationManagerTest.printTotalsByDonor();
    cout << "\n\n";

    // Test DonationManager::printStatistics.
    cout << "-- Testing: DonationManager::printStatistics() after file load --\n";
    cout << "Expected: Number of donors, colleges, and donations loaded from the files.\n";
    cout << "Actual: 10, 7, 10\n";
    donationManagerTest.printStatistics();
    cout << "\n\n";

    // Test DonationManager::printHighestDonor.
    cout << "-- Testing: DonationManager::printHighestDonor() after file load --\n";
    cout << "Expected: Donor with the highest total donation amount.\n";
    cout << "Actual:\n";
    donationManagerTest.printHighestDonor();
    cout << "\n\n";

    // Test DonationManager::printCollegeWithHighestTotal.
    cout << "-- Testing: DonationManager::printCollegeWithHighestTotal() after file load --\n";
    cout << "Expected: College with the highest total donation amount.\n";
    cout << "Actual:\n";
    donationManagerTest.printCollegeWithHighestTotal();
    cout << "\n\n";


    cout << "\n===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}