
#include "gem.h"


void
v_rvoff (short handle)
{
	vdi_control[0] = 5;
	vdi_control[1] = 0;
	vdi_control[3] = 0;
	vdi_control[5] = 14;
	vdi_control[6] = handle;
	vdi (&vdi_params);
}

/*
 * * text function
 */
