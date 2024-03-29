#ifndef	BITARRAY_H
#define	BITARRAY_H

#include <Arduino.h>

class BitArray {
  private:
    uint8_t *arr;
    uint16_t size;

  public:
    //set desired bit to 1
    inline void setBit(uint16_t i) {
      if(arr!=NULL && i < size) arr[i >> 3] |= (1 << (i & 0x07));
    }

    //set desired bit to 0
    inline void clearBit(uint16_t i) {
      if(arr!=NULL && i < size) arr[i >> 3] &= ~(1 << (i & 0x07));
    }

    //write 0 or 1 to desired bit
    inline int8_t writeBit(uint8_t val, uint16_t i) {

      if (arr==NULL || i >= size) return -1;

      if (val > 0) arr[i >> 3] |= (1 << (i & 0x07));
      else arr[i >> 3] &= ~(1 << (i & 0x07));

      return 1;
    }

    //read value of desired bit
    inline int8_t readBit(uint16_t i) {
      if (arr==NULL || i >= size) return -1;

      if (arr[i >> 3] & (1 << (i & 0x07))) return 1;

      return 0;
    }

    //return lenght of initalised bit array
    inline int16_t length() {
      if(arr!=NULL) return size;
      return -1;
    }

    //constructor
    BitArray(uint16_t n) {
      size = n;

      uint16_t bytes = (size >> 3) + (((size & 0x07) > 0) ? 1 : 0); //calculate the minimum number of bytes to hold size of bit array
                                                                    //size >> 3 equivalent to size/8 (integer division)
                                                                    //size & 0x07 equivalent to size%8 (modulo)

      arr = calloc(sizeof(uint8_t) * bytes); //'calloc()' gives you a zero-initialized buffer, while 'malloc()' leaves the memory uninitialized.
    }

    //deconstructor
    ~BitArray() {
      if(arr!=NULL) free(arr); //free allocated memory
    }
};

#endif
