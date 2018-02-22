from ml import *
import importlib.util

GAME_PATH       = r'D:\Game\Steam\steamapps\common\Final Fantasy III'
GAME_PATH_FILES = os.path.join(GAME_PATH, 'files')
GAME_PATH_ZH_CN = os.path.join(GAME_PATH, 'zh_CN.lproj')
GAME_PATH_EN    = os.path.join(GAME_PATH, 'en.lproj')

def import_file(name, file):
    spec = importlib.util.spec_from_file_location(name, "msd\\%s.py" % file)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    return module
