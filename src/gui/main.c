#include <gtk/gtk.h>

int src_coords[2];
bool loc_f;

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

void handler00(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 0);
        }
        else{
            handleMove(game, 0, 0);
        }
        loc_f = false;
    }
}
void handler01(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 1);
        }
        else{
            handleMove(game, 0, 1);
        }
        loc_f = false;
    }
}
void handler02(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 2);
        }
        else{
            handleMove(game, 0, 2);
        }
        loc_f = false;
    }
}
void handler03(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 3);
        }
        else{
            handleMove(game, 0, 3);
        }
        loc_f = false;
    }
}
void handler04(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 4);
        }
        else{
            handleMove(game, 0, 4);
        }
        loc_f = false;
    }
}
void handler05(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 5);
        }
        else{
            handleMove(game, 0, 5);
        }
        loc_f = false;
    }
}
void handler06(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 6);
        }
        else{
            handleMove(game, 0, 6);
        }
        loc_f = false;
    }
}
void handler07(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 7);
        }
        else{
            handleMove(game, 0, 7);
        }
        loc_f = false;
    }
}
void handler08(){
    if (loc_f == 0){
        src_coords[0] = 0;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 0, 8);
        }
        else{
            handleMove(game, 0, 8);
        }
        loc_f = false;
    }
}
void handler10(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 0);
        }
        else{
            handleMove(game, 1, 0);
        }
        loc_f = false;
    }
}
void handler11(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 1);
        }
        else{
            handleMove(game, 1, 1);
        }
        loc_f = false;
    }
}
void handler12(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 2);
        }
        else{
            handleMove(game, 1, 2);
        }
        loc_f = false;
    }
}
void handler13(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 3);
        }
        else{
            handleMove(game, 1, 3);
        }
        loc_f = false;
    }
}
void handler14(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 4);
        }
        else{
            handleMove(game, 1, 4);
        }
        loc_f = false;
    }
}
void handler15(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 5);
        }
        else{
            handleMove(game, 1, 5);
        }
        loc_f = false;
    }
}
void handler16(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 6);
        }
        else{
            handleMove(game, 1, 6);
        }
        loc_f = false;
    }
}
void handler17(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 7);
        }
        else{
            handleMove(game, 1, 7);
        }
        loc_f = false;
    }
}
void handler18(){
    if (loc_f == 0){
        src_coords[0] = 1;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 1, 8);
        }
        else{
            handleMove(game, 1, 8);
        }
        loc_f = false;
    }
}
void handler20(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 0);
        }
        else{
            handleMove(game, 2, 0);
        }
        loc_f = false;
    }
}
void handler21(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 1);
        }
        else{
            handleMove(game, 2, 1);
        }
        loc_f = false;
    }
}
void handler22(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 2);
        }
        else{
            handleMove(game, 2, 2);
        }
        loc_f = false;
    }
}
void handler23(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 3);
        }
        else{
            handleMove(game, 2, 3);
        }
        loc_f = false;
    }
}
void handler24(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 4);
        }
        else{
            handleMove(game, 2, 4);
        }
        loc_f = false;
    }
}
void handler25(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 5);
        }
        else{
            handleMove(game, 2, 5);
        }
        loc_f = false;
    }
}
void handler26(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 6);
        }
        else{
            handleMove(game, 2, 6);
        }
        loc_f = false;
    }
}
void handler27(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 7);
        }
        else{
            handleMove(game, 2, 7);
        }
        loc_f = false;
    }
}
void handler28(){
    if (loc_f == 0){
        src_coords[0] = 2;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 2, 8);
        }
        else{
            handleMove(game, 2, 8);
        }
        loc_f = false;
    }
}
void handler30(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 0);
        }
        else{
            handleMove(game, 3, 0);
        }
        loc_f = false;
    }
}
void handler31(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 1);
        }
        else{
            handleMove(game, 3, 1);
        }
        loc_f = false;
    }
}
void handler32(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 2);
        }
        else{
            handleMove(game, 3, 2);
        }
        loc_f = false;
    }
}
void handler33(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 3);
        }
        else{
            handleMove(game, 3, 3);
        }
        loc_f = false;
    }
}
void handler34(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 4);
        }
        else{
            handleMove(game, 3, 4);
        }
        loc_f = false;
    }
}
void handler35(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 5);
        }
        else{
            handleMove(game, 3, 5);
        }
        loc_f = false;
    }
}
void handler36(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 6);
        }
        else{
            handleMove(game, 3, 6);
        }
        loc_f = false;
    }
}
void handler37(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 7);
        }
        else{
            handleMove(game, 3, 7);
        }
        loc_f = false;
    }
}
void handler38(){
    if (loc_f == 0){
        src_coords[0] = 3;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 3, 8);
        }
        else{
            handleMove(game, 3, 8);
        }
        loc_f = false;
    }
}
void handler40(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 0);
        }
        else{
            handleMove(game, 4, 0);
        }
        loc_f = false;
    }
}
void handler41(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 1);
        }
        else{
            handleMove(game, 4, 1);
        }
        loc_f = false;
    }
}
void handler42(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 2);
        }
        else{
            handleMove(game, 4, 2);
        }
        loc_f = false;
    }
}
void handler43(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 3);
        }
        else{
            handleMove(game, 4, 3);
        }
        loc_f = false;
    }
}
void handler44(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 4);
        }
        else{
            handleMove(game, 4, 4);
        }
        loc_f = false;
    }
}
void handler45(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 5);
        }
        else{
            handleMove(game, 4, 5);
        }
        loc_f = false;
    }
}
void handler46(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 6);
        }
        else{
            handleMove(game, 4, 6);
        }
        loc_f = false;
    }
}
void handler47(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 7);
        }
        else{
            handleMove(game, 4, 7);
        }
        loc_f = false;
    }
}
void handler48(){
    if (loc_f == 0){
        src_coords[0] = 4;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 4, 8);
        }
        else{
            handleMove(game, 4, 8);
        }
        loc_f = false;
    }
}
void handler50(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 0);
        }
        else{
            handleMove(game, 5, 0);
        }
        loc_f = false;
    }
}
void handler51(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 1);
        }
        else{
            handleMove(game, 5, 1);
        }
        loc_f = false;
    }
}
void handler52(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 2);
        }
        else{
            handleMove(game, 5, 2);
        }
        loc_f = false;
    }
}
void handler53(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 3);
        }
        else{
            handleMove(game, 5, 3);
        }
        loc_f = false;
    }
}
void handler54(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 4);
        }
        else{
            handleMove(game, 5, 4);
        }
        loc_f = false;
    }
}
void handler55(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 5);
        }
        else{
            handleMove(game, 5, 5);
        }
        loc_f = false;
    }
}
void handler56(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 6);
        }
        else{
            handleMove(game, 5, 6);
        }
        loc_f = false;
    }
}
void handler57(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 7);
        }
        else{
            handleMove(game, 5, 7);
        }
        loc_f = false;
    }
}
void handler58(){
    if (loc_f == 0){
        src_coords[0] = 5;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 5, 8);
        }
        else{
            handleMove(game, 5, 8);
        }
        loc_f = false;
    }
}
void handler60(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 0);
        }
        else{
            handleMove(game, 6, 0);
        }
        loc_f = false;
    }
}
void handler61(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 1);
        }
        else{
            handleMove(game, 6, 1);
        }
        loc_f = false;
    }
}
void handler62(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 2);
        }
        else{
            handleMove(game, 6, 2);
        }
        loc_f = false;
    }
}
void handler63(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 3);
        }
        else{
            handleMove(game, 6, 3);
        }
        loc_f = false;
    }
}
void handler64(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 4);
        }
        else{
            handleMove(game, 6, 4);
        }
        loc_f = false;
    }
}
void handler65(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 5);
        }
        else{
            handleMove(game, 6, 5);
        }
        loc_f = false;
    }
}
void handler66(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 6);
        }
        else{
            handleMove(game, 6, 6);
        }
        loc_f = false;
    }
}
void handler67(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 7);
        }
        else{
            handleMove(game, 6, 7);
        }
        loc_f = false;
    }
}
void handler68(){
    if (loc_f == 0){
        src_coords[0] = 6;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 6, 8);
        }
        else{
            handleMove(game, 6, 8);
        }
        loc_f = false;
    }
}
void handler70(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 0);
        }
        else{
            handleMove(game, 7, 0);
        }
        loc_f = false;
    }
}
void handler71(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 1);
        }
        else{
            handleMove(game, 7, 1);
        }
        loc_f = false;
    }
}
void handler72(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 2);
        }
        else{
            handleMove(game, 7, 2);
        }
        loc_f = false;
    }
}
void handler73(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 3);
        }
        else{
            handleMove(game, 7, 3);
        }
        loc_f = false;
    }
}
void handler74(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 4);
        }
        else{
            handleMove(game, 7, 4);
        }
        loc_f = false;
    }
}
void handler75(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 5);
        }
        else{
            handleMove(game, 7, 5);
        }
        loc_f = false;
    }
}
void handler76(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 6);
        }
        else{
            handleMove(game, 7, 6);
        }
        loc_f = false;
    }
}
void handler77(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 7);
        }
        else{
            handleMove(game, 7, 7);
        }
        loc_f = false;
    }
}
void handler78(){
    if (loc_f == 0){
        src_coords[0] = 7;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 7, 8);
        }
        else{
            handleMove(game, 7, 8);
        }
        loc_f = false;
    }
}
void handler80(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 0;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 0);
        }
        else{
            handleMove(game, 8, 0);
        }
        loc_f = false;
    }
}
void handler81(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 1;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 1);
        }
        else{
            handleMove(game, 8, 1);
        }
        loc_f = false;
    }
}
void handler82(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 2;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 2);
        }
        else{
            handleMove(game, 8, 2);
        }
        loc_f = false;
    }
}
void handler83(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 3;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 3);
        }
        else{
            handleMove(game, 8, 3);
        }
        loc_f = false;
    }
}
void handler84(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 4;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 4);
        }
        else{
            handleMove(game, 8, 4);
        }
        loc_f = false;
    }
}
void handler85(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 5;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 5);
        }
        else{
            handleMove(game, 8, 5);
        }
        loc_f = false;
    }
}
void handler86(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 6;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 6);
        }
        else{
            handleMove(game, 8, 6);
        }
        loc_f = false;
    }
}
void handler87(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 7;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 7);
        }
        else{
            handleMove(game, 8, 7);
        }
        loc_f = false;
    }
}
void handler88(){
    if (loc_f == 0){
        src_coords[0] = 8;
        src_coords[1] = 8;
        loc_f = true;
    }
    else{
        if (src_coords[0] == -1){
            handleDrop(game, 8, 8);
        }
        else{
            handleMove(game, 8, 8);
        }
        loc_f = false;
    }
}

static void activate (GtkApplication *app,
		      gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;

  struct gm_stuct game;

  init_game(*game);

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window));

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle00), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle01), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle02), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle03), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle04), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle05), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle06), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle07), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 0, 1, 1);

  button = gtk_button_new_with_label ("0");
  g_signal_connect (button, "clicked", G_CALLBACK (handle08), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 0, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle10), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle11), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle12), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle13), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle14), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle15), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle16), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle17), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 1, 1, 1);

  button = gtk_button_new_with_label ("1");
  g_signal_connect (button, "clicked", G_CALLBACK (handle18), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 1, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle20), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle21), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle22), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle23), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle24), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle25), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle26), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle27), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 2, 1, 1);

  button = gtk_button_new_with_label ("2");
  g_signal_connect (button, "clicked", G_CALLBACK (handle28), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 2, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle30), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle31), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle32), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle33), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle34), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle35), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 3, 1, 1);

  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle36), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 3, 1, 1);
 
  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle37), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 3, 1, 1);
 
  button = gtk_button_new_with_label ("3");
  g_signal_connect (button, "clicked", G_CALLBACK (handle38), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 3, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle40), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle41), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle42), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle43), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle44), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle45), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle46), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle47), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 4, 1, 1);
 
  button = gtk_button_new_with_label ("4");
  g_signal_connect (button, "clicked", G_CALLBACK (handle48), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 4, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle50), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle51), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle52), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle53), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle54), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle55), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle56), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle57), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 5, 1, 1);
 
  button = gtk_button_new_with_label ("5");
  g_signal_connect (button, "clicked", G_CALLBACK (handle58), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 5, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle60), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle61), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle62), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle63), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle64), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle65), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle66), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle67), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 6, 1, 1);
 
  button = gtk_button_new_with_label ("6");
  g_signal_connect (button, "clicked", G_CALLBACK (handle68), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 6, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle70), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle71), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle72), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle73), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle74), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle75), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle76), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle77), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 7, 1, 1);
 
  button = gtk_button_new_with_label ("7");
  g_signal_connect (button, "clicked", G_CALLBACK (handle78), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 7, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle80), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle81), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle82), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle83), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle84), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle85), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 8, 1, 1);

  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle86), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle87), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 7, 8, 1, 1);
 
  button = gtk_button_new_with_label ("8");
  g_signal_connect (button, "clicked", G_CALLBACK (handle88), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 8, 8, 1, 1);


  button = gtk_button_new_with_label ("Button 2");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  /* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  /* Place the Quit button in the grid cell (0, 1), and make it
   * span 2 columns.
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);

  /* Now that we are done packing our widgets, we show them all
   * in one go, by calling gtk_widget_show_all() on the window.
   * This call recursively calls gtk_widget_show() on all widgets
   * that are contained in the window, directly or indirectly.
   */
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
