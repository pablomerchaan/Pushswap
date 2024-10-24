#include "pushswap.h"

int	*transform(int *list, struct change actual, int length)
{
	if (actual.type == SA)
		list = transformSA(list, actual.idx);
	else if (actual.type == SB)
		list = transformSB(list, actual.idx);
	else if (actual.type == SS)
		list = transformSS(list, actual.idx);
	else if (actual.type == RA)
		list = transformRA(list, actual.idx);
	else if (actual.type == RB)
		list = transformRB(list, actual.idx, length);
	else if (actual.type == RR)
		list = transformRR(list, actual.idx, length);
	else if (actual.type == RRA)
		list = transformRRA(list, actual.idx);
	else if (actual.type == RRB)
		list = transformRRB(list, actual.idx, length);
	else if (actual.type == RRR)
		list = transformRRR(list, actual.idx, length);
	return (list);
}

int	*transformSA(int *list, int idx)
{
	int	tmp;

	tmp = list[idx - 1];
	list[idx - 1] = list[idx - 2];
	list[idx - 2] = tmp;
	return (list);
}

int	*transformSB(int *list, int idx)
{
	int	tmp;

	tmp = list[idx];
	list[idx] = list[idx + 1];
	list[idx + 1] = tmp;
	return (list);
}

int	*transformSS(int *list, int idx)
{
	int	tmp;

	tmp = list[idx - 1];
	list[idx - 1] = list[idx - 2];
	list[idx - 2] = tmp;
	tmp = list[idx];
	list[idx] = list[idx + 1];
	list[idx + 1] = tmp;
	return (list);
	
}

int	*transformRA(int *list, int idx)
{
	int	tmp;
	int	c;

	tmp = list[idx - 1];
	c = idx - 1;
	while (c > 0)
	{
		list[c] = list[c - 1];
		c--;
	}
	list[0] = tmp;
	return (list);
}

int	*transformRB(int *list, int idx, int length)
{
	int	tmp;
	int	c;

	tmp = list[idx];
	c = idx;
	while (c + 1 < length)
	{
		list[c] = list[c + 1];
		c++;
	}
	list[c] = tmp;
	return (list);
}

int	*transformRR(int *list, int idx, int length)
{
	int	tmp;
	int	c;

	tmp = list[idx - 1];
	c = idx - 1;
	while (c != 0)
	{
		list[c] = list[c - 1];
		c--;
	}
	list[0] = tmp;
	tmp = list[idx];
	c = idx;
	while (c + 1 != length)
	{
		list[c] = list[c + 1];
		c++;
	}
	list[c] = tmp;
	return (list);
}

int	*transformRRA(int *list, int idx)
{
	int	tmp;
	int	c;

	c = 0;
	tmp = list[0];
	while (c < idx - 1)
	{
		list[c] = list[c + 1];
		c++;
	}
	list[c] = tmp;
	return (list);
}
int	*transformRRB(int *list, int idx, int length)
{
	int	tmp;
	int	c;

	tmp = list[length - 1];
	c = length - 1;
	while (c > idx)
	{
		list[c] = list[c - 1];
		c--;
	}
	list[idx] = tmp;
	return (list);
}

int	*transformRRR(int *list, int idx, int length)
{
	int	*r;
	r = transformRRA(list, idx);
	r = transformRRB(list, idx, length);
	return (r);
}
