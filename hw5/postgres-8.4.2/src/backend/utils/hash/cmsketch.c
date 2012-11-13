/*****************************************************************************

	 IMPORTANT: You *must* use palloc0 and pfree, not malloc and free, in your
	 implementation.  This will allow your filter to integrate into PostgreSQL.

******************************************************************************/

#include "postgres.h"
#include "utils/cmsketch.h"

/* initialize the count-min sketch for the specified width and depth */
cmsketch* init_sketch(uint32 width, uint32 depth) {
  return NULL;
}

/* increment 'bits' in each sketch by 1. 
 * 'bits' is an array of indices into each row of the sketch.
 *    Thus, each index is between 0 and 'width', and there are 'depth' of them.
 */
void increment_bits(cmsketch* sketch, uint32 *bits) {

}

/* decrement 'bits' in each sketch by 1.
 * 'bits' is an array of indices into each row of the sketch.
 *    Thus, each index is between 0 and 'width', and there are 'depth' of them.
 */
void decrement_bits(cmsketch* sketch, uint32 *bits) {

}

/* return the minimum among the indicies pointed to by 'bits'
 * 'bits' is an array of indices into each row of the sketch.
 *    Thus, each index is between 0 and 'width', and there are 'depth' of them.
 */
uint32 estimate(cmsketch* sketch, uint32 *bits) {
  return 0;
}

/* set all values in the sketch to zero */
void reset_sketch(cmsketch* sketch) {

}

/* destroy the sketch, freeing any memory it might be using */
void destroy_sketch(cmsketch* sketch) {

}
