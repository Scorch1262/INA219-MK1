/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
 * TERMS.
 */

/*
 * File:
 * Author:
 * Comments:
 * Revision history:
 */

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef XC_INA219_H
#define	XC_INA219_H

#include <xc.h> // include processor files - each processor file is guarded.
#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdio.h>

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>

    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>

    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C
    // linkage so the functions can be used by the c code.

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_INA219_H */

/** Prototypen ************************************************/

// The default address for the INA219 Breakout Board
#define INA219_ADDRESS                         (0x40)    // 1000000 (A0+A1=GND)

// The register for reading values from the INA219
#define INA219_READ                            (0x01)

// The INA219 Config Register
#define INA219_REG_CONFIG                      (0x00)

// The INA219 Config Reset Register
#define INA219_CONFIG_RESET                    (0x8000)

// The INA219 Bus Voltage Range Mask
#define INA219_CONFIG_BVOLTAGERANGE_MASK       (0x2000)

// The INA219 Bus Voltage Range Values
enum {
    INA219_CONFIG_BVOLTAGERANGE_16V = (0x0000), // 0-16V Range
    INA219_CONFIG_BVOLTAGERANGE_32V = (0x2000) // 0-32V Range
};

// The INA219 Mask for Gain bits
#define INA219_CONFIG_GAIN_MASK                (0x1800)

// The INA219 Various Gain values
enum {
    INA219_CONFIG_GAIN_1_40MV = (0x0000), // Gain 1, 40mV Range
    INA219_CONFIG_GAIN_2_80MV = (0x0800), // Gain 2, 80mV Range
    INA219_CONFIG_GAIN_4_160MV = (0x1000), // Gain 4, 160mV Range
    INA219_CONFIG_GAIN_8_320MV = (0x1800) // Gain 8, 320mV Range
};

// The INA219 mask for bus ADC resolution bits
#define INA219_CONFIG_BADCRES_MASK             (0x0780)

// The INA219 bus ADC resolution values
enum {
    INA219_CONFIG_BADCRES_9BIT = (0x0000), // 9-bit bus res = 0..511
    INA219_CONFIG_BADCRES_10BIT = (0x0080), // 10-bit bus res = 0..1023
    INA219_CONFIG_BADCRES_11BIT = (0x0100), // 11-bit bus res = 0..2047
    INA219_CONFIG_BADCRES_12BIT = (0x0180) // 12-bit bus res = 0..4097
};

// The INA219 mask for shunt ADC resolution bits
#define INA219_CONFIG_SADCRES_MASK             (0x0078)

// The values for shunt ADC resolution
enum {
    INA219_CONFIG_SADCRES_9BIT_1S_84US = (0x0000), // 1 x 9-bit shunt sample
    INA219_CONFIG_SADCRES_10BIT_1S_148US = (0x0008), // 1 x 10-bit shunt sample
    INA219_CONFIG_SADCRES_11BIT_1S_276US = (0x0010), // 1 x 11-bit shunt sample
    INA219_CONFIG_SADCRES_12BIT_1S_532US = (0x0018), // 1 x 12-bit shunt sample
    INA219_CONFIG_SADCRES_12BIT_2S_1060US = (0x0048), // 2 x 12-bit shunt samples averaged together
    INA219_CONFIG_SADCRES_12BIT_4S_2130US = (0x0050), // 4 x 12-bit shunt samples averaged together
    INA219_CONFIG_SADCRES_12BIT_8S_4260US = (0x0058), // 8 x 12-bit shunt samples averaged together
    INA219_CONFIG_SADCRES_12BIT_16S_8510US = (0x0060), // 16 x 12-bit shunt samples averaged together
    INA219_CONFIG_SADCRES_12BIT_32S_17MS = (0x0068), // 32 x 12-bit shunt samples averaged together
    INA219_CONFIG_SADCRES_12BIT_64S_34MS = (0x0070), // 64 x 12-bit shunt samples averaged together
    INA219_CONFIG_SADCRES_12BIT_128S_69MS = (0x0078) // 128 x 12-bit shunt samples averaged together
};

// The mask for operating mode bits
#define INA219_CONFIG_MODE_MASK                (0x0007)

// The values for each operating mode
enum {
    INA219_CONFIG_MODE_POWERDOWN = (0x0000),
    INA219_CONFIG_MODE_SVOLT_TRIGGERED = (0x0001),
    INA219_CONFIG_MODE_BVOLT_TRIGGERED = (0x0002),
    INA219_CONFIG_MODE_SANDBVOLT_TRIGGERED = (0x0003),
    INA219_CONFIG_MODE_ADCOFF = (0x0004),
    INA219_CONFIG_MODE_SVOLT_CONTINUOUS = (0x0005),
    INA219_CONFIG_MODE_BVOLT_CONTINUOUS = (0x0006),
    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS = (0x0007)
};


// The shunt voltage register
#define INA219_REG_SHUNTVOLTAGE                (0x01)

// The bus voltage register
#define INA219_REG_BUSVOLTAGE                  (0x02)

// The power register
#define INA219_REG_POWER                       (0x03)

// The current register
#define INA219_REG_CURRENT                     (0x04)

// The calibration register
#define INA219_REG_CALIBRATION                 (0x05)

void INA219_WriteRegister(uint8_t address, uint16_t data);
void INA219_ReadRegister(uint8_t address, uint16_t *data);
int16_t INA219_getBusVoltage_raw(void);
int16_t INA219_getShuntVoltage_raw(void);
int16_t INA219_getCurrent_raw(void);
int16_t INA219_getPower_raw(void);

void INA219_setCalibration_32V_2A(void);
void INA219_setCalibration_32V_1A(void);
void INA219_setCalibration_16V_400mA(void);
void INA219_setCalibration_16V_32A(void); // 32A is 3.2 A
float INA219_getBusVoltage_V(void);
float INA219_getShuntVoltage_mV(void);
float INA219_getCurrent_mA(void);
float INA219_getPower_mW(void);


// Methods that we will be calling from the main program 
void INA219_Initialize(void);

static uint16_t ina219_i2cAddress = INA219_ADDRESS;
static uint16_t ina219_calibrationValue;
static uint16_t ina219_currentDivider_mA;
static uint16_t ina219_powerMultiplier_mW;
