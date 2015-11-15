#include "functions.h"

GtkWidget*
create_window_from_file (gchar *path, gchar *window_name)
{
	GtkWidget *window;
	GtkBuilder *builder;
	GError* error = NULL;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, path, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, NULL);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, window_name));
        if (!window)
        {
                g_critical ("Widget \"%s\" is missing in file %s.",
				window_name,
				path);
        }
        
	g_object_unref (builder);
	
	return window;
}

GtkWidget*
create_window_from_string (const gchar *string, gchar *window_name)
{
	GtkWidget *window;
	GtkBuilder *builder;
	GError* error = NULL;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_string (builder, string, -1, &error))
	{
		g_critical ("Couldn't load builder from string: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, NULL);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, window_name));
        if (!window)
        {
                g_critical ("Widget \"%s\" is missing in string passed as argument.",
				window_name);
        }
        
	g_object_unref (builder);
	
	return window;
}

void
show_message(const gchar *title, const gchar *message)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "%s", message);
    gtk_window_set_title(GTK_WINDOW(dialog), title);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}