#pragma once
#include <iostream>
#include <memory>
#include "Box.h"

class Container {
    // Use smart pointer.
    std::unique_ptr<Box> pbox = nullptr;
public:
    static bool verbose;
    Container(int content): pbox(new Box(content)) {
        if(verbose) std::cout << "Creating Container" << std::endl;
    }
    // Implement copy constructor and copy assignment operator
    Container(const Container & container): pbox(new Box(*container.pbox)) {
        if(verbose) std::cout << "Copying Container" << std::endl;
    }
Container& operator=(const Container& other) {
    if (this != &other) {
        if (verbose) std::cout << "Copy assignment operator for Container\n";
        if (pbox != nullptr && other.pbox != nullptr) {
            *pbox = *other.pbox;
        } else if (other.pbox != nullptr) {
            pbox = std::make_unique<Box>(*other.pbox);
        }
    }
    return *this;
}

    // Implement move constructor and move assignment operator
    Container(Container && container) noexcept : pbox(std::move(container.pbox)) {
        if(verbose) std::cout << "Moving Container\n";
    }
    Container & operator=(Container &&container) noexcept {
        if(this != &container) {
            if(verbose) std::cout << "Moving Container\n";
            pbox = std::move(container.pbox);
        }
        return *this;
    }
    ~Container() {
        if(verbose) std::cout << "Destroying Container \n";
    }
    friend std::ostream & operator << (std::ostream & out, const Container & p){
        return (out << " [" << p.pbox->getContent() << "] ");
    }
    // Overload the + operator
    inline Container operator+(const Container &other) const {
        return Container(this->pbox->getContent() + other.pbox->getContent());
    }
};
bool Container::verbose = false;