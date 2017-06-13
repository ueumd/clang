#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

#include "CSocketProtocol.h"
#include "CSckFactoryTmp1.h"

//面向抽象类编程
int SckSendAndRec(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();

	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketSend(in, inlen);
	if (ret != 0)
	{
		goto End;
	}

	ret = sp->cltSocketRev(out, outlen);
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = sp->cltSocketDestory();
	return 0;
}

int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in, "addafsdfasdfasdfsda");
	inlen = 9;

	CSocketProtocol *sp = NULL;

	sp = new CSckFactoryTmp1;

	ret = SckSendAndRec(sp, in, inlen, out, &outlen);

	if (ret != 0)
	{
		printf("func SckSendAndRec()err:%d\n", ret);
		return ret;
	}

	delete sp;


	cout << "hello..." << endl;

	system("pause");
	return ret;
}