EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:tinyk20
LIBS:SumoRobot-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L tinyK20 U1
U 1 1 5971DCE3
P 5900 3100
F 0 "U1" H 5625 3787 60  0000 C CNN
F 1 "tinyK20" H 5625 3681 60  0000 C CNN
F 2 "Housings_DIP:DIP-32_W15.24mm" H 5700 3000 60  0001 C CNN
F 3 "" H 5700 3000 60  0001 C CNN
	1    5900 3100
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 5971DE18
P 3500 1900
F 0 "#PWR01" H 3500 1750 50  0001 C CNN
F 1 "+3.3V" H 3515 2073 50  0000 C CNN
F 2 "" H 3500 1900 50  0001 C CNN
F 3 "" H 3500 1900 50  0001 C CNN
	1    3500 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 1900 3050 2050
Wire Wire Line
	3500 1900 3500 2050
$Comp
L LED D1
U 1 1 5971DF75
P 3650 2950
F 0 "D1" H 3641 3166 50  0000 C CNN
F 1 "LED" H 3641 3075 50  0000 C CNN
F 2 "LEDs:LED_0805" H 3650 2950 50  0001 C CNN
F 3 "" H 3650 2950 50  0001 C CNN
	1    3650 2950
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5971DFE5
P 3150 2950
F 0 "R1" V 2943 2950 50  0000 C CNN
F 1 "300" V 3034 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3080 2950 50  0001 C CNN
F 3 "" H 3150 2950 50  0001 C CNN
	1    3150 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	3300 2950 3500 2950
NoConn ~ 5050 2800
NoConn ~ 5050 2900
NoConn ~ 5050 3000
NoConn ~ 5050 3100
NoConn ~ 5050 3300
NoConn ~ 5050 3200
NoConn ~ 5050 3400
NoConn ~ 5050 3500
NoConn ~ 5050 3600
NoConn ~ 5050 3700
NoConn ~ 5050 3800
NoConn ~ 5050 3900
NoConn ~ 5050 4000
NoConn ~ 5050 4100
NoConn ~ 5050 4200
NoConn ~ 6200 2700
NoConn ~ 6200 2800
NoConn ~ 6200 2900
NoConn ~ 6200 4000
NoConn ~ 6200 3900
NoConn ~ 6200 3800
NoConn ~ 6200 3700
NoConn ~ 6200 3600
NoConn ~ 6200 3500
NoConn ~ 6200 3400
NoConn ~ 6200 3300
NoConn ~ 6200 3200
NoConn ~ 6200 3100
NoConn ~ 6200 3000
Text GLabel 3950 2950 2    60   Input ~ 0
LED
Wire Wire Line
	3800 2950 3950 2950
Text GLabel 6400 4100 2    60   Input ~ 0
LED
Wire Wire Line
	6200 4100 6400 4100
$Comp
L +3.3V #PWR02
U 1 1 5971E47E
P 6400 4200
F 0 "#PWR02" H 6400 4050 50  0001 C CNN
F 1 "+3.3V" H 6415 4373 50  0000 C CNN
F 2 "" H 6400 4200 50  0001 C CNN
F 3 "" H 6400 4200 50  0001 C CNN
	1    6400 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6200 4200 6400 4200
Wire Wire Line
	5050 2700 4700 2700
Wire Wire Line
	4700 2700 4700 2750
$Comp
L GND #PWR03
U 1 1 5971E5B4
P 2850 3050
F 0 "#PWR03" H 2850 2800 50  0001 C CNN
F 1 "GND" H 2855 2877 50  0000 C CNN
F 2 "" H 2850 3050 50  0001 C CNN
F 3 "" H 2850 3050 50  0001 C CNN
	1    2850 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3050 2850 2950
Wire Wire Line
	2850 2950 3000 2950
$Comp
L PWR_FLAG #FLG04
U 1 1 5971E72D
P 3500 2050
F 0 "#FLG04" H 3500 2125 50  0001 C CNN
F 1 "PWR_FLAG" H 3500 2223 50  0000 C CNN
F 2 "" H 3500 2050 50  0001 C CNN
F 3 "" H 3500 2050 50  0001 C CNN
	1    3500 2050
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 5971E83B
P 3050 2050
F 0 "#FLG05" H 3050 2125 50  0001 C CNN
F 1 "PWR_FLAG" H 3050 2223 50  0000 C CNN
F 2 "" H 3050 2050 50  0001 C CNN
F 3 "" H 3050 2050 50  0001 C CNN
	1    3050 2050
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 5971E961
P 4700 2750
F 0 "#PWR06" H 4700 2500 50  0001 C CNN
F 1 "GND" H 4705 2577 50  0000 C CNN
F 2 "" H 4700 2750 50  0001 C CNN
F 3 "" H 4700 2750 50  0001 C CNN
	1    4700 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5971E993
P 3050 1900
F 0 "#PWR07" H 3050 1650 50  0001 C CNN
F 1 "GND" H 3055 1727 50  0000 C CNN
F 2 "" H 3050 1900 50  0001 C CNN
F 3 "" H 3050 1900 50  0001 C CNN
	1    3050 1900
	-1   0    0    1   
$EndComp
$EndSCHEMATC
