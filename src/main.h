/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Main header file
 */
#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

// Structures, variables, defines, enums
typedef struct _AppWidgets
{
    GtkWidget *merge_button;
    GtkWidget *heap_button;
    GtkWidget *quick_regular_button;
    GtkWidget *quick_medians_button;
    GtkWidget *insertion_button;
    GtkWidget *selection_button;
    GtkWidget *bubble_button;
    GtkWidget *input_type_dropdown;
    GtkWidget *size_entry;
    GtkWidget *run_algorithms;
    GtkWidget *output_label;
}AppWidgets;

// Function declarations
static void on_run_clicked(GtkButton *button, gpointer user_data);
static void activate(GtkApplication *app, gpointer user_data);

#endif
