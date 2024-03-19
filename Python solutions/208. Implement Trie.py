class TrieNode:
    def __init__(self):
        self.endOfWord = False
        self.nextChars = {} # <char, TrieNode>

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root

        for char in word:
            if char not in curr.nextChars:
                curr.nextChars[char] = TrieNode()
            curr = curr.nextChars[char]

        curr.endOfWord = True

    def search(self, word: str) -> bool:
        curr = self.root

        for char in word:
            if char in curr.nextChars:
                curr = curr.nextChars[char]
            else:
                return False
        
        return curr.endOfWord

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for char in prefix:
            if char in curr.nextChars:
                curr = curr.nextChars[char]
            else:
                return False
        
        return True

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")