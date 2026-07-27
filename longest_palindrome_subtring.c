#include <string.h>
#include <stdlib.h>
int expandAroundCenter(char* s, int left, int right, int len)
{
    while(left >= 0 && right < len && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s)
{
    if(s==NULL||strlen(s)<1)
    {
        char* empty =(char*)malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    int len = strlen(s);
    int start = 0, max_len = 0;
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i, len);
        int len2 = expandAroundCenter(s, i, i + 1, len);
        int current_max = len1 > len2 ? len1 : len2;
        if (current_max > max_len)
        {
            max_len = current_max;
            start = i - (current_max - 1) / 2;
        }
    }
    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';
    return result;
}