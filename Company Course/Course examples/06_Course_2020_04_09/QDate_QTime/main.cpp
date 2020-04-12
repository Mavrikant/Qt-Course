#include <QTextStream>
#include <QDate>

int main(void)
{
   QTextStream out(stdout);
   QDate dt1(1993,2,19);

   out<<QDate::currentDate().toJulianDay()-dt1.toJulianDay()<<" days passed since "<<dt1.toString()<<endl;

}
