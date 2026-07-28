#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s, int left, int right)
 {
    while (left < right)
     {
        if (s[left] != s[right])
         {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool check(char* a, char* b)
 {
    int left = 0;
    int right = strlen(a) - 1;
    
    while (left < right && a[left] == b[right])
     {
        left++;
        right--;
    }
    
    return isPalindrome(a, left, right) || isPalindrome(b, left, right);
}

bool checkPalindromeFormation(char* a, char* b)
 {
    return check(a, b) || check(b, a);
}