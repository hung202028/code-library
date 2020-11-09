# Example implementation of Adapter Design Pattern using Python

"""
The 'adapter' pattern is a structural design pattern that help us make two
incompatible interfaces compatible. If we have an old component and we want to
use it in a new system or a new component that we want to integrate to an old
system, the two can rarely communite without requiring any code changes. But,
changing the code is not always possible. In such a cases, we can write
additional layer call "adapter" that makes all the required modifications for
enabling communication between two interfaces.

"""

class WindowInterface(object):
    def __init__(self, ):
        self.query_folder = "C:\\Program Files\\mongodb\\queries\\"


    def execute_script(self) -> str:
        print(f"WINDOW - mongo shell exec: {self.query_folder}")
        return "window"


class MacOSInterface(object):
    def __init__(self, ):
        self.query_folder = "/opt/mongodb/queries/"

    def execute_script(self) -> str:
        print(f"MAC - mongo shell exec - {self.query_folder}")
        return "mac"


class MacOSAdapter(WindowInterface):
    def __init__(self, mac_interface: MacOSInterface):
        self.target = mac_interface

    def execute_script(self) -> str:
        self.target.execute_script()


# Legacy client class - cannot modify code!
class Client(object):
    def __init__(self, executor: WindowInterface):
        self.executor = executor


    def run(self):
        self.executor.execute_script()


if __name__ == '__main__':
    win = WindowInterface()
    client = Client(win)
    client.run()

    mac = MacOSInterface()
    win = MacOSAdapter(mac)
    client = Client(win)
    client.run()







