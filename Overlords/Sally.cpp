#include <iostream>
#include <stdio.h>
#include "Sally.h"
#include <cstring>
using namespace std;

Sally::Sally()
{

}

Sally::Sally(string text){
    str = text;
}

/**
    Overloaded assignment operator assigns a string to a "str" field of a Sally object
*/
Sally Sally::operator=(string passingString){
    cout << "Using overloaded assignment operator" << endl;
    cout << "String passed to Sally is: " << passingString << endl;
    (*this).str = passingString;
    return(*this);

}
/**
    Overloaded == operator checks equality of a Sally object with a given string
*/
bool Sally::operator==(string stringToCheck){
    cout << "Using overloaded == operator" << endl;
    cout << "Checking if " << (*this).str << " is equal to " << stringToCheck << endl;
    if((*this).str == stringToCheck){
        return true;
    }
    return false;
}

/**
    Overloaded << shifts characters of a string to the left by a defined value
*/
const char* Sally::operator<<(int num){
    cout << "Shifting characters with left arrows by value : " << num << endl;
    string currentString = (*this).str;
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
    //Assign the string value to the string of the object
    (*this).str = result;
    const char* resultCharArray = result;
    return resultCharArray;
}

/**
    Overloaded >> shifts characters of a string to the right by a defined value
*/
const char* Sally::operator>>(int num){
    cout << "Shifting characters with right arrows by value: " << num << endl;
    string currentString = (*this).str;
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
