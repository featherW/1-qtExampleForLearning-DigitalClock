#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QTime>
#include <QString>
#include<QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_sysTrayIcon = new QSystemTrayIcon();
    m_sysTrayMenu = new QMenu();
    m_trayExit    = new QAction(tr("退出"),this);
    m_timer       = new QTimer();
}

MainWindow::~MainWindow(void)
{
    if (ui != NULL)
    {
        delete ui;
        ui = NULL;
    }

    if (m_sysTrayIcon != NULL)
    {
        delete m_sysTrayIcon;
        m_sysTrayIcon = NULL;
    }

    if (m_sysTrayMenu != NULL)
    {
        delete m_sysTrayMenu;
        m_sysTrayMenu = NULL;
    }

    if (m_timer != NULL)
    {
        delete m_timer;
        m_timer = NULL;
    }
}

void MainWindow::initWindow()
{
    // FramelessWindowHint 无边框; WindowStaysOnTopHint 程序置顶
    // http://blog.csdn.net/liang19890820/article/details/50553111
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // 设置窗口透明
    // http://wangbaiyuan.cn/getting-started-with-qt-how-to-write-without-borders-the-title-bar-of-windows-transparent-windows-round-controls.html
    setWindowOpacity(0.8);
    setAttribute(Qt::WA_TranslucentBackground);

    // 窗口位置
    QRect deskRect = QApplication::desktop()->availableGeometry();
    move(deskRect.left(), 0);

    // 设置系统托盘
    // http://blog.csdn.net/zhuyunfei/article/details/51433822
    QIcon icon = QIcon(":/res/images/Tray.ico");
    m_sysTrayIcon->setIcon(icon);
    m_sysTrayIcon->setToolTip(QObject::trUtf8("数字时钟"));
    m_sysTrayIcon->show();

    // 设置系统托盘菜单
    // http://www.tuicool.com/articles/RJVBba
    m_sysTrayMenu->addAction(m_trayExit);
    m_sysTrayIcon->setContextMenu(m_sysTrayMenu);
    connect(m_trayExit, SIGNAL(triggered()), this, SLOT(closeClock()));

    // 在界面上显示时间
    connect(m_timer, SIGNAL(timeout()), this, SLOT(showTime()));
    m_timer->start(500);

}


// 鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_mousePoint = event->pos();    //鼠标相对于窗体的位置
    m_isMousePressed = true;        //鼠标按下
    event->accept();
}

// 窗体拖动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // 若鼠标左键被按下
    if(m_isMousePressed == true)
   {
         // 鼠标相对于屏幕的位置
         QPoint curMousePoint = event->globalPos() - m_mousePoint;
        // 移动主窗体位置
         move(curMousePoint);
    }
    event->accept();
}

// 鼠标释放事件
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     // 鼠标未按下
     m_isMousePressed = false;
     event->accept();
}

// 显示时间
void MainWindow::showTime()
{
     QTime time = QTime::currentTime();
     QString textTime = time.toString("hh:mm:ss");
     ui->curTime->display(textTime);
}

// 处理窗口关闭事件
void MainWindow::closeClock()
{
    emit exitsignal();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  if(m_sysTrayIcon->isVisible())
  {
      hide();
      this->close();
      event->ignore();
  }
}
