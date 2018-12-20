EESchema Schematic File Version 4
LIBS:esp_cnc-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ESP32 CNC"
Date "2018-10-16"
Rev "v1.0"
Comp "A. & G. Corp"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP32:ESP32-WROOM U1
U 1 1 5B9E8FBD
P 2450 4050
F 0 "U1" H 2425 5437 60  0000 C CNN
F 1 "ESP32-WROOM" H 2425 5331 60  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32_LARGE_PADS" H 2800 5400 60  0001 C CNN
F 3 "" H 2000 4500 60  0001 C CNN
	1    2450 4050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC547 Q1
U 1 1 5BA6665D
P 9200 1250
F 0 "Q1" H 9391 1296 50  0000 L CNN
F 1 "BC547" H 9391 1205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9400 1175 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 9200 1250 50  0001 L CNN
	1    9200 1250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC547 Q2
U 1 1 5BA66815
P 9200 1850
F 0 "Q2" H 9391 1804 50  0000 L CNN
F 1 "BC547" H 9391 1895 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9400 1775 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 9200 1850 50  0001 L CNN
	1    9200 1850
	1    0    0    1   
$EndComp
Wire Wire Line
	9300 1050 9300 950 
$Comp
L Device:R R5
U 1 1 5BA668D9
P 8750 1250
F 0 "R5" V 8543 1250 50  0000 C CNN
F 1 "12K" V 8634 1250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8680 1250 50  0001 C CNN
F 3 "~" H 8750 1250 50  0001 C CNN
	1    8750 1250
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5BA66958
P 8750 1850
F 0 "R6" V 8543 1850 50  0000 C CNN
F 1 "12K" V 8634 1850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8680 1850 50  0001 C CNN
F 3 "~" H 8750 1850 50  0001 C CNN
	1    8750 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	8900 1250 9000 1250
Wire Wire Line
	8600 1250 8500 1250
Wire Wire Line
	8500 1250 8500 1600
Wire Wire Line
	8500 1600 9300 1600
Wire Wire Line
	9300 1600 9300 1650
Connection ~ 8500 1250
Wire Wire Line
	9300 1450 9300 1500
Wire Wire Line
	9300 1500 8550 1500
Wire Wire Line
	8550 1500 8550 1850
Wire Wire Line
	8550 1850 8600 1850
Connection ~ 8550 1850
Text Label 8350 1850 0    50   ~ 0
RTS
Text Label 8350 1250 0    50   ~ 0
DTR
Wire Wire Line
	8900 1850 9000 1850
$Comp
L ch34x:CH340G U3
U 1 1 5BA685BE
P 7400 1600
F 0 "U3" H 7400 2197 60  0000 C CNN
F 1 "CH340G" H 7400 2091 60  0000 C CNN
F 2 "Package_SO:SOP-16_4.4x10.4mm_P1.27mm" H 7500 1400 60  0001 C CNN
F 3 "" H 7500 1400 60  0000 C CNN
	1    7400 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 1450 8200 1450
Wire Wire Line
	8200 1450 8200 1850
Wire Wire Line
	8200 1850 8550 1850
Wire Wire Line
	7850 1550 8100 1550
Wire Wire Line
	8100 1550 8100 1250
Wire Wire Line
	8100 1250 8500 1250
$Comp
L Device:Crystal Y1
U 1 1 5BA690E8
P 6550 2100
F 0 "Y1" H 6550 1832 50  0000 C CNN
F 1 "12Mhz" H 6550 1923 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-U_Vertical" H 6550 2100 50  0001 C CNN
F 3 "~" H 6550 2100 50  0001 C CNN
	1    6550 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:C C6
U 1 1 5BA69167
P 6300 2300
F 0 "C6" H 6415 2346 50  0000 L CNN
F 1 "22p" H 6415 2255 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6338 2150 50  0001 C CNN
F 3 "~" H 6300 2300 50  0001 C CNN
	1    6300 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5BA691C9
P 6800 2300
F 0 "C7" H 6915 2346 50  0000 L CNN
F 1 "22p" H 6915 2255 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6838 2150 50  0001 C CNN
F 3 "~" H 6800 2300 50  0001 C CNN
	1    6800 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5BA6920C
P 6550 2550
F 0 "#PWR023" H 6550 2300 50  0001 C CNN
F 1 "GND" H 6555 2377 50  0000 C CNN
F 2 "" H 6550 2550 50  0001 C CNN
F 3 "" H 6550 2550 50  0001 C CNN
	1    6550 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1950 6950 1950
Wire Wire Line
	6300 1850 6300 2100
Wire Wire Line
	6300 2450 6550 2450
Wire Wire Line
	6550 2450 6550 2550
Wire Wire Line
	6550 2450 6800 2450
Connection ~ 6550 2450
Wire Wire Line
	6800 1950 6800 2100
Wire Wire Line
	6300 1850 6950 1850
Wire Wire Line
	6300 2100 6400 2100
Connection ~ 6300 2100
Wire Wire Line
	6300 2100 6300 2150
Wire Wire Line
	6700 2100 6800 2100
Connection ~ 6800 2100
Wire Wire Line
	6800 2100 6800 2150
Text GLabel 6800 1450 0    50   Input ~ 0
TX
Text GLabel 6800 1350 0    50   Input ~ 0
RX
$Comp
L power:GND #PWR027
U 1 1 5BA6D942
P 6900 1200
F 0 "#PWR027" H 6900 950 50  0001 C CNN
F 1 "GND" H 6905 1027 50  0000 C CNN
F 2 "" H 6900 1200 50  0001 C CNN
F 3 "" H 6900 1200 50  0001 C CNN
	1    6900 1200
	-1   0    0    1   
$EndComp
Wire Wire Line
	6900 1200 6900 1250
Wire Wire Line
	6900 1250 6950 1250
Wire Wire Line
	6000 1750 6950 1750
Wire Wire Line
	6950 1650 6000 1650
Wire Wire Line
	7850 1250 7950 1250
Wire Wire Line
	7950 1250 7950 1150
$Comp
L Regulator_Linear:LM1117-3.3 U2
U 1 1 5BA71B0D
P 2550 1250
F 0 "U2" H 2550 1492 50  0000 C CNN
F 1 "LM1117-3.3" H 2550 1401 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 2550 1250 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 2550 1250 50  0001 C CNN
	1    2550 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C4
U 1 1 5BA71C31
P 2950 1450
F 0 "C4" H 3068 1496 50  0000 L CNN
F 1 "100u" H 3068 1405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 2988 1300 50  0001 C CNN
F 3 "~" H 2950 1450 50  0001 C CNN
	1    2950 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5BA71CC9
P 2100 1450
F 0 "C2" H 2218 1496 50  0000 L CNN
F 1 "10u" H 2218 1405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 2138 1300 50  0001 C CNN
F 3 "~" H 2100 1450 50  0001 C CNN
	1    2100 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5BA71D23
P 2550 1700
F 0 "#PWR09" H 2550 1450 50  0001 C CNN
F 1 "GND" H 2555 1527 50  0000 C CNN
F 2 "" H 2550 1700 50  0001 C CNN
F 3 "" H 2550 1700 50  0001 C CNN
	1    2550 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1250 2100 1300
Connection ~ 2100 1250
Wire Wire Line
	2100 1250 2250 1250
Wire Wire Line
	2100 1600 2550 1600
Wire Wire Line
	2550 1600 2550 1550
Wire Wire Line
	2550 1600 2550 1700
Connection ~ 2550 1600
Wire Wire Line
	2550 1600 2950 1600
Wire Wire Line
	2850 1250 2950 1250
Wire Wire Line
	2950 1250 2950 1300
Wire Wire Line
	2950 1250 3100 1250
Connection ~ 2950 1250
NoConn ~ 7850 1650
NoConn ~ 7850 1750
NoConn ~ 7850 1850
NoConn ~ 7850 1950
NoConn ~ 7850 1350
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A1
U 1 1 5BA78393
P 5750 4000
F 0 "A1" H 5500 4800 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 5300 4700 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 6025 3250 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 5850 3700 50  0001 C CNN
	1    5750 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3450 1500 3450
Text GLabel 9450 2050 2    50   Input ~ 0
GPIO_0
Wire Wire Line
	9300 950  9450 950 
Wire Wire Line
	9300 2050 9450 2050
Text GLabel 3400 4500 2    50   Input ~ 0
GPIO_0
Text GLabel 900  3550 0    50   Input ~ 0
ESP_EN
$Comp
L power:GND #PWR02
U 1 1 5BA7FF82
P 1350 4800
F 0 "#PWR02" H 1350 4550 50  0001 C CNN
F 1 "GND" H 1355 4627 50  0000 C CNN
F 2 "" H 1350 4800 50  0001 C CNN
F 3 "" H 1350 4800 50  0001 C CNN
	1    1350 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 4800 1350 4750
Wire Wire Line
	1450 5100 2000 5100
$Comp
L power:GND #PWR011
U 1 1 5BA826D3
P 3450 4750
F 0 "#PWR011" H 3450 4500 50  0001 C CNN
F 1 "GND" H 3455 4577 50  0000 C CNN
F 2 "" H 3450 4750 50  0001 C CNN
F 3 "" H 3450 4750 50  0001 C CNN
	1    3450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4700 3450 4700
Wire Wire Line
	3450 4700 3450 4750
Wire Wire Line
	3350 4600 3450 4600
Wire Wire Line
	3450 4600 3450 4700
Connection ~ 3450 4700
NoConn ~ 3350 3800
Wire Wire Line
	6800 1350 6950 1350
Wire Wire Line
	6950 1450 6800 1450
Text GLabel 3400 3600 2    50   Input ~ 0
RX
Text GLabel 3400 3500 2    50   Input ~ 0
TX
Text GLabel 9450 950  2    50   Input ~ 0
ESP_EN
Text GLabel 5300 3900 0    50   Input ~ 0
EN
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A2
U 1 1 5BA79F90
P 7800 4000
F 0 "A2" H 7550 4800 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 7350 4700 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 8075 3250 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 7900 3700 50  0001 C CNN
	1    7800 4000
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A3
U 1 1 5BA781E7
P 9850 4000
F 0 "A3" H 9600 4800 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 9400 4700 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 10125 3250 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 9950 3700 50  0001 C CNN
	1    9850 4000
	1    0    0    -1  
$EndComp
Text GLabel 7350 3900 0    50   Input ~ 0
EN
Text GLabel 9400 3900 0    50   Input ~ 0
EN
$Comp
L power:GND #PWR016
U 1 1 5BAA175F
P 5650 2150
F 0 "#PWR016" H 5650 1900 50  0001 C CNN
F 1 "GND" H 5655 1977 50  0000 C CNN
F 2 "" H 5650 2150 50  0001 C CNN
F 3 "" H 5650 2150 50  0001 C CNN
	1    5650 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2050 5600 2150
Wire Wire Line
	5600 2150 5650 2150
Wire Wire Line
	5650 2150 5700 2150
Wire Wire Line
	5700 2150 5700 2050
Connection ~ 5650 2150
Wire Wire Line
	5350 3600 5350 3700
Wire Wire Line
	7400 3600 7400 3700
Wire Wire Line
	9450 3600 9450 3700
Wire Wire Line
	4650 4300 4700 4300
Wire Wire Line
	4700 4400 4650 4400
Wire Wire Line
	4650 4400 4650 4300
Connection ~ 4650 4300
Wire Wire Line
	4700 4500 4650 4500
Wire Wire Line
	4650 4500 4650 4400
Connection ~ 4650 4400
$Comp
L power:VDD #PWR013
U 1 1 5BAB3A3F
P 4650 4150
F 0 "#PWR013" H 4650 4000 50  0001 C CNN
F 1 "VDD" H 4667 4323 50  0000 C CNN
F 2 "" H 4650 4150 50  0001 C CNN
F 3 "" H 4650 4150 50  0001 C CNN
	1    4650 4150
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR017
U 1 1 5BAB3B50
P 5750 3100
F 0 "#PWR017" H 5750 2950 50  0001 C CNN
F 1 "VDD" H 5767 3273 50  0000 C CNN
F 2 "" H 5750 3100 50  0001 C CNN
F 3 "" H 5750 3100 50  0001 C CNN
	1    5750 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4150 4650 4300
$Comp
L power:VDD #PWR03
U 1 1 5BABA847
P 1400 3050
F 0 "#PWR03" H 1400 2900 50  0001 C CNN
F 1 "VDD" H 1417 3223 50  0000 C CNN
F 2 "" H 1400 3050 50  0001 C CNN
F 3 "" H 1400 3050 50  0001 C CNN
	1    1400 3050
	1    0    0    -1  
$EndComp
$Comp
L custom:VMOT #PWR019
U 1 1 5BAC5FF0
P 5950 3100
F 0 "#PWR019" H 5950 3040 50  0001 C CNN
F 1 "VMOT" H 5950 3275 50  0000 C CNN
F 2 "" H 5950 3100 50  0001 C CNN
F 3 "" H 5950 3100 50  0001 C CNN
	1    5950 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 4300 6750 4300
Wire Wire Line
	6750 4400 6700 4400
Wire Wire Line
	6700 4400 6700 4300
Connection ~ 6700 4300
Wire Wire Line
	6750 4500 6700 4500
Wire Wire Line
	6700 4500 6700 4400
Connection ~ 6700 4400
$Comp
L power:VDD #PWR026
U 1 1 5BA923B7
P 6700 4150
F 0 "#PWR026" H 6700 4000 50  0001 C CNN
F 1 "VDD" H 6717 4323 50  0000 C CNN
F 2 "" H 6700 4150 50  0001 C CNN
F 3 "" H 6700 4150 50  0001 C CNN
	1    6700 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 4150 6700 4300
Wire Wire Line
	8750 4300 8800 4300
Wire Wire Line
	8800 4400 8750 4400
Wire Wire Line
	8750 4400 8750 4300
Connection ~ 8750 4300
Wire Wire Line
	8800 4500 8750 4500
Wire Wire Line
	8750 4500 8750 4400
Connection ~ 8750 4400
$Comp
L power:VDD #PWR033
U 1 1 5BA96160
P 8750 4150
F 0 "#PWR033" H 8750 4000 50  0001 C CNN
F 1 "VDD" H 8767 4323 50  0000 C CNN
F 2 "" H 8750 4150 50  0001 C CNN
F 3 "" H 8750 4150 50  0001 C CNN
	1    8750 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4150 8750 4300
Text GLabel 5300 4000 0    50   Input ~ 0
X_STEP
Text GLabel 5300 4100 0    50   Input ~ 0
X_DIR
Text GLabel 7350 4000 0    50   Input ~ 0
Y_STEP
Text GLabel 7350 4100 0    50   Input ~ 0
Y_DIR
Text GLabel 9400 4000 0    50   Input ~ 0
Z_STEP
Text GLabel 9400 4100 0    50   Input ~ 0
Z_DIR
Wire Wire Line
	9400 3900 9450 3900
Wire Wire Line
	9450 4000 9400 4000
Wire Wire Line
	9400 4100 9450 4100
Wire Wire Line
	7350 3900 7400 3900
Wire Wire Line
	7350 4000 7400 4000
Wire Wire Line
	7350 4100 7400 4100
Wire Wire Line
	5300 3900 5350 3900
Wire Wire Line
	5300 4000 5350 4000
Wire Wire Line
	5300 4100 5350 4100
$Comp
L Connector_Generic:Conn_01x04 J7
U 1 1 5BB0B3E7
P 6500 4000
F 0 "J7" H 6500 4300 50  0000 L CNN
F 1 "X Motor" H 6400 4200 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6500 4000 50  0001 C CNN
F 3 "~" H 6500 4000 50  0001 C CNN
	1    6500 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J10
U 1 1 5BB0B50B
P 8550 4000
F 0 "J10" H 8550 4300 50  0000 L CNN
F 1 "Y Motor" H 8450 4200 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 8550 4000 50  0001 C CNN
F 3 "~" H 8550 4000 50  0001 C CNN
	1    8550 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J12
U 1 1 5BB0B58B
P 10600 4000
F 0 "J12" H 10550 4300 50  0000 L CNN
F 1 "Z Motor" H 10500 4200 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10600 4000 50  0001 C CNN
F 3 "~" H 10600 4000 50  0001 C CNN
	1    10600 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3900 6300 3900
Wire Wire Line
	6300 4000 6250 4000
Wire Wire Line
	6250 4100 6300 4100
Wire Wire Line
	6250 4200 6300 4200
Wire Wire Line
	10350 3900 10400 3900
Wire Wire Line
	10400 4000 10350 4000
Wire Wire Line
	10350 4100 10400 4100
Wire Wire Line
	10400 4200 10350 4200
Wire Wire Line
	8300 3900 8350 3900
Wire Wire Line
	8350 4000 8300 4000
Wire Wire Line
	8300 4100 8350 4100
Wire Wire Line
	8350 4200 8300 4200
NoConn ~ 1500 3650
NoConn ~ 1500 3750
NoConn ~ 1500 3850
NoConn ~ 1500 3950
Text GLabel 1450 4050 0    50   Input ~ 0
PROBE
Text GLabel 1450 4150 0    50   Input ~ 0
EN
Text GLabel 1450 4550 0    50   Input ~ 0
X_STEP
Text GLabel 1450 4650 0    50   Input ~ 0
Y_STEP
Text GLabel 2100 5150 3    50   Input ~ 0
Z_STEP
Text GLabel 1450 4250 0    50   Input ~ 0
X_DIR
Text GLabel 1450 4350 0    50   Input ~ 0
Y_DIR
Text GLabel 1450 4450 0    50   Input ~ 0
Z_DIR
Wire Wire Line
	1450 4050 1500 4050
Wire Wire Line
	1500 4150 1450 4150
Wire Wire Line
	1450 4250 1500 4250
Wire Wire Line
	1500 4350 1450 4350
Wire Wire Line
	1450 4450 1500 4450
Wire Wire Line
	1500 4550 1450 4550
Wire Wire Line
	1450 4650 1500 4650
Wire Wire Line
	2100 5150 2100 5100
Text GLabel 2900 5150 3    50   Input ~ 0
X_LIMIT
Text GLabel 3400 4400 2    50   Input ~ 0
Y_LIMIT
Text GLabel 3400 4100 2    50   Input ~ 0
Z_LIMIT
Text GLabel 3400 4000 2    50   Input ~ 0
SPINDLE_DIR
Text GLabel 3400 3900 2    50   Input ~ 0
SPINDLE_EN
Text GLabel 3400 4300 2    50   Input ~ 0
COOLANT_FLOOD
Text GLabel 3400 4200 2    50   Input ~ 0
COOLANT_MIST
Text GLabel 3400 3700 2    50   Input ~ 0
CTRL_RESET
Text GLabel 3400 3400 2    50   Input ~ 0
CTRL_FEED_HOLD
Text GLabel 3400 3300 2    50   Input ~ 0
CTRL_CYCLE_START
Wire Wire Line
	3350 3300 3400 3300
Wire Wire Line
	3400 3400 3350 3400
Wire Wire Line
	3350 3500 3400 3500
Wire Wire Line
	3400 3600 3350 3600
Wire Wire Line
	3350 3700 3400 3700
Wire Wire Line
	3400 3900 3350 3900
Wire Wire Line
	3350 4000 3400 4000
Wire Wire Line
	3400 4100 3350 4100
Wire Wire Line
	3350 4200 3400 4200
Wire Wire Line
	3400 4300 3350 4300
Wire Wire Line
	3350 4400 3400 4400
Wire Wire Line
	3400 4500 3350 4500
NoConn ~ 2200 5100
NoConn ~ 2300 5100
NoConn ~ 2400 5100
NoConn ~ 2500 5100
NoConn ~ 2600 5100
NoConn ~ 2700 5100
Wire Wire Line
	2900 5150 2900 5100
$Comp
L power:VDD #PWR010
U 1 1 5BC0C165
P 3100 1100
F 0 "#PWR010" H 3100 950 50  0001 C CNN
F 1 "VDD" H 3117 1273 50  0000 C CNN
F 2 "" H 3100 1100 50  0001 C CNN
F 3 "" H 3100 1100 50  0001 C CNN
	1    3100 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1100 3100 1250
Wire Wire Line
	1450 4750 1500 4750
Wire Wire Line
	1350 4750 1450 4750
Connection ~ 1450 4750
Wire Wire Line
	1450 4750 1450 5100
Wire Wire Line
	6000 1450 6100 1450
Text GLabel 4900 5200 0    50   Input ~ 0
CTRL_RESET
Text GLabel 4900 5300 0    50   Input ~ 0
CTRL_FEED_HOLD
Text GLabel 4900 5400 0    50   Input ~ 0
CTRL_CYCLE_START
$Comp
L custom:VIN #PWR04
U 1 1 5BAFBC24
P 1550 1100
F 0 "#PWR04" H 1700 1050 50  0001 C CNN
F 1 "VIN" H 1549 1274 50  0000 C CNN
F 2 "" H 1550 1100 50  0001 C CNN
F 3 "" H 1550 1100 50  0001 C CNN
	1    1550 1100
	1    0    0    -1  
$EndComp
Text GLabel 4900 3650 2    50   Input ~ 0
EN
$Comp
L power:VDD #PWR012
U 1 1 5BB0635B
P 4500 3600
F 0 "#PWR012" H 4500 3450 50  0001 C CNN
F 1 "VDD" H 4517 3773 50  0000 C CNN
F 2 "" H 4500 3600 50  0001 C CNN
F 3 "" H 4500 3600 50  0001 C CNN
	1    4500 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5BB063C9
P 4700 3650
F 0 "R4" V 4493 3650 50  0000 C CNN
F 1 "12K" V 4584 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4630 3650 50  0001 C CNN
F 3 "~" H 4700 3650 50  0001 C CNN
	1    4700 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 3600 4500 3650
Wire Wire Line
	4500 3650 4550 3650
Wire Wire Line
	4850 3650 4900 3650
Text GLabel 4100 6250 0    50   Input ~ 0
SPINDLE_DIR
Text GLabel 4100 6350 0    50   Input ~ 0
SPINDLE_EN
Text GLabel 4100 6150 0    50   Input ~ 0
COOLANT_MIST
Text GLabel 4100 6050 0    50   Input ~ 0
COOLANT_FLOOD
$Comp
L power:GND #PWR014
U 1 1 5BB6D828
P 4700 6400
F 0 "#PWR014" H 4700 6150 50  0001 C CNN
F 1 "GND" H 4705 6227 50  0000 C CNN
F 2 "" H 4700 6400 50  0001 C CNN
F 3 "" H 4700 6400 50  0001 C CNN
	1    4700 6400
	1    0    0    -1  
$EndComp
Text GLabel 4900 5500 0    50   Input ~ 0
PROBE
$Comp
L power:GND #PWR015
U 1 1 5BB6DE32
P 5500 5550
F 0 "#PWR015" H 5500 5300 50  0001 C CNN
F 1 "GND" H 5505 5377 50  0000 C CNN
F 2 "" H 5500 5550 50  0001 C CNN
F 3 "" H 5500 5550 50  0001 C CNN
	1    5500 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5BB6ECC6
P 1000 3350
F 0 "R1" H 1070 3396 50  0000 L CNN
F 1 "12K" H 1070 3305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 930 3350 50  0001 C CNN
F 3 "~" H 1000 3350 50  0001 C CNN
	1    1000 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5BB6F216
P 1000 3750
F 0 "C1" H 1115 3796 50  0000 L CNN
F 1 "1n" H 1115 3705 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 1038 3600 50  0001 C CNN
F 3 "~" H 1000 3750 50  0001 C CNN
	1    1000 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5BB6F41E
P 1000 3950
F 0 "#PWR01" H 1000 3700 50  0001 C CNN
F 1 "GND" H 1005 3777 50  0000 C CNN
F 2 "" H 1000 3950 50  0001 C CNN
F 3 "" H 1000 3950 50  0001 C CNN
	1    1000 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 3200 1000 3150
Wire Wire Line
	1000 3150 1400 3150
Wire Wire Line
	1400 3150 1400 3050
Wire Wire Line
	1400 3150 1400 3450
Connection ~ 1400 3150
Wire Wire Line
	900  3550 1000 3550
Wire Wire Line
	1000 3500 1000 3550
Connection ~ 1000 3550
Wire Wire Line
	1000 3550 1500 3550
Wire Wire Line
	1000 3550 1000 3600
Wire Wire Line
	1000 3950 1000 3900
Wire Wire Line
	4650 6350 4700 6350
Wire Wire Line
	4700 6350 4700 6400
Wire Wire Line
	4700 6350 4700 6250
Wire Wire Line
	4700 6050 4650 6050
Connection ~ 4700 6350
Wire Wire Line
	4650 6150 4700 6150
Connection ~ 4700 6150
Wire Wire Line
	4700 6150 4700 6050
Wire Wire Line
	4650 6250 4700 6250
Connection ~ 4700 6250
Wire Wire Line
	4700 6250 4700 6150
Wire Wire Line
	4900 5200 4950 5200
Wire Wire Line
	4950 5300 4900 5300
Wire Wire Line
	4900 5400 4950 5400
Wire Wire Line
	4900 5500 4950 5500
Wire Wire Line
	5500 5550 5500 5500
Wire Wire Line
	5500 5200 5450 5200
Wire Wire Line
	5450 5300 5500 5300
Connection ~ 5500 5300
Wire Wire Line
	5500 5300 5500 5200
Wire Wire Line
	5450 5400 5500 5400
Connection ~ 5500 5400
Wire Wire Line
	5500 5400 5500 5300
Wire Wire Line
	5450 5500 5500 5500
Connection ~ 5500 5500
Wire Wire Line
	5500 5500 5500 5400
$Comp
L Device:CP C5
U 1 1 5BC63F10
P 6200 3200
F 0 "C5" H 6318 3246 50  0000 L CNN
F 1 "100u" H 6318 3155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 6238 3050 50  0001 C CNN
F 3 "~" H 6200 3200 50  0001 C CNN
	1    6200 3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP C8
U 1 1 5BC64228
P 8250 3200
F 0 "C8" H 8368 3246 50  0000 L CNN
F 1 "100u" H 8368 3155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 8288 3050 50  0001 C CNN
F 3 "~" H 8250 3200 50  0001 C CNN
	1    8250 3200
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP C9
U 1 1 5BC6452A
P 10300 3200
F 0 "C9" H 10418 3246 50  0000 L CNN
F 1 "100u" H 10418 3155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 10338 3050 50  0001 C CNN
F 3 "~" H 10300 3200 50  0001 C CNN
	1    10300 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 3100 5750 3300
Wire Wire Line
	5950 3100 5950 3200
Wire Wire Line
	5950 3200 6050 3200
Connection ~ 5950 3200
Wire Wire Line
	5950 3200 5950 3300
$Comp
L power:GND #PWR018
U 1 1 5BC8986E
P 5850 4850
F 0 "#PWR018" H 5850 4600 50  0001 C CNN
F 1 "GND" H 5855 4677 50  0000 C CNN
F 2 "" H 5850 4850 50  0001 C CNN
F 3 "" H 5850 4850 50  0001 C CNN
	1    5850 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 5BC898F5
P 7900 4850
F 0 "#PWR029" H 7900 4600 50  0001 C CNN
F 1 "GND" H 7905 4677 50  0000 C CNN
F 2 "" H 7900 4850 50  0001 C CNN
F 3 "" H 7900 4850 50  0001 C CNN
	1    7900 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR035
U 1 1 5BC89A55
P 9950 4850
F 0 "#PWR035" H 9950 4600 50  0001 C CNN
F 1 "GND" H 9955 4677 50  0000 C CNN
F 2 "" H 9950 4850 50  0001 C CNN
F 3 "" H 9950 4850 50  0001 C CNN
	1    9950 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4800 5750 4850
Wire Wire Line
	5750 4850 5850 4850
Wire Wire Line
	5850 4850 5950 4850
Wire Wire Line
	5950 4850 5950 4800
Connection ~ 5850 4850
Wire Wire Line
	7800 4800 7800 4850
Wire Wire Line
	7800 4850 7900 4850
Wire Wire Line
	7900 4850 8000 4850
Wire Wire Line
	8000 4850 8000 4800
Connection ~ 7900 4850
Wire Wire Line
	9850 4800 9850 4850
Wire Wire Line
	9850 4850 9950 4850
Wire Wire Line
	9950 4850 10050 4850
Wire Wire Line
	10050 4850 10050 4800
Connection ~ 9950 4850
$Comp
L power:VDD #PWR028
U 1 1 5BCD61D0
P 7800 3100
F 0 "#PWR028" H 7800 2950 50  0001 C CNN
F 1 "VDD" H 7817 3273 50  0000 C CNN
F 2 "" H 7800 3100 50  0001 C CNN
F 3 "" H 7800 3100 50  0001 C CNN
	1    7800 3100
	1    0    0    -1  
$EndComp
$Comp
L custom:VMOT #PWR031
U 1 1 5BCD6219
P 8000 3100
F 0 "#PWR031" H 8000 3040 50  0001 C CNN
F 1 "VMOT" H 8000 3275 50  0000 C CNN
F 2 "" H 8000 3100 50  0001 C CNN
F 3 "" H 8000 3100 50  0001 C CNN
	1    8000 3100
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR034
U 1 1 5BCD63D6
P 9850 3100
F 0 "#PWR034" H 9850 2950 50  0001 C CNN
F 1 "VDD" H 9867 3273 50  0000 C CNN
F 2 "" H 9850 3100 50  0001 C CNN
F 3 "" H 9850 3100 50  0001 C CNN
	1    9850 3100
	1    0    0    -1  
$EndComp
$Comp
L custom:VMOT #PWR036
U 1 1 5BCD641F
P 10050 3100
F 0 "#PWR036" H 10050 3040 50  0001 C CNN
F 1 "VMOT" H 10050 3275 50  0000 C CNN
F 2 "" H 10050 3100 50  0001 C CNN
F 3 "" H 10050 3100 50  0001 C CNN
	1    10050 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5BCD6541
P 6400 3250
F 0 "#PWR021" H 6400 3000 50  0001 C CNN
F 1 "GND" H 6405 3077 50  0000 C CNN
F 2 "" H 6400 3250 50  0001 C CNN
F 3 "" H 6400 3250 50  0001 C CNN
	1    6400 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR032
U 1 1 5BCD658A
P 8450 3250
F 0 "#PWR032" H 8450 3000 50  0001 C CNN
F 1 "GND" H 8455 3077 50  0000 C CNN
F 2 "" H 8450 3250 50  0001 C CNN
F 3 "" H 8450 3250 50  0001 C CNN
	1    8450 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5BCD663A
P 10500 3300
F 0 "#PWR037" H 10500 3050 50  0001 C CNN
F 1 "GND" H 10505 3127 50  0000 C CNN
F 2 "" H 10500 3300 50  0001 C CNN
F 3 "" H 10500 3300 50  0001 C CNN
	1    10500 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 3100 7800 3300
Wire Wire Line
	8000 3100 8000 3200
Wire Wire Line
	8000 3200 8100 3200
Connection ~ 8000 3200
Wire Wire Line
	8000 3200 8000 3300
Wire Wire Line
	8400 3200 8450 3200
Wire Wire Line
	8450 3200 8450 3250
Wire Wire Line
	9850 3100 9850 3300
Wire Wire Line
	10050 3300 10050 3200
Wire Wire Line
	10050 3200 10150 3200
Connection ~ 10050 3200
Wire Wire Line
	10050 3200 10050 3100
Wire Wire Line
	10450 3200 10500 3200
Wire Wire Line
	10500 3200 10500 3300
$Comp
L Connector_Generic:Conn_01x03 J8
U 1 1 5BD414B0
P 6800 5400
F 0 "J8" H 6880 5442 50  0000 L CNN
F 1 "Limits Sel" H 6880 5351 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6800 5400 50  0001 C CNN
F 3 "~" H 6800 5400 50  0001 C CNN
	1    6800 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5BD41562
P 6550 5550
F 0 "#PWR025" H 6550 5300 50  0001 C CNN
F 1 "GND" H 6555 5377 50  0000 C CNN
F 2 "" H 6550 5550 50  0001 C CNN
F 3 "" H 6550 5550 50  0001 C CNN
	1    6550 5550
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR024
U 1 1 5BD415AD
P 6550 5250
F 0 "#PWR024" H 6550 5100 50  0001 C CNN
F 1 "VDD" H 6567 5423 50  0000 C CNN
F 2 "" H 6550 5250 50  0001 C CNN
F 3 "" H 6550 5250 50  0001 C CNN
	1    6550 5250
	1    0    0    -1  
$EndComp
Text GLabel 5850 6000 0    50   Input ~ 0
X_LIMIT
Text GLabel 5850 6200 0    50   Input ~ 0
Z_LIMIT
Text GLabel 5850 6100 0    50   Input ~ 0
Y_LIMIT
Wire Wire Line
	5900 6000 5850 6000
Wire Wire Line
	5850 6100 5900 6100
Wire Wire Line
	5850 6200 5900 6200
Wire Wire Line
	6550 5250 6550 5300
Wire Wire Line
	6550 5300 6600 5300
Wire Wire Line
	6550 5550 6550 5500
Wire Wire Line
	6550 5500 6600 5500
Wire Wire Line
	6600 5400 6450 5400
Wire Wire Line
	6450 5400 6450 6000
Wire Wire Line
	6450 6000 6400 6000
Wire Wire Line
	6450 6000 6450 6100
Wire Wire Line
	6450 6100 6400 6100
Connection ~ 6450 6000
Wire Wire Line
	6450 6100 6450 6200
Wire Wire Line
	6450 6200 6400 6200
Connection ~ 6450 6100
$Comp
L power:VDD #PWR030
U 1 1 5BB1B7F5
P 7950 1150
F 0 "#PWR030" H 7950 1000 50  0001 C CNN
F 1 "VDD" H 7967 1323 50  0000 C CNN
F 2 "" H 7950 1150 50  0001 C CNN
F 3 "" H 7950 1150 50  0001 C CNN
	1    7950 1150
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR022
U 1 1 5BB1B9A1
P 6550 1500
F 0 "#PWR022" H 6550 1350 50  0001 C CNN
F 1 "VDD" H 6567 1673 50  0000 C CNN
F 2 "" H 6550 1500 50  0001 C CNN
F 3 "" H 6550 1500 50  0001 C CNN
	1    6550 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1500 6550 1550
Wire Wire Line
	6550 1550 6950 1550
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5BB2A603
P 1950 5900
F 0 "J1" H 2030 5892 50  0000 L CNN
F 1 "Conn_01x02" H 2030 5801 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1950 5900 50  0001 C CNN
F 3 "~" H 1950 5900 50  0001 C CNN
	1    1950 5900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 5BB2A689
P 1650 6050
F 0 "#PWR07" H 1650 5800 50  0001 C CNN
F 1 "GND" H 1655 5877 50  0000 C CNN
F 2 "" H 1650 6050 50  0001 C CNN
F 3 "" H 1650 6050 50  0001 C CNN
	1    1650 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6050 1650 6000
$Comp
L custom:VIN #PWR020
U 1 1 5BB493C3
P 6100 1350
F 0 "#PWR020" H 6250 1300 50  0001 C CNN
F 1 "VIN" H 6099 1524 50  0000 C CNN
F 2 "" H 6100 1350 50  0001 C CNN
F 3 "" H 6100 1350 50  0001 C CNN
	1    6100 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 1350 6100 1450
Text Label 1800 1250 0    50   ~ 0
5V
Text Label 3100 1150 0    50   ~ 0
3.3V
$Comp
L Switch:SW_Push SW1
U 1 1 5BB1D91F
P 2600 7100
F 0 "SW1" H 2600 7385 50  0000 C CNN
F 1 "Reset" H 2600 7294 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2600 7300 50  0001 C CNN
F 3 "" H 2600 7300 50  0001 C CNN
	1    2600 7100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5BB1DBA9
P 2600 7250
F 0 "C3" H 2715 7296 50  0000 L CNN
F 1 "1n" H 2715 7205 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 2638 7100 50  0001 C CNN
F 3 "~" H 2600 7250 50  0001 C CNN
	1    2600 7250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5BB1DD77
P 2300 7350
F 0 "#PWR08" H 2300 7100 50  0001 C CNN
F 1 "GND" H 2305 7177 50  0000 C CNN
F 2 "" H 2300 7350 50  0001 C CNN
F 3 "" H 2300 7350 50  0001 C CNN
	1    2300 7350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5BB1DF17
P 3150 7100
F 0 "R3" V 2943 7100 50  0000 C CNN
F 1 "470" V 3034 7100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3080 7100 50  0001 C CNN
F 3 "~" H 3150 7100 50  0001 C CNN
	1    3150 7100
	0    1    1    0   
$EndComp
Text GLabel 3400 7100 2    50   Input ~ 0
ESP_EN
Wire Wire Line
	2300 7350 2300 7250
Wire Wire Line
	2300 7100 2400 7100
Wire Wire Line
	2300 7250 2450 7250
Connection ~ 2300 7250
Wire Wire Line
	2300 7250 2300 7100
Wire Wire Line
	2800 7100 2900 7100
Wire Wire Line
	2750 7250 2900 7250
Wire Wire Line
	2900 7250 2900 7100
Connection ~ 2900 7100
Wire Wire Line
	2900 7100 3000 7100
Wire Wire Line
	3300 7100 3400 7100
$Comp
L Device:R R2
U 1 1 5BB6C2C2
P 1550 1450
F 0 "R2" H 1620 1496 50  0000 L CNN
F 1 "680" H 1620 1405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 1480 1450 50  0001 C CNN
F 3 "~" H 1550 1450 50  0001 C CNN
	1    1550 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5BB6C3A8
P 1550 1850
F 0 "D1" V 1588 1733 50  0000 R CNN
F 1 "Red LED" V 1497 1733 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 1550 1850 50  0001 C CNN
F 3 "~" H 1550 1850 50  0001 C CNN
	1    1550 1850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1550 1100 1550 1250
Wire Wire Line
	1550 1250 2100 1250
Connection ~ 1550 1250
Wire Wire Line
	1550 1250 1550 1300
Wire Wire Line
	1550 1600 1550 1700
$Comp
L power:GND #PWR05
U 1 1 5BB9D49D
P 1550 2050
F 0 "#PWR05" H 1550 1800 50  0001 C CNN
F 1 "GND" H 1555 1877 50  0000 C CNN
F 2 "" H 1550 2050 50  0001 C CNN
F 3 "" H 1550 2050 50  0001 C CNN
	1    1550 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2000 1550 2050
Wire Wire Line
	6350 3200 6400 3200
Wire Wire Line
	6400 3200 6400 3250
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J2
U 1 1 5BBD17CA
P 4450 6150
F 0 "J2" H 4500 6467 50  0000 C CNN
F 1 "Outputs" H 4500 6376 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 4450 6150 50  0001 C CNN
F 3 "~" H 4450 6150 50  0001 C CNN
	1    4450 6150
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J4
U 1 1 5BBD19BB
P 5250 5300
F 0 "J4" H 5300 5617 50  0000 C CNN
F 1 "Inputs" H 5300 5526 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 5250 5300 50  0001 C CNN
F 3 "~" H 5250 5300 50  0001 C CNN
	1    5250 5300
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J6
U 1 1 5BBD1BEA
P 6200 6100
F 0 "J6" H 6250 6417 50  0000 C CNN
F 1 "Limits" H 6250 6326 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 6200 6100 50  0001 C CNN
F 3 "~" H 6200 6100 50  0001 C CNN
	1    6200 6100
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J3
U 1 1 5BBD1F27
P 4900 4400
F 0 "J3" H 4950 4717 50  0000 C CNN
F 1 "X Microstep" H 4950 4626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 4900 4400 50  0001 C CNN
F 3 "~" H 4900 4400 50  0001 C CNN
	1    4900 4400
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J9
U 1 1 5BBD2177
P 6950 4400
F 0 "J9" H 7000 4717 50  0000 C CNN
F 1 "Y Microstep" H 7000 4626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 6950 4400 50  0001 C CNN
F 3 "~" H 6950 4400 50  0001 C CNN
	1    6950 4400
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J11
U 1 1 5BBD2301
P 9000 4400
F 0 "J11" H 9050 4717 50  0000 C CNN
F 1 "Z Microstep" H 9050 4626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 9000 4400 50  0001 C CNN
F 3 "~" H 9000 4400 50  0001 C CNN
	1    9000 4400
	1    0    0    1   
$EndComp
NoConn ~ 2800 5100
Wire Wire Line
	4100 6050 4150 6050
Wire Wire Line
	4150 6150 4100 6150
Wire Wire Line
	4100 6250 4150 6250
Wire Wire Line
	4150 6350 4100 6350
$Comp
L custom:VMOT #PWR0101
U 1 1 5BC15A02
P 1650 5800
F 0 "#PWR0101" H 1650 5740 50  0001 C CNN
F 1 "VMOT" H 1650 5975 50  0000 C CNN
F 2 "" H 1650 5800 50  0001 C CNN
F 3 "" H 1650 5800 50  0001 C CNN
	1    1650 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 5800 1650 5900
Wire Wire Line
	1650 5900 1750 5900
Wire Wire Line
	1750 6000 1650 6000
Wire Wire Line
	5200 4300 5350 4300
Wire Wire Line
	5200 4400 5350 4400
Wire Wire Line
	5200 4500 5350 4500
Wire Wire Line
	7250 4300 7400 4300
Wire Wire Line
	7250 4400 7400 4400
Wire Wire Line
	7250 4500 7400 4500
Wire Wire Line
	9300 4300 9450 4300
Wire Wire Line
	9300 4400 9450 4400
Wire Wire Line
	9300 4500 9450 4500
$Comp
L Connector:USB_B_Micro J5
U 1 1 5BCD44F1
P 5700 1650
F 0 "J5" H 5755 2117 50  0000 C CNN
F 1 "USB_B_Micro" H 5755 2026 50  0000 C CNN
F 2 "custom:micro_usb_breakout" H 5850 1600 50  0001 C CNN
F 3 "~" H 5850 1600 50  0001 C CNN
	1    5700 1650
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR06
U 1 1 5BD53A8E
P 7300 2250
F 0 "#PWR06" H 7300 2100 50  0001 C CNN
F 1 "VDD" H 7317 2423 50  0000 C CNN
F 2 "" H 7300 2250 50  0001 C CNN
F 3 "" H 7300 2250 50  0001 C CNN
	1    7300 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR038
U 1 1 5BD6450A
P 7300 2650
F 0 "#PWR038" H 7300 2400 50  0001 C CNN
F 1 "GND" H 7305 2477 50  0000 C CNN
F 2 "" H 7300 2650 50  0001 C CNN
F 3 "" H 7300 2650 50  0001 C CNN
	1    7300 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5BD74FEE
P 7300 2450
F 0 "C10" H 7415 2496 50  0000 L CNN
F 1 "100n" H 7415 2405 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 7338 2300 50  0001 C CNN
F 3 "~" H 7300 2450 50  0001 C CNN
	1    7300 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2250 7300 2300
Wire Wire Line
	7300 2600 7300 2650
$EndSCHEMATC
