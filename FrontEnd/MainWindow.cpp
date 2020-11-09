#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 600);

    m_SendTextLedit = new QLineEdit(this);
    m_SendTextLedit->setGeometry(0, 0, 300, 30);

    m_SendMessageButton = new QPushButton("Send", this);
    m_SendMessageButton->setGeometry(0, 50, 300, 30);

    m_ReceivedTextLabel = new QLabel("Received messages will be displayed here", this);

    m_ReceivedTextLabel->setGeometry(0, 120, 300, 150);

    QDBusConnection::sessionBus().connect(QString(), QString(), "two.one", "trackmessage", this, SLOT(ReceiveData(QByteArray)));
    QDBusConnection::sessionBus().connect(QString(), QString(), "two.one", "trackDeletemessage", this, SLOT(ReceiveDeleteData(QByteArray)));
    connect(m_SendMessageButton, SIGNAL(clicked()), SLOT(SendData()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::SendData()
{
    QDBusMessage msg = QDBusMessage::createSignal("/", "one.two", "trackmessage");
    msg << m_SendTextLedit->text().toLatin1();
    if(QDBusConnection::sessionBus().send(msg))
    {
        qDebug() << "Message Sent" << endl;
    }
    else
    {
        qDebug() << "Message not sent" << endl;
    }

//    QDBusInterface methodcall("/", "one.two", "trackmessage");
//    methodcall.call("MessageCall", m_SendTextLedit->text());
}

void MainWindow::ReceiveData(QByteArray str)
{
    qDebug() << Q_FUNC_INFO << endl;
    m_ReceivedTextLabel->setText(str);
}

void MainWindow::ReceiveDeleteData(QByteArray str)
{
    qDebug() << Q_FUNC_INFO << endl;
    QString name = str.append("in delete function");
    m_ReceivedTextLabel->setText(name);
}
