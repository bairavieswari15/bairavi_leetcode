#include <string.h>
#include <stdlib.h>

#define INF 1000000000

int maxRemovals(char* source, char* pattern, int* targetIndices, int targetIndicesSize)
 {
    int m = strlen(source);
    int n = strlen(pattern);
    
    char* isTarget = (char*)calloc(m, sizeof(char));
    for (int i = 0; i < targetIndicesSize; i++)
     {
        isTarget[targetIndices[i]] = 1;
    }
    
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    for (int j = 0; j <= n; j++)
     {
        dp[j] = -INF;
    }
    dp[0] = 0;
    
    for (int i = 0; i < m; i++)
     {
        int is_del = isTarget[i];
        int* next_dp = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            next_dp[j] = -INF;
        }
        
        for (int j = 0; j <= n; j++)
         {
            if (dp[j] != -INF) {
                if (dp[j] + is_del > next_dp[j])
                 {
                    next_dp[j] = dp[j] + is_del;
                }
                
                if (j < n && source[i] == pattern[j]
                ) {
                    if (dp[j] > next_dp[j + 1])
                     {
                        next_dp[j + 1] = dp[j];
                    }
                }
            }
        }
        free(dp);
        dp = next_dp;
    }
    
    int result = dp[n];
    free(isTarget);
    free(dp);
    return result;
}