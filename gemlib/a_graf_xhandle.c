/*
 *  $Id$
 */

#include "gem_aesP.h"

/** returns important information regarding the
 *  physical workstation currently in use by the AES.
 *
 *  @param wcell pointer to a short int which will contain (on function exit)
 *               the width of the current system character set. \n
 *               [option CHECK_NULLPTR] \a wcell may be NULL
 *  @param hcell  pointer to a short int which will contain (on function exit)
 *               the height of the current system character set. \n
 *               [option CHECK_NULLPTR] \a hcell may be NULL
 *  @param wbox pointer to a short int which will contain (on function exit)
 *               the width of the minimum bounding box of a BOXCHAR character. \n
 *               [option CHECK_NULLPTR] \a wbox may be NULL
 *  @param hbox pointer to a short int which will contain (on function exit)
 *               the height of the minimum bounding box of a BOXCHAR character. \n
 *               [option CHECK_NULLPTR] \a hbox may be NULL
 *  @param  device pointer to a short integer which will contain (on function exit)
 *               the device ID of the physical workstation used by the AES.
 *               This is the value to put in work_in[0] when invoking v_opnvwk()
 *               (TO BE CONFIRMED!!!). \n
 *             [option CHECK_NULLPTR] \a device may be NULL
 *  @param global_aes global AES array
 *
 *  @return the VDI handle for the current physical workstation used
 *          by the AES which is required to open a virtual screen
 *          workstation.
 *
 *  @since MagiC ???.
 *
 *  @sa v_opnvwk()
 *
 *  @note There is currently no defined method of handling an error
 *        generated by this function.
 *
 */

short
mt_graf_xhandle (short *wcell, short *hcell, short *wbox, short *hbox, short *device, short *global_aes)
{
#if !(CHECK_NULLPTR)
	short *ptr;
#endif

	AES_PARAMS(77,0,6,0,0);
	
	/* initialise aes_intout[5] for AES that doesn't support this extension */
	aes_intout[5] = 0;

	AES_TRAP(aes_params);

#if CHECK_NULLPTR
	if (wcell)	*wcell = aes_intout[1];
	if (hcell)	*hcell = aes_intout[2];
	if (wbox)	*wbox  = aes_intout[3];
	if (hbox)	*hbox  = aes_intout[4];
	if (device) *device  = aes_intout[5];
#else
	ptr = &aes_intout[1];
	*wcell = *(ptr ++);									/* [1] */
	*hcell = *(ptr ++);									/* [2] */
	*wbox  = *(ptr ++);									/* [3] */
	*hbox  = *(ptr ++);									/* [4] */
	*device= *(ptr);									/* [4] */
#endif

	return aes_intout[0];
}
