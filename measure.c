#include <pushswap.h>

int	measureSASB(struct change actual, int *list, int length)
{
	int	c;
	int	measure;

	c = 0;
	measure = 0;
	if (actual.type = SA)
	{
		while (c < length)
		{
			if (actual.idx = c + 2)
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
		while(c < length)
		{
			if (actual.idx = c)
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

int	measureSS(struct change actual, int *list, int length)
{
	int	c;
	int	measure;

	c = 0;
	measure = 0;
	while (c < length)
	{
		if (actual.idx = c + 2)
		{
			measure += sq(list[c] - c - 1);
			measure += sq(list[c + 1] - c);
			c = c + 2;
			measure += sq(list[c] - c - 1);
			measure += sq(list[c + 1] - c);
			c++;
		}
		else
			measure += sq(list[c] - c);
		c++;
	}
}

int	measureR(struct change actual, int *list, int length)
{
	int	c;
	int	measure;

	measure = 0;
	if (actual.type = RA)
	{
		c = 0;
		measure += sq(list[actual.idx - 1]);
		while (actual.idx != c + 2)
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
	else if (actual.type = RB)
	{
		c = 0;
		while (actual.idx != c)
		{
			measure += list[c] - c;
			c++;
		}
		measure += sq(list[c] - length + 1);
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
		measure += sq(list[actual.idx - 1]);
		while (actual.idx != c + 2)
		{
			measure += sq(list[c] - c - 1);
			c++;
		}
		c = c + 2;
		measure += sq(list[c] - length + 1);
		c++;
		while (list[c] != '\0')
		{
			measure += list[c]  - c + 1;
			c++;
		}
	}
	return (measure);
}

int	measureRR(struct change actual, int *list, int length)
{
	int	c;
	int	measure;

	measure = 0;
	if (actual.type = RRA)
	{
		c = 1;
		while (actual.idx != c + 1)
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
	else if (actual.type = RRB)
	{
		c = 0;
		while (actual.idx != c)
		{
			measure += list[c] - c;
			c++;
		}
		measure += sq(list[length - 1] - c);
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
		while (actual.idx != c + 1)
		{
			measure += sq(list[c] - c + 1);
			c++;
		}
		measure += sq(list[0] - c);
		c++;
		measure += sq(list[length - 1] - c);
		while (list[c + 1] != '\0')
		{
			measure += list[c]  - c - 1;
			c++;
		}
	}
	return (measure);
}

int	measure(struct change actual, int *list, int norm, int length)
{
	int sum;
	
	if (actual.type == SA || actual.type == SB)
		measure = measureSASB(actual, list, length);
	else if (actual.type == SS)
		measure = measureSS(actual, list, length);
	else if (actual.type = RA || actual.type = RB || actual.type = RR)
		measure = measureR(actual, list, length);
	else if (actual.type = RRA || actual.type = RRB || actual.type = RRR)
		measure = measureRR(actual, list, length);
	return(measure);
}
