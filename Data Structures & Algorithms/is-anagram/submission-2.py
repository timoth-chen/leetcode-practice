class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        c_count = {}
        for c in s:
            c_count[c] = c_count.get(c,0) + 1
        t_count = {}
        for c in t:
            t_count[c] = t_count.get(c,0) + 1
        print(c_count)
        print(t_count)
        for key, value in c_count.items():
            if t_count.get(key, 0) != value:
                return False 
            
        return True