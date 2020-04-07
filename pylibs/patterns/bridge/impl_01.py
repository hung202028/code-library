"""
Using "bridge" pattern is a good idea when you want to share implementation
among multiple objects. Basically, instead of implementing several specialized
classes, definding all that is required within each class, you can define
the following sepecial components:

    1. An abstraction that applies to all classes.
    2. A separated interface for different objects involved.


Bridge pattern is useful when writting softwares such as: os and device drivers
,GUI, and website builders where we have multiple themes and we need to change
a theme of a website based on certain properties.

"""


class ResourceContent:
    """
    Define an abstraction's interface that maintains a reference to an object
    which represent an implementor.
    """

    def __init__(self, imp):
        self._imp = imp

    def show_content(self, path):
        self._imp.fetch(path)


from abc import ABCMeta, abstractmethod


class ResourceContentReader(metaclass=ABCMeta):
    """
    Define the interface for implementation classes that fetch content.
    """

    @abstractmethod
    def fetch(self, path):
        pass


from urllib.request import Request, urlopen
import certifi, ssl


class URLFetcher(ResourceContentReader):
    """ URL Fetcher """

    def fetch(self, path):
        # path is an url
        req = Request(path)
        with urlopen(req,
                     context=ssl.create_default_context(
                         cafile=certifi.where())) as response:
            if response.code == 200:
                page_content = response.read()
                print(page_content)


class LocalFileFetcher(ResourceContentReader):
    """ Local file fetcher """

    def fetch(self, path):
        # path is the file path to a text file.
        with open(path) as f:
            print(f.read())


# client use ResourceContent
if __name__ == '__main__':
    url_fetcher = URLFetcher()
    client = ResourceContent(url_fetcher)
    client.show_content("http://vnexpress.net")

    print("\n", "".center(100, '='), "\n")

    file_fetcher = LocalFileFetcher()
    client = ResourceContent(file_fetcher)
    client.show_content(__file__)
