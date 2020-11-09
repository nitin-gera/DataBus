#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtDBus/QtDBus>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton     *m_SendMessageButton;
    QLineEdit       *m_SendTextLedit;
    QLabel          *m_ReceivedTextLabel;

public slots:

    void SendData();
    void ReceiveData(QByteArray);
    void ReceiveDeleteData(QByteArray);
};

#endif // MAINWINDOW_H
