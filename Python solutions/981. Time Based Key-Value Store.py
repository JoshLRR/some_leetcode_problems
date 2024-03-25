class TimeMap:

    def __init__(self):
        self.mainDict = {}

    def set(self, key: str, value: str, timestamp: int) -> None:

        if key not in self.mainDict:
            self.mainDict[key] = [(timestamp, value)]
        else:
            self.mainDict[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        
        if key in self.mainDict:
            left = 0
            right = len(self.mainDict[key]) - 1

            while left <= right:
                mid = left + (right - left) // 2
                if self.mainDict[key][mid][0] < timestamp:
                    left = mid + 1
                elif self.mainDict[key][mid][0] > timestamp:
                    right = mid - 1
                else:
                    return self.mainDict[key][mid][1]

            if right >= 0:
                return self.mainDict[key][right][1]
        
        return ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

""" 
    

    set -- 

    get -- 
        If the timestamp provided does not exist for the key, return the value with the largest stored timestamp

        Key : list 
        list -> (timestamp, value)
"""


assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")