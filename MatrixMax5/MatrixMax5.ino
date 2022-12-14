#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 9;
int numberOfHorizontalDisplays = 1; // количество матриц по-горизонтали
int numberOfVerticalDisplays = 1; // количество матриц по-вертикали

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

const byte data[8] = {
    0b01100110,
    0b11111111,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000
};

void setup() {
    matrix.setIntensity(7); // яркость от 0 до 15

    matrix.fillScreen(LOW); // очистка матрицы
    for ( int y = 0; y < 8; y++ ) {
        for ( int x = 0; x < 8; x++ ) {
            // зажигаем x-й пиксель в y-й строке
            matrix.drawPixel(x, y, data[y] & (1<<x));
        }
    }
    matrix.write(); // вывод всех пикселей на матрицу
}

void loop() {
}
