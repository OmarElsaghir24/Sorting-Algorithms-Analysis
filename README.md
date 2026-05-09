# Sorting-Algorithms-Analysis

This project implements and compares multiple sorting algorithms from scratch in C language. The goal is to analyze how their running times change with respect to array size and how array is sorted before executing sorting algorithms.

The following algorithms were implemented:

- Merge Sort
- Heap Sort
- Regular Quick Sort
- Quick Sort (3 Medians)
- Insertion Sort
- Selection Sort
- Bubble Sort

The program evaluates performance under different conditions:
- Randomly sorted arrays
- Sorted arrays
- Reversely sorted arrays
- Arrays with multiple duplicates

A GTK-based GUI was implemented to allow interactive testing and comparison.

# Project Structure

-`main.c`:
  Contains the GTK GUI setup and event handling logic.

-`menu_features.c`
  Handles algorithm execution, experiment control, ad user selections.

-`sorting_algorithms.c`
  Contains implementations of all sorting algorithms.

-`utilities.c`
  Includes helper functions such as array generation, algorithm labeling, and element swapping.

-`Makefile`
  Automates compilation and linking of the project.
