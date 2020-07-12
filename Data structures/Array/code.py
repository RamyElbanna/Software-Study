class Vector:
    # properties
    items: []

    # constructor
    def __init__(self, capacity=None):
        if(capacity == None):
            self.items = list([None] * 10)
            self.capacity = 10
        else:
            self.items = list([None] * capacity)
            self.capacity = capacity

        self.size = 0

    # methods
    def print_arr(self):
        print(self.items)

    def getSize(self):
        return self.size

    def push(self, item: int):
        if(self.capacity == self.size):
            self._extendArray(self.items, item)
        else:
            self.items[self.size] = item

        self.size += 1

    def pop(self):
        if(self.size == 0):
            return None

        lastItem = self.items[self.size - 1]
        self.items[self.size - 1] = None
        self.size -= 1
        return lastItem

    def insertAt(self, index: int, item: int):
        # this is not the best implementation
        if(index > self.size):
            return

        for i in range(self.size, index, -1):
            self.items[i] = self.items[i-1]

        self.items[index] = item
        self.size += 1

    def removeAt(self, index: int):
        # to be implemented
        pass

    def _extendArray(self, items, item):
        newList = list([None] * self.capacity * 2)
        for i in range(len(self.items)):
            newList[i] = self.items[i]

        newList[self.size] = item
        self.capacity *= 2
        self.items = newList
