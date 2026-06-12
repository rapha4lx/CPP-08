#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

void testVector() {
    std::cout << "=== Testing std::vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    const std::vector<int> cvec = vec;
    try {
        std::vector<int>::const_iterator it = easyfind(cvec, 20);
        std::cout << "Const found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testList() {
    std::cout << "\n=== Testing std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);

    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testDeque() {
    std::cout << "\n=== Testing std::deque ===" << std::endl;
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);

    try {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 999);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testVector();
    testList();
    testDeque();
    return 0;
}
