/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2015 Gregorio <devim@outlook.it>
 * 
 * NautilusAccelsManager is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NautilusAccelsManager is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "main.h"

#define VIEW_PATH "view/"
#define MODEL_PATH "model/"
#define CONTROLLER_PATH "controllers/"

int
main (int argc, char *argv[])
{
 	GtkWidget *window;

	init_manager ();
	
	gtk_init (&argc, &argv);
	
	#ifdef LOAD_GUI_FROM_FILE
	window = create_window_from_file (MAIN_WINDOW, "window");
	#else
	window = create_window_from_string (mainWindowString, "window");
	#endif
	gtk_widget_hide (window); //Hack to call the 'on show' handler
	gtk_widget_show (window);
	gtk_main ();

	return 0;
}

