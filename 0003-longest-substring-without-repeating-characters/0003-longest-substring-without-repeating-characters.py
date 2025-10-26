class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = i + 1

        maxLength = 0
        temp = set()

        if len(s) == 1:
            return 1

        while j < len(s):
            if not temp:
                temp.add(s[i])
                length = 1
            
            if s[j] in temp:
                i += 1
                j = i + 1
                temp = set()
            
            else:
                temp.add(s[j])
                length += 1
                j += 1
        
            maxLength = max(maxLength, length)

        return maxLength