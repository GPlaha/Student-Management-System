#ifndef CLUB_H
#define CLUB_H
#include <string>

class Club
{
    std::string activity; 
    
    public:
    void setActivity(std::string);
    std::string getActivity();
};

#endif