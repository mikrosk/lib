
#include "gemx.h"


int
vq_margins (int handle, int *top_margin, int *bottom_margin, int *left_margin,
	    int *right_margin, int *hdpi, int *vdpi)
{
	vdi_intout[0] = 0;

	vdi_control[0] = 5;
	vdi_control[1] = 0;
	vdi_control[3] = 0;
	vdi_control[5] = 2100;
	vdi_control[6] = handle;
	vdi (&vdi_params);

	*top_margin = vdi_intout[1];
	*bottom_margin = vdi_intout[2];
	*left_margin = vdi_intout[3];
	*right_margin = vdi_intout[4];
	*hdpi = vdi_intout[5];
	*vdpi = vdi_intout[6];

	return vdi_intout[0];
}

/*
 * * NOTE: requires NVDI version 5.x or higher
 */