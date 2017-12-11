from ml import *

class GoSlice:
    def __init__(self, fs):
        self.array  = fs.ReadPointer()
        self.len    = fs.ReadPointer()
        self.cap    = fs.ReadPointer()

class GoFunctionTable:
    def __init__(self, fs: fileio.FileStream):
        self.entry      = fs.ReadPointer()
        self.funcoff    = fs.ReadPointer()

class GoModuleData:
    def __init__(self, fs):
        self.pclntable  = GoSlice(fs)
        self.ftab       = GoSlice(fs)
