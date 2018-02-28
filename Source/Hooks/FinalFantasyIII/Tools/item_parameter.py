from ml import *
from init import *

eureka_item = import_file('eureka_item', 'eureka_item').items

def getName(offset):
    try:
        return eureka_item[offset][1]
    except KeyError:
        return '<%04X>' % offset

class ItemEntry:
    def __init__(self, fs):
        self.type       = fs.ReadUShort()
        self.id         = fs.ReadUShort()
        self.name       = getName(fs.ReadUShort())
        self.desc       = getName(fs.ReadUShort())

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

        self.value      = fs.ReadUShort()
        self.unknown3   = fs.ReadUShort()
        self.unknown4   = fs.ReadULong()

    def todict(self):
        return [
            '0x%04X: {' % self.id,
            '    type       : %d,' % self.type,
            "    name       : '%s'," % self.name,
            "    desc       : '%s'," % self.desc,
            '    useInBattle: %s,' % bool(self.useInBattle),
            '    useInWorld : %s,' % bool(self.useInWorld),
            # '    target     : \'%s\',' % {0: 'Ally', 1: 'Allies', 2: 'Enemy', 3: 'Enemies', 4: 'Ailment'}[self.target],
            '    buyPrice   : %d,' % self.buyPrice,
            '    sellPrice  : %d,' % self.sellPrice,
            '    value      : %d,' % self.value,
            '},',
        ]

class WeaponEntry:
    def __init__(self, fs):
        self.type       = fs.ReadUShort()
        self.id         = fs.ReadUShort()
        self.name       = getName(fs.ReadUShort())
        self.desc       = getName(fs.ReadUShort())

        self.unknown1   = fs.ReadULong()
        self.unknown2   = fs.ReadULong()
        self.unknown3   = fs.ReadULong()
        self.unknown4   = fs.ReadULong()
        self.unknown5   = fs.ReadULong()

        self.buyPrice   = fs.ReadULong()
        self.sellPrice  = fs.ReadULong()

        self.unknown6   = fs.ReadULong()

        self.value      = fs.ReadUShort()

        self.flags      = fs.ReadUShort()
        self.unknown7   = fs.ReadUShort()
        self.unknown8   = fs.ReadUShort()
        self.unknown9   = fs.ReadULong()
        self.unknown10  = fs.ReadULong()

    def todict(self):
        return [
            '0x%04X: {' % self.id,
            '    type       : %d,' % self.type,
            "    name       : '%s'," % self.name,
            "    desc       : '%s'," % self.desc,
            '    buyPrice   : %d,' % self.buyPrice,
            '    sellPrice  : %d,' % self.sellPrice,
            '    value      : %d,' % self.value,
            '    flags      : 0x%04X,' % self.flags,
            '},',
        ]

class ArmorEntry:
    def __init__(self, fs):
        self.type       = fs.ReadUShort()
        self.id         = fs.ReadUShort()
        self.name       = getName(fs.ReadUShort())
        self.desc       = getName(fs.ReadUShort())

        self.unknown1   = fs.ReadUShort()

        self.strength   = fs.ReadByte()
        self.agility    = fs.ReadByte()
        self.vitality   = fs.ReadByte()
        self.intellect  = fs.ReadByte()
        self.mind       = fs.ReadByte()
        self.weight     = fs.ReadByte()

        self.unknown3   = fs.ReadULong()
        self.unknown4   = fs.ReadULong()
        self.unknown5   = fs.ReadULong()

        self.buyPrice   = fs.ReadULong()
        self.sellPrice  = fs.ReadULong()

        self.unknown6   = fs.ReadULong()

        self.value      = fs.ReadUShort()
        self.value2     = fs.ReadUShort()

        self.flags      = fs.ReadUShort()

        self.unknown8   = fs.ReadUShort()
        self.unknown9   = fs.ReadULong()
        self.unknown10  = fs.ReadULong()
        self.unknown11  = fs.ReadULong()

    def todict(self):
        return [
            '0x%04X: {' % self.id,
            '    type       : %d,' % self.type,
            "    name       : '%s'," % self.name,
            "    desc       : '%s'," % self.desc,
            '    strength   : %d,' % self.strength,
            '    agility    : %d,' % self.agility,
            '    vitality   : %d,' % self.vitality,
            '    intellect  : %d,' % self.intellect,
            '    mind       : %d,' % self.mind,
            '    weight     : %d,' % self.weight,
            '    buyPrice   : %d,' % self.buyPrice,
            '    sellPrice  : %d,' % self.sellPrice,
            '    value      : %d,' % self.value,
            '    value2     : %d,' % self.value2,
            '    flags      : 0x%04X,' % self.flags,
            '},',
        ]

class SpellEntry:
    def __init__(self, fs):
        self.type       = fs.ReadUShort()
        self.id         = fs.ReadUShort()
        self.name       = getName(fs.ReadUShort())
        self.desc       = getName(fs.ReadUShort())

        self.unknown1   = fs.ReadULong()
        self.unknown2   = fs.ReadULong()
        self.unknown3   = fs.ReadULong()
        self.unknown4   = fs.ReadULong()
        self.unknown5   = fs.ReadULong()

        self.buyPrice   = fs.ReadULong()
        self.sellPrice  = fs.ReadULong()

        self.value      = fs.ReadUShort()
        self.value2     = fs.ReadUShort()
        self.value3     = fs.ReadUShort()
        self.value4     = fs.ReadUShort()

        self.flags      = fs.ReadUShort()

        self.unknown8   = fs.ReadUShort()
        self.unknown9   = fs.ReadULong()

    def todict(self):
        return [
            '0x%04X: {' % self.id,
            '    type       : %d,' % self.type,
            "    name       : '%s'," % self.name,
            "    desc       : '%s'," % self.desc,
            '    buyPrice   : %d,' % self.buyPrice,
            '    sellPrice  : %d,' % self.sellPrice,
            '    value      : %d,' % self.value,
            '    value2     : %d,' % self.value2,
            '    value3     : %d,' % self.value3,
            '    value4     : %d,' % self.value4,
            '    flags      : 0x%04X,' % self.flags,
            '},',
        ]

class KeyItemEntry:
    def __init__(self, fs):
        self.type       = fs.ReadUShort()
        self.id         = fs.ReadUShort()
        self.name       = getName(fs.ReadUShort())
        self.desc       = getName(fs.ReadUShort())

        self.unknown1   = fs.ReadULong()
        self.unknown2   = fs.ReadULong()
        self.unknown3   = fs.ReadULong()
        self.unknown4   = fs.ReadULong()
        self.unknown5   = fs.ReadULong()

    def todict(self):
        return [
            '0x%04X: {' % self.id,
            '    type       : %d,' % self.type,
            "    name       : '%s'," % self.name,
            "    desc       : '%s'," % self.desc,
            '    unknown1   : 0x%08X' % self.unknown1,
            '    unknown2   : 0x%08X' % self.unknown2,
            '    unknown3   : 0x%08X' % self.unknown3,
            '    unknown4   : 0x%08X' % self.unknown4,
            '    unknown5   : 0x%08X' % self.unknown5,
            '},',
        ]

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
                pos = fs.Position

                try:
                    obj = cls(fs)
                except KeyError:
                    print('%X' % pos)
                    raise

                lines.append('    %s\n' % '\n    '.join(obj.todict()))

            lines.append('}\n')

    open('item_parameter.bbd.py', 'w', encoding = 'UTF-8').write('\n'.join(lines))

    # console.pause('done')

if __name__ == '__main__':
    Try(main)
