#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    // Example from subject
    std::cout << "=== Subject example ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    // Exception: span full
    std::cout << "\n=== Exception: span full ===" << std::endl;
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        try {
            sp.addNumber(4);
        } catch (const std::exception &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
    }

    // Exception: no span (0 or 1 element)
    std::cout << "\n=== Exception: no span ===" << std::endl;
    {
        Span sp(1);
        sp.addNumber(42);
        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
    }

    // addRange with iterators (10,000 numbers)
    std::cout << "\n=== Range fill: 10,000 numbers ===" << std::endl;
    {
        Span sp(10000);
        std::vector<int> big;
        for (int i = 0; i < 10000; ++i)
            big.push_back(i);
        sp.addRange(big.begin(), big.end());
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
    }

    // addRange overflow
    std::cout << "\n=== Range overflow exception ===" << std::endl;
    {
        Span sp(5);
        std::vector<int> big;
        for (int i = 0; i < 10; ++i)
            big.push_back(i);
        try {
            sp.addRange(big.begin(), big.end());
        } catch (const std::exception &e) {
            std::cout << "Caught: " << e.what() << std::endl;
        }
    }

    return 0;
}
