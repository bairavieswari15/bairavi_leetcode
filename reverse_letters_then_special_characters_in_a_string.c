#include <string.h>
#include <stdlib.h>

char* reverseByType(char* s)
 {
    int len = strlen(s);
    char* letters = (char*)malloc((len + 1) * sizeof(char));
    char* specials = (char*)malloc((len + 1) * sizeof(char));
    int lCount = 0;
    int sCount = 0;
    for (int i = 0; i < len; i++)
     {
        if (s[i] >= 'a' && s[i] <= 'z')
         {
            letters[lCount++] = s[i];
        } else {
            specials[sCount++] = s[i];
        }
    }
    
    int lIdx = lCount - 1;
    int sIdx = sCount - 1;
    
    for (int i = 0; i < len; i++)
     {
        if (s[i] >= 'a' && s[i] <= 'z') 
        {
            s[i] = letters[lIdx--];
        } else {
            s[i] = specials[sIdx--];
        }
    }
    
    free(letters);
    free(specials);
    return s;
}