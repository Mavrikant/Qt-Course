#include <QCoreApplication>

bool isPrime(quint64){


}


void findPrimes(quint64 iStart, quint64 iEnd){

    for(quint64 i=iStart; i<iEnd;i++){
        isPrime(i);
    }

}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
