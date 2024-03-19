class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        brackets = {')':'(', '}':'{', ']':'['}

        for char in s:
            if char in brackets.values():
                stack.append(char)
            elif char in brackets.keys():
                if (stack == [] or brackets[char] != stack.pop()):
                    return False
            else:
                return False
        
        return stack == []

# Create a dict of close bracket to its open bracket
# Scan each char in s, if it's a relevant char add it to the stack
#   if it's a close bracket remove 

s1 = "()"
assert Solution().isValid(s1) == True, "Test failed!"

s2 = "()[]{}"
assert Solution().isValid(s2) == True, "Test failed!"

s3 = "(]"
assert Solution().isValid(s3) == False, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")