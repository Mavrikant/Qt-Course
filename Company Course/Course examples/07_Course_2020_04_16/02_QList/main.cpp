#include <QTextStream>
#include <QList>
#include <algorithm>

int main(void) {

    QTextStream out(stdout);

    QList<QString> authors = {"Balzac", "Tolstoy",
        "Gulbranssen", "London"};

    for (int i=0; i < authors.size(); ++i) {

        out << authors.at(i) << endl;
    }

    authors << "Ozel" << "Kutlu" << "Galsworthy" << "Sienkiewicz";

    out << "***********************" << endl;

    std::sort(authors.begin(), authors.end());

    out << "Sorted:" << endl;
    for (QString author : authors) {

        out << author << endl;
    }

    int ix = authors.indexOf("Sienkiewicz");

    out << "index of Sienkiewicz at sorted list: " << ix << endl;

    authors.append("Kutlu");
    authors.prepend("Kutlu");
    out << "Some elements repeated:" << endl;

    foreach (auto author, authors) {
        out << author << endl;
    }

    int cnt = authors.count("Kutlu");

    out << QString("Kutlu repeats %1 times.").arg(cnt) << endl;

    auto elem = authors.takeFirst();
    //do something with first elem
    out <<"takefirst:"<<elem<<endl;

    authors.removeLast();//it only removes the last elem.

    out << "First element taken, last element removed:" << endl;
    for (QString author : authors) {

        out << author << endl;
    }
}
