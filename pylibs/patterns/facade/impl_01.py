"""
The facade design pattern help us to hide the internal complexity of our system
and expose only what is neccessary to our client through a simplified interface.
In essence, facade is an abstraction layer implemented over an existing
complex system.
"""

from abc import ABCMeta, abstractmethod
from enum import Enum

State = Enum("State", "new running sleeping restart zoombie")


class Server(metaclass=ABCMeta):
    @abstractmethod
    def __init__(self):
        pass

    def __str__(self):
        return self.name

    @abstractmethod
    def boot(self):
        pass

    @abstractmethod
    def kill(self, restart=True):
        pass


class FileServer(Server):
    def __init__(self):
        self.name = "FileServer"
        self.state = State.new

    def boot(self):
        print(f"Booting {self} ...")
        self.state = State.running

    def kill(self, restart=True):
        print(f"Killing {self} ...")
        self.state = State.restart if restart else State.zoombie

    def create_file(self, user: str, filename: str, permissions: tuple):
        print(f"Trying to create file: {filename} for user: {user} with "
              f"permissions: {permissions}")


class ProcessServer(Server):
    def __init__(self):
        self.name = "ProcessServer"
        self.state = State.new

    def boot(self):
        print(f"Booting {self} ...")
        self.state = State.running

    def kill(self, restart=True):
        print(f"Killing {self} ...")
        self.state = State.restart if restart else State.zoombie

    def create_process(self, user: str, process: str):
        print(f"Trying to create process: {process} for user: {user}")


class OperatingSystem:
    """ The facade """

    def __init__(self):
        self.fs = FileServer()
        self.ps = ProcessServer()

    def start(self):
        for server in (self.ps, self.fs):
            server.boot()

    def touch(self, user: str, file: str, permissions: tuple):
        return self.fs.create_file(user, file, permissions)

    def fork(self, user: str, process: str):
        return self.ps.create_process(user, process)


if __name__ == '__main__':
    os = OperatingSystem()
    os.start()

    os.fork("hung", "chrome.exe")
    os.touch("hung", "readme.md", ("r", "w"))
