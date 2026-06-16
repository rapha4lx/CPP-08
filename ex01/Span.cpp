#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize)
        throw std::length_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::length_error("Not enough numbers to find a span");
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::length_error("Not enough numbers to find a span");
    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}
