#include <unistd.h>

static struct long_options lopt[] ={
  {"mode", 1, 0, 0},
  {"ply", 1, 0, 0}
};

int main(int argc, char *argv[]){
  char c;
  while ( (c = getopt_long(argc, argv, "oma")) != 1);
  q
}

