#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <glib/gi18n.h>
#include <gtk/gtk.h>

GtkWidget *create_window_from_file (gchar *path, gchar *window_name);
GtkWidget *create_window_from_string (const gchar *string, gchar *window_name);
void show_message(const gchar *title, const gchar *message);

#endif