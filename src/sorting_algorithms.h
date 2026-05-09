/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Sorting algorithms header file
 */
#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

#include <stdint.h>
#include <stdio.h>

// Function declarations
void merge_sort(int array[], int left, int right);
void merge(int array[], int left, int middle, int right);
void insertion_sort(int array[], int size);
void selection_sort(int array[], int size);
void bubble_sort(int array[], int size);
void quick_sort_regular(int array[], int low, int high);
void Heap_sort(int array[], int size);
void quick_sort_three_medians(int array[], int low, int high);

#endif