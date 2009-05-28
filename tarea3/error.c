#include <stdio.h>
#include "error.h"

void error(char *msg){
	printf("%s\n",msg);
	exit(0);
}	