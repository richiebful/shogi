/** \file */
#pragma once
#include <stdbool.h>

#define DROP_FMT 0
#define PIECE_DST_FMT 1
#define PIECE_DST_UP_FMT 2
#define SRC_DST_FMT 3
#define SRC_DST_UP_FMT 4
#define GRAVEYARD_MAX 38

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
  char graveyard[2][GRAVEYARD_MAX];
  bool check_f;
  bool mate_f;
};

/*legal.c*/
int legalMove(char board[9][9], int player,
	      int *src, int *dst, int from_check_f);
int gmLegalMove(struct gm_status *game, int *src, int *dst);
int legalDrop(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player, char piece, int *dst);
bool legalUpgrade(char board[9][9], char piece, int player, int *loc);
int isCheck(char board[9][9], int player);
int isMate(char board[9][9], char graveyard[2][GRAVEYARD_MAX], int player);
/*init.c*/
void init_game(struct gm_status *game);
int eprintf(char *format, ...);
/*move.c*/
void makeMove(char board[9][9], char graveyard[2][GRAVEYARD_MAX],
	      int player, int *src, int *dst, bool upgrade_f);
void gmMakeMove(struct gm_status *game, int player,
		int *src, int *dst,
		bool upgrade_f, bool update_f);
void makeDrop(char board[9][9], char graveyard[2][GRAVEYARD_MAX],
	      int player, char piece, int *dst);
void gmMakeDrop(struct gm_status *game, int player, char piece,
		int *dst, bool update_f);
void coordsToC(char *converted, int *to_convert);
void cToCoords(int *converted, char *to_convert);
/*display.c*/
void dispBoard(char board[9][9]);
void dispHelp();
bool dispHistory(struct gm_status *game);
void dispGraveyard(char graveyard[2][GRAVEYARD_MAX]);
/*input.c*/
int processCmd(struct gm_status *game, char *command);
int processMv(struct gm_status *game, char piece, int *src, int *dst);
