#include <QCoreApplication>
   #include <QTextStream>

   int main(void)
   {
       QTextStream out(stdout);
       QString str = "";

       /* code... */
       str="ogreniyoruz.";
       /* OUTPUT: "str: ogreniyoruz." */
       out << "str: " << str << endl;

       /* code... */
       str=str.toUpper();
       /* OUTPUT: "str: OGRENIYORUZ." */
       out << "str: " << str << endl;

       /* code... */
       str=str.append(" Egitimleri");
       /* OUTPUT: "str: OGRENIYORUZ. Egitimleri" */
       out << "str: " << str << endl;

       /* code... */
       str=str.append(" her cuma saat 14:30'da yapiyoruz!");
       /* OUTPUT: "str: OGRENIYORUZ. Egitimleri her cuma saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       str=str.toLower();
       /* OUTPUT: "str: ogreniyoruz. egitimleri her cuma saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       str=str.insert(0,"Qt ");
       /* OUTPUT: "str: Qt ogreniyoruz. egitimleri her cuma saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       str.replace("cuma","PERSEMBE");
       /* OUTPUT: "str: Qt ogreniyoruz. egitimleri her PERSEMBE saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       str=str.mid(16);
       /* OUTPUT: "str: egitimleri her PERSEMBE saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       str=str.left(1).toUpper()+str.mid(1);
       /* OUTPUT: "str: Egitimleri her PERSEMBE saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       out<<str.isEmpty()<<endl;;
       /* OUTPUT: "str is not empty!" */

       /* code... */
       str.clear();
       /* OUTPUT: "str: " */
       out << "str: " << str << endl;

       /* code... */
       out<<str.isEmpty()<<endl;
       /* OUTPUT: "str is empty!" */

       /* code... */
       str="Qt ogreniyoruz.";
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << "str: " << str << endl;

       /* Range based for loop code... */
       for ( int i=0; i < str.length(); i++) {
           out << str.at(i) << "*";
       }
       /* OUTPUT: "Q*t* *o*g*r*e*n*i*y*o*r*u*z*.*" */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << endl;
       out << "str: " << str << endl;

       /* foreach loop code... */
       foreach(QChar q, str)
       {
           out << q << "-";
       }
       /* OUTPUT: "Q-t- -o-g-r-e-n-i-y-o-r-u-z-.-" */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << endl;
       out << "str: " << str << endl;

       /* for loop code with iterator... */
       for (auto it = str.cbegin() ; it != str.cend(); ++it) {
           out << *it << ".";
       }
       /* OUTPUT: "Q.t. .o.g.r.e.n.i.y.o.r.u.z..." */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << endl;
       out << "str: " << str << endl;

       /* traditional for loop code with usage of string size... */
       for ( int i=0;i<str.size();i++) {
           out << str[i] << "`";
       }
       /* OUTPUT: "Q`t` `o`g`r`e`n`i`y`o`r`u`z`.`" */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << endl;
       out << "str: " << str << endl;

       /* code... */
       out<<str.right(4)<<endl;
       /* OUTPUT: "ruz." */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << "str: " << str << endl;

       /* code... */
       out<<str.left(5)<<endl;
       /* OUTPUT: "Qt og" */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << "str: " << str << endl;

       /* code... */
       out<<str.mid(5,5)<<endl;
       /* OUTPUT: "reniy" */
       /* OUTPUT: "str: Qt ogreniyoruz." */
       out << "str: " << str << endl;

       /* code... */
       out<<str.left(9)<<endl;
       /* OUTPUT: "str: str: Qt ogreni" */
       out << "str: " << str << endl;

       /* code... */
       str="Egitimleri her cuma saat %1:%2'da %3!";
       /* OUTPUT: "str: Egitimleri her cuma saat %1:%2'da %3!" */
       out << "str: " << str << endl;

       int hh = 14, mm = 30;
       /* code... */
       str=str.arg(hh).arg(mm).arg("yapiyoruz");
       /* OUTPUT: "str: Egitimleri her cuma saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       out<<"str contains "<<str.length()<<" characters!"<<endl;
       /* OUTPUT: "str contains 44 characters!"; */
       /* OUTPUT: "str: Egitimleri her cuma saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;

       /* code... */
       out<<"str contains "<<str.size()<<" characters!"<<endl;
       /* OUTPUT: "str contains 44 characters!"; */
       /* OUTPUT: "str: Egitimleri her cuma saat 14:30'da yapiyoruz!" */
       out << "str: " << str << endl;


       QString str1 = "Egitimleri her cuma saat 14:30'da yapiyoruz!";
       /* code... */
       if(str==str1){
           out<<"str, str1 are equal"<<endl;
       };
       /* OUTPUT: "str, str1 are equal"; */

       /* code... */
       if(str.compare(str1)==0){
           out<<"str, str1 are equal"<<endl;
       };
       /* OUTPUT: "str, str1 are equal"; */

       return 0;
   }
