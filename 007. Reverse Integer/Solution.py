class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            v = int(str(x)[1:][::-1])
            if v > 2**31:
                return 0
            else:
                return -v
        else:
            v = int(str(x)[::-1])
            if v > 2**31-1:
                return 0
            else:
                return v