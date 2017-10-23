#include <QCoreApplication>
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void vectorTest()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(-1);
    v1.push_back(2);

    //迭代器 相当于一个指针
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " "; //1 2 3
    }

    //算法 算法和迭代器无缝连接
    int num1 = count(v1.begin(), v1.end(), 2); //等于2 的有几个

    cout << "num1: " << num1 << endl;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vectorTest();
    return a.exec();
}
