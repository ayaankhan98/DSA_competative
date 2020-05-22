/******************************************************************
 * CONCATENATION - 
 *              to concatenate two string we just need the string
 *              and this operation can be represented by
 *              concat(str1 , str2)
 * Algorithm -
 *              step1 -> calculate the length of both str1 and str2
 *              step2 -> create new memory location to hold the new string that is the concatenated version
 *                       length new string = length str1 + length str2
 *              step3 -> first copy the str1 character by chracter to new string 
 *                       after this copy the next string str2 in the new string from the index 
 *                       where the first string str1 ends
 *                       place the null character at the last
 * 
 * ***************************************************************/


#include <iostream>
#include <string.h>

char* concat(char* str1, char* str2)
{
    int len1 = strlen(str1), len2 = strlen(str2), i;
    char* newstr =  new char[len1+len2];
    for(i=0;i<=len1;++i)
        newstr[i] = str1[i];
    for(i=0;i<=len2;++i)
        newstr[len1+i] = str2[i];
    newstr[len1+len2] = '\0';
    return newstr;
}

int main()
{
    char* str1 = "This is First String";
    char* str2 = "This is Second String";
    char* str3 = concat(str1,str2);
    std::cout<<concat(str3,str1);
    std::cout<<std::endl;
    return 0;
}