#include <pushswap.h>


int	norm(change prev, change candidate)
{
	if (prev.idx == candidate.idx)
	{
		return (1);
	}
	else
		return(|prev.idx - candidate.idx| + 1);
}

int	sq(int c)
{
	int	r;

	r = c * c;
	return(r);
}



enum type_of_change	convert(struct change prev, struct change actual)
{
	int	c;
	int	moves[];
//TODO asegurarse de como inicializar moves y porque, para despues alocarlo correctamente.
	if (prev.idx <= actual.idx)
	{
		c = actual.idx - prev.idx;
		moves = malloc(sizeof(int) * (c + 2));
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
		moves = malloc(sizeof(struct type) * (c + 1));
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
//TODO hacer bien toda la funcion pushswap.
int	main(int argc,char argv[])
{
	struct change	bestchange;
	struct change	candidate;
	int	*list;
	int	length;

	list = NULL;
	if (argc < 2)
		ft_printf("mensaje de error");
	list = malloc(sizeof(int) * (argc - 1));
	if (list == NULL)
		return(NULL);
	length = 0;
	while (length < argc - 1)
	{
		list[length] = ft_atoi(argv[length + 1]);
		length++;
	}
	bestchange = {SB, 0};
	while (best_change != NULL)
	{
		bestchange = NULL;
		candidate = {SB, 0};
		while (candidate != NULL)
		{
			if (measure(candidate, list, length, norm) < measure(bestchange))
				bestchange = candidate;
			candidate = gen_change(candidate, length);
		}
		new array of changes = convert(prev, bestchange);
		partition = bestchange.idx;
		add new_array to changelist;
		//añadir el cambio a la lista
		//aplicar el bestchange al list;  
	}
	return();
}
