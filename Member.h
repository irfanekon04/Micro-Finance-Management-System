#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;

class Member
{
private:
    int memberID;
    string name;
    string address;
    string phone;
    string joinDate;
    double totalSavings;
    bool isActive;

public:
    // Constructors
    Member();
    Member(int id, string n, string addr, string ph, string date);

    // Getters
    int getMemberID() const;
    string getName() const;
    string getAddress() const;
    string getPhone() const;
    string getJoinDate() const;
    double getTotalSavings() const;
    bool getIsActive() const;

    // Setters
    void setName(string n);
    void setAddress(string addr);
    void setPhone(string ph);
    void setTotalSavings(double amount);
    void setIsActive(bool status);

    // Operations
    void depositSavings(double amount);
    bool withdrawSavings(double amount);
    void display() const;

    // File operations
    string toFileString() const;
    void fromFileString(const string &data);
};

#endif