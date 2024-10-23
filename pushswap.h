#include <stdio.h>
#include <fcntl.h>

enum type_of_change
{
	PA;
	PB;
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

struct change SASB(struct change prev, int length);
struct change	SS(struct change prev, int length);
struct change	R(struct change prev, int length);
struct change RR(struct change prev, int length);
struct change gen_change(struct change prev, int length);
int	norm(change prev, change candidate);
int	sq(int c);
int	measureSASB(struct change actual, int *list);
int	measureR(struct change actual, int *list, int length);
int	measureRR(struct change actual, int *list, int length);
int	measure(struct change actual, int *list, int norm, int length);
enum type_of_change	convert(struct change prev, struct change actual);
int	*transform(int *list, struct change actual);
int	*transformSA(int *list, int idx);
int	*transformSB(int *list, int idx);
int	*transformSS(int *list, int idx);
int	*transformRA(int *list, int idx);
int	*transformRB(int *list, int idx);
int	*transformRR(int *list, int idx);
int	*transformRRA(int *list, int idx);
int	*transformRRB(int *list, int idx);
int	*transformRRR(int *list, int idx);
