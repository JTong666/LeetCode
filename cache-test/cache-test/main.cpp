#include<stdio.h>
typedef int md_addr_t;

struct PC_blk
{
	md_addr_t pc_addr;
	struct PC_blk *way_next;
	struct PC_blk *way_pre;
};

struct PC_Set
{
	struct PC_blk *way_head;
	struct PC_blk *way_tail;
};



struct PC_t
{
	struct PC_Set sets[1];
};



