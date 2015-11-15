import xml.dom.minidom
import sys

"""Utility to convert xml (or ui) files created by glade into C strings"""

class XmlWriter:
    def __init__(self):
        self.snippets = []
    def write(self, data):
        if data.isspace(): return
        self.snippets.append(data)
    def __str__(self):
        return ''.join(self.snippets)

if __name__ == "__main__":
    writer = XmlWriter()
    xml = xml.dom.minidom.parse(sys.argv[1])
    xml.writexml(writer)
    strippedXml = ("%s" % (writer)).replace('"', '\\"')

    byteCount = len(strippedXml)
    baseOffset=0
    stripSize=64

    output = open("output.h", 'w')
    output.write("static const char gladestring [] = \n{\n")
    while baseOffset < byteCount:
        skipTrailingQuote = 0
        if baseOffset+stripSize < byteCount and strippedXml[baseOffset+stripSize] == '"':
            skipTrailingQuote = 1
        output.write('  "%s"\n' % (strippedXml[baseOffset:baseOffset+stripSize+skipTrailingQuote]))
        baseOffset += stripSize + skipTrailingQuote

    output.write("};\n")
    output.close()
