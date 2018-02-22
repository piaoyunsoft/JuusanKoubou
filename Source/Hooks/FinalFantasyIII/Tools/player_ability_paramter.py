from ml import *
import importlib.util

def main():
    spec = importlib.util.spec_from_file_location("eureka_battle", "msd\\eureka_battle.py")
    eureka_battle = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(eureka_battle)

    fs = fileio.FileStream(r'D:\Game\Steam\steamapps\common\Final Fantasy III\files\player_ability_paramter.bbd')
    for i in range(fs.Length // 8):
        index, id = fs.ReadUShort(), fs.ReadUShort()
        fs.Position += 4

        if id == 0:
            continue

        print('%04X %s' % (index, eureka_battle.items[id][1]))

    console.pause('done')

if __name__ == '__main__':
    Try(main)
