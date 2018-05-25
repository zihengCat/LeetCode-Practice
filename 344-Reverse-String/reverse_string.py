class Solution:
    def reverseString(self, s):
        l = list(s)
        l.reverse()
        ret = "".join(l)
        return ret

if __name__ == '__main__':
    s = Solution()
    print(s.reverseString("hello"))

