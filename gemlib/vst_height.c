
#include "gem.h"


int
vst_height (int handle, int height, int *charw, int *charh, int *cellw,
	    int *cellh)
{
	vdi_ptsin[0] = 0;
	vdi_ptsin[1] = height;
	vdi_control[0] = 12;
	vdi_control[1] = 1;
	vdi_control[3] = 0;
	vdi_control[6] = handle;
	vdi (&vdi_params);
	*charw = vdi_ptsout[0];
	*charh = vdi_ptsout[1];
	*cellw = vdi_ptsout[2];
	*cellh = vdi_ptsout[3];
	return (int) vdi_intout[0];
}

/*
 * * text attribute
 */