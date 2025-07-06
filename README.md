# Gioia - glittering fashion
Electronic wearable device <br> 
<br> 
![alt-text](https://github.com/Green-bms/gioia/blob/master/Pictures/Gioia_logo.jpg)

Youtube: https://youtu.be/MnyeiMZdmjQ?si=YpLxnYz4cA8ocs8j <br> 
Instructables: https://www.instructables.com/Gioia-Glittering-Fashion/ <br> 
Hackaday.io: https://hackaday.io/project/202226-gioia-glittering-fashion <br> 
Hackster.io: https://www.hackster.io/green-bms/gioia-glittering-fashion-81f5f8 <br> 
Purchase PCB here: <br> 
https://www.pcbway.com/project/shareproject/Gioia_glittering_fashion_21_monocrome_leds_caeb9192.html  <br>
https://www.pcbway.com/project/shareproject/Gioia_glittering_fashion_8_RGB_leds_abd15673.html <br>

## Description
"Gioia" in Italian means joy.<br> 
I wanted to call this project this way in the hope that it will bring joy and happiness to those who wear it.<br> 
This gadget of 3 cm of diametrer can contain a maximum of 24 single-color LEDs or 8 RGB LEDs.<br> 
The infinite animations, which also include letters and symbols, are managed by an Attiny85 microcontroller.<br> 

### The PCB
Gioia's PCBs are made by PCBway https://pcbway.com/g/kY6w10
I chose this supplier because the quality of the PCB and the assembly of the components is of great quality.
The assistance is excellent and the delivery times are always respected

### Battery
The device is powered by a 30mAh LIR1632 rechargeable lithium battery. <br>
![alt-text](https://github.com/Green-bms/gioia/blob/master/Pictures/usb_charging.png) <br> 
Charging is done via a micro USB connector and takes about 90 minutes from 0% to 100%
The device lasts for about 5 continuous hours

### Versions
The project is available in 2 versions:<br>

#### 21 monochrome leds:<br>
![alt-text](https://github.com/Green-bms/gioia/blob/master/Pictures/21_leds.jpg) <br> 
All the documentation to make it is available here: https://github.com/Green-bms/gioia/tree/master/21%20monochrome%20leds%20version

#### 8 RGB leds:<br>
![alt-text](https://github.com/Green-bms/gioia/blob/master/Pictures/8_rgb_leds.jpg) <br> 
Each LED can light up in one of these 7 colors: red, green, blue, yellow, fuchsia, aqua, white. <br>
All the documentation to make it is available here: https://github.com/Green-bms/gioia/tree/master/8%20RGB%20leds%20version

### Microcontroller
The device's LEDs are driven by an Attiny85 microcontroller and 3 74HC595 shift registers.<br> 
The LED animations that can compose various light games, texts and symbols, are programmed in the code to be loaded into the microcontroller<br> 
Programming the microcontroller is very simple: you need to power the device via USB and connect the 4 pins of the ISP programmer to the pads shown in the pictures below.<br> 
![alt-text](https://github.com/Green-bms/gioia/blob/master/Pictures/programming.png)
![alt-text](https://github.com/Green-bms/gioia/blob/master/Pictures/programming%20pins.png)

## Open source Development applications
The project was created using the following Open source applications:
- **KiCad** : to design pcb
- **Arduino IDE** : to design the code for Attiny85 microcontroller of device animations

## Warning
This project is not commercial. This project is for educational and technological purposes.
No warrenty is foreseen.
Green BMS assumes no responsibility for any errors or inaccuracies that may appear in any documentation or file or any software that may be provided.
The use of this project is done entirely at your own risk and responsibility.
The use of this project may not be compliant with local laws or regulations.

## License

This work is licensed under a **Creative Commons Attribution-ShareAlike 4.0 International License**.
https://creativecommons.org/licenses/by-sa/4.0/

### You are free to:

**Share** — copy and redistribute the material in any medium or format

**Adapt**  — remix, transform, and build upon the material
for any purpose, even commercially.
This license is acceptable for Free Cultural Works.
The licensor cannot revoke these freedoms as long as you follow the license terms.

### Under the following terms:

**Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.

**ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

**No additional restrictions** — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.

### Notices:
You do not have to comply with the license for elements of the material in the public domain or where your use is permitted by an applicable exception or limitation.
No warranties are given. The license may not give you all of the permissions necessary for your intended use. For example, other rights such as publicity, privacy, or moral rights may limit how you use the material.

