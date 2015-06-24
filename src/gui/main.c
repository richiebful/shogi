
#include <gtk/gtk.h>
#include <gui.h>
#include <shogi.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

/*Updates GUI*/
void refreshBoard(struct gm_struct *game){
  int offset_r  = 3, offset_f = 2;
  char piece[2];
  GtkWidget *button;
  gchar *label;
  for (int y = 0; i < 9; i++){
    for (int x = 0; j < 9; j++){
      piece[0] = game->board[y][x];
      button = gtk_grid_get_child_at (GtkGrid *grid, (gint) (x+offset_r), (gint) (j+offset_f));
      gtk_button_set_label(button, piece);
    }
  }
}

void handleMove(struct gm_struct *game, int drank, int dfile){
  int dst[2];
  dst[0] = drank;
  dst[1] = dfile;
  if(legalmove(game, game->player, src_coords, dst, 0)){
    mkmove(game, game->player, src_coords, dst);
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
  static int src_coords[2] = [-1, -1];
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
      handleMove(game, 0, 0);
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

  struct gm_stuct game;

  init_game(*game);

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "GNU Shogi");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window));
  
  int rank, file, row, column;
  const int row_offset, col_offset;
  for (rank = 0; rank < 9; rank++){
    row = rank + row_offset;
    for (file = 0; file < 9; file++){
      column = rank + col_offset;
      GEN_BOARD_BUTTON_BINDING(rank, file);
    }
  }

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
