#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdexcept>
#include <limits>

class utilities
{
public:
    static void ignoreCin();
    static int getNumberFunction(std::string);
    static std::string getStringFunction(std::string);
};

#endif
