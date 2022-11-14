#include <stdbool.h>
#include <stdio.h>

/**
 * A function to determine if the machine who runs it using big ar little endian.
 * The function creates a variable of type long, casting it's last byte to pointer of type char
 * (That way we get the last byte of address and not value),
 * and checking if it matches by value to the byte we declared.
 * @return a boolean 1 or 0. 1 means little endian, 0 means big endian.
 */
int is_big_endian() {
    // Creating the variable of type long.
    long num = 0b00001111000011110000111100001111;
    // Creating a mask pointer of size char to catch only the last byte.
    char *mask;
    // Casting the last byte of the number (by address).
    mask = (char *) &num;
    // Checking if it's value is 1111 or not.
    if (*mask == 0b1111)
        // If it is, return 1 - means little endian.
        return 1;
    // Otherwise, return 0 - means big endian.
    return 0;
}

    int get_sign_magnitude(bool bitArray[8]) {

    }

    int get_two_comp(bool bitArray[8]) {

    }