#ifndef SORTTHREAD_H
#define SORTTHREAD_H
#include <QThread>
#include <iostream>
#include <QVector>
#include <QDebug>
#include <QTime>
using namespace std;
enum class SortingType{BubbleSort,SelectionSort,QuickSort};
struct MyComparer
{
    template<typename T1>
    bool operator()(const T1 & a, const T1 & b) const
    {
        return a < b;
    }
};
class SortThread : public QThread
{
  Q_OBJECT
public:
  explicit SortThread(SortingType sortType, QVector<int>::iterator first, QVector<int>::iterator last, QObject *parent = nullptr);

  void selectionSort(QVector<int>::iterator first, QVector<int>::iterator last);
  void bubbleSort(QVector<int>::iterator first, QVector<int>::iterator last);
  void sort(SortingType sortType, QVector<int>::iterator first, QVector<int>::iterator last);
  void quickSort(QVector<int>::iterator start, QVector<int>::iterator end);
  static void swap(QVector<int>::iterator first, QVector<int>::iterator second);
private:
  SortingType m_sortType;
  QVector<int>::iterator m_first;
  QVector<int>::iterator m_last;
  int m_progress;//to update progress of algorithm. Doesnt effect calculation
  void run() override;
  //partition is a part of Quicksort algorithm
  QVector<int>::iterator partition(QVector<int>::iterator start, QVector<int>::iterator end);
signals:
  int progress(int value);
  void sorting_finished();
public slots:


};

#endif // SORTTHREAD_H
