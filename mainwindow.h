#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <QInputDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool connected;
    int foundCount;
    QNetworkConfiguration netcfg;
    QStringList WiFisList;
    QList<QNetworkConfiguration> netcfgList;

public slots:
    void findActiveWirelesses();
    void connectionStatusOpened();
    void connectionStatusClosed();
    void statusBarMessage(QString msg, QString color);
    void configurationStateChanged();

private slots:
    void on_btnConnect_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *findTimer;
    QStandardItemModel* listModel;
    QNetworkSession *session;
};

#endif // MAINWINDOW_H
