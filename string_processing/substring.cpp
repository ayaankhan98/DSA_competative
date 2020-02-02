/*********************************************************************
 * SUBSTRING - 
 *              Accessing a substring from a given string requires three pieces of information
 *              (1) - the name of the string or string itself
 *              (2) - the positon of the first character of the substring in the given string
 *              (3) - the length of the substring or the position of the last character of the substring
 * 
 *  Thus, this operation can be represnted by -
 *                  substring (string, initial, lenght)
 * example - 
 *          substring("abcdefghi",3,4) => cdef
 * 
 * Algorithm - 
 *              pass the string , initial index , lenght of required substring to substring function
 *              if length is 0
 *                  then string underflow
 *              else if length of substring is less than or equal to the remaning string from the initial index
 *                  then copy the string of given lenght in an array and return it
 *              else
 *                  substring required is having more lenght thus, string overflow
 * 
 * *******************************************************************/


#include <iostream>
#include <string>

std::string substring(std::string str, int initial, int length)
{
    int i;
    char substring[length];
    if(length == 0)
        return "String UnderFlow !";
    else if (length <= str.length() - initial + 1)
    {
        for(i=0;i<length;++i)
        {
            substring[i] = str[initial + i -1];
        }
        substring[i] = '\0';
        return substring;
    }
    return "Substring Overflow !";
}

int main()
{
    std::string str = "abcdefghi";
    std::cout<<substring(str,3,1);   // Output =>    c
    std::cout<<substring(str,3,7);   // Output =>    cdefghi
    std::cout<<substring(str,3,8);   // Output =>    String Overflow !
    std::cout<<std::endl;
    return 0;
}