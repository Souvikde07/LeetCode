#O(n) : TC
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        #[3,0,6,1,5]
        #[0,1,3,5,6]
        # 5 4 3 2 1
        n = len(citations)
        temp = [0 for _ in range(n+1)]
        for i,v in enumerate(citations):
            if v > n:
                temp[n] += 1
            else:
                temp[v] += 1
        total = 0
        for i in range(n, -1, -1):
            total += temp[i]
            if total >= i : return i

#O(nlogn) : TC(sorting)
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        citations.sort()
        for i, v in enumerate(citations):
            if n-i <= v:
                return n-i
        return 0