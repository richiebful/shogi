/** \file */

#define CHALLENGING 1
#define REIGNING 2
#define P1 1
#define P2 2

#define DROP_FMT 0
#define PIECE_DST_FMT 1
#define PIECE_DST_UP_FMT 2
#define SRC_DST_FMT 3
#define SRC_DST_UP_FMT 4

//#define ERROR_F

struct time_s{
  //sec format
  int player_t[2];
  time_t last_t;
  int advance_t; //time added per move, if at all
};

struct hist_s{
  char move[6];
  time_t tm_executed;
  struct hist_s *prev_move;
  struct hist_s *next_move;
  int num;
};

struct gm_status{
  char board[9][9];
  struct hist_s *history;
  struct time_s clock;
  int player;
  char graveyard[2][38];
  bool check_f;
  bool mate_f;
};

/*legal.c*/
int legaldest(struct gm_status *game, int player, int rank, int file);
int legalmove(struct gm_status *game, int player, int *src, int *dst, 
	      int from_check_f);
int inrange(int rank, int file);
int legalsrc(struct gm_status *game, int player, int rank, int file);
int legaldrop(struct gm_status *game, int player, char piece, int *dst);
bool legalUpgrade(struct gm_status *game, int player, int *coords);
/*init.c*/
void init_game(struct gm_status *game);
int eprintf(char *format, ...);
/*move.c*/
void mkmove(struct gm_status *game, int player,
	    int *src, int *dst, bool update_f, bool upgrade_f);
void mkdrop(struct gm_status *game, int player, 
	    char piece, int *dst, bool update_f);
void cToCoords(int *converted, char *to_convert);
void coordsToC(char *converted, int *to_convert);
void updateHistory(struct gm_status *game, char *move, time_t tm_executed);
int digGrave(struct gm_status *game, int player, char piece);
bool isUpgradedPiece(char piece);
int moveFormat(char *move);
bool undo(struct gm_status *game);
/*check.c*/
int ischeck(struct gm_status *game, int player);
int ismate(struct gm_status *game, int player);
/*clock.c*/
long updateClock(struct gm_status *game);

/*display.c*/
void dispBoard(char board[9][9]);
void dispClock(struct gm_status *game);
void dispHelp();
bool dispHistory(struct gm_status *game);
void dispGraveyard(char graveyard[2][38]);
/*input.c*/
int processcmd(struct gm_status *game, char *command);
int processmv(struct gm_status *game, char piece, int *src, int *dst);
