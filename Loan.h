#ifndef LOAN_H
#define LOAN_H

#include <string>
using namespace std;

class Loan
{
private:
    int loanID;
    int memberID;
    double loanAmount;
    double interestRate;
    int durationMonths;
    double totalPayable;
    double paidAmount;
    double remainingBalance;
    string issueDate;
    string status; 

public:
    // Constructors
    Loan();
    Loan(int lId, int mId, double amount, double rate, int duration, string date);

    // Getters
    int getLoanID() const;
    int getMemberID() const;
    double getLoanAmount() const;
    double getInterestRate() const;
    int getDurationMonths() const;
    double getTotalPayable() const;
    double getPaidAmount() const;
    double getRemainingBalance() const;
    string getIssueDate() const;
    string getStatus() const;

    // Setters
    void setStatus(string s);

    // Operations
    void calculateTotalPayable();
    bool makeRepayment(double amount);
    void display() const;

    // File operations
    string toFileString() const;
    void fromFileString(const string &data);
};

#endif