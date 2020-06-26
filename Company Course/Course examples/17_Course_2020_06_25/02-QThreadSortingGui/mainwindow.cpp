#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
#include <QRandomGenerator>
#include <sortthread.h>
#include <QApplication>
using namespace std;

/* Function to print an array */
void printArray(QVector<int>::iterator first, size_t size)
{
  size_t i;
  for (i = 0; i < size; i++)
    cout << *(first+i) << " ";
  cout << endl;
}
//Generates 3 equal random arrays
void random_arrays(QVector<int> &a1,QVector<int> &a2,QVector<int> &a3, size_t size,int min,int max)
{
  unsigned int umax = abs(max-min);
  for(size_t i=0; i<size;i++){
    auto val = min + QRandomGenerator::global()->generate()%umax;
    a1  << val;
    a2 << val;
    a3 << val;
  }
}

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->progressBar_1->setValue(0);
  ui->progressBar_2->setValue(0);
  ui->progressBar_3->setValue(0);
  array1.reserve(ArraySize);
  array2.reserve(ArraySize);
  array3.reserve(ArraySize);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_btnStart_clicked()
{
  QList<SortThread*> pthreads;


  random_arrays(array1,array2,array3,ArraySize,0,ArraySize);
  cout<<"unsorted array1: \n";
  printArray(array1.begin(), 20);
  cout<<"unsorted array2: \n";
  printArray(array2.begin(), 20);
  cout<<"unsorted array3: \n";
  printArray(array3.begin(), 20);

  SortThread* pt = new SortThread(SortingType::BubbleSort,array1.begin(), array1.end()-1,this);
  connect(pt, &SortThread::progress, ui->progressBar_1, &QProgressBar::setValue);
  ui->progressBar_1->setRange(0,array3.end()-array3.begin()-1-2);
  connect(pt,&SortThread::sorting_finished, this,&MainWindow::on_sorting_finished);
  pthreads << pt;

  pt = new SortThread(SortingType::SelectionSort,array2.begin(), array2.end()-1,this);
  connect(pt,&SortThread::progress, ui->progressBar_2,&QProgressBar::setValue);
  ui->progressBar_2->setRange(0,array3.end()-array3.begin()-1-2);
  pthreads << pt;

  pt = new SortThread(SortingType::QuickSort,array3.begin(), array3.end()-1,this);
  connect(pt,&SortThread::progress, ui->progressBar_3,&QProgressBar::setValue);
  ui->progressBar_3->setRange(0,array3.end()-array3.begin()-1);
  pthreads << pt;
  //std::sort(array3.begin(),array3.end());
  foreach(auto t,pthreads)
    t->start();

//  cout<<"unsorted array: \n";
//  printArray(array3.begin(), array3.count());
//  qDebug() << "Begin : " << array3.begin() << "End : " << array3.end();
//  SortThread *t = new SortThread(SortingType::QuickSort,array3.begin(), array3.end(),this);
//  t->sort(SortingType::QuickSort,array3.begin(), array3.end());
//  cout<<"sorted array: \n";
//  printArray(array3.begin(), array3.count());

}

void MainWindow::on_btnClose_clicked()
{
  qApp->exit();

}

void MainWindow::on_sorting_finished()
{
  cout<<"sorted array1: \n";
  printArray(array1.begin(), 20);
  cout<<"sorted array2: \n";
  printArray(array2.begin(), 20);
  cout<<"sorted array3: \n";
  printArray(array3.begin(), 20);
}
