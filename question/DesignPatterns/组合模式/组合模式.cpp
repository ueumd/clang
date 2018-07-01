#include <iostream>
#include "list"
#include "string"
using namespace std;

/*
通过递归手段来构造树形的对象结构，并可以通过一个对象来访问整个对象树。

将对象组合成树形结构以表示“部分-整体”的层次结构。它使得客户对单个对象和复合对象的使用具有一致性。

适用于：
单个对象和组合对象的使用具有一致性。将对象组合成树形结构以表示“部分--整体”

目录层次
*/

/*
创建抽象构件
IFile 需要定义访问及管理子构件的接口：
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
创建叶子构件
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
创建容器构件
由于容器构件中可以包含子节点，因此对容器构件进行处理时可以使用递归方式。
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
				for (i = 0; i <= level; i++) //注意<= 
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
	//开发一个递归函数现在根结点下的所有子结点
	cout << "测试递归函数" << endl;

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