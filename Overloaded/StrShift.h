#ifndef STRSHIFT_H
#define STRSHIFT_H

class StrShift
{
    public:
        StrShift();
        std::string str;
        StrShift(std::string);
        StrShift operator=(std::string);
        const char* operator<<(int);
        const char* operator>>(int);
        bool operator==(std::string);
        bool operator==(StrShift);
};



#endif
