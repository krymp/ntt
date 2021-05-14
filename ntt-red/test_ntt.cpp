#include "ntt.h"
#include <iostream>
#define n 1024U

int main() {
	int32_t vec[n];

	  for (int i = 0; i < n; i++){
	      vec[i] = i;
      }

	ntt_red_ct_std2rev( vec);

	for (int i = 0; i< n ; i++) {
		std::cout << vec[i] << std::endl;
	}
 /*Downloads/ntt_rage/SRI/NTT/src/test_ntt_nina.cpp:12: undefined reference to `ntt_red_ct_std2rev(int*)*/

}
