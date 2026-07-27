class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char = set()
        left = 0
        maxlength = 0
        for right in range(len(s)):
            while s[right] in char:
                char.remove(s[left])
                left += 1
            char.add(s[right])
            maxlength = max(maxlength, right - left + 1)
        
        return maxlength