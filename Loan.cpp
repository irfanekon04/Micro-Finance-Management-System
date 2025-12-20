#include "Loan.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

// Constructors
Loan::Loan() : loanID(0), memberID(0), loanAmount(0.0), interestRate(0.0),
               durationMonths(0), totalPayable(0.0), paidAmount(0.0),
               remainingBalance(0.0), status("Active") {}

Loan::Loan(int lId, int mId, double amount, double rate, int duration, string date)
    : loanID(lId), memberID(mId), loanAmount(amount), interestRate(rate),
      durationMonths(duration), issueDate(date), paidAmount(0.0), status("Active")
{
    calculateTotalPayable();
}

// Getters
int Loan::getLoanID() const { return loanID; }
int Loan::getMemberID() const { return memberID; }
double Loan::getLoanAmount() const { return loanAmount; }
double Loan::getInterestRate() const { return interestRate; }
int Loan::getDurationMonths() const { return durationMonths; }
double Loan::getTotalPayable() const { return totalPayable; }
double Loan::getPaidAmount() const { return paidAmount; }
double Loan::getRemainingBalance() const { return remainingBalance; }
string Loan::getIssueDate() const { return issueDate; }
string Loan::getStatus() const { return status; }

// Setters
void Loan::setStatus(string s) { status = s; }

// Operations
void Loan::calculateTotalPayable()
{
    // interest calculation
    double interest = loanAmount * (interestRate / 100.0) * (durationMonths / 12.0);
    totalPayable = loanAmount + interest;
    remainingBalance = totalPayable - paidAmount;
}

bool Loan::makeRepayment(double amount)
{
    if (amount > 0 && amount <= remainingBalance)
    {
        paidAmount += amount;
        remainingBalance -= amount;

        if (remainingBalance <= 0.01)
        { // Account for floating point precision
            remainingBalance = 0;
            status = "Completed";
        }
        return true;
    }
    return false;
}

void Loan::display() const
{
    cout << "\n+============================================================+\n";
    cout << "|                     LOAN DETAILS                           |\n";
    cout << "+============================================================+\n";
    cout << "| Loan ID         : " << setw(39) << left << loanID << "|\n";
    cout << "| Member ID       : " << setw(39) << left << memberID << "|\n";
    cout << "| Loan Amount     : $" << setw(38) << left << fixed << setprecision(2) << loanAmount << "|\n";
    cout << "| Interest Rate   : " << setw(38) << left << interestRate << "%|\n";
    cout << "| Duration        : " << setw(37) << left << durationMonths << " months|\n";
    cout << "| Total Payable   : $" << setw(38) << left << totalPayable << "|\n";
    cout << "| Paid Amount     : $" << setw(38) << left << paidAmount << "|\n";
    cout << "| Remaining       : $" << setw(38) << left << remainingBalance << "|\n";
    cout << "| Issue Date      : " << setw(39) << left << issueDate << "|\n";
    cout << "| Status          : " << setw(39) << left << status << "|\n";
    cout << "+============================================================+\n";
}

// File operations
string Loan::toFileString() const
{
    stringstream ss;
    ss << loanID << "|" << memberID << "|" << loanAmount << "|"
       << interestRate << "|" << durationMonths << "|" << totalPayable << "|"
       << paidAmount << "|" << remainingBalance << "|" << issueDate << "|" << status;
    return ss.str();
}

void Loan::fromFileString(const string &data)
{
    stringstream ss(data);
    string temp;

    getline(ss, temp, '|');
    loanID = stoi(temp);
    getline(ss, temp, '|');
    memberID = stoi(temp);
    getline(ss, temp, '|');
    loanAmount = stod(temp);
    getline(ss, temp, '|');
    interestRate = stod(temp);
    getline(ss, temp, '|');
    durationMonths = stoi(temp);
    getline(ss, temp, '|');
    totalPayable = stod(temp);
    getline(ss, temp, '|');
    paidAmount = stod(temp);
    getline(ss, temp, '|');
    remainingBalance = stod(temp);
    getline(ss, issueDate, '|');
    getline(ss, status, '|');
}