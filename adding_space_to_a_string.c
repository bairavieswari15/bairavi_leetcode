#include <string.h>
#include <stdlib.h>
char* addSpaces(char* s, int* spaces, int spacesSize)
 {
    int len = strlen(s);
    char* result = (char*)malloc((len + spacesSize + 1) * sizeof(char));
    int sIdx = 0;
    int spaceIdx = 0;
    int resIdx = 0;
    while (sIdx < len)
     {
        if (spaceIdx < spacesSize && sIdx == spaces[spaceIdx])
         {
            result[resIdx++] = ' ';
            spaceIdx++;
        }
        result[resIdx++] = s[sIdx++];
    }
    result[resIdx] = '\0';
    return result;
}