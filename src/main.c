/*
 * Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * 
 * Compilation:
 *  gcc $(pkg-config --cflags gtk4) main.c menu_features.c utilities.c sorting_algorithms.c $(pkg-config --libs gtk4) -o program
 * ./program
 * 
 * Compilation with Makefile:
 * make
 * ./console_app
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <gtk/gtk.h>
#include "main.h"
#include "sorting_algorithms.h"
#include "utilities.h"
#include "menu.h"
#include "menu_features.h"

// This function handles events for when any of the buttons, dropdowns, etc are being interacted with
static void on_run_clicked(GtkButton *button, gpointer user_data)
{
    (void)button;
    AppWidgets *app = user_data;
    int count = 0;
    int sorting_algorithms[7];

    // Stores selected algorithms at each index depending on selections made
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->merge_button)))
    {
       sorting_algorithms[count++] = MERGE_SORT;
    }
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->heap_button)))
    {
        sorting_algorithms[count++] = HEAP_SORT;
    }
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->quick_regular_button)))
    {
        sorting_algorithms[count++] = QUICK_SORT_REGULAR;
    }
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->quick_medians_button)))
    {
        sorting_algorithms[count++] = QUICK_SORT_3MEDIANS;
    }
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->insertion_button)))
    {
        sorting_algorithms[count++] = INSERTION_SORT;
    }
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->selection_button)))
    {
        sorting_algorithms[count++] = SELECTION_SORT;
    }
    if(gtk_check_button_get_active(GTK_CHECK_BUTTON(app->bubble_button)))
    {
        sorting_algorithms[count++] = BUBBLE_SORT;
    }

    // Read selected options from GUI interface to use for algorithm comparison 
    guint input_index = gtk_drop_down_get_selected(GTK_DROP_DOWN(app->input_type_dropdown));
    const char *size_text = gtk_editable_get_text(GTK_EDITABLE(app->size_entry));
    int size = atoi(size_text);

    // Selects array sorting order based on selected option read from dropdown
    Input_Type sorting_order;
    switch(input_index)
    {
        case 0: sorting_order = RANDOM; break;
        case 1: sorting_order = SORTED; break;
        case 2: sorting_order = REVERSE_SORTED; break;
        case 3: sorting_order = DUPLICATES; break;
    }

    char buffer[256];

    // Handles event of no selected algorithms
    if(count == 0) 
    {
        snprintf(buffer, sizeof(buffer), "Please select an algorithm (or more).\n");
    }
    else if(count == 1)
    {
        // Handles event of only one algorithm selected
        double time = run_one_algorithm_backend(sorting_algorithms[0], size, sorting_order);
        snprintf(buffer, sizeof(buffer), "%s: %.4f seconds\n", algorithm_to_string(sorting_algorithms[0]), time);

    }
    else 
    {
        // More than one algorithm selected 
        buffer[0] = '\0';

        for(int i = 0; i < count; i++)
        {
            double time = run_one_algorithm_backend(sorting_algorithms[i], size, sorting_order);

            char line[128];
            snprintf(line, sizeof(line), "%s: %.4f seconds\n", algorithm_to_string(sorting_algorithms[i]), time);

            strncat(buffer, line, sizeof(buffer) - strlen(buffer) - 1);
        }
        
    }

    gtk_label_set_text(GTK_LABEL(app->output_label), buffer);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    (void)user_data;
    GtkWidget *window;
    //GtkWidget *grid;
    const char* input_types[] = {"Random", "Sorted", "Reverse Sorted", "Duplicates", NULL};
    // Create new window for GUI and set title 
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Algorithms Project");

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Set window size
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

    // Construct container to pack buttons, dropdowns, and text-field input buttons
    //grid = gtk_grid_new();

    // Pack the container in the window created
    //gtk_window_set_child(GTK_WINDOW(window), grid);

    // Allocates memory for created structure used for button, dropdown, and entry field buttons
    AppWidgets *widgets = g_malloc(sizeof(AppWidgets));

    // Create check buttons for selecting algorithms to run
    widgets->merge_button = gtk_check_button_new_with_label("Merge Sort");
    widgets->heap_button = gtk_check_button_new_with_label("Heap Sort");
    widgets->quick_regular_button = gtk_check_button_new_with_label("Regular Quick Sort");
    widgets->quick_medians_button = gtk_check_button_new_with_label("Quick Sort (3 Medians)");
    widgets->insertion_button = gtk_check_button_new_with_label("Insertion Sort");
    widgets->selection_button = gtk_check_button_new_with_label("Selection Sort");
    widgets->bubble_button = gtk_check_button_new_with_label("Bubble Sort");
    // Create a dropdown box to select how arrays will be sorted 
    widgets->input_type_dropdown = gtk_drop_down_new_from_strings(input_types);
    // Create an entry box for providing the size of the array
    widgets->size_entry = gtk_entry_new();
    // Create a label to output algorithm comparison results
    widgets->output_label = gtk_label_new("Print Output");
    // Create new button for executing algorithms
    GtkWidget *run_button = gtk_button_new_with_label("Run Algorithms");
    g_signal_connect(run_button, "clicked", G_CALLBACK(on_run_clicked), widgets);

    // Set an array size as default when window first loads
    gtk_editable_set_text(GTK_EDITABLE(widgets->size_entry), "1000");

    // Appends buttons created to interface
    gtk_box_append(GTK_BOX(box), widgets->merge_button);
    gtk_box_append(GTK_BOX(box), widgets->heap_button);
    gtk_box_append(GTK_BOX(box), widgets->quick_regular_button);
    gtk_box_append(GTK_BOX(box), widgets->quick_medians_button);
    gtk_box_append(GTK_BOX(box), widgets->insertion_button);
    gtk_box_append(GTK_BOX(box), widgets->selection_button);
    gtk_box_append(GTK_BOX(box), widgets->bubble_button);
    gtk_box_append(GTK_BOX(box), widgets->input_type_dropdown);
    gtk_box_append(GTK_BOX(box), widgets->size_entry);
    gtk_box_append(GTK_BOX(box), run_button);
    gtk_box_append(GTK_BOX(box), widgets->output_label);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.project.test", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
