#include <xc.h>
#include <assert.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "ina219.h"

#define INA219_ADDR     0x40

#define Config          0x00
#define Shunt_Voltage   0x01
#define Bus_Voltage     0x02
#define Power           0x03
#define Current         0x04
#define Calibration     0x05

uint8_t  writeBuffer[3] = {0x00, 0x00, 0x00};                           // definiert "writeBuffer"
uint8_t  readBuffer[10] = {0x00, 0x00};                                 // definiert "readBuffer"

void INA219_Initialize(void) {
//    INA219_setCalibration_16V_400mA();
//    INA219_setCalibration_16V_32A();
//    INA219_setCalibration_32V_2A();
}

void INA219_WriteRegister(uint8_t address, uint16_t data) {
    uint8_t writeBuffer[3];

    writeBuffer[0] = address;
    writeBuffer[1] = (uint8_t) (data >> 8);
    writeBuffer[2] = (uint8_t) (data & 0x00FF);
    I2C_WriteNBytes(INA219_ADDRESS, writeBuffer, sizeof (writeBuffer));
}

void INA219_ReadRegister(uint8_t address, uint16_t *data) {
    *data = I2C_Read2ByteRegister(INA219_ADDRESS, address);
}

void INA219_setCalibration_32V_2A(void) {
    ina219_calibrationValue = 4096;
    ina219_currentDivider_mA = 100;
    ina219_powerMultiplier_mW = 2;
    INA219_WriteRegister(INA219_REG_CALIBRATION, ina219_calibrationValue);
    INA219_WriteRegister(INA219_REG_CONFIG, (INA219_CONFIG_BVOLTAGERANGE_32V |
            INA219_CONFIG_GAIN_8_320MV |
            INA219_CONFIG_BADCRES_12BIT |
            INA219_CONFIG_SADCRES_12BIT_1S_532US |
            INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS));
}

void INA219_setCalibration_32V_1A(void) {
    ina219_calibrationValue = 10240;
    ina219_currentDivider_mA = 25;
    ina219_powerMultiplier_mW = 1;
    INA219_WriteRegister(INA219_REG_CALIBRATION, ina219_calibrationValue);
    INA219_WriteRegister(INA219_REG_CONFIG, (INA219_CONFIG_BVOLTAGERANGE_32V |
            INA219_CONFIG_GAIN_8_320MV |
            INA219_CONFIG_BADCRES_12BIT |
            INA219_CONFIG_SADCRES_12BIT_1S_532US |
            INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS));
}

void INA219_setCalibration_16V_400mA(void) {
    ina219_calibrationValue = 33554UL;
    ina219_currentDivider_mA = 8192;
    ina219_powerMultiplier_mW = 1;
    INA219_WriteRegister(INA219_REG_CALIBRATION, ina219_calibrationValue);
    INA219_WriteRegister(INA219_REG_CONFIG, (INA219_CONFIG_BVOLTAGERANGE_16V |
            INA219_CONFIG_GAIN_1_40MV |
            INA219_CONFIG_BADCRES_12BIT |
            INA219_CONFIG_SADCRES_12BIT_128S_69MS |
            INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS));
}

void INA219_setCalibration_16V_32A(void) {
    ina219_calibrationValue = 4194UL;
    ina219_currentDivider_mA = 1024;
    ina219_powerMultiplier_mW = 1;
    INA219_WriteRegister(INA219_REG_CALIBRATION, ina219_calibrationValue);
    INA219_WriteRegister(INA219_REG_CONFIG, (INA219_CONFIG_BVOLTAGERANGE_16V |
            INA219_CONFIG_GAIN_8_320MV |
            INA219_CONFIG_BADCRES_12BIT |
            INA219_CONFIG_SADCRES_12BIT_128S_69MS |
            INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS));
}

int16_t INA219_getBusVoltage_raw(void) {
    int16_t value;
    INA219_ReadRegister(INA219_REG_BUSVOLTAGE, &value);
    return (int16_t) value;
}

int16_t INA219_getShuntVoltage_raw(void) {
    int16_t value;
    INA219_ReadRegister(INA219_REG_SHUNTVOLTAGE, &value);
    return (int16_t) value;
}

int16_t INA219_getCurrent_raw(void) {
    int16_t value;
    INA219_ReadRegister(INA219_REG_CURRENT, &value);
    return (int16_t) value;
}

int16_t INA219_getPower_raw(void) {
    uint16_t value;
    //    INA219_WriteRegister(INA219_REG_CALIBRATION, ina219_calibrationValue);
    INA219_WriteRegister(INA219_REG_POWER, &value);
    return (int16_t) value;
}

float INA219_getBusVoltage_V(void) {
    int16_t value = INA219_getBusVoltage_raw();
    return (value >> 3) * 0.004f;
}

float INA219_getShuntVoltage_mV(void) {
    uint16_t value = INA219_getShuntVoltage_raw();
    return value * 0.01;
}

float INA219_getCurrent_mA(void) {
    float valueDec = INA219_getCurrent_raw();
    valueDec = valueDec / ina219_currentDivider_mA * 100.f;
    return valueDec;
}

float INA219_getPower_mW(void) {
    float valueDec = INA219_getPower_raw();
    valueDec *= ina219_powerMultiplier_mW;
    return valueDec;
}