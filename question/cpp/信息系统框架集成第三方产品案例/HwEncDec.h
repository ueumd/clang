#pragma once
#include "CEncDesProtocol.h"
class HwEncDec : public CEncDesProtocol
{
public:
	HwEncDec()
	{
	}
	~HwEncDec()
	{
	}
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);
};

