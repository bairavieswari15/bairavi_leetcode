class Solution:
    def maxArea(self, height: list[int]) -> int:
        left = 0
        right = len(height) - 1
        maxwater = 0
        while left < right:
            width = right - left
            currheight = min(height[left], height[right])
            currwater = width * currheight
            if currwater > maxwater:
                maxwater = currwater
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return maxwater