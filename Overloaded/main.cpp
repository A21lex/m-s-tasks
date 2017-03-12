#include <iostream>
#include <stdio.h>
#include "StrShift.h"
using namespace std;

int main()
{
    StrShift example;
    example = "Microsoft";

    printf("\"example << 2\" results in %s\n", example << 2);
    printf("\"example << 2\" second time results in %s\n", example << 2);
    printf("\"example >> 3\" results in %s\n", example >> 3);
    if(example == "tMicrosof"){
        cout << "example is indeed tMicrosof" << endl;
    }

}
