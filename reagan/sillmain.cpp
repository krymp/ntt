#include <cmath>		/* log2() */
#include <cstdint> 		/* int64_t, uint64_t */
#include <cstdlib>		/* srand(), rand() */
#include <ctime>		/* time() */
#include <iostream> 		/* std::cout, std::endl */
#include <cstdint> 		/* int64_t, uint64_t */
#include "sillmain.h"
/**
 * Perform the operation 'base^exp (mod m)' using the memory-efficient method
 *
 * @param base	The base of the expression
 * @param exp	The exponent of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
uint64_t modExp(uint64_t base, uint64_t exp, uint64_t m){

	uint64_t result = 1;
	
	while(exp > 0){

		if(exp % 2){

			result = modulo(result*base, m);

		}

		exp = exp >> 1;
		base = modulo(base*base,m);
	}

	return result;
}

/**
 * Perform the operation 'base (mod m)'
 *
 * @param base	The base of the expression
 * @param m	The modulus of the expression
 * @return 	The result of the expression
 */
uint64_t modulo(int64_t base, int64_t m){
	int64_t result = base % m;

	return (result >= 0) ? result : result + m;
}

#define  n  1024U
#define  p  68719403009U
#define  r  36048964756U

uint64_t *inPlaceNTT_DIT(uint64_t *vec){



	uint64_t *result;
	uint64_t m, k_, a, factor1, factor2;

	//result = (uint64_t *) malloc(n*sizeof(uint64_t));

	for(uint64_t i = 1; i <= log2(n); i++){ 

		m = pow(2,i);

		k_ = (p - 1)/m;
		a = modExp(r,k_,p);

		for(uint64_t j = 0; j < n; j+=m){

			for(uint64_t k = 0; k < m/2; k++){

				factor1 = vec[j + k];
				factor2 = modulo(modExp(a,k,p)*vec[j + k + m/2],p);
			
				vec[j + k] 		= modulo(factor1 + factor2, p);
				vec[j + k+m/2] 	= modulo(factor1 - factor2, p);

			}
		}

	}

	return vec;
}
