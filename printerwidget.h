#ifndef PRINTERWIDGET_H
#define PRINTERWIDGET_H

#include "printers/baseprinter.h"
#include "sioworker.h"
#include "printers/nativeoutput.h"

#include <QFrame>

namespace Ui {
    class PrinterWidget;
}

class PrinterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit PrinterWidget(int printerNum, QWidget *parent = Q_NULLPTR);
    ~PrinterWidget();

    int getPrinterNumber() const { return printerNo_; }
    void setup();

    Printers::BasePrinter *printer() const { return mPrinter; }
    void setPrinter(Printers::BasePrinter *printer) { mPrinter = printer; }

    void setSioWorker(SioWorker *sio);

signals:
    void actionEject(int deviceId);
    void actionConnectPrinter(int deviceId);

private slots:
    bool selectPrinter();
    bool selectOutput();
    void on_actionConnectPrinter_triggered();
    void on_actionDisconnectPrinter_triggered();
    void on_outputSelection_currentIndexChanged(const QString &outputName);
    void on_atariPrinters_currentIndexChanged(const QString &printerName);

private:
    Ui::PrinterWidget *ui;
    int printerNo_;
    Printers::BasePrinter *mPrinter;
    Printers::NativeOutput *mDevice;
    SioWorker *mSio;
    bool mInitialized;
};

#endif // PRINTERWIDGET_H
