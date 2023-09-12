#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QStringList>
#include <QDir>
#include <QFileDialog>
#include <QCoreApplication>
#include <Qfile>
#include <QVector>
#include <algorithm>
#include <QCollator>
#include <QMouseEvent>
#include "define.h"
#include <QPainter>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
//图像投影效果
#include <QGraphicsDropShadowEffect>


namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private:
	Ui::MainWindow *ui;

    bool isPlay = false;//播放状态
    QString MusicPath;//音乐文件夹
    QStringList fileList;//文件名称列表
    QMediaPlaylist *PlayerList; //播放列表指针
    QMediaPlayer *Player;//播放器指针
    int musicNum;//音乐数量
    QString durationTime;//音乐时长
    QString positionTime; //音乐播放位置
    QStringList listLyricsText;//歌词文本
    QVector<int> listLyricsTime;//歌词时间
    QPoint last;//窗口拖动用变量
    bool isPressedWidget = false;//窗口拖动用变量
    bool first = true;//单次执行变量
    //相对路径
    QString path = "./assets/";
//    QString path = "../src/assets/";

private slots:

    //初始化函数
	void init();
    //添加tableWidget函数
    void addItem(QString name);
    //获取路径下所有需要的文件类型文件
    QStringList getFileNames(const QString &path);

	void SlotShowCurrentMedia();

    //按钮槽函数
	void SlotButtonStart();
	void SlotButtonPrevious();
	void SlotButtonNext();
    void on_ButtonOpenFloder_clicked();
    void on_ButtonClose_clicked();
    void on_ButtonMin_clicked();
    void on_ButtonAbout_clicked();

    //表格双击播放槽函数
    void slotTable(int,int);
    //音乐时长改变槽函数
    void onDurationChanged(qint64 duration);
    //播放位置改变槽函数
    void onPositionChanged(qint64 position);
    //拖动进度条槽函数
    void on_horizontalSlider_valueChanged(int value);

    //获得文件夹路径
    QString getFloderPath();
    //设置文件夹路径
    void setFloderPath(QString dir);
    //获得歌词
    void getLyrics();
    //音乐改变函数
    void SlotMusicChanged();
    //重写关于窗口拖动用的三个函数
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


};

#endif // MAINWINDOW_H
