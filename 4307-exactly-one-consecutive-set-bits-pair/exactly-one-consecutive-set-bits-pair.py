class Solution:
    def consecutiveSetBits(self, n: int) -> bool:
        binary = bin(n)[2:]
        cnt = 0
        for bit in range(len(binary)-1):
            if binary[bit] == '1' and binary[bit+1] == '1':
                cnt += 1
        return cnt == 1

        