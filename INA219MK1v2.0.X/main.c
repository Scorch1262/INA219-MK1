/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "ina219.h"

float   shunt_mV;                                   // definiert "shunt_mV"
float   bus_voltage;                                // definiert "bus_voltage"
float   power_mW;                                   // definiert "power_mW"
float   current_mA;                                 // definiert "current_mA"

/*
                         Main application
 */
void main(void){
    // Initialize the device
    SYSTEM_Initialize();
    __delay_ms(500);                                // warte 500ms
    INA219_Initialize();                            // ruft "INA219_Initialize" auf
    INA219_setCalibration_32V_2A();                 // ruft "INA219_setCalibration_32V_2A" auf
    //INA219_setCalibration_32V_1A();                 // ruft "INA219_setCalibration_32V_1A" auf
    //INA219_setCalibration_16V_400mA();              // ruft "INA219_setCalibration_16V_400mA" auf
    //INA219_setCalibration_16V_32A();                // ruft "INA219_setCalibration_16V_32A" auf

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    while (1){                                          // Endloschleife
        shunt_mV = INA219_getShuntVoltage_mV();         // schreibt ergebnis von "INA219_getShuntVoltage_mV" in "Shunt_Voltage"
        bus_voltage = INA219_getBusVoltage_V();         // schreibt ergebnis von "INA219_getBusVoltage_V" in "Bus_Voltage"
        power_mW = INA219_getPower_mW();                // schreibt ergebnis von "INA219_getPower_mW" in "Power"
        current_mA = INA219_getCurrent_mA();            // schreibt ergebnis von "INA219_getCurrent_mA" in "Current"
        current_mA = current_mA / 10;                   // current_mA geteilt durch 10

        printf("Shunt-Spannung: %.2fmV \r\n",shunt_mV);     // schreibt "Shunt-Spannung: %fV \r\n" an UART  
        printf("BUS-Spannung:   %.2fV \r\n",bus_voltage);   // schreibt "BUS-Spannung: %fV \r\n" an UART  
        printf("Leistung:       %.2fmW \r\n",power_mW);     // schreibt "Leistung: %fmW \r\n" an UART  
        printf("Strom:          %.2fmA \r\n",current_mA);   // schreibt "Strom: %fmA \r\n" an UART  
        
        __delay_ms(500);                                // warte 500ms
    }                                                   // 
}                                                       // 
/**
 End of File
*/