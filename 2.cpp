#include<iostream>
#include<string>
using namespace std;
class Employee {
private:
	string name;
	float taxRate;
public:
	void setName(string n) {
		name = n;
	}
	string getName() { 
		return name;
	}
	virtual float calcSalary() {
		return 0;
	}
	Employee(string nam) {
		name = nam;
		taxRate = 0.5;
		calcSalary();
	}
	Employee() {
		string name = "";
		taxRate = 0;
		calcSalary();
	}
};
class Salaried: public Employee {
private:
	int salary;
public:
	Salaried(string n, int SalarySal) {
		salary = SalarySal;
		setName(n);
	}
	Salaried() {
		salary = 0;
		setName("");
	}
	float calcSalary() {
		float tax = salary * 0.05;
		return salary - tax;
	}
};
class Hourly: public Employee {
private:
	int hours, hourlyRate = 600, salary; float tax;
public:
	Hourly(string n, int hoursmain) {
		hours = hoursmain;
		setName(n);
	}
	Hourly() {
		hours = 1;
		setName("");
	}
	float calcSalary() {
		salary = hours * hourlyRate;
		float tax = salary * 0.05;
		return salary - tax;
	}
};
class Commissioned: public Employee {
private:
	int sales; float commissionRate = 400;
public:
	Commissioned(string n, int salesmain) {
		sales = salesmain;
		setName(n);
	}
	Commissioned() {
		sales = 1;
		setName("");
	}
	float calcSalary() {
		float salary;
		salary = sales * commissionRate;
		float tax = salary * 0.05;
		return salary - tax;
	}
};
int main() {
	int numemp, typeemp, hrs, sales, tax, salary; string name;
	cout << "Enter Number of Employees = ";
	cin >> numemp;
	Employee* EMP[10];
	for (int i = 0; i < numemp; ++i) {
		cout << "Enter Name of " << i + 1 << " Employee = ";
		cin >> name;
		cout << "Type of Employee = ";
		cin >> typeemp;
		if (typeemp == 1) {
			cout << "Enter Salary = ";
			cin >> salary;
			EMP[i] = new Salaried(name, salary);
		}
		else if (typeemp == 2) {
			cout << "Enter Hours = ";
			cin >> hrs;
			EMP[i] = new Hourly(name, hrs);
		}
		else if (typeemp == 3) {
			cout << "Enter Sales = ";
			cin >> sales;
			EMP[i] = new Commissioned(name, sales);
		}
		else
			cout << "Error, only 1, 2 or 3 valid inputs";
	}
	cout << "Employee Name\t Salary\n";
	for (int i = 0; i < numemp; ++i) {
		cout << EMP[i]->getName() << "\t\t" << EMP[i]->calcSalary() << endl;
	}
}