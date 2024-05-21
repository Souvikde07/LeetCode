class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
    
        n = len(needle)
        m = len(haystack)  
        for i in range(m+1-n):
            for j in range(n):
                if(haystack[i+j] != needle[j]):
                    break
                if j==n-1:
                    return i
        return -1