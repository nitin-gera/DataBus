#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include <QObject>
#include <QtDBus>

class InterfaceManager : public QObject
{
    Q_OBJECT
private:
    bool    flag;
public:
    explicit InterfaceManager(QObject *parent = nullptr);

signals:

public slots:
    void ReceiveData(QByteArray);
    void MessageCall(QString);

private:
};

#endif // INTERFACEMANAGER_H
