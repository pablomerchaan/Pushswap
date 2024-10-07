#include <stdio.h>
#include <fcntl.h>

enum type_of_change
{
	SA;
	SB;
	SS;
	RA;
	RB;
	RR;
	RRA;
	RRB;
	RRR;
}

struct change
{
	type_of_change type;
	int idx;
}

change *SASB(change *prev, int lenght)
{
	change new_change;

	if (prev->idx <= lenght/2)
	{
		new_change->idx = prev->idx + 1;
		new_change->type = prev->type;
	}
	else if (prev->idx < lenght)
	{
		new_change->idx = prev->idx + 1;
		new_change->type = SA;
	}
	else
	{
		new_change->idx = 2;
		new_change->type = RA;
	}
	return (new_change);
}
change *R(change *prev, int lenght)
{
	change new_change;

	if(prev->type == RA)
	{
		if(prev->idx < lenght)
		{
			new_change->type = prev->type;
			new_change->idx = prev->idx + 1;
		}
		else
		{
			new_change->type = RB;
			new_change->idx = 0;
		}
	}
	else if(prev->type = RB)
	{
		if(prev->idx < lenght - 3)
		{
			new_change->type = prev->type;
			new_change->idx = prev->idx + 1;
		}
		else
		{
			new_change->type = RR;
			new_change->idx = 2;
		}
	}
	else if (prev->type = RR)
	{
		if(prev->idx < lenght - 2)
		{
			new_change->type = prev->type;
			new_change->idx = prev->idx + 1;
		}
		else
		{
			new_change->type = RRA;
			new_change->idx = 3;
		}
	}
	return (new_change);
}

change *RR(change *prev, int lenght)
{
	change new_change;

	else if(prev->type == RRA)
	{
		if(prev->idx < lenght)
		{
			new_change->type = prev->type;
			new_change->idx = prev->idx + 1;
		}
		else
		{
			new_change->type = RRB;
			new_change->idx = 0;
		}
	}
	else if(prev->type = RRB)
	{
		if(prev->idx < lenght - 3)
		{
			new_change->type = prev->type;
			new_change->idx = prev->idx + 1;
		}
		else
		{
			new_change->type = RRR;
			new_change->idx = 2;
		}
	}
	else if (prev->type = RRR)
	{
		if(prev->idx < lenght - 2)
		{
			new_change->type = prev->type;
			new_change->idx = prev->idx + 1;
		}
		else
			return(NULL);
	}
	return (new_change);
}


change *gen_change(change *prev, int lenght)
{
	change new_change;
	
	new_change = malloc(sizeof(change));
	if (prev->type == SA || prev->type == SB)
		new_change = SASB(prev, lenght);
	else if (prev->type = RA || prev->type = RB || prev->type = RR)
		new_change = R(prev, lenght);
	else if (prev->type = RRA || prev->type = RRB || prev->type = RRR)
		new_change = RR(prev, lenght);
	return(new_change);
}

int	norm(change *prev, change *candidate)
{
	if (prev->idx == candidate->idx)
	{
		return (1);
	}
	else
		return(|prev->idx - candidate->idx| + 1);
}

int	measure(change *actual, int *a, int lenght, int norm)
{
	int	measure;
	int	c;
	int	sum;

	measure = 0;
	c = 0;
	sum = 0;
	while (a[c] != '\0')
	{
		c++;
		sum += a[c];
	}
	c = 1;
	while (a[c] != '\0')
	{
		measure += (a[c] - a[c - 1]);
		c++;
	}
	measure = measure/norm;
	measure = measure/sum;
	return (measure);
}


pushswap()
{
/Con la norma y la medida, haremos el bucle principal:
mientras no esté ordenada:
	best_change = gen_change(change)
	while(gen_change O la medida de bestchange sea tal)
		if medida(new_change) mejor que medida(best change)
			best_change = new_change;
		else
			new_change = gen_change(new_change);
	change=best_change
	print(best_change)
	
}		
