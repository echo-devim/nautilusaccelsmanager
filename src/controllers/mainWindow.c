#include "mainWindow.h"

static GtkListStore *listStore = NULL;

void
on_btnNew_clicked (GtkButton *button, gpointer user_data)
{
	#ifdef LOAD_GUI_FROM_FILE
	gtk_widget_show (create_window_from_file (SELECT_SCRIPT_DIALOG, "dialogSelectScript"));
	#else
	gtk_widget_show (create_window_from_string (selectScriptDialogString, "dialogSelectScript"));
	#endif
}

static void
add_all_elem (gpointer key, gpointer value, gpointer user_data)
{
	GtkTreeIter iter;
	gtk_list_store_insert ((GtkListStore*)user_data, &iter, -1);
	gtk_list_store_set ((GtkListStore*)user_data, &iter, 1, key, -1);
	gtk_list_store_set ((GtkListStore*)user_data, &iter, 0, value, -1);
}

void
refresh_list (void)
{
	g_assert_nonnull (listStore);
	gtk_list_store_clear (listStore);
	foreach_script_do (add_all_elem, listStore);
}

void
on_main_window_show (GtkWidget *widget, gpointer user_data)
{
	GtkListStore *ls = (GtkListStore *) G_OBJECT (user_data);
	listStore = ls;
	refresh_list ();
}

void
on_btnDelete_clicked (GtkButton *button, gpointer user_data)
{
	GtkTreeView *tw = (GtkTreeView *) G_OBJECT (user_data);
	GtkTreeModel *model = gtk_tree_view_get_model (tw);
	GtkTreeIter iter;
	gtk_tree_selection_get_selected (gtk_tree_view_get_selection (tw), &model, &iter);
	const gchar *script_name;
	GValue value={0,};
	gtk_tree_model_get_value (model, &iter, 1, &value);
	script_name = g_value_get_string (&value);
	delete_accel (script_name);
	g_value_unset (&value);
}

void
on_btnSave_clicked (GtkButton *button, gpointer user_data)
{
	save_accels ();
	show_message ("NAM", "Shortcuts saved! Please restart Nautilus.");
}