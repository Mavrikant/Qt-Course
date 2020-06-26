#include "sortthread.h"

SortThread::SortThread(SortingType sortType, QVector<int>::iterator first, QVector<int>::iterator last, QObject *parent) :
  QThread(parent),m_sortType(sortType),m_first(first),m_last(last)
{

}
void SortThread::run()
{
  sort(m_sortType,m_first,m_last);
  emit sorting_finished();
}

void SortThread::sort(SortingType sortType,QVector<int>::iterator first, QVector<int>::iterator last){
  QTime start = QTime::currentTime();
  m_progress = 0;
  if(SortingType::BubbleSort == sortType)
    bubbleSort(first,last);
  else if(SortingType::SelectionSort == sortType)
    selectionSort(first,last);
  else{
    emit progress(0);
    //quickSort(first,last);
    qSort(first,last);
    emit progress(last-first);
  }

  QTime finish = QTime::currentTime();
  float t = start.msecsTo(finish)/1000.0;
  QStringList strList = {"BubbleSort","Selection Sort", "Quick Sort"};
  qDebug() << strList[(int)sortType] << "Time(ms): " << t;
}




void SortThread::swap(QVector<int>::iterator first, QVector<int>::iterator second)
{
  auto temp = *first;
  *first = *second;
  *second = temp;
}

void SortThread::bubbleSort(QVector<int>::iterator first, QVector<int>::iterator last)
{
  for (auto it = first; it != last-1; it++){
    // Last i elements are already in place
    for (auto jt = first; jt != first+(last-it-1); jt++)
      if (*jt > *(jt+1))
        swap(jt, jt+1);
    emit progress(it-first);
  }

}

void SortThread::selectionSort(QVector<int>::iterator first, QVector<int>::iterator last)
{

  auto it_min = first;
  for(auto it = first; it != last-1; it++) {
    it_min = it;   //get index of minimum data
    for(auto jt =it+1; jt<last; jt++)
      if(*jt < *it_min)
         it_min = jt;
    //placing in correct position
    swap(it, it_min);
    emit progress(it-first);
  }

}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
QVector<int>::iterator SortThread::partition (QVector<int>::iterator start, QVector<int>::iterator end)
{
  auto pivot = end;
  //P-index indicates the pivot value index
  auto index = start;
  //Here we will check if array value is
  //less than pivot
  //then we will place it at left side
  //by swapping

  for(auto i = start; i != end; i++)
  {
    if(*i <= *pivot){
        swap(i,index);
        index++;
    }
  }
  //Now exchanging value of
  //pivot and P-index
  swap(index,end);

  //at last returning the pivot value index
  return index;
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void SortThread::quickSort(QVector<int>::iterator start, QVector<int>::iterator end)
{
  if(start<end)
  {
    auto index = partition(start,end);
    quickSort(start,index-1);
    quickSort(index+1,end);
  }
  m_progress++;
  emit progress(m_progress);
}






