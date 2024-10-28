#include "pushswap.h"

struct change changeSA(struct change prev, int length)
{
	struct change new_change;

	if (prev.idx < length)
	{
		new_change.idx = prev.idx + 1;
		new_change.type = prev.type;
	}
	else
	{
		new_change.idx = 0;
		new_change.type = 3;
	}
	return (new_change);
}

struct change changeSB(struct change prev, int length)
{
	struct change new_change;

	if (prev.idx < length - 2)
	{
		new_change.idx = prev.idx + 1;
		new_change.type = prev.type;
	}
	else
	{
		new_change.idx = 2;
		new_change.type = 4;
	}
	return (new_change);
}

struct change	changeSS(struct change prev, int length)
{
	struct change	new_change;

	if (prev.idx < length - 2 && prev.idx > 1)
	{
		new_change.idx = prev.idx + 1;
		new_change.type = prev.type;
	}
	else
	{		
		new_change.idx = 3;
		new_change.type = 5;
	}
	return (new_change);
}

struct change	changeR(struct change prev, int length)
{
	struct change new_change;

	if(prev.type == 5)
	{
		if(prev.idx < length)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = 6;
			new_change.idx = 0;
		}
	}
	else if(prev.type == 6)
	{
		if(prev.idx < length - 2)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = 7;
			new_change.idx = 2;
		}
	}
	else if (prev.type == 7)
	{
		if(prev.idx < length - 2)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = 8;
			new_change.idx = 3;
		}
	}
	return (new_change);
}

struct change changeRR(struct change prev, int length)
{
	struct change new_change;

	if(prev.type == 8)
	{
		if(prev.idx < length)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = 9;
			new_change.idx = 0;
		}
	}
	else if(prev.type == 9)
	{
		if(prev.idx < length - 2)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = 10;
			new_change.idx = 2;
		}
	}
	else if (prev.type == 10)
	{
		if(prev.idx < length - 2)
		{
			new_change.type = prev.type;
			new_change.idx = prev.idx + 1;
		}
		else
		{
			new_change.type = 0;
			new_change.idx = 0;
			return(new_change);
		}
	}
	return (new_change);
}

struct change gen_change(struct change prev, int length)
{
	struct change new_change;
	
	if (prev.type == 2)
		new_change = changeSA(prev, length);
	else if(prev.type == 3)
		new_change = changeSB(prev, length);
	else if(prev.type == 4)
		new_change = changeSS(prev, length);
	else if (prev.type == 5 || prev.type == 6 || prev.type == 7)
		new_change = changeR(prev, length);
	else if (prev.type == 8 || prev.type == 9 || prev.type == 10)
		new_change = changeRR(prev, length);
	else
		new_change = prev;
	return(new_change);
}
