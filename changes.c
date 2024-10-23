#include <pushswap.h>

struct change SASB(struct change prev, int length)
{
	struct change new_change;

	if (prev.idx <= length/2)
	{
		new_change.idx = prev.idx + 1;
		new_change.type = prev.type;
	}
	else if (prev.idx < length)
	{
		new_change.idx = prev.idx + 1;
		new_change.type = SA;
	}
	else
	{
		new_change.idx = 2;
		new_change.type = SS;
	}
	return (new_change);
}

struct change	SS(struct change prev, int length)
{
	struct change	new_change;

	if (prev.idx < length - 2)
	{
		new_change.idx = prev.idx + 1;
		new_change.type = prev.type;
	}
	else
	{		
		new_change.idx = 2;
		new_change.type = RA;
	}
	return (new_change);
}

struct change	R(struct change prev, int length)
{
	struct change new_change;

	if(prev.type == RA)
	{
		if(prev.idx < length)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = RB;
			new_change.idx = 0;
		}
	}
	else if(prev.type = RB)
	{
		if(prev.idx < length - 3)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = RR;
			new_change.idx = 2;
		}
	}
	else if (prev.type = RR)
	{
		if(prev.idx < length - 2)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = RRA;
			new_change.idx = 3;
		}
	}
	return (new_change);
}

struct change RR(struct change prev, int length)
{
	change new_change;

	else if(prev.type == RRA)
	{
		if(prev.idx < length)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = RRB;
			new_change.idx = 0;
		}
	}
	else if(prev.type = RRB)
	{
		if(prev.idx < length - 3)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = RRR;
			new_change.idx = 2;
		}
	}
	else if (prev.type = RRR)
	{
		if(prev.idx < length - 2)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
			return(NULL);
	}
	return (new_change);
}

struct change gen_change(struct change prev, int length)
{
	change new_change;
	
	new_change = malloc(sizeof(change));
	if (prev.type == SA || prev.type == SB)
		new_change = SASB(prev, length);
	else if (prev.type = RA || prev.type = RB || prev.type = RR)
		new_change = R(prev, length);
	else if (prev.type = RRA || prev.type = RRB || prev.type = RRR)
		new_change = RR(prev, length);
	return(new_change);
}
