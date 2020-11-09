from xml.etree import ElementTree
from datetime import datetime

fmt = "%Y-%m-%dT%H:%M:%S.%Z"
def _read_xml():
    with open("foo.xml") as f:
        tree = ElementTree.parse(f)
        for node in tree.iter():
            tag = node.tag
            if (tag == "tz"):
                time_str = node.attrib.get("time")
                utc_offset = node.text

                print(f"Time: {time_str}, Offset: {utc_offset}")
                t = datetime.strptime(time_str, fmt)
                print(t)

def extract_xml(tag_name: str, xml_data: str):
    pass


if __name__ == '__main__':
    _read_xml()

