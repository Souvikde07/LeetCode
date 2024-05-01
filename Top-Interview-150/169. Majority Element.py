#using hashmap - Easy Solution
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = {}
        res, maxCount = 0, 0

        for n in nums:
            count[n] = 1 + count.get(n,0)
            res = n if count[n] > maxCount else res
            maxCount = max(count[n],maxCount)
        return res

#To solve it in linear time and O(1) space - Boyers Moore Algorithm
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res, count = 0, 0
        for n in nums:
            if count == 0:
                res = n
            count+= (1 if n == res else -1)
        return res
