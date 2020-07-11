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
- Now outputs on `PIN21` UART2 TXD ASCII characters each second. This
  pin should be connected to RXD signal of your USB-TO-TTL Serial adapter
  (for example CH341 adapter, or `USB Console #954` for Raspberry PI)
  On PC this port must have settings:
  - Baud rate: 9600
  - Data bits: 8
  - Stop Bits: 1
  - Parity: None
  - Flow control: None
- NOTE: If you use CH341 adapter and have Win 7 SP1 you
  may need to download driver `CH341SER_64_bit.zip` driver
  from: https://www.srishtirobotics.com/more/blog/154-arduino-uno-r3-clone-ch340-ch341-usb-driver The original Dollatek driver seems to have no longer
  valid signature

Important UART Notes:
- The UART PIN assignments are reverted (???) on my SPDIP package:
  - PIN21 is TXD (PIC Output) = J6 PIN4 on Microstick II
  - PIN22 is RXD (PIC Input)  = J6 PIN5 on Microstick II
- the data were corrupted when I tried baud rate 115200. Need to find
  why (maybe OSC out of range???, or need different clock for high speed
  baudrate ???)


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
