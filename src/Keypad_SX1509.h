#pragma once
#include "Keypad.h"
#include <SparkFunSX1509.h>

class Keypad_SX1509 : public Keypad {
public:
    Keypad_SX1509(char *userKeymap, byte *row, byte *col,
                  byte numRows, byte numCols, SX1509 &io)
        : Keypad(userKeymap, row, col, numRows, numCols), _io(io) {}

    void pin_mode(byte pinNum, byte mode) override {
        if (mode == INPUT_PULLUP) {
            _io.pinMode(pinNum, INPUT_PULLUP);
        } else {
            _io.pinMode(pinNum, mode);  // OUTPUT or INPUT
        }
    }

    void pin_write(byte pinNum, bool level) override {
        _io.digitalWrite(pinNum, level);
    }

    int pin_read(byte pinNum) override {
        return _io.digitalRead(pinNum);
    }

private:
    SX1509 &_io;
};