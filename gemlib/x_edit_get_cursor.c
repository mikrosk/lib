
#include "gemx.h"


short
edit_get_cursor (OBJECT *tree, short obj, char **cursorpos)
{
	aes_intin[0] = obj;
	aes_intin[1] = 4;
	
	aes_addrin[0] = (long) tree;
	
	aes_control[0] = 216;
	aes_control[1] = 2;
	aes_control[2] = 1;
	aes_control[3] = 1;
	aes_control[4] = 0;
	
	aes (&aes_params);
	
	*cursorpos = (char *) aes_addrout[0];
	return aes_intout[0];
}