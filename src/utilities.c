/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Utilities source file
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "menu_features.h"

void generate_array(int *array, int array_size)
{
    for(int i = 0; i < array_size; i++)
    {
        array[i] = rand() % 100;
    }
}

// This function performs swapping of two elements switching their positions
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_sorted_array(int *array, int array_size)
{
    printf("\nSorted Array: ");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// This function generates an array with elements randomly sorted
void generate_random_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 200;
    }
}

// This function generates an array with elements sorted in ascending order
void generate_sorted_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = i;
    }
}

// This function generates an array with elements sorted in reverse (descending) order
void generate_reversely_sorted_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = size - i;
    }
}

// This function generates an array with many duplicates present 
void generate_array_with_duplicates(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

// This function is used to return a string version of an enum (for how arrays will be sorted) 
const char* input_type_to_string(Input_Type input_type)
{
    switch(input_type)
    {
        case RANDOM:
           return "Random";
        case SORTED:
           return "Sorted";
        case REVERSE_SORTED:
           return "Reverse Sorted";
        case DUPLICATES:
           return "Duplicates";
        default:
           return "Unknown";
    }
}

// This function is used to return a string version of an enum (sorting algorithm names)
const char* algorithm_to_string(Algorithm algorithm)
{
    switch(algorithm)
    {
        case MERGE_SORT:
           return "Merge Sort";
           break;
        case HEAP_SORT:
           return "Heap Sort";
           break;
        case QUICK_SORT_REGULAR:
           return "Regular Quick Sort";
           break;
        case QUICK_SORT_3MEDIANS:
           return "Quick Sort (3 Medians)";
           break;
        case INSERTION_SORT:
           return "Insertion Sort";
           break;
        case SELECTION_SORT:
           return "Selection Sort";
           break;
        case BUBBLE_SORT:
           return "Bubble Sort";
           break;
        default:
           return "Unknown algorithm";
    }
}