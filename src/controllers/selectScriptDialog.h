#ifndef _SELECT_SCRIPT_DIALOG_H
#define _SELECT_SCRIPT_DIALOG_H

#include "controller.h"

void on_btnSelect_clicked (GtkButton *button, gpointer user_data);
const gchar *getSelectedScriptName (void);
void on_select_dialog_show (GtkWidget *widget, gpointer user_data);

#endif