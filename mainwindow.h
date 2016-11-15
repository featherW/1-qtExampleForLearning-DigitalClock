#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initWindow();

protected:

    // 无边框下窗口移动
    // http://blog.csdn.net/u014284565/article/details/21795559
    virtual void mousePressEvent(QMouseEvent *event);   //鼠标按下事件
    virtual void mouseMoveEvent(QMouseEvent *event);    //窗体拖动事件
    virtual void mouseReleaseEvent(QMouseEvent *event); //鼠标释放事件

private:
    Ui::MainWindow    *ui;
    QPoint            m_mousePoint;              //鼠标相对于窗体的位置
    bool              m_isMousePressed;          //鼠标是否按下

    QSystemTrayIcon   *m_sysTrayIcon;            // 系统托盘图标
    QMenu             *m_sysTrayMenu;            // 系统托盘菜单
    QAction           *m_trayExit;               // 系统托盘菜单退出程序
};

#endif // MAINWINDOW_H
