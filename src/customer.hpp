#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <iostream>

#include "types.hpp"

namespace Bank {

class Customer {
public:
    Customer(i32 id, const std::string& name)
        : customer_id(id), customer_name(name) {}

    i32 GetCustomerId() const {
        return customer_id;
    }

    std::string GetCustomerName() const {
        return customer_name;
    }

    void DisplayCustomerInfo() const {
        std::cout << "Customer ID: " << customer_id << std::endl;
        std::cout << "Customer Name: " << customer_name << std::endl;
    }

private:
    i32 customer_id;
    std::string customer_name;
};

} 

#endif
