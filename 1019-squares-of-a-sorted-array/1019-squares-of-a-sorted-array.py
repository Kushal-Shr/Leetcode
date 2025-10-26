class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        if nums[0] >= 0:
            for i in range(len(nums)):
                nums[i] = nums[i] ** 2
            return nums
        
        left = 0
        right = len(nums) - 1
        pos = len(nums) - 1

        ans = [0] * len(nums)

        while left <= right:
            
            if abs(nums[left]) > abs(nums[right]):
                ans[pos] = nums[left] ** 2
                left += 1
            else:
                ans[pos] = nums[right] ** 2
                right -= 1

            pos -= 1

        return ans
                    


