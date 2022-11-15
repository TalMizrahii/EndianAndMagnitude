// 206960890 Tal Mizrahi
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

/**
 * A power calculation function to calculate the base to the power of the exponent.
 * @param base the base of the number we want to calculate the power of.
 * @param exponent the exponent of the number we want to calculate the power of.
 * @return base^exponent.
 */
int power(int base, int exponent) {
    // Initiating the result to 1.
    int result = 1;
    // Iterating the calculation as the amount of the exponent.
    for (int i = 0; i < exponent; i++) {
        result = result * base;
    }
    return result;
}
/**
 * Taking an array representing a byte, and calculating his value in decimal (all bits except the MSB).
 * @param bitArray bitArray array of boolean values representing a byte.
 * @return The decimal value of all bits except the MSB in unsigned notation.
 */
int magnitude_check(bool bitArray[8]){
    // Declaring the mask to be a constant value of 1.
    const int MASK = 1;
    // Declaring the sum in decimal, and a temp variable to store the numeric value of the bitarray's position.
    int sum = 0, temp;
    // Iterating the array as the amount of its length - 1.
    for (int i = 0; i < 7; i++) {
        // Storing the numeric value of the bitarray's position.
        temp = bitArray[i] & MASK;
        // multiplying the temp by 2 to the power of i's position in the array and adding it to the sum.
        sum += temp * power(2, i);
    }
    // Otherwise, return the positive sum.
    return sum;
}

/**
 * Calculating an array of boolean values representing a byte in the Sign/Magnitude notation.
 * We use magnitude_check function to check every bit in the array (except the MSB),
 * multiplying it by 2 to the power of it's position in the array and summing it.
 * If the MSB is 1 (true), returning the sum as negative, if it's 0 (false), returning the sum as positive.
 * @param bitArray array of boolean values representing a byte in the Sign/Magnitude notation.
 * @return the number the array represent in Sign/Magnitude notation.
 */
int get_sign_magnitude(bool bitArray[8]) {
    // Getting the decimal value of all bit except the MSB.
    int sum = magnitude_check(bitArray);
    // If the MSB is 1 (true), return the negative sum.
    if (bitArray[7] == true) {
        return -sum;
    }
    // Otherwise, return the positive sum.
    return sum;
}

/**
 * Calculating an array of boolean values representing a byte in the Two's complement notation.
 * We use magnitude_check function to check every bit in the array (except the MSB),
 * multiplying it by 2 to the power of it's position in the array and summing it.
 * If the MSB is 1 (true), we subtract 2 to the power of the MSB's index, if it's 0 (false), we do nothing to the sum.
 * @param bitArray array of boolean values representing a byte in the Sign/Magnitude notation.
 * @return the decimal value the array represent in Two's complement notation.
 */
int get_two_comp(bool bitArray[8]) {
    // Declaring the mask to be a constant value of 1.
    const int MASK = 1;
    // Checking the MSB's value and storing it in the variable temp.
    int temp = bitArray[7] & MASK;
    // Getting the decimal value of all bit except the MSB.
    int sum = magnitude_check(bitArray);
    // Subtracting the calculation of temp multiplied by 2 to the power of the MSB's index.
    sum -= temp * power(2, 7);
    // Returning the decimal value the array represent in Two's complement notation.
    return sum;
}