#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void getMaxSubsequence(int* nums, int size, int k, int* out)
 {
    int top = 0;
    int drop = size - k;
    for (int i = 0; i < size; i++)
     {
        while (top > 0 && out[top - 1] < nums[i] && drop > 0)
         {
            top--;
            drop--;
        }
        if (top < k) {
            out[top++] = nums[i];
        } else {
            drop--;
        }
    }
}

bool isGreater(int* nums1, int len1, int i, int* nums2, int len2, int j)
 {
    while (i < len1 && j < len2) {
        if (nums1[i] > nums2[j]) return true;
        if (nums1[i] < nums2[j]) return false;
        i++;
        j++;
    }
    return i < len1;
}

void merge(int* sub1, int len1, int* sub2, int len2, int* out)
 {
    int i = 0, j = 0, r = 0;
    while (i < len1 || j < len2)
     {
        if (isGreater(sub1, len1, i, sub2, len2, j))
         {
            out[r++] = sub1[i++];
        } else {
            out[r++] = sub2[j++];
        }
    }
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize)
 {
    *returnSize = k;
    int* ans = (int*)calloc(k, sizeof(int));
    int* sub1 = (int*)malloc(k * sizeof(int));
    int* sub2 = (int*)malloc(k * sizeof(int));
    int* candidate = (int*)malloc(k * sizeof(int));

    int start = (k - nums2Size > 0) ? k - nums2Size : 0;
    int end = (k < nums1Size) ? k : nums1Size;

    for (int i = start; i <= end; i++)
     {
        int j = k - i;
        getMaxSubsequence(nums1, nums1Size, i, sub1);
        getMaxSubsequence(nums2, nums2Size, j, sub2);
        merge(sub1, i, sub2, j, candidate);

        if (isGreater(candidate, k, 0, ans, k, 0))
         {
            memcpy(ans, candidate, k * sizeof(int));
        }
    }
    free(sub1);
    free(sub2);
    free(candidate);
    return ans;
}