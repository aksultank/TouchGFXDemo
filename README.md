# TouchGFXDemo
I try to run TouchGFX on Nucleo-F412ZG+SPI LCD(https://www.amazon.co.jp/dp/B072N551V3).
I already are a success it.

For SPI LCD is as;
- SPILCDTest
- SPILCDTestFPS
- SPILCDTestXY
- SPILCDTestFPS412

For SPI TC is as;
- TouchTest
- TouchTestHW
- TouchTestHW412

For Combination test is as;
- DrawingTest

For small GUI by TouchGFX test as;
- GUITestNoOS
https://youtu.be/tz8haqRtUfs

# Hardware Connection
| Pinname | Function |
|---|---|
|PC6|DC|
|PB8|LED|
|PB15|RESET|
|PA5|LCD SCK|
|PA6|LCD MISO|
|PA7|LCD MOSI|
|PD14|LCD CS|
|PB5|TS MOSI|
|PB3|TS SCK|
|PB4|TS MISO|
|PE9|TS CS|
|PE13|TS IRQ|

![Nucleo and SPI LCD](https://github.com/kotetsuy/TouchGFXDemo/tree/master/images/IMG_1484.jpg)

# TODO
I'm going to support QSPI board to support bitmap on TouchGFX.
