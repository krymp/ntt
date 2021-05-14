#include "sillmain.h"

#define  n  1024U
#define  p  68719403009U
#define  r  36048964756U
int main(int argc, char *argv[]){


	uint64_t vec[n];

  for (int i = 0; i < n; i++){
    vec[i] = i;
  }

  uint64_t *outVec = inPlaceNTT_DIT(vec);
  printf("my vec thing is = %llu", *outVec);
	return 0;

}

