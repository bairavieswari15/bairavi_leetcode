#include <string.h>
int strStr(char* haystack, char* needle)
 {
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    if (l2 == 0) return 0;
    for (int i = 0; i <= l1 - l2; i++) 
    {
        int j = 0;
        while (j < l2 && haystack[i + j] == needle[j])
         {
            j++;
        }
        if (j == l2)
         {
            return i;
        }
    }
    return -1;
}