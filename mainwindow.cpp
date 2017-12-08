#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QGridLayout *layout =new QGridLayout();
    button=new QPushButton("Browse");
    QLabel *lab=new QLabel("PATH");
    line = new QLineEdit();
    res= new QTextBrowser();
    res->setPlaceholderText("Contenu fichier");
    layout->addWidget(lab,0,0);
    layout->addWidget(line,0,1);
    layout->addWidget(button,0,2);
    layout->addWidget(res,1,1);
    QWidget *window=new QWidget();
    window->setLayout(layout);
    this->setCentralWidget(window);
    QObject::connect(button,SIGNAL(clicked(bool)),this,SLOT(browse_click()));
}

void MainWindow::browse_click()
{
    QFileDialog *dialog=new QFileDialog();
    dialog->setFileMode(QFileDialog::ExistingFile);
    dialog->setDirectory("C:\\Users\\Zied\\Desktop");
    dialog->setNameFilter("fichier texte (*.*)");
    dialog->setViewMode(QFileDialog::List);
    if(dialog->exec())
    {
        line->setText(dialog->selectedFiles().first());
         QFile file(line->text());
         if(file.open(QIODevice::ReadOnly)|QIODevice::Text)
         {
             QTextStream flux(&file);
             while(!flux.atEnd())
             {
                 QString ligne= flux.readLine(20);
                 res->append(ligne);
             }

         }
         else
         {
             QMessageBox b;
             b.setText("Erreur ouverture");
             b.exec();
         }
    }
}

MainWindow::~MainWindow()
{
}
