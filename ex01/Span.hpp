#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        typename std::iterator_traits<Iterator>::difference_type count =
            std::distance(begin, end);
        if (_numbers.size() + static_cast<size_t>(count) > _maxSize)
            throw std::length_error("Not enough capacity to add range");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int   _maxSize;
    std::vector<int> _numbers;
};

#endif
