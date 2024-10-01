#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <iostream>

namespace Bank {

class Customer {
public:
    Customer(int id, const string& name)
        : customer_id(id), customer_name(name) {}

    int GetCustomerId() const {
        return customer_id;
    }

    string GetCustomerName() const {
        return customer_name;
    }

    void DisplayCustomerInfo() const {
        cout << "Customer ID: " << customer_id << endl;
        cout << "Customer Name: " << customer_name << endl;
    }

private:
    int customer_id;
    string customer_name;
};

} 

#endif
