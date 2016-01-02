

#include "gem_vdiP.h"

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
 *  @param filename 
 *  @param mode 
 *
 *  @return 
 *
 *  @since all VDI versions
 *
 *  @sa
 *
 *
 *  @note Use it for work with userdef, not reentrant function!
 */

short
udef_v_loadcache (short handle, const char *filename, short mode)
{
	short n = 1 + vdi_str2array_n (filename, _VDIParBlk.vdi_intin + 1, VDI_INTINMAX-1);

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, 0L, _VDIParBlk.vdi_intout, _VDIParBlk.vdi_ptsout );

	_VDIParBlk.vdi_intin[0] = mode;

	VDI_TRAP (vdi_params, handle, 250, 0, n);
	
	return _VDIParBlk.vdi_intout[0];
}