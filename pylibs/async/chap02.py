from concurrent.futures import ThreadPoolExecutor as Executor


def worker(data: str):
    print(f"Worker execute: {data}")

def example_01():
    data = "hello, world!"
    with Executor(max_workers=10) as exe:
        future = exe.submit(worker, data)

def main():
    example_01()

if __name__ == '__main__':
    main()