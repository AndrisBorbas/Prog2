#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

struct Serializable {
    virtual void write(std::ostream &) const {}
    virtual void read(std::istream &)  {}
    virtual ~Serializable() {}
};

#endif // SERIALIZABLE_H
