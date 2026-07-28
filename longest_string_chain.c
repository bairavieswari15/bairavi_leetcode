#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compareStrings(const void* a, const void* b)
 {
    return strlen(*(const char**)a) - strlen(*(const char**)b);
}

bool isPredecessor(const char* w1, const char* w2)
 {
    int len1 = strlen(w1);
    int len2 = strlen(w2);
    if (len1 + 1 != len2) return false;
    
    int i = 0, j = 0;
    while (i < len1 && j < len2)
     {
        if (w1[i] == w2[j])
         {
            i++;
        }
        j++;
    }
    return i == len1;
}

int longestStrChain(char** words, int wordsSize)
 {
    qsort(words, wordsSize, sizeof(char*), compareStrings);
    
    int* dp = (int*)malloc(wordsSize * sizeof(int));
    int maxChain = 1;
    
    for (int i = 0; i < wordsSize; i++)
     {
        dp[i] = 1;
    }
    
    for (int i = 1; i < wordsSize; i++)
     {
        for (int j = 0; j < i; j++)
         {
            if (isPredecessor(words[j], words[i]))
             {
                if (dp[j] + 1 > dp[i])
                 {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > maxChain)
         {
            maxChain = dp[i];
        }
    }
    
    free(dp);
    return maxChain;
}