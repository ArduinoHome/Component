//#ifndef COVERDATAINTERFACE_H
//#define COVERDATAINTERFACE_H

enum CoverState
{
    CLOSED,
    OPENING,
    PAUSED,
    OPENED,
    CLOSING,
};

enum CoverCommand
{
    CLOSE,
    OPEN,
    PAUSE,
    TOGGLE,
};



//#endif