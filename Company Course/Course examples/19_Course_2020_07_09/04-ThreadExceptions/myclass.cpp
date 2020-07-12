#include "myclass.h"
#include <QDebug>
MyClass::MyClass(int id):m_id(id)
{
  qDebug() << QString("Object #%1 Constructor called!").arg(m_id);
}

MyClass::~MyClass()
{
  qDebug() << QString("Object #%1 Destructor called!").arg(m_id);
}
