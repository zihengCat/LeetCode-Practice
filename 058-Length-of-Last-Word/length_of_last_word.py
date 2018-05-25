class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = s.split(' ')
        #print(l)
        if (len(l[len(l) - 1]) == 0):
            return len(l[len(l) - 2])
        else:
            return len(l[len(l) - 1])



if __name__ == '__main__':
    s = Solution()
    print(s.lengthOfLastWord('a '))

