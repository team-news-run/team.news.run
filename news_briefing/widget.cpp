#include "widget.h"
#include <QPushButton>
#include <QApplication>
#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QBitmap>
#include <QLabel>
#include <QTextEdit>
#include <QStackedLayout>
#include <QButtonGroup>
#include <QMessageBox>
#include <QString>
#include <string>
#include <vector>
#include <QTextCodec>
#include <QFont>
#include <QPainter>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <iostream>
#include "news_contents.h"

#define PATH_BG "./images/background.png"
#define PATH_CENTER "./images/center.png"
#define PATH_RUN "./images/run.png"
#define PATH_ECONOMY "./images/economy.png"
#define PATH_POLITICS "./images/politics.png"
#define PATH_IT "./images/it.png"
#define PATH_SOCIETY "./images/society.png"
#define PATH_GLOBAL "./images/global.png"
#define PATH_HOME "./images/home.png"
#define PATH_UNDO "./images/undo.png"
#define PATH_REDO "./images/redo.png"
#define PATH_UPFONT "./images/upFont.png"
#define PATH_DOWNFONT "./images/downFont.png"
#define PATH_IMG_ECO "/home/ubuntu1604/run/images/_economy.png"
#define PATH_IMG_POL "/home/ubuntu1604/run/images/_politics.png"
#define PATH_IMG_IT "/home/ubuntu1604/run/images/_it.png"
#define PATH_IMG_SOC "/home/ubuntu1604/run/images/_society.png"
#define PATH_IMG_GLO "/home/ubuntu1604/run/images/_global.png"
#define PATH_STR_ECO "/home/ubuntu1604/run/images/__economy.png"
#define PATH_STR_POL "/home/ubuntu1604/run/images/__politics.png"
#define PATH_STR_IT "/home/ubuntu1604/run/images/__it.png"
#define PATH_STR_SOC "/home/ubuntu1604/run/images/__society.png"
#define PATH_STR_GLO "/home/ubuntu1604/run/images/__global.png"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(640, 640);
    QPixmap bg(PATH_BG);
    QPalette p(palette());
    p.setBrush(QPalette::Background, bg);

    setAutoFillBackground(true);
    setPalette(p);

    // layer 1
    QFrame *frame1 = new QFrame(this);
    QPushButton *centerBt = new QPushButton(frame1);
    QPixmap centerPixmap(PATH_CENTER);
    QIcon centerIcon(centerPixmap);
    centerBt->setIcon(centerIcon);
    centerBt->setMask(centerPixmap.mask());
    centerBt->setIconSize(centerPixmap.rect().size());
    centerBt->setGeometry(200, 180, 300, 300);

    QLabel *runLabel = new QLabel(frame1);
    runLabel->setGeometry(210, 220, 32, 226);
    QPixmap runPixmap = QPixmap(PATH_RUN);
    runLabel->setPixmap(runPixmap);

    QPushButton *economyBt = new QPushButton(frame1);
    QPixmap economyPixmap(PATH_ECONOMY);
    QIcon economyIcon(economyPixmap);
    economyBt->setIcon(economyIcon);
    economyBt->setMask( economyPixmap.mask());
    economyBt->setIconSize(economyPixmap.rect().size());
    economyBt->setGeometry(260, 45, 100, 130);

    QPushButton *politicsBt = new QPushButton(frame1);
    QPixmap politicsPixmap(PATH_POLITICS);
    QIcon politicsIcon(politicsPixmap);
    politicsBt->setIcon(politicsIcon);
    politicsBt->setMask( politicsPixmap.mask());
    politicsBt->setIconSize(politicsPixmap.rect().size());
    politicsBt->setGeometry(53, 205, 100, 130);

    QPushButton *itBt = new QPushButton(frame1);
    QPixmap sciencePixmap(PATH_IT);
    QIcon scienceIcon(sciencePixmap);
    itBt->setIcon(scienceIcon);
    itBt->setMask( sciencePixmap.mask());
    itBt->setIconSize(sciencePixmap.rect().size());
    itBt->setGeometry(470, 205, 100, 130);

    QPushButton *societyBt = new QPushButton(frame1);
    QPixmap societyPixmap(PATH_SOCIETY);
    QIcon societyIcon(societyPixmap);
    societyBt->setIcon(societyIcon); 
    societyBt->setMask( societyPixmap.mask());
    societyBt->setIconSize(societyPixmap.rect().size());
    societyBt->setGeometry(135, 460, 100, 130);

    QPushButton *globalBt = new QPushButton(frame1);
    QPixmap sportsPixmap(PATH_GLOBAL);
    QIcon sportsIcon(sportsPixmap);
    globalBt->setIcon(sportsIcon);
    globalBt->setMask( sportsPixmap.mask());
    globalBt->setIconSize(sportsPixmap.rect().size());
    globalBt->setGeometry(390, 460, 100, 130);

    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(economyBt, 0);
    buttonGroup->addButton(politicsBt, 1);
    buttonGroup->addButton(itBt, 2);
    buttonGroup->addButton(societyBt, 3);
    buttonGroup->addButton(globalBt, 4);



    // layer 2
    QFrame *frame2 = new QFrame(this);
    m_textEdit = new QTextEdit(frame2);
    m_textEdit->setGeometry(10, 100, 620, 520);
    m_fontScale = 10;
    QFont font = m_textEdit->currentFont();
    font.setPointSizeF(m_fontScale);
    m_textEdit->setCurrentFont(font);

    //m_textEdit->sett

    QButtonGroup *buttonGroup2 = new QButtonGroup(frame2);
    QPushButton *homeBt = new QPushButton(frame2);
    QPixmap homePixmap(PATH_HOME);
    QIcon homeIcon(homePixmap);
    homeBt->setIcon(homeIcon);
    homeBt->setMask( homePixmap.mask());
    homeBt->setIconSize(homePixmap.rect().size());
    homeBt->setGeometry(10, 10, 32, 32);

    QPushButton *prevBt = new QPushButton(frame2);
    QPixmap prevPixmap(PATH_UNDO);
    QIcon prevIcon(prevPixmap);
    prevBt->setIcon(prevIcon);
    prevBt->setMask( prevPixmap.mask());
    prevBt->setIconSize(prevPixmap.rect().size());
    prevBt->setGeometry(50, 10, 32, 32);

    QPushButton *nextBt = new QPushButton(frame2);
    QPixmap nextPixmap(PATH_REDO);
    QIcon nextIcon(nextPixmap);
    nextBt->setIcon(nextIcon);
    nextBt->setMask( nextPixmap.mask());
    nextBt->setIconSize(nextPixmap.rect().size());
    nextBt->setGeometry(90, 10, 32, 32);

    QPushButton *fontUpBt = new QPushButton(frame2);
    QPixmap fontUpPixmap(PATH_UPFONT);
    QIcon fontUpIcon(fontUpPixmap);
    fontUpBt->setIcon(fontUpIcon);
    fontUpBt->setMask( fontUpPixmap.mask());
    fontUpBt->setIconSize(fontUpPixmap.rect().size());
    fontUpBt->setGeometry(600, 10, 32, 32);

    QPushButton *fontDownBt = new QPushButton(frame2);
    QPixmap fontDownPixmap(PATH_DOWNFONT);
    QIcon fontDownIcon(fontDownPixmap);
    fontDownBt->setIcon(fontDownIcon);
    fontDownBt->setMask( fontDownPixmap.mask());
    fontDownBt->setIconSize(fontDownPixmap.rect().size());
    fontDownBt->setGeometry(600, 50, 32, 32);


    m_topicLabel = new QLabel(frame2);
    m_topicLabel->setGeometry(290, 60, 85, 22);
    //m_topicLabel->move(50,50);

    m_topicBt = new QPushButton(frame2);
    m_topicBt->setGeometry(250, 55, 32, 32);

    buttonGroup2->addButton(homeBt, 0);
    buttonGroup2->addButton(nextBt, 1);
    buttonGroup2->addButton(prevBt, 2);
    buttonGroup2->addButton(fontUpBt, 3);
    buttonGroup2->addButton(fontDownBt, 4);


    m_stackedLayout = new QStackedLayout();
    m_stackedLayout->addWidget(frame1);
    m_stackedLayout->addWidget(frame2);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(frame1);
    //setLayout(formLayout);

    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(readNews(int)));
    connect(buttonGroup2, SIGNAL(buttonClicked(int)), m_stackedLayout, SLOT(setCurrentIndex(int)));
    connect(buttonGroup2, SIGNAL(buttonClicked(int)), this, SLOT(anotherContent(int)));
    connect(buttonGroup2, SIGNAL(buttonClicked(int)), this, SLOT(setFontScale(int)));
}




Widget::~Widget()
{
}

void Widget::printfIndex(int id)
{
    QString str = QString("%1").arg(id);
    qDebug(str.toLatin1());
}

void Widget::readNews(int id)
{
    emit m_stackedLayout->setCurrentIndex(1);
    std::string topic[5] = {"economic", "politics", "digital", "society", "digital"};
    m_page = 1;
    m_textEdit->setText(topic[id].c_str());

    QPixmap topicPixmap, topicLabelPixmap;
    switch(id)
    {
        case 0:
            topicPixmap = QPixmap(PATH_IMG_ECO);
            topicLabelPixmap = QPixmap(PATH_STR_ECO);
            break;
        case 1:
            topicPixmap = QPixmap(PATH_IMG_POL);
            topicLabelPixmap = QPixmap(PATH_STR_POL);
            break;
        case 2:
            topicPixmap = QPixmap(PATH_IMG_IT);
            topicLabelPixmap = QPixmap(PATH_STR_IT);
            break;
        case 3:
            topicPixmap = QPixmap(PATH_IMG_SOC);
            topicLabelPixmap = QPixmap(PATH_STR_SOC);
            break;
        case 4:
            topicPixmap = QPixmap(PATH_IMG_GLO);
            topicLabelPixmap = QPixmap(PATH_STR_GLO);
            break;
    }

    QIcon topicIcon(topicPixmap);
    m_topicBt->setIcon(topicIcon);
    m_topicBt->setMask( topicPixmap.mask());
    m_topicBt->setIconSize(topicPixmap.rect().size());

    m_topicLabel->setPixmap(topicLabelPixmap);


    NewsContents nc;
    // topic을 요청하면 요약된 news 기사를 얻는다.
    m_contents = nc.contents(topic[id]);

    if(m_contents.size() == 0)
        return;
    //m_textEdit->setText(topic[id].c_str());
    //std::cout << "News Topic : " << topic << std::endl;
    //std::string tempStr = "djisjdiosjadiojsadoijasdoijsaoijdoiasjdojsaodijiosajdiosajdoisajdoijasoidjoisajdoisajdoijsaoidjaosidjoi게임업계가 모바일게임의 생명연장을 두고 골머리를 앓는다  모바일게임 제작비용은  콘솔 등 기타 플랫폼의 게임과 비슷한 수준이지만 수명이 짧다  최근 모바일게임업계를 강타한  열풍이 대표적이다  게임업계 한 관계자는 모바일게임 개발비용이 수백억원에 달할 정도로 증가했다며 이에 상응하는 수익을 내기 위해서는 게임의 수익구조보다 게임성에 집중해 앱마켓의 매출 상위권 목록에 오래 살아있어야 한다고 말했다";  
    m_textEdit->setText(QString::fromLocal8Bit(m_contents[0].c_str()));
    //m_textEdit->setText(QString::fromLocal8Bit(tempStr.c_str()));
    std::cout << "size : " << m_contents.size() << std::endl;
    std::cout << m_contents[0]  << std::endl;
    //for(const auto& text : m_contents) {
    //    std::cout << "nc_test::" << cnt++ << " text : " << std::endl;
    //    std::cout << text << std::endl;
    //}
}

void Widget::anotherContent(int id)
{
    if(id == 1){
        m_page++;
        
        if(m_page > (int)m_contents.size()){
            QMessageBox::warning(this, "Error", "There is no next page.", QMessageBox::Ok, NULL);
            m_page--;
            return;
        }


        m_textEdit->setText(QString::fromLocal8Bit(m_contents[m_page - 1].c_str()));
    }
    else if(id == 2){
        m_page--;
        if(m_page <= 0){
            QMessageBox::warning(this, "Error", "There is no previous page.", QMessageBox::Ok, NULL);
            m_page++;
            return;
        }


        m_textEdit->setText(QString::fromLocal8Bit(m_contents[m_page - 1].c_str()));
    }
}

void Widget::setFontScale(int id)
{
    if(id == 3){
        QFont font = m_textEdit->currentFont();
        font.setPointSizeF(++m_fontScale);
        m_textEdit->setCurrentFont(font);
        m_textEdit->setText(QString::fromLocal8Bit(m_contents[m_page - 1].c_str()));
    }
    else if(id == 4){
        QFont font = m_textEdit->currentFont();
        font.setPointSizeF(--m_fontScale);
        m_textEdit->setCurrentFont(font);
        m_textEdit->setText(QString::fromLocal8Bit(m_contents[m_page - 1].c_str()));
    }
}
