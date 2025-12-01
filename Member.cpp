#include "Member.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// Constructors
Member::Member() : memberID(0), totalSavings(0.0), isActive(true) {}

Member::Member(int id, string n, string addr, string ph, string date)
    : memberID(id), name(n), address(addr), phone(ph), joinDate(date),
      totalSavings(0.0), isActive(true) {}

// Getters
int Member::getMemberID() const { return memberID; }
string Member::getName() const { return name; }
string Member::getAddress() const { return address; }
string Member::getPhone() const { return phone; }
string Member::getJoinDate() const { return joinDate; }
double Member::getTotalSavings() const { return totalSavings; }
bool Member::getIsActive() const { return isActive; }

// Setters
void Member::setName(string n) { name = n; }
void Member::setAddress(string addr) { address = addr; }
void Member::setPhone(string ph) { phone = ph; }
void Member::setTotalSavings(double amount) { totalSavings = amount; }
void Member::setIsActive(bool status) { isActive = status; }

// Operations
void Member::depositSavings(double amount)
{
    if (amount > 0)
    {
        totalSavings += amount;
    }
}

bool Member::withdrawSavings(double amount)
{
    if (amount > 0 && amount <= totalSavings)
    {
        totalSavings -= amount;
        return true;
    }
    return false;
}

void Member::display() const
{
    cout << "\n+============================================================+\n";
    cout << "|                    MEMBER DETAILS                          |\n";
    cout << "+============================================================+\n";
    cout << "| Member ID      : " << setw(40) << left << memberID << "|\n";
    cout << "| Name           : " << setw(40) << left << name << "|\n";
    cout << "| Address        : " << setw(40) << left << address << "|\n";
    cout << "| Phone          : " << setw(40) << left << phone << "|\n";
    cout << "| Join Date      : " << setw(40) << left << joinDate << "|\n";
    cout << "| Total Savings  : $" << setw(39) << left << fixed << setprecision(2) << totalSavings << "|\n";
    cout << "| Status         : " << setw(40) << left << (isActive ? "Active" : "Inactive") << "|\n";
    cout << "+============================================================+\n";
}

// File operations
string Member::toFileString() const
{
    stringstream ss;
    ss << memberID << "|" << name << "|" << address << "|"
       << phone << "|" << joinDate << "|" << totalSavings << "|" << isActive;
    return ss.str();
}

void Member::fromFileString(const string &data)
{
    stringstream ss(data);
    string temp;

    getline(ss, temp, '|');
    memberID = stoi(temp);
    getline(ss, name, '|');
    getline(ss, address, '|');
    getline(ss, phone, '|');
    getline(ss, joinDate, '|');
    getline(ss, temp, '|');
    totalSavings = stod(temp);
    getline(ss, temp, '|');
    isActive = (temp == "1");
}