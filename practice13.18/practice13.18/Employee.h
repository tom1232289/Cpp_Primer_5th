#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>	
#include <string>

using namespace std;

class Employee {
public:
	Employee() = default;
	Employee(const string sName):
		name(sName)
	{
		mysn = count++;
	}
	Employee(const Employee &e) {
		name = e.name;
		mysn = count++;
	}
	Employee &operator=(const Employee &rhs) {
		name = rhs.name;
		mysn = count++;
		return *this;
	}

	const string &getName() { return name; }
	int getMysn() { return mysn; }
	
private:
	string name;
	int mysn;
	static int count;
};

int Employee::count = 0;

void f(Employee &s) {
	cout << s.getName() << ":" << s.getMysn() << endl;
}


#endif // !EMPLOYEE_H