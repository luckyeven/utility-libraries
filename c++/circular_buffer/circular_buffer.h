#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <vector>
#include <stdexcept>

template<typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    size_t head;
    size_t tail;
    size_t max_size;
    bool is_full;

public:
    CircularBuffer(size_t size);

    void push(T item);
    T pop();
    bool is_empty() const;
    bool is_full_buffer() const;
    size_t size() const;
    void clear();
    size_t capacity() const;
    T& operator[](size_t index);
};

#include "circular_buffer.cpp"  

#endif
