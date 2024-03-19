class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        ans = ""

        while (i >= 0 or j >= 0 or carry):
            sum = carry
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1

            ans += str(carry % 2)
            carry //= 2    

        return ans[::-1]

        

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")