/*
 *   NOTE: requires NVDI version 3.x or higher
 */

#include "gem_vdiP.h"
#include "gemx.h"


void
v_ftext16 (short handle, short x, short y, const WCHAR * wstr)
{
	register short n = vdi_wstrlen ((const short *)wstr);
	
	vdi_params.intin = (const short *)wstr;
	
	vdi_ptsin[0] = x;
	vdi_ptsin[1] = y;

	VDI_TRAP (vdi_params, handle, 241, 1,n);

	vdi_params.intin = vdi_intin;
}
