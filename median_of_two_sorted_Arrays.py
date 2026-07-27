class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1 
        m, n = len(nums1), len(nums2)
        total = m + n
        half = (total + 1) // 2
        left = 0
        right = m
        while left <= right:
            mid = (left + right) // 2  
            j = half - mid        
            if mid < m and nums2[j-1] > nums1[mid]:
                left = mid + 1
            elif mid > 0 and nums1[mid-1] > nums2[j]:
                right = mid - 1
            else:
                if mid == 0:
                    max_left = nums2[j-1]
                elif j == 0:
                    max_left = nums1[mid-1]
                else:
                    max_left = max(nums1[mid-1], nums2[j-1])
                if total % 2 == 1:
                    return float(max_left)
                if mid == m:
                    min_right = nums2[j]
                elif j == n:
                    min_right = nums1[mid]
                else:
                    min_right = min(nums1[mid], nums2[j])
                    
                return (max_left + min_right) / 2.0