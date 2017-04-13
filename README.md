# qtExampleForLearning

qt5的小例子, 仅仅是学习用

## 代码中有关qt的入门技巧包括

### 1 QT窗口无边框和置顶

```
setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
```

其中'''FramelessWindowHint'''为无边框参数, '''WindowStaysOnTopHint'''为置顶参数


### 2 QT设置窗口透明度

```
setWindowOpacity(0.5);
```

### 3 QT设置背景透明

```
setAttribute(Qt::WA_TranslucentBackground);
```

### 4 QT设置窗口位置

```
QRect deskRect = QApplication::desktop()->availableGeometry();
move(deskRect.right() - this->width(), 0);
```

### 5 QT设置皮肤

```
QFile qss(":/res/default.qss");
qss.open(QFile::ReadOnly);
qApp->setStyleSheet(qss.readAll());
```

### 6 QT设置系统托盘

```
QIcon icon = QIcon(":/res/images/Tray.png");
m_sysTrayIcon->setIcon(icon);
m_sysTrayIcon->setToolTip(QObject::trUtf8("数字时钟"));
m_sysTrayIcon->show();
```

其他技巧(系统托盘添加菜单、显示时间、窗口拖动等)可以参考代码中的博客链接。
