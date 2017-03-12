#ifndef SALLY_H
#define SALLY_H

class Sally
{
    public:
        Sally();
        std::string str;
        Sally(std::string);
        Sally operator=(std::string);
        const char* operator<<(int);
        const char* operator>>(int);
};



#endif
