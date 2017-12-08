#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void browse_click();
private:

    QPushButton *button;
    QLineEdit *line;
    QTextBrowser *res;

};

#endif // MAINWINDOW_H
