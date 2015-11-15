#include "selectScriptDialog.h"

static const gchar *script_name;

const gchar *
getSelectedScriptName (void)
{
    return script_name;
}

void
on_btnSelect_clicked (GtkButton *button, gpointer user_data)
{
	GtkComboBox *cmbScriptNames = (GtkComboBox *) G_OBJECT (user_data);
	script_name = gtk_combo_box_get_active_id(cmbScriptNames);
	if (script_name != NULL) {
		#ifdef LOAD_GUI_FROM_FILE
	    gtk_widget_show (create_window_from_file (KEY_REGISTER_DIALOG, "dialogKeyRegister"));
	    #else
	    gtk_widget_show (create_window_from_string (keyRegisterDialogString, "dialogKeyRegister"));
	    #endif
	    on_btnCancel_clicked (NULL, gtk_widget_get_toplevel ((GtkWidget *)cmbScriptNames));
	}
}

void
on_select_dialog_show (GtkWidget *widget, gpointer user_data)
{
	GtkTreeIter iter;
	GtkListStore *ls = (GtkListStore *) G_OBJECT (user_data);
	gchar *path = g_build_filename (g_get_home_dir (), SCRIPTS_PATH, NULL);
	GError *error = NULL;
	const gchar *filename;
	GDir *dir = g_dir_open (path, 0, &error);
	if (error != NULL) {
		DEBUG ("Unable to open '%s', error message: %s", path, error->message);
		g_clear_error (&error);
	} else
		while ((filename = g_dir_read_name (dir)))
    		gtk_list_store_insert_with_values ((GtkListStore*)user_data, &iter, -1, 1, filename, -1);
    g_free (path);
}