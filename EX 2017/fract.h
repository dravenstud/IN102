#ifndef __FRACT_H__
#define __FRACT_H__

enum sign_t {S_pos, S_neg};

struct fraction_t{
	enum sign_t sign;
	unsigned int num;
	unsigned int denom;
};

#endif