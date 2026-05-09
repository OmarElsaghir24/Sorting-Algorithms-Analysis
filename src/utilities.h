/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Utilities header file
 */
#ifndef UTILITIES_H
#define UTILITIES_H

#include "menu_features.h"

// Function declarations
void swap(int *a, int *b);
void generate_array(int *array, int array_size);
void print_sorted_array(int *array, int array_size);
void generate_random_array(int *array, int size);
void generate_sorted_array(int *array, int size);
void generate_reversely_sorted_array(int *array, int size);
void generate_array_with_duplicates(int *array, int size);
const char* input_type_to_string(Input_Type input_type);
const char* algorithm_to_string(Algorithm algorithm);

#endif