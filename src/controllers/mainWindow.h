#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include "controller.h"

void on_btnNew_clicked (GtkButton *button, gpointer user_data);
static void add_all_elem (gpointer key, gpointer value, gpointer user_data);
void refresh_list (void);
void on_main_window_show (GtkWidget *widget, gpointer user_data);
void on_btnSave_clicked (GtkButton *button, gpointer user_data);

#endif