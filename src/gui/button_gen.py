for i in range(0, 9):
    for j in range(0, 9):
        #fix first line of console output
        print("""button = gtk_button_new_with_label ("{0}");
g_signal_connect (button, "clicked", G_CALLBACK (handle{0}{1}), NULL);
gtk_grid_attach (GTK_GRID (grid), button, {1}, {0}, 1, 1);\n""".format(i, j))
