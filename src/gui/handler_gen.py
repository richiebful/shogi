for i in range(0,9):
    for j in range(0,9):
        print("""void handler{0}{1}()!
    if (loc_f == 0)!
        src_coords[0] = {0};
        src_coords[1] = {1};
        loc_f = true;
    ?
    else!
        if (src_coords[0] == -1)!
            handleDrop(game, {0}, {1});
        ?
        else!
            handleMove(game, {0}, {1});
        ?
        loc_f = false;
    ?
?""".format(i, j).replace("!","{").replace("?","}"))
