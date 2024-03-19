from typing import List
import math
class Solution:
    def __init__(self):
        self.operands = [
            '+',
            '-',
            '/',
            '*'
        ]

    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        result = 0
        for token in tokens:
            if token not in self.operands:
                stack.append(int(token))
            elif token in self.operands:
                operand2 = int(stack.pop())
                operand1 = int(stack.pop())

                if token == '+':
                    result = operand2 + operand1
                elif token == '-':
                    result = operand1 - operand2
                elif token == '/':
                    result = int(operand1 / operand2)
                elif token == '*':
                    result = operand1 * operand2
                # print(result)
                stack.append(result)

        ans = stack.pop()
        # print(ans)
        return ans

tokens1 = ["2","1","+","3","*"]
ans1 = 9
assert Solution().evalRPN(tokens1) == ans1, "Test failed!"

tokens2 = ["4","13","5","/","+"]
ans2 = 6
assert Solution().evalRPN(tokens2) == ans2, "Test failed!"

tokens3 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
ans3 = 22
assert Solution().evalRPN(tokens3) == ans3, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")