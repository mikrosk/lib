#include "gemx.h"
#include "gem_aesP.h"


short
form_wbutton (OBJECT * fo_btree, short fo_bobject, short fo_bclicks,
	      short *fo_bnxtobj, short whandle)
{
	aes_intin[0] = fo_bobject;
	aes_intin[1] = fo_bclicks;
	aes_intin[2] = whandle;
	aes_addrin[0] = (long) fo_btree;
	aes_control[0] = 63;
	aes_control[1] = 3;
	aes_control[2] = 2;
	aes_control[3] = 1;
	aes_control[4] = 0;
	aes (&aes_params);
	*fo_bnxtobj = aes_intout[1];
	return aes_intout[0];
}
