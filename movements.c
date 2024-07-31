static void	sa(int *a, int *b)
{
	int	tmp;

	tmp = a[0];
	if (a[1] != '\0')
	{
		a[0] = a[1];
		a[1] = tmp;

	}
}

static void	sb(int *a, int *b)
{
	 int     tmp;

        tmp = b[0];
        if (b[1] != '\0')
        {
		b[0] = b[1];
        	b[1] = tmp;
	}
}

void	ss(int *a, int *b)
{
	sb(a, b);
	sa(a, b);
}

void	pa(int *a, int *b)
{
	int	l;

	l = 0;
	while (a[l] != '\0')
		l++;
	while (l > 0)
	{
		a[l] = a[l - 1];
		l--;
	}
	a[0] = b[0];
	while (b[l] != '\0')
	{
		b[l] = b[l + 1];
		l++;
	}
}

void	pb(int *a, int *b)
{
      int     l;

        l = 0;
	while (b[l] != '\0')
		l++;
        while (l > 0)
        {
                b[l] = b[l - 1];
                l--;
        }
        b[0] = a[0];
        while (a[l] != '\0')
        {
                a[l] = a[l + 1];
                l++;
        }
}

void ra(int *a, int *b)
{
	int	tmp;
	int	s;

	s = 0;
	while (a[s] != '\0')
		s++;
	tmp = a[s - 1];
	while (s > 0)
	{
		a[s] = a[s - 1];
		s--;
	}
	a[0] = tmp;
}

void	rb(int *a, int *b)
{
        int     tmp;
        int     s;

        s = 0;
        while (b[s] != '\0')
                s++;
        tmp = b[s - 1];
        while (s > 0)
        {
                b[s] = b[s - 1];
                s--;
        }
        b[0] = tmp;
}

void	rr(int *a, int *b)
{
	rb(a, b);
	ra(a, b);
}

void	rra(int *a, int *b)
{
	int     tmp;
        int     s;

        s = 0;
        tmp = a[0];
        while (a[s + 1] != '\0')
	{
		a[s] = a[s + 1];
		s++;
	}
	a[s] = tmp;
}

void    rrb(int *a, int *b)
{
        int     tmp;
        int     s;

        s = 0;
        tmp = b[0];
        while (b[s + 1] != '\0')
        {
                b[s] = b[s + 1];
                s++;
        }
        b[s] = tmp;
}

void	rrr(int *a, int *b)
{
	rra(a, b);
	rrb(a, b);
}

#include <stdio.h>

int main()
{
	int v[10] = {1, 2, 3, 4, 5};
	int *a = &v[0];
	int *b;
	ra(a, b);
	printf("%i   %i", a[0], a[1]);
	return (0);
}
