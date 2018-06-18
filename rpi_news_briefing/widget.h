#ifndef WIDGET_H


#define WIDGET_H




#include <QWidget>


class QStackedLayout;


class QTextEdit;


class QPushButton;


class QLabel;


class QPainter;




class Widget : public QWidget


{


    Q_OBJECT




    public:


        Widget(QWidget *parent = 0);


        ~Widget();




        public slots:


            void printfIndex(int id);


        void readNews(int id);


        void anotherContent(int id);


        void setFontScale(int id);




    private:


        QStackedLayout *m_stackedLayout;


        QTextEdit *m_textEdit;


        std::vector<std::string> m_contents;


        int m_page, m_fontScale;


        QPushButton *m_topicBt;


        QLabel *m_topicLabel;


};




#endif // WIDGET_H
