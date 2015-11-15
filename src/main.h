#ifndef _MAIN_H
#define _MAIN_H

#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include "model/manager.h"
#include "controllers/controller.h"
#include "functions.h"

#define SCRIPTS_PATH "/.local/share/nautilus/scripts"
#define CONFIG_PATH "/.config/nautilus/"
#define CONFIG_FILE_NAME "scripts-accels"
#define DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__);

/* Load gui from string by default */
#if 0
#define LOAD_GUI_FROM_FILE
#define MAIN_WINDOW "view/mainWindow.ui"
#define SELECT_SCRIPT_DIALOG "view/selectScriptDialog.ui"
#define KEY_REGISTER_DIALOG "view/keyRegisterDialog.ui"
#else
#include "view/keyRegisterDialog.h"
#include "view/selectScriptDialog.h"
#include "view/mainWindow.h"
#endif

#endif