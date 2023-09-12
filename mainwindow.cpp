#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化
    init();
}

//析构函数
MainWindow::~MainWindow()
{
	delete ui;
}

//初始化函数
void MainWindow::init()
{
    /*播放列表和播放器*/

    PlayerList = new QMediaPlaylist;
    //设置QMediaPlayer循环播放
    PlayerList->setPlaybackMode(QMediaPlaylist::Loop);
    Player = new QMediaPlayer;

    /*连接信号与槽*/
    //展示当前播放的音乐（Player定义后才能进行连接）
    connect(Player,&QMediaPlayer::currentMediaChanged,this,&MainWindow::SlotMusicChanged);
    //进度条
    connect(Player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));//拖动
    connect(Player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));//移动

    //首次设置
    if(first){

        /*连接信号与槽*/

        //三个控制按钮
        connect(ui->ButtonPause,&QPushButton::clicked,this,&MainWindow::SlotButtonStart);
        connect(ui->ButtonNext,&QPushButton::clicked,this,&MainWindow::SlotButtonNext);
        connect(ui->ButtonPrevious,&QPushButton::clicked,this,&MainWindow::SlotButtonPrevious);
        //表项双击
        connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(slotTable(int,int)));

        /*窗口设置*/

        //窗口透明
        this->setAttribute(Qt::WA_TranslucentBackground);
        //隐藏边框
        this->setWindowFlags(Qt::FramelessWindowHint |
                             Qt::WindowSystemMenuHint |
                             Qt::WindowMinMaxButtonsHint);
        //添加阴影效果：
        QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect();
        shadow->setBlurRadius(5);//设置圆角半径
        shadow->setColor(QColor(0,0,0));//设置边框颜色
        shadow->setXOffset(-0.5);//设置向右下方偏移
        shadow->setYOffset(-0.5);//设置向右下方偏移
        ui->MainWidget->setGraphicsEffect(shadow);
        //渐变色
        ui->MainWidget->setStyleSheet("#MainWidget{border-radius:10px;"
                                      " background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                                      "stop:0 #0bb4e4, stop:1 #20dfb0);}");

        /*表格设置*/

        //设置表格不可编辑
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //设置表格不可选中
        //ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        //隐藏行号
        ui->tableWidget->verticalHeader()->setVisible(false);
        //隐藏表头
        ui->tableWidget->horizontalHeader()->setVisible(false);
        //去除边框
        ui->tableWidget->setFrameShape(QFrame::NoFrame);
        //网格线不可见
        ui->tableWidget->setShowGrid(false);
        //解决选中虚框问题
        ui->tableWidget->setFocusPolicy(Qt::NoFocus);
        //表格样式
        ui->tableWidget->setStyleSheet("background-color: #00000000; color:#000000; font: 25px 仿宋_GB2312");

        /*按钮设置*/
        //播放暂停按钮
        ui->ButtonPause->setIcon(QIcon(path + "play.png"));
        ui->ButtonPause->setIconSize(QSize(60,60));
        ui->ButtonPause->setStyleSheet(BUTTONSTYLE2);
        //下一首按钮
        ui->ButtonNext->setIcon(QIcon(path + "next.png"));
        ui->ButtonNext->setIconSize(QSize(60,60));
        ui->ButtonNext->setStyleSheet(BUTTONSTYLE2);
        //上一首按钮
        ui->ButtonPrevious->setIcon(QIcon(path + "previous.png"));
        ui->ButtonPrevious->setIconSize(QSize(60,60));
        ui->ButtonPrevious->setStyleSheet(BUTTONSTYLE2);
        //关闭按钮
        ui->ButtonClose->setIcon(QIcon(path + "close.png"));
        ui->ButtonClose->setIconSize(QSize(60,60));
        ui->ButtonClose->setStyleSheet(BUTTONSTYLE2);
        //最小化按钮
        ui->ButtonMin->setIcon(QIcon(path + "min.png"));
        ui->ButtonMin->setIconSize(QSize(60,60));
        ui->ButtonMin->setStyleSheet(BUTTONSTYLE2);
        //打开文件夹按钮
        ui->ButtonOpenFloder->setText("打开文件夹");
        ui->ButtonOpenFloder->setStyleSheet(BUTTONSTYLE2);
        //关于按钮
        ui->ButtonAbout->setText("关于");
        ui->ButtonAbout->setStyleSheet(BUTTONSTYLE2);

        /*其他*/

        //分割线设置
        ui->line->setStyleSheet("background:#000000;");
        ui->line_2->setStyleSheet("background:#000000;");
        //不再重复设置
        first = false;
    }

    //重置处理，清空表格
    ui->tableWidget->setRowCount(0);

    /*获得音乐文件*/

    //从保存的文件读取音乐文件夹路径
    this->MusicPath = getFloderPath();
    //获取文件夹路径下的所有音乐文件
    fileList = getFileNames(this->MusicPath);
    //音乐数量
    musicNum = fileList.size();

    /*准备播放音乐*/

    if(musicNum != 0)
    {
        //输出所有音乐文件到表格
        for(int i=0;i<fileList.size();i++)
        {
            QString fileName = fileList.at(i);
            addItem(fileName);
            //向Player播放列表中添加音乐文件
            PlayerList->addMedia(QUrl::fromLocalFile(MusicPath+"\\"+fileName));
        }

        //设置Player播放列表中正在播放音乐的位置
        PlayerList->setCurrentIndex(0);

        //展示当前音乐名
        SlotShowCurrentMedia();

        //将Player播放列表加载到Player
        Player->setPlaylist(PlayerList);
    }
    else
    {
        //未找到音乐文件，提示先打开音乐文件夹
        ui->labelMusicName->setText("请先打开音乐文件夹");
        ui->labelMusicName->setStyleSheet("font-size:25px; color:#000000");
        //无音乐时歌词
        ui->Lyric4->setText("无音乐");
        ui->Lyric4->setStyleSheet("font-size:30px; color:rgb(0, 128, 255)");
        ui->Lyric1->clear();
        ui->Lyric2->clear();
        ui->Lyric3->clear();
        ui->Lyric5->clear();
        ui->Lyric6->clear();
        ui->Lyric7->clear();
    }
}

//获取路径下所有需要的文件类型文件
QStringList MainWindow::getFileNames(const QString &path)
{
	QDir dir(path);
    QStringList nameFilters;
    //获取的音乐文件类型
    nameFilters << "*.mp3" << "*.flac";
    //获得目录中符合筛选条件的文件（按名称排序？）
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable);
    //按音乐名排序
    QCollator collator;
    collator.setNumericMode(true);
    std::sort(files.begin(), files.end(),
                  [& collator](const QString & str1, const QString & str2)
    {
          return collator.compare(str1, str2) < 0;
    }
    );
	return files;
}

//展示当前音乐名
void MainWindow::SlotShowCurrentMedia()
{
    if(PlayerList->isEmpty())
        return;
    int idx = PlayerList->currentIndex();
    QString musicName = fileList.at(idx);
    //去除文件名后缀
    musicName =  musicName.left(musicName.lastIndexOf("."));
    ui->labelMusicName->setText(musicName);
    ui->labelMusicName->setStyleSheet("font-size:25px; color:#000000");
}

//播放，暂停
void MainWindow::SlotButtonStart()
{
	if(!isPlay)
    {
        isPlay = true;
        ui->ButtonPause->setIcon(QIcon(path + "pause.png"));
        Player->play();

    }
	else
    {
        isPlay = false;
        ui->ButtonPause->setIcon(QIcon(path + "play.png"));
        Player->pause();
    }
}

//上一首
void MainWindow::SlotButtonPrevious()
{
    //考虑循环播放
    if(PlayerList->currentIndex() == 0)
    {
        PlayerList->setCurrentIndex(musicNum-1);
    }
    else
    {
        PlayerList->previous();
    }
}

//下一首
void MainWindow::SlotButtonNext()
{
    //考虑循环播放
    if(PlayerList->currentIndex() == musicNum-1)
    {
        PlayerList->setCurrentIndex(0);
    }
    else
    {
        PlayerList->next();
    }
}

//增加项目
void MainWindow::addItem(QString name)
{
	int count = ui->tableWidget->rowCount();
	ui->tableWidget->setRowCount(count+1);
	
    QTableWidgetItem *itemName = new QTableWidgetItem(name);
	ui->tableWidget->setItem(count, 0 , itemName);
}

//打开文件夹
void MainWindow::on_ButtonOpenFloder_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"选择一个文件",
                                                   QCoreApplication::applicationFilePath());
        //暂停
        isPlay = false;
        Player->pause();
        ui->ButtonPause->setIcon(QIcon(path + "play.png"));
        //设置文件夹路径
        setFloderPath(dir);
        //回收空间
        delete Player;
        delete PlayerList;
        //重新初始化
        init();
}

//从保存的文件读取音乐文件夹路径
QString MainWindow::getFloderPath()
{
    QFile file(path + "path.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    file.close();
    return QString(ba);
}

//设置音乐文件夹路径
void MainWindow::setFloderPath(QString dir)
{
    QFile file(path + "path.txt");
    file.open(QIODevice::WriteOnly);
    QByteArray ba;
    ba.append(dir);
    file.write(ba);
    file.close();
}

//表格双击播放
void MainWindow::slotTable(int row,int)
{
    PlayerList->setCurrentIndex(row);
    ui->ButtonPause->setIcon(QIcon(path + "pause.png"));
    Player->play();
    isPlay = true;
}

//获取歌词
void MainWindow::getLyrics()
{
    listLyricsText.clear();
    listLyricsTime.clear();

    int idx = PlayerList->currentIndex();
    int loc = ui->tableWidget->item(idx,0)->text().lastIndexOf(".");
    QString lyricsPath =  MusicPath + "//" + ui->tableWidget->item(idx,0)->text().left(loc) + ".lrc";
    QFile file(lyricsPath);
       file.open(QIODevice::ReadOnly | QIODevice::Text);
       QString line="";
       while((line=file.readLine())>0){
           //解析歌词文件内容
           if(line == NULL || line.isEmpty()){
                  qDebug()<<"thie line is empty!";
              }
              QRegularExpression regularExpression("\\[(\\d+)?:(\\d+)?(\\.\\d+)?\\](.*)?");
              int index = 0;
              QRegularExpressionMatch match;
              match = regularExpression.match(line, index);
              if(match.hasMatch()) {
                  int totalTime;
                  totalTime = match.captured(1).toInt() * 60 + match.captured(2).toInt();                    /*  计算该时间点秒数            */
                  QString currentText =QString::fromStdString(match.captured(4).toStdString());      /*   获取歌词文本*/
                  if(!currentText.isEmpty())
                  {
                      listLyricsText.push_back(currentText);
                      listLyricsTime.push_back(totalTime);
                  }
              }
       }
       for(int i=0;i<3;i++)
       {
           listLyricsText.push_front("");
           listLyricsText.push_back("");
           listLyricsTime.push_front(-1);
           listLyricsTime.push_back(-1);
       }
}

//文件时长变化，更新当前播放文件名显示
//播放文件数据总大小的信号， 它可以获得文件时间长度。
void MainWindow::onDurationChanged(qint64 duration)
{
    ui->horizontalSlider->setMaximum(duration); //设置进度条最大值 也就是歌曲时长 ms
    int secs = duration/1000; //全部秒数
    int mins = secs/60;//分
    secs = secs % 60;//秒
    durationTime = QString::number(mins) + (secs < 10 ? ":0" : ":") + QString::number(secs);
    ui->labelTime->setText(positionTime+"/"+durationTime);
    ui->labelTime->setStyleSheet("font-size:25px; color:#000000");
}

//当前文件播放位置变化，更新进度显示。播放到什么位置的信号， 参数是以毫秒来计算的。
void MainWindow::onPositionChanged(qint64 position)
{
    if(ui->horizontalSlider->isSliderDown())
        return;//如果手动调整进度条，则不处理
    ui->horizontalSlider->setSliderPosition(position);
    int totalsecs = position/1000;
    int mins = totalsecs/60;
    int secs = totalsecs % 60;
    positionTime = QString::number(mins) + (secs < 10 ? ":0" : ":") + QString::number(secs);
    ui->labelTime->setText(positionTime+"/"+durationTime);
    ui->labelTime->setStyleSheet("font-size:25px; color:#000000");
    if(std::find(listLyricsTime.begin(),listLyricsTime.end(),totalsecs) != listLyricsTime.end())
    {
        int loc = std::find(listLyricsTime.begin(),listLyricsTime.end(),totalsecs)-listLyricsTime.begin();
        ui->Lyric1->setText(listLyricsText.at(loc-3));
        ui->Lyric1->setStyleSheet("font-size:25px; color:#555555");
        ui->Lyric2->setText(listLyricsText.at(loc-2));
        ui->Lyric2->setStyleSheet("font-size:25px; color:#555555");
        ui->Lyric3->setText(listLyricsText.at(loc-1));
        ui->Lyric3->setStyleSheet("font-size:25px; color:#555555");
        ui->Lyric4->setText(listLyricsText.at(loc));
        ui->Lyric4->setStyleSheet("font-size:25px; color:#000000");
        ui->Lyric5->setText(listLyricsText.at(loc+1));
        ui->Lyric5->setStyleSheet("font-size:25px; color:#555555");
        ui->Lyric6->setText(listLyricsText.at(loc+2));
        ui->Lyric6->setStyleSheet("font-size:25px; color:#555555");
        ui->Lyric7->setText(listLyricsText.at(loc+3));
        ui->Lyric7->setStyleSheet("font-size:25px; color:#555555");
    }
}

//解决播放卡顿问题
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(qAbs (Player->position() -value ) > 99){
        Player->setPosition(value);//文件播放位置 根据进度条传入的参数
    }
}

//音乐切换
void MainWindow::SlotMusicChanged()
{
    //改变播放音乐名
    SlotShowCurrentMedia();
    //改变歌词
    getLyrics();
}

//三个鼠标事件的重写,实现窗口拖动
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if( e->button() == Qt::LeftButton &&
                ui->widget_title_bar->rect().contains((e->globalPos())- this->frameGeometry().topLeft()))
    {
        isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
        last = e->globalPos();
    }
//    e->ignore();//表示继续向下传递事件，其他的控件还可以去获取
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (isPressedWidget)
    {
         int dx = e->globalX() - last.x();
         int dy = e->globalY() - last.y();
         last = e->globalPos();
         move(x()+dx, y()+dy);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        isPressedWidget = false; // 鼠标松开时，置为false
    }
}

//关闭按钮
void MainWindow::on_ButtonClose_clicked()
{
    this->close();
}

//最小化按钮
void MainWindow::on_ButtonMin_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

//关于按钮
void MainWindow::on_ButtonAbout_clicked()
{
    QMessageBox::about(NULL, "About", "Designed by 竹星梦华!    ");
}


