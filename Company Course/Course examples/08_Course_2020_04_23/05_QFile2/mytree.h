#ifndef MYTREE_H
#define MYTREE_H
#include <QStringList>

class MyTree
{
private:
    QString delimiter;
    int index;
    double girth;
    double height;
    double volume;
    bool treeIsEmpty;
public:
    MyTree(QString propCsv = "", QString del = ",");
    QString toString(int width = 0);
    bool isEmpty()
    {
        return treeIsEmpty;
    }

};

#endif // MYTREE_H
