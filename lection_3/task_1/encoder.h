#ifndef ENCODER_H
#define ENCODER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Encoder;
}
QT_END_NAMESPACE

class Encoder : public QMainWindow
{
    Q_OBJECT

public:
    Encoder(QWidget *parent = nullptr);
    ~Encoder();

public slots:
    void encoder();

private:
    Ui::Encoder *ui;
};
#endif // ENCODER_H
