#ifndef CLIENT_H
#define CLIENT_H

#include <QThread>

class ClientThread : public QThread
{
  Q_OBJECT
public:
  explicit ClientThread(QObject *parent = nullptr, int id=0);
  int id() const;

private:
  void run() override;
  int m_id;
signals:

public slots:

};

#endif // CLIENT_H
