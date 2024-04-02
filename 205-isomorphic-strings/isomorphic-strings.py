class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        m = Counter()
        p = Counter()
        n = len(s)
        for c in range(len(s)):
            if s[c] in m and m[s[c]] != t[c]:
                return False
            elif s[c] not in m and t[c] in p:
                return False
            m[s[c]] = t[c]
            p[t[c]] += 1
        
        return True