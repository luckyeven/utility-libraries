#include "circular_buffer.h"

// Constructor
template<typename T>
CircularBuffer<T>::CircularBuffer(size_t size)
    : buffer(size), head(0), tail(0), max_size(size), is_full(false) {}

// Push an element into the buffer
template<typename T>
void CircularBuffer<T>::push(T item) {
    buffer[head] = item;
    if (is_full) {
        tail = (tail + 1) % max_size;  // Overwrite tail when buffer is full
    }
    head = (head + 1) % max_size;
    is_full = head == tail;
}

// Pop an element from the buffer
template<typename T>
T CircularBuffer<T>::pop() {
    if (is_empty()) {
        throw std::runtime_error("Buffer is empty");
    }

    T item = buffer[tail];
    is_full = false;
    tail = (tail + 1) % max_size;
    return item;
}

// Check if the buffer is empty
template<typename T>
bool CircularBuffer<T>::is_empty() const {
    return (!is_full && (head == tail));
}

// Check if the buffer is full
template<typename T>
bool CircularBuffer<T>::is_full_buffer() const {
    return is_full;
}

// Get the current size of the buffer
template<typename T>
size_t CircularBuffer<T>::size() const {
    if (is_full) {
        return max_size;
    }

    if (head >= tail) {
        return head - tail;
    } else {
        return max_size + head - tail;
    }
}

// Clear the buffer
template<typename T>
void CircularBuffer<T>::clear() {
    head = tail = 0;
    is_full = false;
}

// Return the maximum capacity of the buffer
template<typename T>
size_t CircularBuffer<T>::capacity() const {
    return max_size;
}

// Access an element by index (from the tail)
template<typename T>
T& CircularBuffer<T>::operator[](size_t index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    return buffer[(tail + index) % max_size];
}
