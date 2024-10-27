#include "pushswap.h"


int	norm(struct change prev, int partition)
{
	int	c;

	c = 0;
	if (prev.idx == partition)
	{
		return (1);
	}
	else
	{
		if (prev.idx < partition)
			c = partition - prev.idx;
		else
			c = prev.idx - partition;
	}
	return(c + 1);
}

int	sq(int c)
{
	int	r;

	r = c * c;
	return(r);
}



int	*convert(struct change prev, struct change actual)
{
	int	c;
	int	*moves;
//TODO asegurarse de como inicializar moves y porque, para despues alocarlo correctamente.
	if (prev.idx <= actual.idx)
	{
		c = actual.idx - prev.idx;
		moves = malloc(sizeof(int) * (c + 2));
		if (!moves)
			return (NULL);
		moves[c] = actual.type;
		c--;
		while (c <= 0)
		{
			moves[c] = 0;
			c--;
		}
	}
	else
	{
		c = prev.idx - actual.idx;
		moves = malloc(sizeof(int) * (c + 1));
		moves[c] = actual.type;
		c--;
		while (c <= 0)
		{
			moves[c] = 1;
			c--;
		}
	}
	return (moves);
}

int	main(int argc, char **argv)
{
	struct change	bestchange;
	struct change	candidate;
	struct change	tmp;
	int	*list;
	int	partition;
	int	length;
	int	me;
	int	l;

	list = NULL;
	if (argc < 2)
		printf("mensaje de error");
	list = malloc(sizeof(int) * (argc - 1));
	length = 0;
	while (length < argc - 1)
	{
		list[length] = ft_atoi(argv[length + 1]);
		length++;
	}
	bestchange.type = 1;
	bestchange.idx = 0;
	partition = 0;
	while (bestchange.type != 0)
	{
		bestchange.type = 0;
		bestchange.idx = 0;
		candidate.type = 2;
		candidate.idx = 2;
		while (candidate.type != 0)
		{
			me = measure(candidate, list, length); 
			if (me < fastmeasure(list, length))
			{
				if (me/norm(candidate, partition) < measure(bestchange, list, length)/norm(bestchange, partition))
					bestchange = candidate;
			}
			candidate = gen_change(candidate, length);
		//printf("%i", bestchange.type);
		}
		partition = bestchange.idx;
		printf(",");
		if (bestchange.type != 0)
		{
			transform(list, bestchange, length);
			l = 0;
			while (l < length)
			{
				printf("%i ", list[l]);
				l++;
			}
		}
	}
	free (list);
	return(0);
}
