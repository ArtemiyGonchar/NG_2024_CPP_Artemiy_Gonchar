#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Howl)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);
    lw = new QListWidget(this);

    m_player->setAudioOutput(m_audioOutput);
    ui->s_volume->setValue(m_audioOutput->volume());
    ui->p_position->setValue(0);
    ui->s_volume->setRange(0, 100);

    connect (ui->b_select, &QPushButton::clicked, this, &Howl::setSong);
    connect (ui->s_volume, &QSlider::valueChanged, this, &Howl::updateVolume);
    connect (ui->b_playPause, &QPushButton::clicked, this, &Howl::playPause);
    connect (m_player, &QMediaPlayer::positionChanged, this, &Howl::updatePosition);
    connect (ui->listWidget, &QListWidget::doubleClicked, this, &Howl::removeSong);
    connect (ui->listWidget, &QListWidget::clicked, this, &Howl::setSongFromPlaylist);
    connect(ui->b_next, &QPushButton::clicked, this, &Howl::next);
    connect(ui->b_previous, &QPushButton::clicked, this, &Howl::previous);
}

Howl::~Howl()
{
    delete ui;
}

void Howl::setSongFromPlaylist()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    QString itemName = item->text();
    ui->l_songName->setText(itemName);
    m_player->setSource(QUrl::fromLocalFile(itemName));
    m_player->play();
}


void Howl::removeSong()
{
    m_player->pause();
    QListWidgetItem *item = ui->listWidget->currentItem();
    //ui->listWidget->addItem("hello");
    delete item;
}

void Howl::playPause()
{
    if (m_player->isPlaying()) {
        m_player->pause();
    } else {
        m_player->play();
    }
}

void Howl::next()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    int currentIndex = ui->listWidget->row(currentItem);
    QListWidgetItem *item = ui->listWidget->item(currentIndex + 1);
    if(item){
        QString itemName = item->text();
        ui->l_songName->setText(itemName);
        m_player->setSource(QUrl::fromLocalFile(itemName));
        m_player->play();
        ui->listWidget->setCurrentItem(item);
    }
}

void Howl::previous()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    int currentIndex = ui->listWidget->row(currentItem);
    QListWidgetItem *item = ui->listWidget->item(currentIndex - 1);
    if(item){
        QString itemName = item->text();
        ui->l_songName->setText(itemName);
        m_player->setSource(QUrl::fromLocalFile(itemName));
        m_player->play();
        ui->listWidget->setCurrentItem(item);
    }
}

void Howl::updatePosition(qint64 pos)
{
    ui->p_position->setValue(pos / (m_player->duration() / 100));
}

void Howl::setSong()
{
    QString path = QFileDialog::getOpenFileName(this, "Chto budem igrat'?", QDir::homePath(), "*.mp3");
    ui->l_songName->setText(path);
    m_player->setSource(QUrl::fromLocalFile(path));

    //QString match_name = lw->findItems(path, Qt::MatchExactly);
    Qt::MatchFlags flags = Qt::MatchExactly | Qt::MatchCaseSensitive;
    QList<QListWidgetItem *> matchName = ui->listWidget->findItems(path, flags);
    //if (&QListWidget::findItems != path){
    if (matchName.isEmpty()){
        ui->listWidget->addItem(path);
    } /*else {
        QListWidgetItem *item = ui->listWidget->currentItem();
        QString itemName = item->text();
        m_player->setSource(QUrl::fromLocalFile(itemName));
    }
    */
    //}
    //ui->listWidget->addItem(path);
}

void Howl::updateVolume(float volume)
{
    m_audioOutput->setVolume(volume/100);
}
