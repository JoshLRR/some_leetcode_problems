class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # s = s.replace(" ", "")
        left = 0
        right = len(s) - 1
        print(s)

        while (left < right):
            while left < right and not s[left].isalnum():
                left +=1
            while left < right and not s[right].isalnum():
                right -= 1
            if (s[left] is not s[right]):
                return False
            left += 1
            right -= 1

        return True
        
# assert Solution(). == , "Test failed!"
Solution().isPalindrome("poop    POOOOP poooop    pooooop;;;:::''")

print("\033[32mAll tests passed!\033[0m\n")