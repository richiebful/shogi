/** \file */
#include <shogi.h>
/*
 * Checks whether a move works *Coords are in absolute terms
 */
int
legalmove(struct gm_status *game, int player,
	  int *src, int *dst, int from_check_f)
{
    /*
     * Convert coordinates to array dimensions
     */
    int             srank = src[0];
    int             sfile = src[1];
    int             drank = dst[0];
    int             dfile = dst[1];
    /*
     * Get relative coordinates, which are useful for directional pieces
     */
    int             rel_dir = (player == REIGNING) ? 1 : -1;
    char            board[9][9];
    memcpy(board, game->board, sizeof(board));
    /*
     * Only checks whether that move puts the current mover into check if
     * this isn't being called from a second iteration of ischeck 
     */
    struct gm_status test_game;
    if (from_check_f == false) {
	memcpy(&test_game, game, sizeof(test_game));
	mkmove(&test_game, player, src, dst);
    }
    char            piece = board[srank][sfile];
    char            sPiece = board[drank][dfile];
    if (legaldest(game, player, dst[0], dst[1]) == false) {
	return false;
    }
    if (legalsrc(game, player, src[0], src[1]) == false) {
	return false;
    } else if (drank == srank && dfile == sfile) {
	return false;
    } else if (from_check_f == false && ischeck(&test_game, player)) {
	/*
	 * checks if the player puts himself into check by making his
	 * move, if so, it is illegal.
	 */
	return false;
    } else if (piece == 'P' || piece == 'p') {
	// pawns can only move forward one relative rank
	if (srank + rel_dir == drank && sfile == dfile) {
	    return true;
	} else {
	    return false;
	}
    } else if (piece == 'R' || piece == 'r' || piece == 'S' || piece == 's') {	// checks 
										// legality 
										// of 
										// rook 
										// move
	int             i,
	                rook_lf = true;
	if (!((drank != srank && dfile == sfile) ||
	      (drank == srank && dfile != sfile))) {
	    rook_lf = false;
	} else if (drank > srank) {	// it is implied that dfile ==
					// sfile
	    for (i = srank + 1; i != drank; ++i) {
		if (board[i][sfile] != ' ') {
		    rook_lf = false;
		    break;
		}
	    }
	} else if (drank < srank) {
	    for (i = srank - 1; i != drank; --i) {
		if (board[i][sfile] != ' ') {
		    rook_lf = false;
		    break;
		}
	    }
	} else if (dfile > sfile) {
	    for (i = sfile + 1; i != dfile; ++i) {
		if (board[srank][i] != ' ') {
		    rook_lf = false;
		    break;
		}
	    }
	} else {		// dfile < sfile
	    for (i = sfile - 1; i != dfile; --i) {
		if (board[srank][i] != ' ') {
		    rook_lf = false;
		}
	    }
	}
	if (piece == 'R' || piece == 'r' || rook_lf == true) {
	    return rook_lf;
	} else if (rook_lf == false && (piece == 's' || piece == 'S')) {
	    // if it is upgraded rook and rooklf is false
	    int             i;
	    int             possible[4][2] = { {srank + 1, sfile},
	    {srank - 1, sfile},
	    {srank, sfile + 1},
	    {srank, sfile - 1}
	    };
	    for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
		if (possible[i][0] == drank && possible[i][1] == dfile) {
		    return true;
		}
	    }
	    return rook_lf;
	}
    } else if (piece == 'B' || piece == 'b' || piece == 'C' || piece == 'c') {	// checks 
										// bishop's 
										// legality
	double          slope,
	                direction;
	bool            bishop_fatal_f = false;
	slope = (drank - srank) / (dfile - sfile);
	if (slope != 1 && slope != -1) {
	    return false;
	} else if (dfile < sfile) {
	    direction = -1;
	} else {
	    direction = 1;
	}
	int             i,
	                yInt = srank - slope * sfile;
	for (i = sfile + direction; i != dfile; i += direction) {
	    // checks whether the move is blocked by a piece
	    printf("%i, %i", i, (int) slope * i + yInt);
	    if (board[(int) slope * i + yInt][i] != ' ') {
		bishop_fatal_f = true;
		break;
	    }
	}
	if (bishop_fatal_f == true) {
	    return false;
	} else if (piece == 'B' || piece == 'b') {
	    // returns opposite of fatal_f
	    return true;
	} else {
	    int             possible[4][2] = { {srank + 1, sfile},
	    {srank - 1, sfile},
	    {srank, sfile + 1},
	    {srank, sfile - 1}
	    };
	    for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
		if (possible[i][0] == drank && possible[i][1] == dfile) {
		    return true;
		}
	    }
	    return false;
	}
    } else if (piece == 'L' || piece == 'l') {	// checks lance's legality
	int             direction;
	/*
	 * lance must stay in same file
	 */
	if (sfile != dfile) {
	    return false;
	} else if ((drank - srank) * rel_dir < 0) {
	    return false;
	} else if (drank > srank && player == 2) {
	    direction = 1;
	} else if (drank < srank && player == 1) {
	    direction = -1;
	} else {
	    return false;
	}
	int             i;
	for (i = srank + direction; i != drank; i += direction) {
	    if (board[sfile][i] != ' ') {
		return false;
	    }
	}
	return true;
    } else if (piece == 'K' || piece == 'k') {
	int             possible[8][2] = { {srank + 1, sfile + 1},
	{srank + 1, sfile},
	{srank + 1, sfile - 1},
	{srank, sfile + 1},
	{srank, sfile - 1},
	{srank - 1, sfile + 1},
	{srank - 1, sfile},
	{srank - 1, sfile - 1}
	};
	int             i;
	for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
	    if (possible[i][0] == drank && possible[i][1] == dfile) {
		return true;
	    }
	}
	return false;
    } else if (piece == 'G' || piece == 'g') {
	int             possible[5][2] = { {srank + rel_dir, sfile - 1},
	{srank + rel_dir, sfile},
	{srank + rel_dir, sfile + 1},
	{srank - rel_dir, sfile - 1},
	{srank - rel_dir, sfile + 1}
	};
	int             i;
	for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
	    if (possible[i][0] == drank && possible[i][1] == dfile) {
		return true;
	    }
	}
	return false;
    } else if (piece == 'U' || piece == 'u' ||
	       piece == 'H' || piece == 'h' ||
	       piece == 'Q' || piece == 'q' ||
	       piece == 'M' || piece == 'm' ||
	       piece == 'O' || piece == 'o') {
	int             i;
	int             possible[6][2] = { {srank + rel_dir, sfile - 1},
	{srank + rel_dir, sfile},
	{srank + rel_dir, sfile + 1},
	{srank, sfile - 1},
	{srank, sfile + 1},
	{srank - rel_dir, sfile}
	};
	for (i = 0; i < sizeof(possible) / sizeof(possible[0]); i++) {
	    if (possible[i][0] == drank && possible[i][1] == dfile) {
		return true;
	    }
	}
	return false;
    }
    return false;
}
/*
 * Determines whether the rank and file are out of range *of the board or
 * not. 
 */
int
inrange(int rank, int file)
{
    if (rank > 8 || rank < 0 || file > 8 || file < 0) {
	return false;
    }
    return true;
}
/*
 * determines whether a destination is legal regardless of *a specific
 * move's legality 
 */
int
legaldest(struct gm_status *game, int player, int rank, int file)
{
    char            dpiece = game->board[rank][file];
    if (inrange(rank, file) == false) {
	return false;
    } else if (player == P1) {
	if (isupper(dpiece) || dpiece == ' ') {
	    return true;
	} else {		// player can't attack own piece
	    return false;
	}
    } else if (player == P2) {
	if (islower(dpiece) || dpiece == ' ') {
	    return true;
	} else {		// player can't attack own piece
	    return false;
	}
    }
    return -1;
}
/*
 * Tests whether the coordinates point to something can be moved *by a
 * certain player 
 */
int
legalsrc(struct gm_status *game, int player, int rank, int file)
{
    char            spiece = game->board[rank][file];
    if (inrange(rank, file) == false) {
	return false;
    } else if (player == P1) {
	if (isupper(spiece)) {
	    return false;
	} else {
	    return true;
	}
    } else {
	if (islower(spiece)) {
	    return false;
	} else {
	    return true;
	}
    }
}
/*
 * Returns true if drop is legal, false if not *Coordinates must be in
 * absolute terms 
 */
int
legaldrop(struct gm_status *game, int player, char piece, int *dst)
{
    int             drank = dst[0];
    int             dfile = dst[1];
    char            board[9][9];
    memcpy(board, game->board, sizeof(game->board));
    char            dpiece = board[drank][dfile];
    if (dpiece != ' ') {
	return false;
    } else if (legaldest(game, player, drank, dfile) == false) {
	return false;
    } else if (player == P1 && isupper(piece)) {
	return false;
    } else if (islower(piece)) {
	return false;
    } else {
	int             i;
	if (player == 1) {
	    for (i = 0; i < 38; i++) {
		if (game->graveyard.challenging[i] == piece) {
		    return true;
		}
	    }
	    return false;
	} else {		// player == 2
	    for (i = 0; i < 38; i++) {
		if (game->graveyard.reigning[i] == piece) {
		    return true;
		}
	    }
	    return false;
	}
	return true;
    }
}
#ifdef LEGAL_TEST
int
main(void)
{
    struct gm_status game;
    init_game(&game);
    int             legal_f = 0,
	i;
    // of form {{{srank,sfile},{drank,dfile}},...}
    int             trueCases[10][2][2];
    int             falseCases[1][2][2] = { {{7, 1}, {8, 4}} };
    int             srank,
                    sfile,
                    drank,
                    dfile;
    FOREACH(trueCases, i) {
	srank = trueCases[i][0][0];
	sfile = trueCases[i][0][1];
	drank = trueCases[i][1][0];
	dfile = trueCases[i][1][1];
	legal_f = legalmove(&game, 1, trueCases[i][0], trueCases[i][1]);
	printf("%i,%i to %i,%i -> %i", srank, sfile, drank, dfile,
	       legal_f);
    }
    FOREACH(falseCases, i) {
	srank = falseCases[i][0][0];
	sfile = falseCases[i][0][1];
	drank = falseCases[i][1][0];
	dfile = falseCases[i][1][1];
	legal_f = legalmove(&game, 1, falseCases[i][0], falseCases[i][1]);
	printf("%i,%i to %i,%i returns %i\n", srank, sfile, drank, dfile,
	       legal_f);
    }
    return 0;
}
#endif
