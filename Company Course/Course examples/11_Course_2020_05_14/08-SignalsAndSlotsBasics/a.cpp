#include "a.h"

int A::state() const
{
  return m_state;
}

void A::setState(int state)
{
  if(state != m_state){
    m_state = state;
    emit stateChanged(state);
  }
}

A::A(QObject *parent) : QObject(parent)
{
  m_state = 0;
}
