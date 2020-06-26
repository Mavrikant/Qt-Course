#ifndef FILECOPY_H
#define FILECOPY_H

enum copyReturnCode {
    Succes = 0,
    InvalidCount,
    SFNotExist,
    DFAlreadyExist,
    CopyFail
};

copyReturnCode filecopy(int argc, const char *argv[]);

#endif // FILECOPY_H
