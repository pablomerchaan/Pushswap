#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

enum type_of_change
{
	PA, PB, SA, SB, SS, RA, RB, RR, RRA, RRB, RRR
};

struct change
{
	enum type_of_change type;
	int idx;
};

int	ft_atoi(const char *str);
struct change SASB(struct change prev, int length);
struct change	changeSS(struct change prev, int length);
struct change	changeR(struct change prev, int length);
struct change changeRR(struct change prev, int length);
struct change gen_change(struct change prev, int length);
int	norm(struct change prev, int partition);
int	sq(int c);
int	measureSASB(struct change actual, int *list, int length);
int	measureSS(struct change actual, int *list, int length);
int	measureR(struct change actual, int *list, int length);
int	measureRR(struct change actual, int *list, int length);
int	measure(struct change actual, int *list, int length);
int	*convert(struct change prev, struct change actual);
int	*transform(int *list, struct change actual, int length);
int	*transformSA(int *list, int idx);
int	*transformSB(int *list, int idx);
int	*transformSS(int *list, int idx);
int	*transformRA(int *list, int idx);
int	*transformRB(int *list, int idx, int length);
int	*transformRR(int *list, int idx, int length);
int	*transformRRA(int *list, int idx);
int	*transformRRB(int *list, int idx, int length);
int	*transformRRR(int *list, int idx, int length);
