#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();
    QString getPosition() const;
    QString getFavoriteOs() const;

private slots:
    void on_okButton_clicked();

private:
    QString position;
    QString favoriteOs;
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
