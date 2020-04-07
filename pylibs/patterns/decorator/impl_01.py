from functools import wraps

"""
    We use the "decorator" pattern as an convenient way of extending behavior
    of an object without using inheritance.
    Python, with its built-in decorator feature, extends the decorator concept
    event more, by allow us to extend any callable (method, function or class)
    without using inheritance or composition.

 """


def cache(func):
    ds = {}

    @wraps(func)
    def memorize(*args):
        if args not in ds:
            ds[args] = func(*args)

        return ds[args]

    return memorize


## Client code
@cache
def calc(n: int) -> int:
    if n <= 1:
        return 1

    return calc(n - 1) + calc(n - 2)


if __name__ == '__main__':
    m = calc(10)
    print(m)