#include "InterfaceManager.h"

InterfaceManager::InterfaceManager(QObject *parent) : QObject(parent)
{
    flag = false;
    QDBusConnection::sessionBus().connect(QString(), QString(), "one.two", "trackmessage", this, SLOT(ReceiveData(QByteArray)));
}

void InterfaceManager :: ReceiveData(QByteArray str)
{
    qDebug() << Q_FUNC_INFO << str << endl;

    QString     send_message(str);
    send_message.append(" received by receiver");

    QDBusMessage msg;
    if(flag)
    {
        msg = QDBusMessage::createSignal("/", "two.one", "trackmessage");
        msg << send_message.toLocal8Bit();

        flag = false;
    }
    else
    {
        msg = QDBusMessage::createSignal("/", "two.one", "trackDeletemessage");
        msg << send_message.toLocal8Bit();

        flag = true;
    }
    QDBusConnection::sessionBus().send(msg);
}

void InterfaceManager::MessageCall(QString str)
{
    qInfo() << Q_FUNC_INFO << str << endl;
}
