// This C++ program checks whether a string is a palindrome or not, after removing all non-alpha-numeric characters
// The problem was found on NeetCode
// Written by Daniel Tamele, 12.04.2025

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    bool palindromeness = true;

    // Remove non-alphanumeric characters from string
    s.erase(remove_if(s.begin(), s.end(), [](unsigned char c)
    {
        return !isalnum(c);
    }), s.end());

    // Convert the string to lowercase
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
    {
        return tolower(c);
    });

    // Getting the string length of the modified string
    int string_length = s.length();

    // Checking the strings characters from both sides
    int j = string_length - 1;
    for (int i = 0; i < string_length / 2; i++)
    {
        if (s[i] != s[j])
        {
            palindromeness = false;
            break;
        }
        else
        {
            j--;
        }
    }

    return palindromeness;
}

int main()
{
   bool test = isPalindrome("Was it a car or a cat I saw?");
   cout << test << endl;
   bool test2 = isPalindrome("This is not a Palindrome!");
   cout << test2;
}
