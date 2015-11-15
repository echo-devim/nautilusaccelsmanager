#ifndef _KEY_REGISTER_DIALOG
#define _KEY_REGISTER_DIALOG

#include "../main.h"

void on_dialogKeyRegister_unrealize (GtkWidget *widget, gpointer data);
gboolean on_dialog_key_press_event (GtkWidget *widget, GdkEventKey *event, gpointer user_data);
void on_btnOk_clicked (GtkButton *button, gpointer user_data);
const gchar *getSelectedShortcut (void);

#endif