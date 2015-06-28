#include <gtk/gtk.h>
#include <shogi.h>

#define GEN_BOARD_BUTTON_BINDING(rank, file)	\
  button = gtk_button_new_with_label ("0"); \
  g_signal_connect (button, "clicked", G_CALLBACK (handle\ rank\ file), NULL); \
  gtk_grid_attach (GTK_GRID (grid), button, row, column, 1, 1);

void refreshBoard(struct gm_struct *game);

