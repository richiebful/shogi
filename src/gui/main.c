#include <gui.h>
#include <shogi.h>
#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

/*Updates GUI*/
void refreshBoard(struct gm_status *game){
  int offset_r  = 3, offset_f = 2, y, x;
  char piece[2];
  GtkWidget *button;
  gchar *label;
  for (y = 0; y < 9; y++){
    for (x = 0; x < 9; x++){
      piece[0] = game->board[y][x];
      button = gtk_grid_get_child_at (GtkGrid *grid, (gint) (x+offset_r), (gint) (j+offset_f));
      gtk_button_set_label(button, piece);
    }
  }
}

void handleMove(struct gm_struct *game, int *src, int *dst){
  if(legalmove(game, game->player, src, dst, 0)){
    mkmove(game, game->player, src, dst);
  }
  refreshBoard(game);
} 

void handleDrop(struct gm_struct *game, int drank, int dfile){
  int dst[2];
  dst[0] = drank;
  dst[1] = dfile;
  if (legaldrop(game, game->player, dst)){
    mkdrop(game, game->player, dst);
  }
  refreshBoard(game);
}

void handleBoardButton(rank, file){
  static int src_coords[2] = {-1, -1};
  static bool loc_f = false;
  if (loc_f == false){
    src_coords[0] = rank;
    src_coords[1] = file;
    loc_f = true;
  }
  else{
    if (src_coords[0] == -1){
      handleDrop(game, rank, file);
    }
    else{
      int dst[2] = {rank, file};
      handleMove(game, src_coords, dst);
    }
    loc_f = false;
  }
}

void handler00(){
  handleBoardButton(0,0);
}
void handler01(){
  handleBoardButton(0,1);
}
void handler02(){
  handleBoardButton(0,2);
}
void handler03(){
  handleBoardButton(0,3);
}
void handler04(){
  handleBoardButton(0,4);
}
void handler05(){
  handleBoardButton(0,5);
}
void handler06(){
  handleBoardButton(0,6);
}
void handler07(){
  handleBoardButton(0,7);
}
void handler08(){
  handleBoardButton(0,8);
}
void handler10(){
  handleBoardButton(1,0);
}
void handler11(){
  handleBoardButton(1,1);
}
void handler12(){
  handleBoardButton(1,2);
}
void handler13(){
  handleBoardButton(1,3);
}
void handler14(){
  handleBoardButton(1,4);
}
void handler15(){
  handleBoardButton(1,5);
}
void handler16(){
  handleBoardButton(1,6);
}
void handler17(){
  handleBoardButton(1,7);
}
void handler18(){
  handleBoardButton(1,8);
}
void handler20(){
  handleBoardButton(2,0);
}
void handler21(){
  handleBoardButton(2,1);
}
void handler22(){
  handleBoardButton(2,2);
}
void handler23(){
  handleBoardButton(2,3);
}
void handler24(){
  handleBoardButton(2,4);
}
void handler25(){
  handleBoardButton(2,5);
}
void handler26(){
  handleBoardButton(2,6);
}
void handler27(){
  handleBoardButton(2,7);
}
void handler28(){
  handleBoardButton(2,8);
}
void handler30(){
  handleBoardButton(3,0);
}
void handler31(){
  handleBoardButton(3,1);
}
void handler32(){
  handleBoardButton(3,2);
}
void handler33(){
  handleBoardButton(3,3);
}
void handler34(){
  handleBoardButton(3,4);
}
void handler35(){
  handleBoardButton(3,5);
}
void handler36(){
  handleBoardButton(3,6);
}
void handler37(){
  handleBoardButton(3,7);
}
void handler38(){
  handleBoardButton(3,8);
}
void handler40(){
  handleBoardButton(4,0);
}
void handler41(){
  handleBoardButton(4,1);
}
void handler42(){
  handleBoardButton(4,2);
}
void handler43(){
  handleBoardButton(4,3);
}
void handler44(){
  handleBoardButton(4,4);
}
void handler45(){
  handleBoardButton(4,5);
}
void handler46(){
  handleBoardButton(4,6);
}
void handler47(){
  handleBoardButton(4,7);
}
void handler48(){
  handleBoardButton(4,8);
}
void handler50(){
  handleBoardButton(5,0);
}
void handler51(){
  handleBoardButton(5,1);
}
void handler52(){
  handleBoardButton(5,2);
}
void handler53(){
  handleBoardButton(5,3);
}
void handler54(){
  handleBoardButton(5,4);
}
void handler55(){
  handleBoardButton(5,5);
}
void handler56(){
  handleBoardButton(5,6);
}
void handler57(){
  handleBoardButton(5,7);
}
void handler58(){
  handleBoardButton(5,8);
}
void handler60(){
  handleBoardButton(6,0);
}
void handler61(){
  handleBoardButton(6,1);
}
void handler62(){
  handleBoardButton(6,2);
}
void handler63(){
  handleBoardButton(6,3);
}
void handler64(){
  handleBoardButton(6,4);
}
void handler65(){
  handleBoardButton(6,5);
}
void handler66(){
  handleBoardButton(6,6);
}
void handler67(){
  handleBoardButton(6,7);
}
void handler68(){
  handleBoardButton(6,8);
}
void handler70(){
  handleBoardButton(7,0);
}
void handler71(){
  handleBoardButton(7,1);
}
void handler72(){
  handleBoardButton(7,2);
}
void handler73(){
  handleBoardButton(7,3);
}
void handler74(){
  handleBoardButton(7,4);
}
void handler75(){
  handleBoardButton(7,5);
}
void handler76(){
  handleBoardButton(7,6);
}
void handler77(){
  handleBoardButton(7,7);
}
void handler78(){
  handleBoardButton(7,8);
}
void handler80(){
  handleBoardButton(8,0);
}
void handler81(){
  handleBoardButton(8,1);
}
void handler82(){
  handleBoardButton(8,2);
}
void handler83(){
  handleBoardButton(8,3);
}
void handler84(){
  handleBoardButton(8,4);
}
void handler85(){
  handleBoardButton(8,5);
}
void handler86(){
  handleBoardButton(8,6);
}
void handler87(){
  handleBoardButton(8,7);
}
void handler88(){
  handleBoardButton(8,8);
}


static void activate(GtkApplication *app,
		     gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  struct gm_status game;

  init_game(*game);

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "GNU Shogi");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);
  
  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler00), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler01), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler02), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler03), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler04), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler05), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler06), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler07), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handler08), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 0, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler10), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler11), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler12), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler13), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler14), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler15), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler16), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler17), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handler18), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 1, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler20), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler21), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler22), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler23), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler24), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler25), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler26), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler27), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handler28), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 2, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler30), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler31), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler32), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler33), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler34), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler35), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler36), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler37), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handler38), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 3, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler40), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler41), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler42), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler43), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler44), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler45), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler46), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler47), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 4, 1, 1);

  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handler48), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 4, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler50), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler51), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler52), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler53), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler54), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler55), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler56), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler57), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 5, 1, 1);

  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handler58), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 5, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler60), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler61), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler62), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler63), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler64), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler65), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler66), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler67), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 6, 1, 1);

  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handler68), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 6, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler70), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler71), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler72), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler73), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler74), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler75), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler76), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler77), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 7, 1, 1);

  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handler78), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 7, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler80), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler81), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler82), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler83), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler84), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler85), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler86), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler87), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handler88), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 8, 1, 1);

  

  refreshBoard(game);
  gtk_widget_show_all (window);

}

int main (int argc, char **argv){

  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
