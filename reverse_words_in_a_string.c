#include <string.h>
void reverse(char* s, int i, int j) {
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}
char* reverseWords(char* s)
 {
    int len = strlen(s);
    reverse(s, 0, len - 1);
    int writeIdx = 0;
    for (int i = 0; i < len; i++)
     {
        if (s[i] != ' ')
         {
            if (writeIdx != 0)
             {
                s[writeIdx++] = ' ';
            }
            int start = writeIdx;
            while (i < len && s[i] != ' ')
             {
                s[writeIdx++] = s[i++];
            }
            reverse(s, start, writeIdx - 1);
        }
    }
    s[writeIdx] = '\0';
    return s;
}