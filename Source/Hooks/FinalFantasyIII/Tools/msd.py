from ml import *
from init import *

class MSDItem:
    def __init__(self, textId, flags, offset):
        self.offset = offset
        self.id     = textId
        self.flags  = flags
        self.text   = ''

def dump(file):
    fs = fileio.FileStream(file)

    if fs.Read(4) != b'MSDA':
        raise Exception('not a valid msd file')

    fs.Position += 4
    count = fs.ReadULong()
    fs.Position += 4

    items = []

    for i in range(count):
        items.append(MSDItem(fs.ReadULong(), fs.ReadULong(), fs.ReadULong()))

    lines = [
        'items = {',
    ]

    for item in items:
        if item.offset == 0:
            continue

        fs.Position = item.offset
        item.text = fs.ReadMultiByte('UTF8')

        lines.append("    0x%04X: (0x%08X, '%s')," % (item.id, item.flags, item.text.replace('\n', '\\n')))

    lines.append('}')

    output = os.path.join(os.path.dirname(__file__), 'msd', os.path.splitext(os.path.basename(file))[0]) + '.py'
    open(output, 'w', encoding = 'UTF8').write('\n'.join(lines))

def main():
    for f in fileio.getDirectoryFiles(GAME_PATH_EN, '*.msd'):
        dump(f)

    # dump(r'D:\Game\Steam\steamapps\common\Final Fantasy III\zh_CN.lproj\eureka_item.msd')

    console.pause('done')

if __name__ == '__main__':
    Try(main)
