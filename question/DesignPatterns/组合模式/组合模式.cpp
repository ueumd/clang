#include <iostream>
#include "list"
#include "string"
using namespace std;

/*
ͨ���ݹ��ֶ����������εĶ���ṹ��������ͨ��һ������������������������

��������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ����ʹ�ÿͻ��Ե�������͸��϶����ʹ�þ���һ���ԡ�

�����ڣ�
�����������϶����ʹ�þ���һ���ԡ���������ϳ����νṹ�Ա�ʾ������--���塱

Ŀ¼���
*/

/*
�������󹹼�
IFile ��Ҫ������ʼ������ӹ����Ľӿڣ�
*/
class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *>* getChild() = 0;
protected:
private:
};

/*
����Ҷ�ӹ���
*/
class File : public IFile
{
public:
	File(string name)
	{
		m_list = NULL;
		m_name = "";
		m_name = name;
	}
	~File()
	{
		if (m_list != NULL)
		{
			delete m_list;
		}
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		return -1;
	}
	virtual int remove(IFile *ifile)
	{
		return -1;
	}
	virtual list<IFile *>* getChild()
	{
		return NULL;
	}

private:
	list<IFile *> *	m_list;
	string		m_name;

};

/*
������������
�������������п��԰����ӽڵ㣬��˶������������д���ʱ����ʹ�õݹ鷽ʽ��
*/
class Folder : public IFile
{
public:
	Folder(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
	}
	~Folder()
	{
		if (m_list == NULL)
		{
			delete m_list;
		}
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile *>* getChild()
	{
		return m_list;
	}

private:
	list<IFile *> *	m_list;
	string			m_name;

};

void showTree(IFile *ifile, int level)
{
	list<IFile *> *l = NULL;
	int i = 0;
	for (i = 0; i<level; i++)
	{
		printf("\t");
	}
	ifile->display();

	l = ifile->getChild();
	if (l != NULL)
	{
		for (list<IFile *>::iterator it = l->begin(); it != l->end(); it++)
		{
			if ((*it)->getChild() == NULL)
			{
				for (i = 0; i <= level; i++) //ע��<= 
				{
					printf("\t");
				}
				(*it)->display();
			}
			else
			{
				showTree((*it), level + 1);
			}

		}
	}
}

void main()
{
	Folder *root = new Folder("C:");

	Folder *dir1 = new Folder("111dir");
	File *txt1 = new File("aaa.txt");

	Folder *dir12 = new Folder("222dir");
	//dir12->display();
	File *txt12 = new File("222.txt");
	//txt12->display();


	root->display();
	root->add(dir1);
	root->add(txt1);

	dir1->add(dir12);
	dir1->add(txt12);

	/*
	list<IFile *> *l = dir1->getChild();
	for (list<IFile *>::iterator it=l->begin(); it!=l->end(); it++)
	{
	(*it)->display();
	}
	*/
	//����һ���ݹ麯�����ڸ�����µ������ӽ��
	cout << "���Եݹ麯��" << endl;

	showTree(root, 0);

	delete txt12;
	delete dir12;
	delete dir1;
	delete txt1;
	delete root;
	cout << "hello..." << endl;
	system("pause");
	return;
}