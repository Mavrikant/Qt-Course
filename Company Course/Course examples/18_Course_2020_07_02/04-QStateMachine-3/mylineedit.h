#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QStateMachine>
#include <QFinalState>
#include <QDebug>

class MyLineEdit : public QLineEdit
{
  Q_OBJECT
public:
  explicit MyLineEdit(QWidget *parent = nullptr);
private:
  QStateMachine machine;
  QState *s0;
  QState *s1;
  QState *s2;
  QFinalState *s3;

signals:

public slots:
  void found(){
    qDebug() << "ASK found";
  }
  void afound(){
    qDebug() << "Key A found";
  }
  void sfound(){
    qDebug() << "Key S found";
  }
  void kfound(){
    qDebug() << "Key K found";
  }
};

#endif // MYLINEEDIT_H
