#ifndef _MANAGER_H
#define _MANAGER_H

#include <string.h>
#include <stdio.h>
#include "../main.h"

void init_manager (void);
void load_accels (void);
void new_accel (gpointer script_name, gpointer shortcut);
void foreach_script_do (gpointer function, gpointer user_data);
void delete_accel (const gchar* script_name);
void save_accels (void);

#endif