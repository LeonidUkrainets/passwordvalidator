
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QRegularExpressionValidator>
#include <QRegularExpressionMatch>
class Validator
{
public:
    //Validator()         {};
    virtual ~Validator() {};
    virtual bool isValid(QString somestring)=0;
};
class SomeValidator : public Validator
{
public:
    virtual bool isValid(QString somestring)
    {
        return true;
    }
};
class NewValidator : public Validator
{
    QRegularExpression reg;
public:
    NewValidator(QString str)
    {
        reg = QRegularExpression (str);
    }
    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch = reg.match(somestring);
        bool ismatch = regmatch.hasMatch();
        if  (ismatch==true)
            return true;
        else
            return false;
    }
};
class PasswordValidator : public Validator
{
    QString str = "(.*[A-Z]+.*[a-z]+.*)|(.*[a-z]+.*[A-Z]+.*)";
    QString str1 = "(.*[A-Z]+.*[a-z]+.*)";
    QString str2 = "(.*[a-z]+.*[A-Z]+.*)";
    QRegularExpression reg=QRegularExpression(str);
    QRegularExpression reg1=QRegularExpression(str1);
    QRegularExpression reg2=QRegularExpression(str2);
public:

    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch1 = reg1.match(somestring);
        QRegularExpressionMatch regmatch2 = reg2.match(somestring);
        bool ismatch1 = regmatch1.hasMatch() ;
        bool ismatch2 = regmatch2.hasMatch() ;
        bool ismatch = ismatch1 || ismatch2;
        if  (ismatch==true && somestring.size()>=8 && somestring.size()<=18)
            return true;
        else
            return false;
    }
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
