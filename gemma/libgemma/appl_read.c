# include "extdef.h"

long
appl_read(short apid, short len, void *apbuf)
{
	GEM_ARRAY *gem;

	gem = gem_control();
	gem->int_in[0] = apid;
	gem->int_in[1] = len;
	gem->addr_in[0] = (long)apbuf;

	return call_aes(gem, 11);
}

/* EOF */