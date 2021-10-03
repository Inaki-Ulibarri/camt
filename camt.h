/* libraries*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Flags*/
struct flags{
	bool line_numbers;
	} p_flags;

/* Misc*/
static unsigned int ln_count; //line numbers counter
