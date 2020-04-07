import asyncio
import time


class QuickStart:

    def example_01(self):
        async def main():
            print(f"{time.ctime()} : Start")
            await asyncio.sleep(1.0)
            print(f"{time.ctime()} : End")

        asyncio.run(main())

    def example_02(self):
        async def main():
            print(f"{time.ctime()} : Start")
            await asyncio.sleep(1.0)
            print(f"{time.ctime()} : End")

        loop = asyncio.get_event_loop()

        task = loop.create_task(main())
        loop.run_until_complete(task)

        # collect pending task and re-run
        pending = asyncio.all_tasks(loop=loop)
        for task_01 in pending:
            task_01.cancel()
        group = asyncio.gather(*pending, return_exceptions=True)
        loop.run_until_complete(group)

        loop.close()  # mandatory

    def example_03(self):
        async def main():
            print(f"{time.ctime()} : Coroutine Start")
            await asyncio.sleep(1.0)
            print(f"{time.ctime()} : Coroutine End")

        def blocking():
            print(f"Blocking started!")
            time.sleep(0.5)
            print(f"Blocking ended!")

        loop = asyncio.get_event_loop()

        task = loop.create_task(main())
        loop.run_in_executor(None, blocking)
        #time.sleep(2)
        loop.run_until_complete(task)

        pending = asyncio.all_tasks(loop=loop)
        for p_task in pending:
            p_task.cancel()
        group = asyncio.gather(*pending, return_exceptions=True)
        loop.run_until_complete(group)

        loop.close()

    def example_04(self):
        pass

    def run(self):
        self.example_03()


if __name__ == '__main__':
    obj = QuickStart()
    obj.run()
