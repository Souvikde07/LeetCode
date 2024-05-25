class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left <= right:
            pair_sum = numbers[left] + numbers[right]
            if pair_sum < target:
                left += 1
            elif pair_sum > target:
                right -= 1
            else:
                return [left+1, right+1]
        return [-1, -1]