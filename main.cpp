#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include "Member.h"
#include "Loan.h"

using namespace std;

// Global vectors to store data
vector<Member> members;
vector<Loan> loans;

// File names
const string MEMBERS_FILE = "members.txt";
const string LOANS_FILE = "loans.txt";

// Function declarations
void loadData();
void saveData();
void clearScreen();
void pauseScreen();
void displayMainMenu();
void memberMenu();
void loanMenu();
void savingsMenu();
void reportsMenu();

// Member functions
void addMember();
void viewAllMembers();
void searchMember();
void editMember();
void deleteMember();

// Loan functions
void issueLoan();
void makeRepayment();
void viewAllLoans();
void viewLoansByMember();

// Savings functions
void depositSavings();
void withdrawSavings();
void viewSavingsHistory();

// Report functions
void activeLoanReport();
void overdueLoansReport();
void summaryReport();

// Utility functions
int generateMemberID();
int generateLoanID();
Member *findMemberByID(int id);
string getCurrentDate();

// ==================== MAIN FUNCTION ====================
int main()
{
    loadData();

    int choice;
    do
    {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            memberMenu();
            break;
        case 2:
            loanMenu();
            break;
        case 3:
            savingsMenu();
            break;
        case 4:
            reportsMenu();
            break;
        case 5:
            saveData();
            cout << "\n✓ Data saved successfully!\n";
            pauseScreen();
            break;
        case 0:
            saveData();
            cout << "\n+==========================================+\n";
            cout << "|  Thank you for using our system!         |\n";
            cout << "|  Data saved. Goodbye!                    |\n";
            cout << "+==========================================+\n";
            break;
        default:
            cout << "\n✗ Invalid choice! Please try again.\n";
            pauseScreen();
        }
    } while (choice != 0);

    return 0;
}

// ==================== MENU FUNCTIONS ====================
void displayMainMenu()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|     DIGITAL MICRO-FINANCE MANAGEMENT SYSTEM                |\n";
    cout << "+============================================================+\n";
    cout << "|  1. Member Management                                      |\n";
    cout << "|  2. Loan Management                                        |\n";
    cout << "|  3. Savings Management                                     |\n";
    cout << "|  4. Reports & Analytics                                    |\n";
    cout << "|  5. Save Data                                              |\n";
    cout << "|  0. Exit                                                   |\n";
    cout << "+============================================================+\n";
}

void memberMenu()
{
    int choice;
    do
    {
        clearScreen();
        cout << "\n+============================================================+\n";
        cout << "|                 MEMBER MANAGEMENT                          |\n";
        cout << "+============================================================+\n";
        cout << "|  1. Add New Member                                         |\n";
        cout << "|  2. View All Members                                       |\n";
        cout << "|  3. Search Member                                          |\n";
        cout << "|  4. Edit Member                                            |\n";
        cout << "|  5. Delete Member                                          |\n";
        cout << "|  0. Back to Main Menu                                      |\n";
        cout << "+============================================================+\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addMember();
            break;
        case 2:
            viewAllMembers();
            break;
        case 3:
            searchMember();
            break;
        case 4:
            editMember();
            break;
        case 5:
            deleteMember();
            break;
        case 0:
            break;
        default:
            cout << "\n Invalid choice!\n";
            pauseScreen();
        }
    } while (choice != 0);
}

void loanMenu()
{
    int choice;
    do
    {
        clearScreen();
        cout << "\n+============================================================+\n";
        cout << "|                  LOAN MANAGEMENT                           |\n";
        cout << "+============================================================+\n";
        cout << "|  1. Issue New Loan                                         |\n";
        cout << "|  2. Make Loan Repayment                                    |\n";
        cout << "|  3. View All Loans                                         |\n";
        cout << "|  4. View Loans by Member                                   |\n";
        cout << "|  0. Back to Main Menu                                      |\n";
        cout << "+============================================================+\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            issueLoan();
            break;
        case 2:
            makeRepayment();
            break;
        case 3:
            viewAllLoans();
            break;
        case 4:
            viewLoansByMember();
            break;
        case 0:
            break;
        default:
            cout << "\n Invalid choice!\n";
            pauseScreen();
        }
    } while (choice != 0);
}

void savingsMenu()
{
    int choice;
    do
    {
        clearScreen();
        cout << "\n+============================================================+\n";
        cout << "|                SAVINGS MANAGEMENT                          |\n";
        cout << "+============================================================+\n";
        cout << "|  1. Deposit Savings                                        |\n";
        cout << "|  2. Withdraw Savings                                       |\n";
        cout << "|  3. View Member Savings                                    |\n";
        cout << "|  0. Back to Main Menu                                      |\n";
        cout << "+============================================================+\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            depositSavings();
            break;
        case 2:
            withdrawSavings();
            break;
        case 3:
            viewSavingsHistory();
            break;
        case 0:
            break;
        default:
            cout << "\n Invalid choice!\n";
            pauseScreen();
        }
    } while (choice != 0);
}

void reportsMenu()
{
    int choice;
    do
    {
        clearScreen();
        cout << "\n+============================================================+\n";
        cout << "|              REPORTS & ANALYTICS                           |\n";
        cout << "+============================================================+\n";
        cout << "|  1. Active Loans Report                                    |\n";
        cout << "|  2. Overdue Loans Report                                   |\n";
        cout << "|  3. Summary Report                                         |\n";
        cout << "|  0. Back to Main Menu                                      |\n";
        cout << "+============================================================+\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            activeLoanReport();
            break;
        case 2:
            overdueLoansReport();
            break;
        case 3:
            summaryReport();
            break;
        case 0:
            break;
        default:
            cout << "\n Invalid choice!\n";
            pauseScreen();
        }
    } while (choice != 0);
}

// ==================== MEMBER FUNCTIONS ====================
void addMember()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                  ADD NEW MEMBER                            |\n";
    cout << "+============================================================+\n";

    cin.ignore();
    string name, address, phone;

    cout << "\nEnter Member Name: ";
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Phone: ";
    getline(cin, phone);

    int id = generateMemberID();
    string date = getCurrentDate();

    Member newMember(id, name, address, phone, date);
    members.push_back(newMember);

    cout << "\n Member added successfully! Member ID: " << id << "\n";
    pauseScreen();
}

void viewAllMembers()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                  ALL MEMBERS LIST                          |\n";
    cout << "+============================================================+\n";

    if (members.empty())
    {
        cout << "\nNo members found in the system.\n";
    }
    else
    {
        cout << "\n"
             << setw(6) << "ID" << setw(25) << "Name"
             << setw(20) << "Phone" << setw(15) << "Savings\n";
        cout << string(66, '-') << "\n";

        for (const auto &member : members)
        {
            if (member.getIsActive())
            {
                cout << setw(6) << member.getMemberID()
                     << setw(25) << member.getName()
                     << setw(20) << member.getPhone()
                     << " $" << setw(12) << fixed << setprecision(2)
                     << member.getTotalSavings() << "\n";
            }
        }
    }
    pauseScreen();
}

void searchMember()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                   SEARCH MEMBER                            |\n";
    cout << "+============================================================+\n";

    cout << "\n1. Search by ID\n2. Search by Name\nChoose: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        int id;
        cout << "Enter Member ID: ";
        cin >> id;

        Member *member = findMemberByID(id);
        if (member && member->getIsActive())
        {
            member->display();
        }
        else
        {
            cout << "\n Member not found!\n";
        }
    }
    else if (choice == 2)
    {
        cin.ignore();
        string searchName;
        cout << "Enter Member Name: ";
        getline(cin, searchName);

        bool found = false;
        for (auto &member : members)
        {
            if (member.getIsActive() &&
                member.getName().find(searchName) != string::npos)
            {
                member.display();
                found = true;
            }
        }
        if (!found)
        {
            cout << "\n No member found with that name!\n";
        }
    }
    pauseScreen();
}

void editMember()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                    EDIT MEMBER                             |\n";
    cout << "+============================================================+\n";

    int id;
    cout << "\nEnter Member ID: ";
    cin >> id;

    Member *member = findMemberByID(id);
    if (member && member->getIsActive())
    {
        member->display();

        cin.ignore();
        string name, address, phone;

        cout << "\nEnter new Name (or press Enter to keep current): ";
        getline(cin, name);
        if (!name.empty())
            member->setName(name);

        cout << "Enter new Address (or press Enter to keep current): ";
        getline(cin, address);
        if (!address.empty())
            member->setAddress(address);

        cout << "Enter new Phone (or press Enter to keep current): ";
        getline(cin, phone);
        if (!phone.empty())
            member->setPhone(phone);

        cout << "\n Member updated successfully!\n";
    }
    else
    {
        cout << "\n Member not found!\n";
    }
    pauseScreen();
}

void deleteMember()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                  DELETE MEMBER                             |\n";
    cout << "+============================================================+\n";

    int id;
    cout << "\nEnter Member ID: ";
    cin >> id;

    Member *member = findMemberByID(id);
    if (member && member->getIsActive())
    {
        member->display();

        cout << "\nAre you sure you want to delete this member? (Y/N): ";
        char confirm;
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y')
        {
            member->setIsActive(false);
            cout << "\n Member deleted successfully!\n";
        }
        else
        {
            cout << "\n Deletion cancelled.\n";
        }
    }
    else
    {
        cout << "\n Member not found!\n";
    }
    pauseScreen();
}

// ==================== LOAN FUNCTIONS ====================
void issueLoan()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                   ISSUE NEW LOAN                           |\n";
    cout << "+============================================================+\n";

    int memberID;
    cout << "\nEnter Member ID: ";
    cin >> memberID;

    Member *member = findMemberByID(memberID);
    if (!member || !member->getIsActive())
    {
        cout << "\n Member not found!\n";
        pauseScreen();
        return;
    }

    member->display();

    double amount, rate;
    int duration;

    cout << "\nEnter Loan Amount: $";
    cin >> amount;
    cout << "Enter Interest Rate (%): ";
    cin >> rate;
    cout << "Enter Duration (months): ";
    cin >> duration;

    int loanID = generateLoanID();
    string date = getCurrentDate();

    Loan newLoan(loanID, memberID, amount, rate, duration, date);
    loans.push_back(newLoan);

    cout << "\n Loan issued successfully! Loan ID: " << loanID << "\n";
    newLoan.display();
    pauseScreen();
}

void makeRepayment()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                  MAKE LOAN REPAYMENT                       |\n";
    cout << "+============================================================+\n";

    int loanID;
    cout << "\nEnter Loan ID: ";
    cin >> loanID;

    bool found = false;
    for (auto &loan : loans)
    {
        if (loan.getLoanID() == loanID)
        {
            found = true;
            loan.display();

            if (loan.getStatus() == "Completed")
            {
                cout << "\n This loan is already completed!\n";
                break;
            }

            double amount;
            cout << "\nEnter Repayment Amount: $";
            cin >> amount;

            if (loan.makeRepayment(amount))
            {
                cout << "\n Repayment processed successfully!\n";
                cout << "Remaining Balance: $" << fixed << setprecision(2)
                     << loan.getRemainingBalance() << "\n";

                if (loan.getStatus() == "Completed")
                {
                    cout << "\n Loan fully paid! Status: COMPLETED\n";
                }
            }
            else
            {
                cout << "\n Invalid repayment amount!\n";
            }
            break;
        }
    }

    if (!found)
    {
        cout << "\n Loan not found!\n";
    }
    pauseScreen();
}

void viewAllLoans()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                    ALL LOANS LIST                          |\n";
    cout << "+============================================================+\n";

    if (loans.empty())
    {
        cout << "\nNo loans found in the system.\n";
    }
    else
    {
        cout << "\n"
             << setw(8) << "Loan ID" << setw(10) << "Member"
             << setw(12) << "Amount" << setw(12) << "Remaining"
             << setw(12) << "Status\n";
        cout << string(54, '-') << "\n";

        for (const auto &loan : loans)
        {
            cout << setw(8) << loan.getLoanID()
                 << setw(10) << loan.getMemberID()
                 << " $" << setw(10) << fixed << setprecision(2) << loan.getLoanAmount()
                 << " $" << setw(10) << loan.getRemainingBalance()
                 << setw(12) << loan.getStatus() << "\n";
        }
    }
    pauseScreen();
}

void viewLoansByMember()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|               VIEW LOANS BY MEMBER                         |\n";
    cout << "+============================================================+\n";

    int memberID;
    cout << "\nEnter Member ID: ";
    cin >> memberID;

    Member *member = findMemberByID(memberID);
    if (!member || !member->getIsActive())
    {
        cout << "\n Member not found!\n";
        pauseScreen();
        return;
    }

    member->display();

    bool found = false;
    for (auto &loan : loans)
    {
        if (loan.getMemberID() == memberID)
        {
            loan.display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo loans found for this member.\n";
    }
    pauseScreen();
}

// ==================== SAVINGS FUNCTIONS ====================
void depositSavings()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                  DEPOSIT SAVINGS                           |\n";
    cout << "+============================================================+\n";

    int memberID;
    cout << "\nEnter Member ID: ";
    cin >> memberID;

    Member *member = findMemberByID(memberID);
    if (!member || !member->getIsActive())
    {
        cout << "\n Member not found!\n";
        pauseScreen();
        return;
    }

    double amount;
    cout << "Enter Deposit Amount: $";
    cin >> amount;

    if (amount > 0)
    {
        member->depositSavings(amount);
        cout << "\n Deposit successful!\n";
        cout << "New Savings Balance: $" << fixed << setprecision(2)
             << member->getTotalSavings() << "\n";
    }
    else
    {
        cout << "\n Invalid amount!\n";
    }
    pauseScreen();
}

void withdrawSavings()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                 WITHDRAW SAVINGS                           |\n";
    cout << "+============================================================+\n";

    int memberID;
    cout << "\nEnter Member ID: ";
    cin >> memberID;

    Member *member = findMemberByID(memberID);
    if (!member || !member->getIsActive())
    {
        cout << "\n Member not found!\n";
        pauseScreen();
        return;
    }

    cout << "Current Savings: $" << fixed << setprecision(2)
         << member->getTotalSavings() << "\n";

    double amount;
    cout << "Enter Withdrawal Amount: $";
    cin >> amount;

    if (member->withdrawSavings(amount))
    {
        cout << "\n Withdrawal successful!\n";
        cout << "New Savings Balance: $" << fixed << setprecision(2)
             << member->getTotalSavings() << "\n";
    }
    else
    {
        cout << "\n Insufficient balance or invalid amount!\n";
    }
    pauseScreen();
}

void viewSavingsHistory()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|              VIEW MEMBER SAVINGS                           |\n";
    cout << "+============================================================+\n";

    int memberID;
    cout << "\nEnter Member ID: ";
    cin >> memberID;

    Member *member = findMemberByID(memberID);
    if (!member || !member->getIsActive())
    {
        cout << "\n✗ Member not found!\n";
    }
    else
    {
        member->display();
    }
    pauseScreen();
}

// ==================== REPORT FUNCTIONS ====================
void activeLoanReport()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                ACTIVE LOANS REPORT                         |\n";
    cout << "+============================================================+\n";

    int activeCount = 0;
    double totalActive = 0.0;

    cout << "\n"
         << setw(8) << "Loan ID" << setw(10) << "Member"
         << setw(12) << "Amount" << setw(12) << "Remaining\n";
    cout << string(42, '-') << "\n";

    for (const auto &loan : loans)
    {
        if (loan.getStatus() == "Active")
        {
            cout << setw(8) << loan.getLoanID()
                 << setw(10) << loan.getMemberID()
                 << " $" << setw(10) << fixed << setprecision(2)
                 << loan.getLoanAmount()
                 << " $" << setw(10) << loan.getRemainingBalance() << "\n";
            activeCount++;
            totalActive += loan.getRemainingBalance();
        }
    }

    cout << "\n===========================================\n";
    cout << "Total Active Loans: " << activeCount << "\n";
    cout << "Total Outstanding: $" << fixed << setprecision(2) << totalActive << "\n";
    pauseScreen();
}

void overdueLoansReport()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|               OVERDUE LOANS REPORT                         |\n";
    cout << "+============================================================+\n";

    int overdueCount = 0;

    for (const auto &loan : loans)
    {
        if (loan.getStatus() == "Overdue")
        {
            loan.display();
            overdueCount++;
        }
    }

    if (overdueCount == 0)
    {
        cout << "\n No overdue loans found!\n";
    }
    else
    {
        cout << "\nTotal Overdue Loans: " << overdueCount << "\n";
    }
    pauseScreen();
}

void summaryReport()
{
    clearScreen();
    cout << "\n+============================================================+\n";
    cout << "|                  SUMMARY REPORT                            |\n";
    cout << "+============================================================+\n";

    int activeMembers = 0;
    double totalSavings = 0.0;

    for (const auto &member : members)
    {
        if (member.getIsActive())
        {
            activeMembers++;
            totalSavings += member.getTotalSavings();
        }
    }

    int totalLoans = loans.size();
    int activeLoans = 0;
    int completedLoans = 0;
    double totalLoanAmount = 0.0;
    double totalOutstanding = 0.0;

    for (const auto &loan : loans)
    {
        totalLoanAmount += loan.getLoanAmount();
        if (loan.getStatus() == "Active")
        {
            activeLoans++;
            totalOutstanding += loan.getRemainingBalance();
        }
        else if (loan.getStatus() == "Completed")
        {
            completedLoans++;
        }
    }

    cout << "\n  MEMBER STATISTICS:\n";
    cout << "   Total Active Members: " << activeMembers << "\n";
    cout << "   Total Savings Collected: $" << fixed << setprecision(2)
         << totalSavings << "\n\n";

    cout << "  LOAN STATISTICS:\n";
    cout << "   Total Loans Issued: " << totalLoans << "\n";
    cout << "   Active Loans: " << activeLoans << "\n";
    cout << "   Completed Loans: " << completedLoans << "\n";
    cout << "   Total Loan Amount: $" << totalLoanAmount << "\n";
    cout << "   Total Outstanding: $" << totalOutstanding << "\n";

    pauseScreen();
}

// ==================== FILE HANDLING ====================
void loadData()
{
    // Load members
    ifstream memberFile(MEMBERS_FILE);
    if (memberFile.is_open())
    {
        string line;
        while (getline(memberFile, line))
        {
            if (!line.empty())
            {
                Member m;
                m.fromFileString(line);
                members.push_back(m);
            }
        }
        memberFile.close();
    }

    // Load loans
    ifstream loanFile(LOANS_FILE);
    if (loanFile.is_open())
    {
        string line;
        while (getline(loanFile, line))
        {
            if (!line.empty())
            {
                Loan l;
                l.fromFileString(line);
                loans.push_back(l);
            }
        }
        loanFile.close();
    }
}

void saveData()
{
    // Save members
    ofstream memberFile(MEMBERS_FILE);
    if (memberFile.is_open())
    {
        for (const auto &member : members)
        {
            memberFile << member.toFileString() << "\n";
        }
        memberFile.close();
    }

    // Save loans
    ofstream loanFile(LOANS_FILE);
    if (loanFile.is_open())
    {
        for (const auto &loan : loans)
        {
            loanFile << loan.toFileString() << "\n";
        }
        loanFile.close();
    }
}

// ==================== UTILITY FUNCTIONS ====================
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int generateMemberID()
{
    if (members.empty())
        return 1001;

    int maxID = 0;
    for (const auto &member : members)
    {
        if (member.getMemberID() > maxID)
        {
            maxID = member.getMemberID();
        }
    }
    return maxID + 1;
}

int generateLoanID()
{
    if (loans.empty())
        return 5001;

    int maxID = 0;
    for (const auto &loan : loans)
    {
        if (loan.getLoanID() > maxID)
        {
            maxID = loan.getLoanID();
        }
    }
    return maxID + 1;
}

Member *findMemberByID(int id)
{
    for (auto &member : members)
    {
        if (member.getMemberID() == id)
        {
            return &member;
        }
    }
    return nullptr;
}

string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_mday << "/"
       << setw(2) << (1 + ltm->tm_mon) << "/"
       << (1900 + ltm->tm_year);

    return ss.str();
}