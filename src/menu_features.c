/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Menu Features source file
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"
#include "utilities.h"
#include "menu_features.h"

void run_one_algorithm(void)
{
   int size;
   int option;
   printf("1. Mergesort\n");
   printf("2. Heapsort\n");
   printf("3. Quicksort\n");
   printf("4. Insertion sort\n");
   printf("5. Selection sort\n");
   printf("6. Bubble sort\n");

   printf("Select algorithm: ");
   scanf("%d", &option);

   printf("Enter input size: ");
   scanf("%d", &size);

   int data[size];

   generate_array(data, size);

   switch(option)
   {
      case 1:
         merge_sort(data, 0, size - 1);
         break;
      case 2:
         Heap_sort(data, size);
         break;
      case 3:
         int choice;
         printf("1. Regular Quick sort\n");
         printf("2. Quick sort with 3 medians\n");
         printf("Select a version of quick sort: ");
         scanf("%d", &choice);

         if(choice == 1)
         {
            quick_sort_regular(data, 0, size - 1);
         }
         else
         {
            quick_sort_three_medians(data, 0, size - 1);
         }
         break;
      case 4:
         insertion_sort(data, size);
         break;
      case 5:
         selection_sort(data, size);
         break;
      case 6:
         bubble_sort(data, size);
         break;
   }

   print_sorted_array(data, size);
}

// Test function for implementing runtime analysis of all algorithms. 
double measure_algorithms(int algorithm, int* original_array, int size)
{
   int* copy_array = malloc(size * sizeof(int));
   if(copy_array == NULL)
   {
      printf("Memory Allocation failed!\n");
      return -1.0;
   }

   for(int i = 0; i < size; i++)
   {
      copy_array[i] = original_array[i];
   }

   clock_t start = clock();

   switch(algorithm)
   {
      case MERGE_SORT:
         merge_sort(copy_array, 0, size - 1);
         break;
      case HEAP_SORT:
         Heap_sort(copy_array, size);
         break;
      case QUICK_SORT_REGULAR:
         quick_sort_regular(copy_array, 0, size - 1);
         break;
      case QUICK_SORT_3MEDIANS:
         quick_sort_three_medians(copy_array, 0, size - 1);
         break;
      case INSERTION_SORT:
         insertion_sort(copy_array, size);
         break;
      case SELECTION_SORT:
         selection_sort(copy_array, size);
         break;
      case BUBBLE_SORT:
         bubble_sort(copy_array, size);
         break;
   }
   
   clock_t end = clock();
   free(copy_array);

   return (double)(end - start) / CLOCKS_PER_SEC;
}

// This function is used for running the selected algorithm(s) and measure running time based on size of array.
// It first allocates an array around the size provided from the GUI interface, then sorts the array elements based
// on selected sorting order read from GUI, and then sorts the array using the algorithm(s). 
double run_one_algorithm_backend(int algorithm, int size, Input_Type sorting_order)
{

   int* data = malloc(size * sizeof(int));
   if(data == NULL)
   {
      return -1.0;
   }

   // Select array sorting order before executing sorting algorithms
   switch(sorting_order)
   {
      case RANDOM:
         generate_random_array(data, size);
         break;
      case SORTED:
         generate_sorted_array(data, size);
         break;
      case REVERSE_SORTED:
         generate_reversely_sorted_array(data, size);
         break;
      case DUPLICATES:
         generate_array_with_duplicates(data, size);
         break;
   }

   // Begin runtime analysis for selected algorithm(s)
   clock_t start = clock();

   switch(algorithm)
   {
      case 0:
         merge_sort(data, 0, size - 1);
         break;
      case 1:
         Heap_sort(data, size);
         break;
      case 2:
         quick_sort_regular(data, 0, size - 1);
         break;
      case 3:
         quick_sort_three_medians(data, 0, size - 1);
         break;
      case 4:
         insertion_sort(data, size);
         break;
      case 5:
         selection_sort(data, size);
         break;
      case 6:
         bubble_sort(data, size);
         break;
   }

   // End runtime analysis
   clock_t end = clock();

   // Returns elapsed time for how long the algorithm(s) took to finish sorting array elements
   return (double)(end - start) / CLOCKS_PER_SEC;
}

// Function for testing array sorting order selection.
Input_Type change_input_type(void)
{
   int choice;
   printf("1. Random\n");
   printf("2. Sorted\n");
   printf("3. Reversely sorted\n");
   printf("4. Duplicates\n");
   printf("Enter choice of array condition: ");
   scanf("%d", &choice);

   switch(choice)
   {
      case 1:
         printf("Random values will be generated\n");
         return RANDOM;
         break;
      case 2:
         printf("Array values will be sorted in increasing order\n");
         return SORTED;
         break;
      case 3:
         printf("Array values will be reversely sorted\n");
         return REVERSE_SORTED;
         break;
      case 4:
         printf("Duplicates values present in array\n");
         return DUPLICATES;
         break;
      default:
         printf("Invalid input. Please select a valid choice.\n");
         return 0;
         break;
   }
}

void compare_algorithms(int size, Input_Type current_input_type)
{
   int* array = malloc(size * sizeof(int));
   if(array == NULL)
   {
      printf("Memory allocation failed!\n");
      return;
   }

   switch(current_input_type)
   {
      case RANDOM:
         generate_random_array(array, size);
         break;
      case SORTED:
         generate_sorted_array(array, size);
         break;
      case REVERSE_SORTED:
         generate_reversely_sorted_array(array, size);
         break;
      case DUPLICATES:
         generate_array_with_duplicates(array, size);
         break;
   }

   double merge_time = measure_algorithms(MERGE_SORT, array, size);
   double heap_time = measure_algorithms(HEAP_SORT, array, size);
   double quick_regular_time = measure_algorithms(QUICK_SORT_REGULAR, array, size);
   double quick_median3_time = measure_algorithms(QUICK_SORT_3MEDIANS, array, size);
   double insertion_time = measure_algorithms(INSERTION_SORT, array, size);
   double selection_time = measure_algorithms(SELECTION_SORT, array, size);
   double bubble_time = measure_algorithms(BUBBLE_SORT, array, size);

   printf("\n==== Comparison Results ====\n");
   printf("Input size = %d\n", size);
   printf("Input type = %s\n", input_type_to_string(current_input_type));
   printf("Merge sort = %.4f seconds\n", merge_time);
   printf("Heap sort = %.4f seconds\n", heap_time);
   printf("Regular Quick sort = %.4f seconds\n", quick_regular_time);
   printf("Quick sort 3 medians = %.4f seconds\n", quick_median3_time);
   printf("Insertion sort = %.4f seconds\n", insertion_time);
   printf("Selection sort = %.4f seconds\n", selection_time);
   printf("Bubble sort = %.4f seconds\n", bubble_time);

   free(array);
}

void run_full_experiment(void)
{
   Input_Type current_input_type;
   current_input_type = change_input_type();
   //int sizes[] = {1000, 3000, 5000, 9000};
   int sizes[] = {1000, 2500, 5000, 7500, 10000, 20000, 30000, 40000, 50000, 100000};
   int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

   for(int i = 0; i < num_sizes; i++)
   {
      compare_algorithms(sizes[i], current_input_type);
   }
}