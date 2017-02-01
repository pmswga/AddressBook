#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::CreateFile(QString file_name)
{
    qDebug() << "Точка входа";
    file_name += ".txt";
    
    QFile new_file(file_name);
    new_file.open(QIODevice::WriteOnly);
    new_file.close();
    close();
}

void Widget::on_view_clicked()
{
    QString name;
    QString second_name;
    QString email;
    QString telephone;
    QString n = "\n";
    QString t = "\t";

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    if(ui->name->isChecked())
    {
        name = ui->nameE->text();
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(name);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
    }

    if(ui->second_name->isChecked())
    {
        second_name = ui->second_nameE->text();
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(second_name);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item);
    }

    if(ui->email->isChecked())
    {
        email = ui->emailE->text();
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(email);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, item);
    }

    if(ui->telephone->isChecked())
    {
        telephone = ui->telephoneE->text();
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(telephone);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, item);
    }
}

void Widget::on_nameE_textEdited(const QString &arg1)
{
    if(arg1 != NULL) ui->name->setChecked(true);
    else ui->name->setChecked(false);
}

void Widget::on_second_nameE_textEdited(const QString &arg2)
{
    if(arg2 != NULL) ui->second_name->setChecked(true);
    else ui->second_name->setChecked(false);
}

void Widget::on_emailE_textEdited(const QString &arg3)
{
    if(arg3 != NULL) ui->email->setChecked(true);
    else ui->email->setChecked(false);
}

void Widget::on_telephoneE_textEdited(const QString &arg4)
{
    if(arg4 != NULL) ui->telephone->setChecked(true);
    else ui->telephone->setChecked(false);
}

void Widget::on_all_gal_clicked()
{
    ui->name->setChecked(true);
    ui->second_name->setChecked(true);
    ui->email->setChecked(true);
    ui->telephone->setChecked(true);
}

void Widget::on_no_gal_clicked()
{
    ui->name->setChecked(false);
    ui->second_name->setChecked(false);
    ui->email->setChecked(false);
    ui->telephone->setChecked(false);
}

void Widget::on_clear_clicked()
{
    ui->nameE->clear();
    ui->second_nameE->clear();
    ui->emailE->clear();
    ui->telephoneE->clear();
    ui->name->setChecked(false);
    ui->second_name->setChecked(false);
    ui->email->setChecked(false);
    ui->telephone->setChecked(false);
}

void Widget::on_save_clicked()
{
    QFile file("Book.txt");
    file.open(QIODevice::Append | QIODevice::Text);
    QTextStream write_file(&file);

    QString name = ui->nameE->text();
    QString second_name = ui->second_nameE->text();
    QString email = ui->emailE->text();
    QString telephone = ui->telephoneE->text();
    QString n = "\n";

    if(ui->name->isChecked())
    {
        name = ui->nameE->text();
        write_file << name + n;
    }

    if(ui->second_name->isChecked())
    {
        second_name = ui->second_nameE->text();
        write_file << second_name + n;
    }

    if(ui->email->isChecked())
    {
        email = ui->emailE->text();
        write_file << email + n;
    }

    if(ui->telephone->isChecked())
    {
        telephone = ui->telephoneE->text();
        write_file << telephone + n;
    }
    file.close();
}

void Widget::on_load_clicked()
{
   QFile file("Book.txt");
   QTextStream line(&file);
   if(!file.open(QIODevice::ReadOnly))
   {
       QMessageBox::warning(0, "Ошибка", "Невозможно загрузить данные из файла, так как его не существует.", QMessageBox::Ok, QMessageBox::Ok);
       bool isCreate = QMessageBox::question(0, "Создать файл", "Вы хотите создать файл?", QMessageBox::Yes | QMessageBox::No);
       if(isCreate)
       {
           QDialog *widget = new QDialog(0);
           QLabel *label = new QLabel("Имя файла(Без расширения)", widget);
           QLineEdit *file_name = new QLineEdit(widget);
           QPushButton *create_file = new QPushButton("Создать файл", widget);
           QGridLayout *grid_layout = new QGridLayout(widget);
           QHBoxLayout *hbox_layout = new QHBoxLayout();
           
           hbox_layout->addWidget(label, 0);
           hbox_layout->addWidget(file_name, 1);
           hbox_layout->addWidget(create_file, 2);
           
           grid_layout->addLayout(hbox_layout, 0, 0, 0, 0, Qt::AlignHCenter);
           
           widget->setLayout(grid_layout);
           widget->exec();
           
           QString file = file_name->text();
           qDebug() << file;
           widget->connect(create_file, SIGNAL(clicked()), this, SLOT(CreateFile(QString)));
       }
   }
   QString a;

   ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

   for(int i = 0; i < ui->tableWidget->columnCount(); i++)
   {
       line >> a;
       QTableWidgetItem* item = new QTableWidgetItem;
       item->setText(a);
       item->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, i, item);
   }

   file.close();
}

