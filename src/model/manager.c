#include "manager.h"

static GHashTable *script_accels = NULL;

void
init_manager (void) {
	if (script_accels == NULL) {
		script_accels = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
		load_accels ();
	}
}

void
load_accels (void)
{
	gchar *path = g_build_filename (g_get_home_dir (), CONFIG_PATH CONFIG_FILE_NAME, NULL);
	gchar *contents;
	GError *error = NULL;
	const int max_len = 100;
	int i;
	if (g_file_get_contents (path, &contents, NULL, &error)) {
		gchar **lines = g_strsplit (contents, "\n", -1);
		g_free (contents);
		for (i = 0; lines[i] && (strstr (lines[i], " ") > 0); i++) {
			gchar **result = g_strsplit (lines[i], " ", 2);
			g_hash_table_insert (script_accels, g_strndup (result[1], max_len), g_strndup (result[0], max_len));
			g_free (result);
		}
		g_strfreev (lines);
	} else {
		DEBUG ("Unable to open '%s', error message: %s", path, error->message);
		g_clear_error (&error);
	}
	g_free (path);
}

void
save_accels (void)
{
	gchar *path = g_build_filename (g_get_home_dir (), CONFIG_PATH CONFIG_FILE_NAME, NULL);
	gchar *contents, *shortcut, *script_name;
	GError *error = NULL;
	GHashTableIter iter;
	g_hash_table_iter_init (&iter, script_accels);
	contents = (g_string_new (""))->str;
	while (g_hash_table_iter_next (&iter, (gpointer *) &script_name, (gpointer *) &shortcut)) {
		gchar *temp = contents;
		contents = g_strconcat (contents, shortcut, " ", script_name, "\n", NULL);
		g_free (temp);
	}
	if (!g_file_set_contents (path, (const char *) contents, -1, &error)) {
		DEBUG ("Unable to open '%s', error message: %s", path, error->message);
		g_clear_error (&error);
	}
	g_free (contents);
	g_free (path);
}

void
new_accel (gpointer script_name, gpointer shortcut)
{
	if (!g_hash_table_contains (script_accels, script_name)) {
		g_hash_table_insert (script_accels, g_strdup (script_name), g_strdup (shortcut));
		refresh_list ();
	}
}

void
delete_accel (const gchar* script_name)
{
	g_hash_table_remove (script_accels, script_name);
	refresh_list ();
}

void
foreach_script_do (gpointer function, gpointer user_data)
{
    g_hash_table_foreach (script_accels, function, user_data);
}
