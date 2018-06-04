#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

#include "CSocketProtocol.h"
#include "CSckFactoryTmp1.h"
#include "CSckFactoryTmp2.h"
#include "HwEncDec.h"

//抽象类多继承
//class MainOp : public CSocketProtocol, public CEncDesProtocol
//{
//
//};

//组合方式
class MainOp
{
public:
	MainOp()
	{
		this->sp = NULL;
		this->ed = NULL;
	}
	MainOp(CSocketProtocol *sp, CEncDesProtocol *ed)
	{
		this->sp = sp;
		this->ed = ed;
	}

	void setSp(CSocketProtocol *sp)
	{
		this->sp = sp;
	}

	void setEd(CEncDesProtocol *ed)
	{
		this->ed = ed;
	}
	public:
		int SckSendAndRec_EncDec3(CSocketProtocol *sp, CEncDesProtocol *ed, unsigned char *in, int inlen, unsigned char *out, int *outlen)
		{
			int ret = 0;

			unsigned char data[4096];

			int datalen = 0;

			ret = sp->cltSocketInit();

			if (ret != 0)
			{
				goto End;
			}
			ret = ed->EncData(in, inlen, data, &datalen); //加密
			if (ret != 0)
			{
				goto End;
			}
			ret = sp->cltSocketSend(data, datalen);//发送数据之前加密
			if (ret != 0)
			{
				goto End;
			}

			ret = sp->cltSocketRev(data, &datalen);
			if (ret != 0)
			{
				goto End;
			}

			ret = ed->DecData(data, datalen, out, outlen); //解密
			if (ret != 0)
			{
				goto End;
			}
		End:
			ret = sp->cltSocketDestory();
			return 0;
		}
		int SckSendAndRec_EncDec3(unsigned char *in, int inlen, unsigned char *out, int *outlen)
		{
			int ret = 0;
			unsigned char data[4096];
			int datalen = 0;

			ret = this->sp->cltSocketInit();
			if (ret != 0)
			{
				goto End;
			}

			ret = this->ed->EncData(in, inlen, data, &datalen); //加密
			if (ret != 0)
			{
				goto End;
			}

			ret = this->sp->cltSocketSend(data, datalen);//发送数据之前加密
			if (ret != 0)
			{
				goto End;
			}

			ret = this->sp->cltSocketRev(data, &datalen);
			if (ret != 0)
			{
				goto End;
			}

			ret = this->ed->DecData(data, datalen, out, outlen); //解密
			if (ret != 0)
			{
				goto End;
			}
		End:
			ret = this->sp->cltSocketDestory();
			return 0;
		}

private:

	CSocketProtocol *sp;
	CEncDesProtocol *ed;
};

int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in, "aaaadddd");
	inlen = 9;

	MainOp *myMainOp=new MainOp;


	CSocketProtocol *sp = NULL;
	CEncDesProtocol *ed = NULL;//加密解密

							   //sp = new CSckFactoryTmp1;
	sp = new CSckFactoryTmp2;
	ed = new HwEncDec;

	myMainOp->setSp(sp);
	myMainOp->setEd(ed);

	//SckSendAndRec_EncDec3(sp, ed, in, inlen, out, &outlen);

	ret = myMainOp->SckSendAndRec_EncDec3(in, inlen, out, &outlen);

	if (ret != 0)
	{
		printf("func SckSendAndRec_EncDec3()err:%d\n", ret);
		return ret;
	}

	delete sp;
	delete ed;
	delete myMainOp;


	cout << "hello..." << endl;

	system("pause");
	return ret;
}