/* 
 * A Cache simulator that can replay traces from Valgrind and output
 * statistics such as number of hits, misses, and evictions.
 * The replacement policy is LRU. 
 *
 * Implementation and assumptions:
 *
 *  1. Each load/store can cause at most one cache miss. (I examined
 *  the trace, the largest request I saw was for 8 bytes).
 *
 *  2. Instruction loads (I) are ignored, since we are interested in
 *  evaluating trans.c in terms of its data cache performance.
 *
 *  3. data modify (M) is treated as a load followed by a store to the
 *  same address. Hence, an M operation can result in two cache hits,
 *  or a miss and a hit plus an possible eviction.
 *
 * The function printCachesimResults() is given to print output.
 * Please use this function to print the number of hits, misses and
 * evictions.  This is crucial for the driver to evaluate your work.
 *
 *
 * Yi Zhuang (yzhuang@cs.cmu.edu)
 * Date: 08/28/2010
 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>

#include "cachelab-tools.h"

// S,s, E, B,b are defined as in CSAPP page 597
unsigned int s;
unsigned int S;
unsigned int b;
unsigned int B;
unsigned int E;
char* trace_file;

unsigned int miss_count = 0;
unsigned int hit_count = 0;
unsigned int eviction_count = 0;

/*TODO 1: define a struct that can represent a cache line */

/*TODO 4b: define functions or macros to extract the tag, set, and block bits */
void printUsage(char* argv[]){
    printf("\nUsage example: %s -s 4 -E 1 -b 4 -t simple_test.trace\n", 
           argv[0]);
    printf("Explanation of options:\n");
    printf("-s: number of set index bits.\n");
    printf("-E: number of lines per set.\n");
    printf("-b: number of block bits.\n");
    printf("-t: the file containing the input trace.\n\n");
    printf("Please see text book CASPP page 597 for a more\n") ;
    printf("detailed explanation of s, S, b, B and E.\n");
    exit(1);
}

int
main(int argc, char* argv[])
{
  // Parse commandline options
  char c;
  while( (c=getopt(argc,argv,"s:E:b:t:")) != -1){
    switch(c){
    case 's':
      s = atoi(optarg);
      break;
    case 'E':
      E = atoi(optarg);
      break;
    case 'b':
      b = atoi(optarg);
      break;
    case 't':
      trace_file = optarg;
      break;
    case '?':
      printUsage(argv);
      exit(1);
    default:
      printUsage(argv);
      exit(1);
    }
  }

  S = (unsigned int) pow(2, s);
  B = (unsigned int) pow(2, b);


  /*TODO 2: allocate memory to hold the entire cache */

  /*TODO 3: open the trace file and loop over the contents
	 While looping, extract the following items from each trace string:
	  operation type as a single char
	  address as a long long
	  size as an int

	 The C function 'fscanf' may be helpful for this. Run 'man fscanf' for more
	 details.
	 */

  /*TODO 4a: While looping over the trace file, record statistics for your cache.

	 For L, M, or S operation, check if the data is in your cache. Then,
	 update your hit, miss, and eviction counts as needed.
	 
	 It will be helpful to create functions or macros that can extract the tag,
	 set, and block bits from the address. See TODO 4b

	 Remember to evict the LRU line when bring in a new line. All invalid lines
	 should be evicted before searching for LRU lines.
	 */

  
  // output results so that the driver can grade my work
  printCachesimResults(hit_count, miss_count, eviction_count);
  return 0;
}
