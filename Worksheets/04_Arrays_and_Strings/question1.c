/**
 * question1.c - Worksheet 4
 *
 * @author		Even A. Nilsen
 * @version		21.09.2016
 */
#include <stdio.h>
#include "question1.h"

/**
 * Adds up all array elements and returns the sum
 * @param intArray[] the array which elements you want the sum of
 * @return sum
 */
int sum(int intArray[], int length)
{
    int i;
    int sum = 0;
    for (i = 0; i < length; i++) {
        sum += intArray[i];
    }

    return sum;
}

/**
 * Finds the largest element in an array and returns its index
 * @param intArray[] the array to search
 * @return index
 */
int max(int intArray[], int length)
{
    int index = 0;
    int largestElement = 0;
    int i;
    for (i = 0; i < length; i++) {
        if (largestElement < intArray[i]) {
            largestElement = intArray[i];
        }
    }

    while (intArray[index] != largestElement) {
        index++;
    }
    
    return index;
}

/**
 * Reverses the order of the array elements
 * @param intArray[] the array to reverse
 * @param end  last index
 */
void reverse(int intArray[], int end)
{
    int start = 0;
    int temp;

    while (end > start) {
        temp = intArray[end];
        intArray[end] = intArray[start];
        intArray[start] = temp;
        end--;
        start++;
    }

}
