#include <iostream>
#include "circular_buffer.h"

int main() {
    CircularBuffer<int> cb(5);  // Circular buffer of size 5

    cb.push(1);
    cb.push(2);
    cb.push(3);
    cb.push(4);
    cb.push(5);

    std::cout << "Buffer full? " << (cb.is_full_buffer() ? "Yes" : "No") << std::endl;

    cb.push(6);  // Overwrite the oldest (1)

    std::cout << "Pop: " << cb.pop() << std::endl;  // Should return 2
    std::cout << "Pop: " << cb.pop() << std::endl;

    cb.push(7);
    cb.push(8);

    while (!cb.is_empty()) {
        std::cout << "Pop: " << cb.pop() << std::endl;
    }

    return 0;
}
