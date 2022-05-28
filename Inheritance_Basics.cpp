// Demonstration of Inheritance


#include<iostream>
#include<string>
using namespace std;
class Employee {
	string name;
public:
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	Employee(string nam) {
		name = nam;
	}
	Employee() {
		string name = "";
	}
	virtual string raiseSalary() {
		return 0;
	}
	virtual Employee* promote(Employee *pro) {
		return 0;
	}
	virtual string transfer() {
		return 0;
	}
	virtual string getType() {
		return 0;
	}
};
class Manager : public Employee {
	string s, t, q;
public:
	Manager(string n) {
		setName(n);
	}
	Manager() {
		setName("");
	}
	string raiseSalary() {
		s = "Salary of this Manager has been increased.";
		return s;
	}
	Employee* promote(Employee *pro) {
		cout << "This Manager has been promoted to an Upper Manager.";
		pro = new Manager(getName());
		return pro;
	}
	string transfer() {
		t = "Salary of this Manager has been Transferred.";
		return t;
	}
	string getType() {
		q =  "Status is Manager.";
		return q;
	}
};
class Engineer :public Employee {
	string s, t, q;
public:
	Engineer(string n) {
		setName(n);
	}
	Engineer() {
		setName("");
	}
	string raiseSalary() {
		s = "Salary of this Engineer has been increased.";
		return s;
	}
	Employee* promote(Employee *pro) {
		delete pro;
		pro = new Manager(getName());
		return pro;
	}
	string transfer() {
		t = "Salary of this Engineer has been Transferred.";
		return t;
	}
	string getType() {
		q = "Status is Engineer.";
		return q;
	}
};
class Worker :public Employee {
	string s, t, q;
public:
	Worker(string n) {
		setName(n);
	}
	Worker() {
		setName("");
	}
	string raiseSalary() {
		s = "Salary of this Worker has been increased.";
		return s;
	}
	Employee* promote(Employee *pro) {
        delete pro;
		pro = new Engineer(getName());
		return pro;
	}
	string transfer() {
		t = "Salary of this Worker has been Transferred.";
		return t;
	}
	string getType() {
		q = "Status is Worker.";
		return q;
	}
};
int main() {
	int numEmp, numTask; string name, typeEmp, task;
	cout << "Enter Number of Employees = ";
	cin >> numEmp;
	Employee* Emp[numEmp];
	for (int i = 0; i < numEmp; ++i) {
		cout << "Enter Name of " << i + 1 << " Employee = ";
		cin >> name;
		cout << "Type of Employee = ";
		cin >> typeEmp;
		if (typeEmp == "Manager") {
			Emp[i] = new Manager(name);
		}
		if (typeEmp == "Engineer") {
			Emp[i] = new Engineer(name);
		}
		if (typeEmp == "Worker") {
			Emp[i] = new Worker(name);
		}
	}
	for (int i = 0; i < numEmp; ++i) {
		cout << "Employee Name = "<< Emp[i]->getName() << endl;
		cout <<"Number of tasks to be peformed on this Employee = ";
		cin >> numTask;
		for (int j = 0; j < numTask; ++j) {
			cout << "Enter the task that you wish to perform: ";
			cin >> task;
			if (task == "RaiseSalary") {
				cout << Emp[i]->raiseSalary();
			}
			if (task == "Promote") {
				Emp[i]->promote(Emp[i]);
				cout << Emp[i]->getType();
			}
			if (task == "Transfer") {
				cout << Emp[i]->transfer();
			}
			cout << endl;
		}
	}
	return 0;
}
