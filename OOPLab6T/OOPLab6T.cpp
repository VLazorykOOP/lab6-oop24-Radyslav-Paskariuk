// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

using namespace std;

#include "Lab6Example.h"

// #1
class Base1 {
public:
    int data1;
};

class Derived2 : public Base1 {
public:
    int data2;
};

class Derived3 : public Base1 {
public:
    int data3;
};

class Derived4 : public Derived2 {
public:
    int data4;
};

class Derived5 : public Derived2, public Derived4 {
public:
    int data5;
};

class Derived6 : public Base1, public Derived3, public Derived4 {
public:
    int data6;
};

//#2 
class Employee {
public:
    virtual double calculateSalary() const = 0;
};

// Похідні класи
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

class SalariedEmployee : public Employee {
private:
    double salary;

public:
    SalariedEmployee(double s) : salary(s) {}

    double calculateSalary() const override {
        return salary;
    }
};


class CommissionEmployee : public Employee {
private:
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(double sales, double rate) : salesAmount(sales), commissionRate(rate) {}

    double calculateSalary() const override {
        return salesAmount * commissionRate;
    }
};

int main()
{
    //#1
    std::cout << "#1\n";
    Base1 obj1;
    Derived2 obj2;
    Derived3 obj3;
    Derived4 obj4;
    Derived5 obj5;
    Derived6 obj6;

    cout << "Size of Base1: " << sizeof(obj1) << " bytes" << endl;
    cout << "Size of Derived2: " << sizeof(obj2) << " bytes" << endl;
    cout << "Size of Derived3: " << sizeof(obj3) << " bytes" << endl;
    cout << "Size of Derived4: " << sizeof(obj4) << " bytes" << endl;
    cout << "Size of Derived5: " << sizeof(obj5) << " bytes" << endl;
    cout << "Size of Derived6: " << sizeof(obj6) << " bytes" << endl;

    //#2
    std::cout << "#2\n";
    HourlyEmployee hourlyEmp(15, 10);
    SalariedEmployee salariedEmp(300);
    CommissionEmployee commissionEmp(500, 1);

    cout << "Hourly Employee Salary: $" << hourlyEmp.calculateSalary() << endl;
    cout << "Salaried Employee Salary: $" << salariedEmp.calculateSalary() << endl;
    cout << "Commission Employee Salary: $" << commissionEmp.calculateSalary() << endl;

    return 0;

}