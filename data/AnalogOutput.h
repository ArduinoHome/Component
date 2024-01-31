#ifndef ANALOGOUTPUT_H
#define ANALOGOUTPUT_H

class AnalogOutput
{
public:
    virtual int GetValue();

    virtual void SetValue(int value);

};

#endif