from collections import Counter

class ListNode:
    def __init__(self, key: int, value: int):
        self.right = None
        self.left = None  # Correct the case to 'left'
        self.val = value
        self.key = key

class LRUCache:
    def __init__(self, capacity: int):
        self.leastRecentDummy = ListNode(-1, 0)
        self.mostRecentDummy = ListNode(-2, 0)
        self.leastRecentDummy.right = self.mostRecentDummy
        self.mostRecentDummy.left = self.leastRecentDummy
        self.capacity = capacity
        self.nodeMap = {}

    def get(self, key: int) -> int:
        if key not in self.nodeMap:
            return -1
        node = self.nodeMap[key]
        # Remove node from its current position
        node.left.right = node.right
        node.right.left = node.left
        # Move node to the most recent position
        self.moveToMostRecent(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.nodeMap:
            self.nodeMap[key].val = value
            self.get(key)  # This will move the node to the most recent position
            return

        if len(self.nodeMap) == self.capacity:
            # Remove the least recently used node
            lru = self.leastRecentDummy.right
            self.leastRecentDummy.right = lru.right
            lru.right.left = self.leastRecentDummy
            del self.nodeMap[lru.key]

        # Create and insert the new node
        newNode = ListNode(key, value)
        self.nodeMap[key] = newNode
        self.moveToMostRecent(newNode)

    def moveToMostRecent(self, node):
        # Insert node just before mostRecentDummy
        temp = self.mostRecentDummy.left
        temp.right = node
        node.left = temp
        node.right = self.mostRecentDummy
        self.mostRecentDummy.left = node


        

"""
    Doubly linked list + hash map for O(1) lookup
    <--- Least Recent       Most Recent --->

    get() -- 
        Stitch the node's prev and next together, then move it to the right side

"""