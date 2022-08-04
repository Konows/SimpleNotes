#include "subtext.h"

#include <QDebug>

subText::subText(QWidget *parent)
    : QTextEdit{parent}
{
    this->filepath.clear();
    file = new QFile(this);
}

//function
//新建文件
void subText::Newfile()
{
    static int index = 1;
    QString title = QString("未命名的文档(%1)").arg(index);//设置初始标题
    this->setWindowTitle(title);

    //启用星号(未保存时标题栏星号提示)
    //connect(this->document(),SIGNAL(contentsChanged()),this,SLOT(doProcessContentsChanged()));

    index++;
}

//打开文件
void subText::Openfile()
{
    //获取要打开的文本文件
    QString path = QFileDialog::getOpenFileName(this, "获取文本文件", ".", "Text(*.cpp *.h *.txt");

    //保存文件路径，设置窗体名
    if(path.isEmpty())
    {
        return;
    }
    this->filepath = path;

    //启用星号(未保存时标题栏星号提示)
    //connect(this->document(),SIGNAL(contentsChanged()),this,SLOT(doProcessContentsChanged()));

//    QStringList list = filepath.split("/");
//    QString filename = list.at(list.length()-1);
    QFileInfo info(path);
    QString filename = info.fileName();
    this->setWindowTitle(filename);

    //对文件进行操作（文件流）
    file->setFileName(path);
    bool ret = file->open(QIODevice::ReadOnly|QIODevice::Text);
    if(!ret)
    {
        QMessageBox::warning(this,"打开文件失败","打开文件失败");
        return;
    }
    QTextStream stream(file);
    stream.setCodec(this->codeName.toLocal8Bit().data());
    while(!stream.atEnd())
    {
        QString str = stream.readLine();
        this->append(str);
    }
    file->close();
}

void subText::setCodeName(const QString codename)
{
    this->codeName = codename;
}

//保存文件
bool subText::Savefile()
{
//    if(!this->isWindowModified())
//    {
//       return;
//    }
    if(this->filepath.isEmpty())
    {
        QString path = QFileDialog::getSaveFileName(this,"保存",".","Text(*.cpp *.h *.txt");
        if(path.isEmpty())
        {
            return false;
        }

        this->filepath=path;
    }
    //对文件操作
    file->setFileName(this->filepath);
    bool ret = file->open(QIODevice::WriteOnly|QIODevice::Text);

    if(!ret)
    {
        QMessageBox::warning(this,"失败","打开文件失败");
        return false;
    }
    QTextStream stream(file);
    stream.setCodec(this->codeName.toLocal8Bit().data());

    stream << this->toPlainText();
    stream.flush();

    file->close();
    qDebug()<<"tips";
//    this->setWindowModified(false);
    QMessageBox::information(this,"成功","保存文件成功");
    return true;
}

//另存为
void subText::Saveas()
{
    QString path = this->filepath;
    this->filepath.clear();

    bool ret = Savefile();
    if(!ret)
    {
        this->filepath = path;
    }
}
//end function

//events
//关闭事件
void subText::closeEvent(QCloseEvent *e)
{
//    if(!this->isWindowModified())
//    {
//       return;
//    }
    QMessageBox::StandardButton ret = QMessageBox::information(this,"提示",
                             "当前文件未保存",
                             QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(ret == QMessageBox::Yes)
    {
        Savefile();
        e->accept();
    }
    else if (ret == QMessageBox::No)
    {
        e->accept();
    }
    else
    {
        e->ignore();
    }
}
//end events

//slots
//启用星号
void subText::doProcessContentsChanged()
{
    this->setWindowModified(true);
}


//end slots
