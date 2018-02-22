from ml import *
from init import *

eureka_item = import_file('eureka_item', 'eureka_item').items

class ItemEntry:
    def __init__(self, fs):
        self.type       = fs.ReadUShort()
        self.id         = fs.ReadUShort()
        self.name       = eureka_item[fs.ReadUShort()][1]
        self.desc       = fs.ReadUShort()

        self.unknown1   = fs.ReadULong()
        self.unknown2   = fs.ReadULong()

        self.useInBattle= fs.ReadByte()
        self.useInWorld = fs.ReadByte()
        self.flag3      = fs.ReadByte()
        self.flag4      = fs.ReadByte()

        self.flag5      = fs.ReadUShort()
        self.flag6      = fs.ReadUShort()
        self.target     = fs.ReadUShort()
        self.flag8      = fs.ReadUShort()

        self.buyPrice   = fs.ReadULong()
        self.sellPrice  = fs.ReadULong()

        self.restoreHP  = fs.ReadUShort()
        self.unknown3   = fs.ReadUShort()
        self.unknown4   = fs.ReadULong()

    def todict(self):
        return [
            '0x%04X: {' % self.id,
            '    type       : 0x%04X,' % self.type,
            "    name       : '%s'," % self.name,
            '    useInBattle: %s,' % bool(self.useInBattle),
            '    useInWorld : %s,' % bool(self.useInWorld),
            '    target     : \'%s\',' % {0: 'Ally', 1: 'Allies', 2: 'Enemy', 3: 'Enemies', 4: 'Ailment'}[self.target],
            '    buyPrice   : %d,' % self.buyPrice,
            '    sellPrice  : %d,' % self.sellPrice,
            '    restoreHP  : %d,' % self.restoreHP,
            '},',
        ]

class WeaponEntry:
    def __init__(self, fs):
        self.type   = fs.ReadUShort()
        self.id     = fs.ReadUShort()
        self.name   = fs.ReadUShort()
        self.desc   = fs.ReadUShort()

class ArmorEntry:
    def __init__(self, fs):
        self.type   = fs.ReadUShort()
        self.id     = fs.ReadUShort()
        self.name   = fs.ReadUShort()
        self.desc   = fs.ReadUShort()

class SpellEntry:
    def __init__(self, fs):
        self.type   = fs.ReadUShort()
        self.id     = fs.ReadUShort()
        self.name   = fs.ReadUShort()
        self.desc   = fs.ReadUShort()

class KeyItemEntry:
    def __init__(self, fs):
        self.type   = fs.ReadUShort()
        self.id     = fs.ReadUShort()
        self.name   = fs.ReadUShort()
        self.desc   = fs.ReadUShort()

def main():
    lines = []

    with fileio.FileStream(os.path.join(GAME_PATH_FILES, 'item_parameter.pak')) as fs:
        fs.Position = 8

        fixedSize = fs.ReadULong()
        if fixedSize != 0:
            raise NotImplementedError

        fs.Position += 4

        itemsOffset,    itemsCount      = fs.ReadULong(), fs.ReadULong() // 0x2C
        weaponsOffset,  weaponsCount    = fs.ReadULong(), fs.ReadULong() // 0x38
        armorOffset,    armorCount      = fs.ReadULong(), fs.ReadULong() // 0x3C
        spellsOffset,   spellsCount     = fs.ReadULong(), fs.ReadULong() // 0x34
        keyItemsOffset, keyItemsCount   = fs.ReadULong(), fs.ReadULong() // 0x1C

        offsets = [
            ('Items',       ItemEntry,      itemsOffset,        itemsCount),
            ('Weapons',     WeaponEntry,    weaponsOffset,      weaponsCount),
            ('Armor',       ArmorEntry,     armorOffset,        armorCount),
            ('Spells',      SpellEntry,     spellsOffset,       spellsCount),
            ('KeyItems',    KeyItemEntry,   keyItemsOffset,     keyItemsCount),
        ]

        for o in offsets:
            name, cls, offset, count = o
            lines.append('%s = {' % name)

            fs.Position = offset
            for _ in range(count):
                obj = cls(fs)
                lines.append('    %s\n' % '\n    '.join(obj.todict()))

            lines.append('}\n')

            break

        # for i in range(0x7F):
        #     pos = fs.Position

        #     typ, id, name, desc = fs.ReadUShort(), fs.ReadUShort(), fs.ReadUShort(), fs.ReadUShort()

        #     try:
        #         lines.append("    0x%04X: (0x%04X, '%s', '%s')," % (id, typ, eureka_item[name][1], eureka_item[desc][1]))
        #     except:
        #         print('%08X: %04X %04X %04X %04X' % (pos, id, typ, name, desc))
        #         raise

        #     fs.Position += 0x34 - 8

    open('item_parameter.bbd.py', 'w', encoding = 'UTF-8').write('\n'.join(lines))

    # console.pause('done')

if __name__ == '__main__':
    Try(main)
