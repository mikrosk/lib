#include "gem_aesP.h"
#include "mt_gemx.h"

/** Examine settings: Font
 *
 *  @param tree RSC-tree of object
 *  @param obj Object number
 *  @param font_id will be filled with the Font-ID \n
 *         [option CHECK_NULLPTR] font_id may be NULL
 *  @param font_h will be filled with the Height for vst_point() \n
 *         [option CHECK_NULLPTR] font_h may be NULL
 *  @param mono will be filled with the Flag for equidistant font \n
 *         [option CHECK_NULLPTR] mono may be NULL
 *  @param font_pix will be filled with:
 *         - 0=points, 
 *         - 1=pixels (from 3.5.98 on) 
 *         .
 *         [option CHECK_NULLPTR] font_pix may be NULL
 *  @param global_aes global AES array
 *
 *  @return 0 for error, else 1
 *
 *  \p font_pix is only available from version 8 of the SLB. This library ensures that 
 *  old SLB versionen always return a Null.
 *
 *  @since from MagiC 5.20 onwards. As it is 
 *         implemented as part of the shared library (SLB or SharedLib), 
 *         one only needs to open the library with:\n
 *         <pre>Slbopen("EDITOBJC.SLB", NULL, 0L, &slb, &slbexec);</pre>
 *         The library installs a new AES object-type G_EDIT (37)
 *         as well as the AES functions mt_edit_xx().
 *
 */

short
mt_edit_get_font( OBJECT *tree, short obj, short *font_id, short *font_h,
				  short *font_pix, short *mono, short *global_aes )
{
	AES_PARAMS(216,2,5,1,0);
	
	aes_intin[0]  = obj;
	aes_intin[1]  = 3;
	aes_addrin[0] = (long)tree;
	aes_intout[4] = 0;	/* For old libraries */

	AES_TRAP(aes_params);

#if CHECK_NULLPTR
	if (font_id)
#endif
	*font_id  = aes_intout[1];
#if CHECK_NULLPTR
	if (font_h)
#endif
	*font_h   = aes_intout[2];
#if CHECK_NULLPTR
	if (font_pix)
#endif
	*font_pix = aes_intout[4];
#if CHECK_NULLPTR
	if (mono)
#endif
	*mono     = aes_intout[3];
	
	return(aes_intout[0]);
}
