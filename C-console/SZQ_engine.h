#include <time.h>
#include "SZQ_basic.h"

int computerPlay(char** QP);

int row_score(char** QP, int row);
int column_score(char** QP, int column);
int Pdiag_score(char** QP, int postion);
int Ndiag_score(char** QP, int postion);