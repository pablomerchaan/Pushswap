#include "pushswap.h"

int	fastmeasure(int *list, int length)
{
	int	c;
	int	sum;

	c = 0;
	sum = 0;
	while (c < length)
	{
		sum += sq(list[c] - c);
		c++;
	}
	return (sum);
}

int	measureSASB(struct change actual, int *list, int length)
{
	int	c;
	int	measure;

	c = 0;
	measure = 0;
	if (actual.type == 2)
	{
		while (c < length)
		{
			if (actual.idx == c + 2)
			{
				measure += sq(list[c] - c - 1);
				measure += sq(list[c + 1] - c);
				c++;
			}
			else
			{
				measure += sq(list[c] - c);
				c++;
			}
		}
	}
	else
	{
		c = 0;
		while(c < length)
		{
			if (actual.idx == c)
			{
				measure += sq(list[c] - c - 1);
				measure += sq(list[c + 1] - c);
				c = c + 2;
			}
			else
			{
				measure += sq(list[c] - c);
				c++;
			}
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
		if (actual.idx == c + 2)
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
	return (measure);
}

int	measureR(struct change actual, int *list, int length)
{
	int	c;
	int	measure;

	measure = 0;
	if (actual.type == 5)
	{
		c = 0;
		measure += sq(list[actual.idx - 1]);
		while (actual.idx != c + 1)
		{
			measure += sq(list[c] - c - 1);
			c++;
		}
		c++;
		while (c < length)
		{
			measure += sq(list[c]  - c);
			c++;
		}
	}
	else if (actual.type == 6)
	{
		c = 0;
		while (actual.idx != c)
		{
			measure += sq(list[c] - c);
			c++;
		}
		measure += sq(list[c] - length + 1);
		c++;
		while (c < length)
		{
			measure += sq(list[c]  - c + 1);
			c++;
		}
	}
	else //RR
	{
		c = 0;
		measure += sq(list[actual.idx - 1]);
		while (actual.idx != c + 1)
		{
			measure += sq(list[c] - c - 1);
			c++;
		}
		c++;
		measure += sq(list[c] - length + 1);
		c++;
		while (c < length)
		{
			measure += sq(list[c]  - c + 1);
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
	if (actual.type == 8)
	{
		c = 0;
		while (actual.idx != c + 1)
		{
			measure += sq(list[c + 1] - c);
			c++;
		}
		measure += sq(list[0] - c);
		c++;
		while (c < length)
		{
			measure += sq(list[c]  - c);
			c++;
		}
	}
	else if (actual.type == 9)
	{
		c = 0;
		while (actual.idx != c)
		{
			measure += sq(list[c] - c);
			c++;
		}
		measure += sq(list[length - 1] - c);
		while (c + 1 < length)
		{
			measure += sq(list[c]  - c - 1);
			c++;
		}
	}
	else //RRR
	{
		c = 0;
		while (actual.idx != c + 1)
		{
			measure += sq(list[c + 1] - c);
			c++;
		}
		measure += sq(list[0] - c);
		c++;
		measure += sq(list[length - 1] - c);
		while (c + 1 < length)
		{
			measure += sq(list[c]  - c - 1);
			c++;
		}
	}
	return (measure);
}

int	measure(struct change actual, int *list, int length)
{
	int	m = 0;
	if (actual.type == 0)
		m = INT_MAX;
	if (actual.type == 2 || actual.type == 3){
		m = measureSASB(actual, list, length);
		//printf("%s%i", "medida SA:  ", m);
		}
	else if (actual.type == 4){
		m = measureSS(actual, list, length);
		//printf("%s%i", "medida SS:  ", m);
		}
	else if (actual.type == 5 || actual.type == 6 || actual.type == 7){
		m = measureR(actual, list, length);
		//printf("%s%i", "medida R:  ", m);
		}
	else if (actual.type == 8 || actual.type == 9 || actual.type == 10){
		m = measureRR(actual, list, length);
		//printf("%s%i", "medida RR:  ", m);
		}
	return(m);
}
/*
int	main()
{
	struct change test;
	int m;
	int fm;
	int list[5];
	int *p;

	test.idx = 2;
	test.type = 7;
	m = 4;
	p = list;
	while(m >= 0)
	{
		list[m] = m + 3;
		m--;
	}
	m = measure(test, p, 5);
	p = transform(p, test, 5);
	fm = fastmeasure(p, 5);
	printf("%s%i\n", "measure:  ", m);
	printf("%s%i\n", "fastmeasure:  ", fm);
	return (0);
}
*/
