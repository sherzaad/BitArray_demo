#include "BitArray.h"

BitArray arr(9);

void printBitArray() {
  for (int i = 0; i < arr.length(); ++i) {
    Serial.print("bit");
    Serial.print(i, DEC);
    Serial.print(": ");
    Serial.println(arr.readBit(i), DEC);
  }
  Serial.println("");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

  printBitArray();

  arr.setBit(3);

  arr.setBit(8);

  printBitArray();

  arr.clearBit(8);

  printBitArray();
}

void loop() {
  // put your main code here, to run repeatedly:

}
