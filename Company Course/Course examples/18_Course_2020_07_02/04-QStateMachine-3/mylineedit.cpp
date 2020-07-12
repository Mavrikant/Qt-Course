#include "mylineedit.h"
#include <QtWidgets>

MyLineEdit::MyLineEdit( QWidget *parent) :
  QLineEdit(parent)
{
  QKeyEventTransition *ATransition = new
         QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_A);
  QKeyEventTransition *STransition = new
         QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_S);
  QKeyEventTransition *KTransition = new
         QKeyEventTransition(this, QEvent::KeyPress, Qt::Key_K);

  s0 = new QState();
  s1 = new QState();
  s2 = new QState();
  s3 = new QFinalState();

  machine.addState(s0);
  machine.addState(s1);
  machine.addState(s2);
  machine.addState(s3);

  machine.setInitialState(s0);

  ATransition->setTargetState(s1); 
  s0->addTransition(ATransition);

  STransition->setTargetState(s2);
  s1->addTransition(STransition);

  KTransition->setTargetState(s3);
  s2->addTransition(KTransition);

  connect(&machine,&QStateMachine::finished,
          this, &MyLineEdit::found);
  connect(s1,&QState::entered,this,&MyLineEdit::afound);
  connect(s2,&QState::entered,this,&MyLineEdit::sfound);
  connect(s3,&QState::entered,this,&MyLineEdit::kfound);

  machine.start();
}
