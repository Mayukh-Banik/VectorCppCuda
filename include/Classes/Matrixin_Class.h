#pragma once
#include <cstdint>

class Matrixin
{
private:
    double* Data;
    uint64_t ElementCount;
    uint64_t* Shape;
    uint64_t* Size;
    uint8_t ItemSize = sizeof(double);
    uint64_t NBytes;
    Matrixin* Base = nullptr;
    const char* DataType = "Double";
    bool DeviceHost = false;
    
public:
    Matrixin();
    Matrixin(uint64_t ElementCount = 0);
    Matrixin(uint64_t ElementCount = 0, uint64_t* Shape = nullptr);
};

