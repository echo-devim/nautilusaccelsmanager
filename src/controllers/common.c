#include "controller.h"

/* Signal handlers */
/* Note: signal autoconnection only works with non-static methods */

void
on_window_destroy (GtkWidget *widget, gpointer data)
{
	gtk_main_quit ();
}

void
on_btnCancel_clicked (GtkButton *button, gpointer user_data)
{
	GtkWidget *dialog = (GtkWidget *) G_OBJECT (user_data);
	gtk_widget_destroy(dialog);
}
