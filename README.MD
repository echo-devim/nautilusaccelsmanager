# NautilusAccelsManager

Nautilus (the GNOME file manager) supports a new feature to define custom shortcuts to launch the scripts in the special scripts folder.

The special scripts folder is:
`~/.locale/applications/nautilus/scripts` and here you can put any executable you want and it will appear in the right-click context-menu.

The shortcut configuration file is in `~/.config/nautilus/scripts-accels` and here you can define your custom shortcuts.

I wrote NautilusAccelsManager to edit this file with a gui.

![screenshot](NAM.png "NAM")

### Details
Every script will run in the context of the current directory and Nautilus will pass to it all the file names of the selected files in the folder. You can use also some environment variable to get more information like:

- NAUTILUS_SCRIPT_SELECTED_FILE_PATHS
- NAUTILUS_SCRIPT_SELECTED_URIS
- NAUTILUS_SCRIPT_CURRENT_URI
- NAUTILUS_SCRIPT_WINDOW_GEOMETRY

This is the link of the commit that introduce the new feature:
https://git.gnome.org/browse/nautilus/commit/?id=9fe1335

## License
GPLv3