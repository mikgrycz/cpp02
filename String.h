#include <iostream>
#include <memory>
#include "MyString.h"

class String {
    using string = emcpp::MyString;
    std::shared_ptr<string> pstr;

public:
    String() : pstr(std::make_shared<string>()) {}  // creates an empty string

    String(const char *str) : pstr(std::make_shared<string>(str)) {}  // copy C-string

    String(const String &s) : pstr(s.pstr) {}  // share the same string

    String &operator=(const String &s) {  // share the same string
        if (this != &s) {
            pstr = s.pstr;
        }
        return *this;
    }

    void set(int index, char ch) {
        if (pstr && pstr.use_count() > 1) {
            pstr = std::make_shared<string>(*pstr);  // make a copy
        }
        (*pstr)[index] = ch;
    }

    char get(int index) const {
        return (*pstr)[index];
    }

    friend String operator+(String a, String b) {
        if (!a.pstr->empty() && !b.pstr->empty()) {
            return String((a.pstr->c_str() + *b.pstr).c_str());
        }
        return String();
    }

    friend std::ostream &operator<<(std::ostream &out, String s) {
        out << *s.pstr;
        return out;
    }
};
