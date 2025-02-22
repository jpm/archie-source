#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "patrie.h"
#include "defs.h"
#include "levels.h"
#include "page.h"


char *prog;


void usage(void)
{
  fprintf(stderr, "Usage: %s <infix-trie> <level-trie>\n", prog);
  exit(1);
}


int main(int ac, char **av)
{
  int nlevs;
  struct patrie_config config;
  struct trie_single_level **levels;
  
  prog = av[0];
  
  if (ac < 3 || ac > 5) usage();

  patrieAlloc(&config);
  
  config.printDebug = 1;
  config.printStats = 1;
  config.assertCheck = 1;
  
  if (strcmp(av[1], "-pagesize") == 0) {
    config.levelPageSize = atoi(av[2]);
    av += 2;
  }
  
  if ( ! (config.infixTrieFP = fopen(av[1], "rb")) ||
       ! (config.levelTrieFP = fopen(av[2], "w+b"))) {
    fprintf(stderr, "%s: can't open one or both of `%s', `%s'.\n", prog, av[1], av[2]);
    perror("fopen");
    exit(1);
  }
  
#error fix up
#if 0
  patrieLevelBuild(&config, &nlevs, &levels);
#endif

  exit(0);
}
