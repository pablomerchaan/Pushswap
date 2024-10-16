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

int	sq(int c)
{
	int	r;

	r = c * c;
	return(r);
}

int	measureSASB(struct change actual, int *list)
{
	int	c;
	int	measure;

	c = 0;
	measure = 0;
	if (actual->type = SA)
	{
		while (list[c] != '\0')
		{
			if (actual->idx = c + 2)
			{
				measure += sq(list[c] - c - 1);
				measure += sq(list[c + 1] - c);
				c++;
			}
			else
				measure += sq(list[c] - c);
			c++;
		}
	}
	else
	{
		c = 0;
		while(list[c] != '\0')
		{
			if (actual->idx = c)
			{
				measure += sq(list[c] - c - 1);
				measure += sq(list[c + 1] - c);
				c++;
			}
			else
				measure += sq(list[c] - c);
			c++;
		}
	}
	return (measure);
}

int	measureR(struct change actual, int *list)
{
	int	c;
	int	measure;
	int	lenght;

	lenght = strlen(list);
	measure = 0;
	if (actual->type = RA)
	{
		c = 0;
		measure += sq(list[actual->idx - 1]);
		while (actual->idx != c + 2)
		{
			measure += sq(list[c] - c - 1);
			c++;
		}
		c = c + 2;
		while (list[c] != '\0')
		{
			measure += sq(list[c]  - c);
			c++;
		}
	}
	else if (actual->type = RB)
	{
		c = 0;
		while (actual->idx != c)
		{
			measure += list[c] - c;
			c++;
		}
		measure += sq(list[c] - lenght + 1);
		c++;
		while (list[c] != '\0')
		{
			measure += list[c]  - c + 1;
			c++;
		}
	}
	else //RR
	{
		c = 0;
		measure += sq(list[actual->idx - 1]);
		while (actual->idx != c + 2)
		{
			measure += sq(list[c] - c - 1);
			c++;
		}
		c = c + 2;
		measure += sq(list[c] - lenght + 1);
		c++;
		while (list[c] != '\0')
		{
			measure += list[c]  - c + 1;
			c++;
		}
	}
	return (measure);
}

int	measureRR(struct change actual, int *list)
{
	int	c;
	int	measure;
	int	lenght;

	lenght = strlen(list);
	measure = 0;
	if (actual->type = RRA)
	{
		c = 1;
		while (actual->idx != c + 1)
		{
			measure += sq(list[c] - c + 1);
			c++;
		}
		measure += sq(list[0] - c);
		c++;
		while (list[c] != '\0')
		{
			measure += sq(list[c]  - c);
			c++;
		}
	}
	else if (actual->type = RRB)
	{
		c = 0;
		while (actual->idx != c)
		{
			measure += list[c] - c;
			c++;
		}
		measure += sq(list[lenght - 1] - c);
		c++;
		while (list[c + 1] != '\0')
		{
			measure += list[c]  - c - 1;
			c++;
		}
	}
	else //RRR
	{
		c = 1;
		while (actual->idx != c + 1)
		{
			measure += sq(list[c] - c + 1);
			c++;
		}
		measure += sq(list[0] - c);
		c++;
		measure += sq(list[lenght - 1] - c);
		while (list[c + 1] != '\0')
		{
			measure += list[c]  - c - 1;
			c++;
		}
	}
	return (measure);
}

int	measure(change *actual, int *list, int norm)
{
	int sum;
	
	if (actual->type == SA || actual->type == SB)
		measure = measureSASB(actual, list);
	else if (actual->type = RA || actual->type = RB || actual->type = RR)
		measure = measureR(actual, list);
	else if (actual->type = RRA || actual->type = RRB || actual->type = RRR)
		measure = measureRR(actual, list);
	return(measure);
}

pushswap(int *list)
{
	struct change	bestchange;
	struct change	candidate;
	int	partition;
	int	lenght;

	lenght = strlen(list);
	partition = lenght;
	bestchange = (SB, 0);
	while (best_change != NULL)
	{
		bestchange = NULL;
		candidate = (SB, 0);
		while (candidate != NULL)
		{
			if (measure(candidate, list, lenght, norm) < measure(bestchange))
				bestchange = candidate;
			candidate = gen_change(candidate, lenght);
		}
		new array of changes = convert(bestchange, partition);
		partition = bestchange->idx;
		add new_array to changelist;
		//añadir el cambio a la lista
		//aplicar el bestchange al list;  
	}
	return();
}
