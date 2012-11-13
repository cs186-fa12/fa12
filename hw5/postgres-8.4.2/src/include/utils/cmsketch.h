#ifndef _CMSKETCH_H_
#define _CMSKETCH_H_

#include <stdint.h>

/* Don't change anything that's already in this file, but feel free to add more
	 things to if you think you need them  */

typedef struct cmsketch {
   /* CS186-TODO: add fields here as you need them */
} cmsketch;

/* initialize the count-min sketch for the specified width and depth */
extern cmsketch* init_sketch(uint32_t width, uint32_t depth);

/* increment 'bits' in each sketch by 1.
 * 'bits' is an array of indices into each row of the sketch.
 *    Thus, each index is between 0 and 'width', and there are 'depth' of them.
 */
extern void increment_bits(cmsketch* sketch, uint32_t *bits);

/* decrement 'bits' in each sketch by 1.
 * 'bits' is an array of indices into each row of the sketch.
 *    Thus, each index is between 0 and 'width', and there are 'depth' of them.
 */
extern void decrement_bits(cmsketch* sketch, uint32_t *bits);

/* return the minimum among the indicies pointed to by 'bits'
 * 'bits' is an array of indices into each row of the sketch.
 *    Thus, each index is between 0 and 'width', and there are 'depth' of them.
 */
extern uint32_t estimate(cmsketch* sketch, uint32_t *bits);

/* set all values in the sketch to zero */
extern void reset_sketch(cmsketch* sketch);

/* destroy the sketch, freeing any memory it might be using */
extern void destroy_sketch(cmsketch* sketch);

/* Redefine palloc to malloc if we are testing the CountMin sketch */
/* NB186: These lines are required for the unit test to work correctly! */
#ifdef TESTING
#undef palloc0
#define palloc0(n) calloc(n,1)

#undef palloc
#define palloc malloc

#undef pfree
#define pfree free
#endif

#endif //_CMSKETCH_H_
