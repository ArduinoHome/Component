//#ifndef COVERDATAINTERFACE_H
//#define COVERDATAINTERFACE_H

enum CoverState : byte
{
    CLOSED,
    OPENING,
    PAUSED,
    OPENED,
    CLOSING,
};

enum CoverCommand : byte
{
    CLOSE,
    OPEN,
    PAUSE,
    TOGGLE,
};



//#endif