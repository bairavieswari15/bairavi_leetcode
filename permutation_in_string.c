#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2)
 {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 > len2)
     {
        return false;
    }
    
    int s1Count[26] = {0};
    int s2Count[26] = {0};
    
    for (int i = 0; i < len1; i++)
     {
        s1Count[s1[i] - 'a']++;
        s2Count[s2[i] - 'a']++;
    }
    
    int matches = 0;
    for (int i = 0; i < 26; i++)
     {
        if (s1Count[i] == s2Count[i])
         {
            matches++;
        }
    }
    
    for (int i = 0; i < len2 - len1; i++)
     {
        if (matches == 26)
         {
            return true;
        }
        
        int r = s2[i + len1] - 'a';
        s2Count[r]++;
        if (s2Count[r] == s1Count[r])
         {
            matches++;
        } else if (s2Count[r] == s1Count[r] + 1)
         {
            matches--;
        }
        
        int l = s2[i] - 'a';
        s2Count[l]--;
        if (s2Count[l] == s1Count[l])
         {
            matches++;
        } else if (s2Count[l] == s1Count[l] - 1)
         {
            matches--;
        }
    }
    
    return matches == 26;
}