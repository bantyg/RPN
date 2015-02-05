#include "stack.h"
struct Result{
	int error;
	int status;
};

typedef struct Result Result;
Result evaluate(char *expression);


