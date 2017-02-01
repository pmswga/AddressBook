#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QHBoxLayout>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void CreateFile(QString file_name);
    
    void on_view_clicked();
    void on_nameE_textEdited(const QString &arg1);
    void on_second_nameE_textEdited(const QString &arg2);
    void on_emailE_textEdited(const QString &arg3);
    void on_telephoneE_textEdited(const QString &arg4);
    void on_all_gal_clicked();
    void on_no_gal_clicked();
    void on_clear_clicked();
    void on_save_clicked();
    void on_load_clicked();

private:
    
    Ui::Widget *ui;
};

#endif
