class Stack(object):
   def __init__(self):
       self.__list = list()

   def is_empty(self):
       return self.__list == []

   def push(self, item):
       self.__list.append(item)

   def pop(self):
       return self.__list.pop()

   def size(self):
       return len(self.__list)

if __name__ == '__main__':
    s = Stack()
    s.push('1')
    s.push('2')
    s.push('3')
    print(s.pop())
    print(s.pop())
    print(s.pop())

