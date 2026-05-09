/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Menu Features header file
 */
#ifndef MENU_FEATURES_H
#define MENU_FEATURES_H

// Structures, variables, defines, enums
typedef enum 
{
    MERGE_SORT,
    HEAP_SORT,
    QUICK_SORT_REGULAR,
    QUICK_SORT_3MEDIANS,
    INSERTION_SORT,
    SELECTION_SORT,
    BUBBLE_SORT
}Algorithm;

typedef enum
{
    RANDOM,
    SORTED,
    REVERSE_SORTED,
    DUPLICATES
}Input_Type;

// Function declarations
void run_one_algorithm(void);
void compare_all_algorithms(void);
Input_Type change_input_type(void);
void run_full_experiment(void);
double run_one_algorithm_backend(int algorithm, int size, Input_Type sorting_order);

#endif