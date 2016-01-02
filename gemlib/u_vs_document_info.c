

#include "gem_vdiP.h"
#include "mt_gemx.h"

typedef struct
{
    short    vdi_control[VDI_CNTRLMAX];
    short    vdi_intin[VDI_INTINMAX];
    short    vdi_intout[VDI_INTOUTMAX];
    short    vdi_ptsin[VDI_PTSINMAX];
    short    vdi_ptsout[VDI_PTSOUTMAX];
} VDIPARBLK;

extern VDIPARBLK _VDIParBlk;


/** 
 *
 *  @param handle Device handle
 *  @param type 
 *  @param s 
 *  @param wchar 
 *
 *  @return 
 *
 *  @since NVDI 5 ?
 *
 *  @note Use it for work with userdef, not reentrant function!
 *
 */

short
udef_vs_document_info (short handle, short type, char *s, short wchar)
{
	short n = 1;

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, 0L, _VDIParBlk.vdi_intout, vdi_dummy);

	_VDIParBlk.vdi_intout[0] = 0;
	_VDIParBlk.vdi_intin[0]  = type;
	if (wchar) {
		/* 16bit strings not yet supported! */
		return 0;
	
	} else {
		n += vdi_str2array_n (s, _VDIParBlk.vdi_intin + 1, VDI_INTINMAX-1);
	}
	VDI_TRAP_ESC (vdi_params, handle, 5,2103, 0,n);
	
	return _VDIParBlk.vdi_intout[0];
}
