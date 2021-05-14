#include <cmath>		/* log2() */
#include <cstdint> 		/* int64_t, uint64_t */
#include <cstdlib>		/* srand(), rand() */
#include <ctime>		/* time() */
#include <iostream> 		/* std::cout, std::endl */
#include <cstdint> 		/* int64_t, uint64_t */
uint64_t * inPlaceNTT_DIT(uint64_t *vec);

uint64_t modExp(uint64_t base, uint64_t exp, uint64_t m);

uint64_t modulo(int64_t base, int64_t m);
