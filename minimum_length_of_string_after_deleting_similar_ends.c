#include <string.h>

int minimumLength(char* s)
 {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right && s[left] == s[right])
     {
        char pivot = s[left];
        
        while (left <= right && s[left] == pivot)
         {
            left++;
        }
        while (left <= right && s[right] == pivot)
         {
            right--;
        }
    }
    
    return right - left + 1;
}