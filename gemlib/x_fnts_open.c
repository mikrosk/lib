/*
 *  $Id$
 */

#include "gemx.h"
#include "gem_aesP.h"

/** opens a window dialog with the font selector
 *
 *  @param fnt_dialog Pointer to management structure
 *  @param button_flags Flags for supported buttons:
 *         - FNTS_SNAME 	0x01	 Select checkbox for names 
 *         - FNTS_SSTYLE	0x02	 Select checkbox for style 
 *         - FNTS_SSIZE 	0x04	 Select checkbox for height
 *         - FNTS_SRATIO	0x08	 Select checkbox for width/height ratio 
 *         - FNTS_CHNAME	0x0100   Display checkbox for names 
 *         - FNTS_CHSTYLE	0x0200   Display checkbox for style 
 *         - FNTS_CHSIZE	0x0400   Display checkbox for height
 *         - FNTS_CHRATIO	0x0800   Display checkbox for width/height ratio 
 *         - FNTS_RATIO 	0x1000   Width/height ratio adjustable 
 *         - FNTS_BSET  	0x2000   Button "Set" selectable 
 *         - FNTS_BMARK 	0x4000   Button "Mark" selectable 
 *  @param x x-coordinate of the window or -1 (centred)
 *  @param y y-coordinate of the window or -1 (centred)
 *  @param id Font ID
 *  @param pt Height in 1/65536 point
 *  @param ratio Width/height ratio in 1/65536
 *  @param global_aes global AES array
 *
 *  @return Handle of the window or 0 (error)
 *
 *  @since mt_appl_getinfo(7) give informations on mt_fnts_xx() functions availability
 *
 */

short 
mt_fnts_open(FNT_DIALOG *fnt_dialog, short button_flags, short x, short y,
             long id, long pt, long ratio, short *global_aes)
{
	unsigned short *i;
	
	AES_PARAMS(182,9,1,1,0);
                    
	aes_intin[0] = button_flags;
	aes_intin[1] = x;
	aes_intin[2] = y;
	i = (unsigned short *)&id;
	aes_intin[3] = i[0];
	aes_intin[4] = i[1];
	i = (unsigned short *)&pt;
	aes_intin[5] = i[0];
	aes_intin[6] = i[1];
	i = (unsigned short *)&ratio;
	aes_intin[7] = i[0];
	aes_intin[8] = i[1];
	aes_addrin[0] = (long)fnt_dialog;

	AES_TRAP(aes_params);

	return aes_intout[0];
}
