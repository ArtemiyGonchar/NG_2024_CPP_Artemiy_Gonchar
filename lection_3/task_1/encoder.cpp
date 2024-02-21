#include "encoder.h"
#include "./ui_encoder.h"

Encoder::Encoder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Encoder)
{
    ui->setupUi(this);
    connect(ui->e_key, &QLineEdit::textChanged, this, &Encoder::encoder);
    connect(ui->t_text,&QTextEdit::textChanged, this, &Encoder::encoder);
    connect(ui->b_encode,&QRadioButton::clicked, this, &Encoder::encoder);
}

Encoder::~Encoder()
{
    delete ui;
}

void Encoder::encoder() {
    QString text = ui->t_text->toPlainText();
    QString key = ui->e_key->text();
    bool endButton = ui->b_encode->isChecked();

    QString word = text;
    QString encodedText;

    if (text.isEmpty() || key.isEmpty())
        return;

    if (endButton) {
        for (int i = 0; i < text.length(); i++) {
            if (text[i].isLetter()) {
                int keyIndex = i % key.length();
                int sdvig = key[keyIndex].unicode() - 'a';
                QChar encodedChar = QChar('a' + ((text[i].unicode() - 'a' + sdvig) % 26));

                encodedText += encodedChar;
            } else {
                encodedText += text[i];
            }
        }
        ui->l_result->setText(encodedText);
    } else {
        for (int i = 0; i < text.length(); i++) {
            if (text[i].isLetter()) {
                int keyIndex = i % key.length();
                int sdvig = key[keyIndex].unicode() - 'a';
                QChar encodedChar = QChar('a' + ((text[i].unicode() - 'a' - sdvig + 26) % 26));
                //QChar encodedChar = QChar(text[i].unicode() - 'a' - sdvig);
                //if (encodedChar < 0)
                encodedText += encodedChar;
            } else {
                encodedText += text[i];
            }
        }
        ui->l_result->setText(encodedText);
    }
}


