import threading
from queue import Queue


class Account(object):
    def __init__(self, a: int, b: int):
        self.a = a
        self.b = b

    def give(self, to: Account, a=0, b=0):
        self.change(-a, -b)
        to.change(a, b)

    def change(self, a: int, b: int):
        self.a += a
        self.b += b


class ThreadBot(threading.Thread):
    def __init__(self):
        pass


accounts = Account(a=100, b=100)

