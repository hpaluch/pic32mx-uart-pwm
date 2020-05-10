# PIC32MX UART LED PWM

Introductory project for [Microstick II][PIC Microstick II] 
with PIC32MX.

It *will* allow controlling LED brightness via commands
on RS232/UART port.

WARNING! Work in progress. Currently it flip-flops two levels
of brightness of onboard LED D6 each second.


Used peripherals:
- on-chip oscillator 8MHz 
- TMR2 - 1ms interval, PR2=8000 (divides 8MHz), clock source for PWM (OCMP1)
- OCMP1 - PWM output to on-board LED D6


More information on PWM is available on [PIC32 Output Compare data sheet - PDF][PIC32 Output Compare].

# Requirements

## Hardware requirements

* [Microstick II][PIC Microstick II]  demo board
* [PIC32MX250F128B SPDIP][PIC32MX250F128B] inserted into socket U5
  (included with board, should be default)
* programming pins switch S1 in position `A`

## Software requirements

* [XC32 compiler][XC compilers] - tested version v2.30
* [MPLAB X IDE][MPLAB X IDE] - tested version v5.25
  - installed  [MPLAB Harmony Configurator 3 Plugin][Harmony] - tested
    version 3.4.2
  - uses only `csp` component from Harmony Framework

[PIC32 Output Compare]: http://ww1.microchip.com/downloads/en/devicedoc/61111e.pdf
[Harmony]: https://www.microchip.com/mplab/mplab-harmony
[XC compilers]: https://www.microchip.com/mplab/compilers
[MPLAB X IDE]: https://www.microchip.com/mplab/mplab-x-ide
[PIC32MX250F128B]: https://www.microchip.com/wwwproducts/en/PIC32MX250F128B
[PIC Microstick II]: https://www.microchip.com/DevelopmentTools/ProductDetails/dm330013-2
