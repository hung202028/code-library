# Decorator tutorials

def logged(func):
    def with_logging(*args, **kwargs):
        print(f"LOGGING: {func.__name__}")
        return func(*args, **kwargs)

    return with_logging


from functools import wraps


def logged2(func):
    @wraps(func)
    def with_logging(*args, **kwargs):
        print(f"LOGGING-2: {func.__name__}")
        return func(*args, **kwargs)

    return with_logging


class Decorator(object):
    def __init__(self): pass

    def calc(self, int_arr: list) -> int:
        n = sum(int_arr)
        print(f"SUM: {n}")


class NativeDecorator(Decorator):
    def __init__(self): pass

    @logged
    def run(self):
        """
        This is the document of function run in class NativeDecorator
        """
        self.calc([1, 2, 3])


class FuncToolDecorator(Decorator):
    def __init__(self): pass

    @logged2
    def run(self):
        """
        This is the document of function run in class FuncToolDecorator
        """
        self.calc([10, 20, 30])


if __name__ == '__main__':
    obj = NativeDecorator()
    obj.run()

    print(f"DOC-1: {obj.run.__doc__}")  # NONE => because of native decorator

    obj = FuncToolDecorator()
    obj.run()

    print(f"DOC-2: {obj.run.__doc__}")  # Make used of functools wraps
