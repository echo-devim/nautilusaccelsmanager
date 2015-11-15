#include "keyRegisterDialog.h"

#define GDK_Shift_L 0xffe1
#define GDK_Shift_R 0xffe2
#define GDK_Alt_L 0xffe9
#define GDK_Alt_R 0xffea
#define GDK_Super_L 0xffeb
#define GDK_Super_R 0xffec
#define GDK_Control_L 0xffe3
#define GDK_Control_R 0xffe4

static gboolean pressed = FALSE;
static const gchar *shortcut;

const gchar *
getSelectedShortcut (void)
{
    return shortcut;
}

gboolean
on_dialog_key_press_event (GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    GtkLabel *label = (GtkLabel *) G_OBJECT (user_data);
    if (!pressed) {
        pressed = TRUE;
        gtk_label_set_text (label, "");
    }
    switch (event->keyval)
    {
        case GDK_Control_L:
        case GDK_Control_R:
            gtk_label_set_text (label, g_strconcat (gtk_label_get_text (label), "<control>", NULL));
            break;
        case GDK_Shift_L:
        case GDK_Shift_R:
            gtk_label_set_text (label, g_strconcat (gtk_label_get_text (label), "<shift>", NULL));
            break;
        case GDK_Alt_L:
        case GDK_Alt_R:
            gtk_label_set_text (label, g_strconcat (gtk_label_get_text (label), "<alt>", NULL));
            break;
        case GDK_Super_L:
        case GDK_Super_R:
            gtk_label_set_text (label, g_strconcat (gtk_label_get_text (label), "<super>", NULL));
            break;
        default:
            gtk_label_set_text (label, g_strconcat (gtk_label_get_text (label), gdk_keyval_name (event->keyval), NULL));
    }
    return FALSE;
}

void
on_dialogKeyRegister_unrealize (GtkWidget *widget, gpointer data)
{
    pressed = FALSE;
}

void
on_btnOk_clicked (GtkButton *button, gpointer user_data)
{
    GtkLabel *label = (GtkLabel *) G_OBJECT (user_data);
    shortcut = gtk_label_get_text (label);
    new_accel ((gpointer) getSelectedScriptName (), (gpointer) shortcut);
    on_btnCancel_clicked (NULL, gtk_widget_get_toplevel ((GtkWidget *)label));
}