/*
Usage:  A String Replacement Problem
Author: Annie Kim
Date:   Aug 19, 2013
Problem Link:   http://leetcode.com/2010/11/microsoft-string-replacement-problem.html
*/

#include <iostream>
using namespace std;

bool isMatch(char *str, const char *pattern)
{
    while (*pattern)
        if (*str++ != *pattern++)
            return false;
    return true;
}

void replace(char str[], const char *pattern) 
{
    int N = strlen(str);
    int M = strlen(pattern);
    int index = -1;
    int i = 0;
    while (i < N)
    {
        if (i <= N - M && isMatch(str + i, pattern))
        {
            if (index == -1 || str[index] != 'X')
                str[++index] = 'X';
            i += M;
        }
        else
        {
            str[++index] = str[i++];
        }
    }
    str[++index] = '\0';
}
/*
int main()
{
    char str[] = "aabbaabbaaabbbaabb";
    const char *pattern = "aaabb";
    replace(str, pattern);
    cout << str << endl;
    return 0;
}
*/