/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QWidget *MainWidget;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_title_bar;
    QPushButton *ButtonOpenFloder;
    QPushButton *ButtonAbout;
    QPushButton *ButtonClose;
    QPushButton *ButtonMin;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacerLyric1;
    QLabel *Lyric1;
    QLabel *Lyric2;
    QLabel *Lyric3;
    QLabel *Lyric4;
    QLabel *Lyric5;
    QLabel *Lyric6;
    QLabel *Lyric7;
    QSpacerItem *verticalSpacerLyric2;
    QFrame *line_2;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonPrevious;
    QPushButton *ButtonPause;
    QPushButton *ButtonNext;
    QSpacerItem *horizontalSpacer_1;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelMusicName;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *no_use;
    QSpacerItem *verticalSpacer;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelTime;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 960);
        MainWindow->setMinimumSize(QSize(1280, 960));
        MainWindow->setMaximumSize(QSize(1280, 960));
        MainWindow->setBaseSize(QSize(1280, 960));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        MainWidget = new QWidget(centralWidget);
        MainWidget->setObjectName(QStringLiteral("MainWidget"));
        verticalLayout_6 = new QVBoxLayout(MainWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        widget_title_bar = new QWidget(MainWidget);
        widget_title_bar->setObjectName(QStringLiteral("widget_title_bar"));
        widget_title_bar->setMinimumSize(QSize(0, 60));
        widget_title_bar->setMaximumSize(QSize(16777215, 60));
        ButtonOpenFloder = new QPushButton(widget_title_bar);
        ButtonOpenFloder->setObjectName(QStringLiteral("ButtonOpenFloder"));
        ButtonOpenFloder->setGeometry(QRect(0, 0, 120, 60));
        ButtonAbout = new QPushButton(widget_title_bar);
        ButtonAbout->setObjectName(QStringLiteral("ButtonAbout"));
        ButtonAbout->setGeometry(QRect(130, 0, 121, 60));
        ButtonClose = new QPushButton(widget_title_bar);
        ButtonClose->setObjectName(QStringLiteral("ButtonClose"));
        ButtonClose->setGeometry(QRect(1170, 0, 60, 60));
        ButtonClose->setMinimumSize(QSize(60, 60));
        ButtonClose->setMaximumSize(QSize(60, 60));
        ButtonMin = new QPushButton(widget_title_bar);
        ButtonMin->setObjectName(QStringLiteral("ButtonMin"));
        ButtonMin->setGeometry(QRect(1100, 0, 60, 60));
        ButtonMin->setMinimumSize(QSize(60, 60));
        ButtonMin->setMaximumSize(QSize(60, 60));

        verticalLayout_6->addWidget(widget_title_bar);

        line = new QFrame(MainWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget1 = new QWidget(MainWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setMinimumSize(QSize(550, 0));
        verticalLayout_5 = new QVBoxLayout(widget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableWidget = new QTableWidget(widget1);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableWidget);


        horizontalLayout_3->addWidget(widget1);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        widget2 = new QWidget(MainWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setMinimumSize(QSize(610, 0));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacerLyric1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacerLyric1);

        Lyric1 = new QLabel(widget2);
        Lyric1->setObjectName(QStringLiteral("Lyric1"));
        Lyric1->setMinimumSize(QSize(400, 60));
        Lyric1->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric1);

        Lyric2 = new QLabel(widget2);
        Lyric2->setObjectName(QStringLiteral("Lyric2"));
        Lyric2->setMinimumSize(QSize(0, 60));
        Lyric2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric2);

        Lyric3 = new QLabel(widget2);
        Lyric3->setObjectName(QStringLiteral("Lyric3"));
        Lyric3->setMinimumSize(QSize(0, 60));
        Lyric3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric3);

        Lyric4 = new QLabel(widget2);
        Lyric4->setObjectName(QStringLiteral("Lyric4"));
        Lyric4->setMinimumSize(QSize(0, 60));
        Lyric4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric4);

        Lyric5 = new QLabel(widget2);
        Lyric5->setObjectName(QStringLiteral("Lyric5"));
        Lyric5->setMinimumSize(QSize(0, 60));
        Lyric5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric5);

        Lyric6 = new QLabel(widget2);
        Lyric6->setObjectName(QStringLiteral("Lyric6"));
        Lyric6->setMinimumSize(QSize(0, 60));
        Lyric6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric6);

        Lyric7 = new QLabel(widget2);
        Lyric7->setObjectName(QStringLiteral("Lyric7"));
        Lyric7->setMinimumSize(QSize(0, 60));
        Lyric7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Lyric7);

        verticalSpacerLyric2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacerLyric2);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_5->addWidget(widget2);


        verticalLayout_6->addLayout(horizontalLayout_5);

        line_2 = new QFrame(MainWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_2);

        widget3 = new QWidget(MainWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setMinimumSize(QSize(640, 100));
        widget3->setMaximumSize(QSize(16777215, 100));
        verticalLayout_7 = new QVBoxLayout(widget3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ButtonPrevious = new QPushButton(widget3);
        ButtonPrevious->setObjectName(QStringLiteral("ButtonPrevious"));
        ButtonPrevious->setMinimumSize(QSize(60, 60));
        ButtonPrevious->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(ButtonPrevious);

        ButtonPause = new QPushButton(widget3);
        ButtonPause->setObjectName(QStringLiteral("ButtonPause"));
        ButtonPause->setMinimumSize(QSize(60, 60));
        ButtonPause->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(ButtonPause);

        ButtonNext = new QPushButton(widget3);
        ButtonNext->setObjectName(QStringLiteral("ButtonNext"));
        ButtonNext->setMinimumSize(QSize(60, 60));
        ButtonNext->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(ButtonNext);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_1 = new QSpacerItem(57, 57, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelMusicName = new QLabel(widget3);
        labelMusicName->setObjectName(QStringLiteral("labelMusicName"));
        labelMusicName->setMinimumSize(QSize(300, 40));
        labelMusicName->setMaximumSize(QSize(16777215, 40));

        verticalLayout_4->addWidget(labelMusicName);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        no_use = new QLabel(widget3);
        no_use->setObjectName(QStringLiteral("no_use"));
        no_use->setMinimumSize(QSize(0, 10));
        no_use->setMaximumSize(QSize(16777215, 10));

        verticalLayout->addWidget(no_use);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalSlider = new QSlider(widget3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(400, 20));
        horizontalSlider->setMaximumSize(QSize(16777215, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        labelTime = new QLabel(widget3);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setMinimumSize(QSize(0, 40));
        labelTime->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_4->addWidget(labelTime);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout_6->addWidget(widget3);


        verticalLayout_8->addWidget(MainWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 17));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271(&O)", Q_NULLPTR));
        ButtonOpenFloder->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        ButtonAbout->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        ButtonClose->setText(QString());
        ButtonMin->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\255\214\346\233\262", Q_NULLPTR));
        Lyric1->setText(QString());
        Lyric2->setText(QString());
        Lyric3->setText(QString());
        Lyric4->setText(QString());
        Lyric5->setText(QString());
        Lyric6->setText(QString());
        Lyric7->setText(QString());
        ButtonPrevious->setText(QString());
        ButtonPause->setText(QString());
        ButtonNext->setText(QString());
        labelMusicName->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\346\255\214\346\233\262\345\220\215</p></body></html>", Q_NULLPTR));
        no_use->setText(QString());
        labelTime->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
