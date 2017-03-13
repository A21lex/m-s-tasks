#include <iostream>
#include <stdio.h>
#include "StrShift.h"
#include <cstring>
using namespace std;

StrShift::StrShift()
{

}

StrShift::StrShift(string text){
    str = text;
}

/**
    Overloaded assignment operator assigns a string to a "str" field of a StrShift object
*/
StrShift StrShift::operator=(string passingString){
    cout << "Using overloaded assignment operator" << endl;
    cout << "String passed to StrShift is: " << passingString << endl;
    (*this).str = passingString;
    return(*this);

}
/**
    Overloaded == operator for a string checks equality of a StrShift object with the given string
*/
bool StrShift::operator==(string stringToCheck){
    cout << "Using overloaded == operator" << endl;
    cout << "Checking if " << (*this).str << " is equal to " << stringToCheck << endl;
    if((*this).str == stringToCheck){
        return true;
    }
    return false;
}
/**
    Overloaded == operator for a StrShift object checks equality of the StrShift object with another StrShift object
    (checking if their strs are the same)
*/
bool StrShift::operator==(StrShift anotherStrShift){
    cout << "Using overloaded == operator" << endl;
    cout << "Checking if " << (*this).str << " is equal to " << anotherStrShift.str << endl;
    if((*this).str == anotherStrShift.str){
        return true;
    }
    return false;
}

/**
    Overloaded << shifts characters of a string to the left by a defined value
*/
const char* StrShift::operator<<(int num){
    if (num < 0){
            num = (*this).str.length() + num;
    }
    cout << "Shifting characters with left arrows by value : " << num << endl;
    string currentString = (*this).str;
    num %= currentString.length(); //num must be mod stringLength to avoid trying to access unassigned memory
    const char *chars = currentString.c_str();
    char *keepShifted = new char[currentString.length()-num];
    char *moveLeft = new char[num + 1];
    for (int i = currentString.length() - 1; i >= 0; i--){
        if (i >= (currentString.length() - num)){
            moveLeft[i-(currentString.length()-num)] = chars[i];
        }
        else{
            keepShifted[i] = chars[i];
            continue;
        }
    }
    char result[currentString.length()];
    strcpy(result, moveLeft);
    strcat(result, keepShifted);
    //strcat(result, '\0');
    //Assign the string value to the string of the object
    (*this).str = result;
    const char* resultCharArray = result;
    return resultCharArray;
}

/**
    Overloaded >> shifts characters of a string to the right by a defined value
*/
const char* StrShift::operator>>(int num){
    if (num < 0){
            num = (*this).str.length() + num;
    }
    cout << "Shifting characters with right arrows by value: " << num << endl;
    string currentString = (*this).str;
    num %= currentString.length(); //num must be mod stringLength to avoid trying to access unassigned memory
    const char *chars = currentString.c_str();
    char *keepShifted = new char[num+1];
    char *moveRight = new char[currentString.length()-num];
    for (int i = 0; i < currentString.length(); i++){
        if (i < num){
            keepShifted[i] = chars[i];
            continue;
        }
        else{
            moveRight[i-num] = chars[i];
        }
    }
    char result[currentString.length()];
    strcpy(result, moveRight);
    strcat(result, keepShifted);
    //Assign the string value to the string of the object
    (*this).str = result;
    const char* resultCharArray = result;
    return resultCharArray;
}
