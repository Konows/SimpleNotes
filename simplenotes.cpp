#include "simplenotes.h"
#include "ui_simplenotes.h"

#include<QDebug>

SimpleNotes::SimpleNotes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleNotes)
{
    ui->setupUi(this);

    Init();//初始化
}

SimpleNotes::~SimpleNotes()
{
    delete ui;
}

//function
//初始化
void SimpleNotes::Init()
{
    codeName = "UTF-8";
    //新建文件
    connect(ui->action_new,SIGNAL(triggered(bool)),this,SLOT(doProcessNew(bool)));
    //打开文件
    connect(ui->action_open,SIGNAL(triggered(bool)),this,SLOT(doProcessOpen(bool)));
    //保存文件
    connect(ui->action_save,SIGNAL(triggered(bool)),this,SLOT(doProcessSave(bool)));
    //另存为
    connect(ui->action_saveas,SIGNAL(triggered(bool)),this,SLOT(doProcessSaveas(bool)));
    //关闭
    connect(ui->action_exit,SIGNAL(triggered(bool)),this,SLOT(doProcessExit(bool)));
    //设置编码格式为UTF-8
    connect(ui->action_utf,SIGNAL(triggered(bool)),this,SLOT(doProcessUTF(bool)));
    //设置编码格式为GB2312
    connect(ui->action_gb,SIGNAL(triggered(bool)),this,SLOT(doProcessGB(bool)));

}
//end function

//event
//end event

//slots
//新建文件
void SimpleNotes::doProcessNew(bool)
{
//    qDebug() << "test";
    subText *sub = new subText();
    ui->mdiArea->addSubWindow((QWidget *)sub);
    sub->setCodeName(codeName);
    sub->Newfile();
    sub->show();
}

//打开文件
void SimpleNotes::doProcessOpen(bool)
{
    subText *sub = new subText();
    ui->mdiArea->addSubWindow((QWidget *)sub);
    sub->setCodeName(codeName);
    sub->Openfile();
    sub->show();
}

//保存文件
void SimpleNotes::doProcessSave(bool)
{
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();//活跃的子窗口
    QWidget *win = subWin->widget();
    subText *sub = (subText *)win;
    sub->Savefile();
}

//另存为
void SimpleNotes::doProcessSaveas(bool)
{
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();//活跃的子窗口
    QWidget *win = subWin->widget();
    subText *sub = (subText *)win;
    sub->Saveas();
}

//关闭当前子窗口
void SimpleNotes::doProcessExit(bool)
{
    QMdiSubWindow *subWin = ui->mdiArea->activeSubWindow();//活跃的子窗口
    QWidget *win = subWin->widget();
    subText *sub = (subText *)win;
    sub->close();
}

//设置编码格式为UTF-8
void SimpleNotes::doProcessUTF(bool)
{
    qDebug() << codeName;
    this->codeName = "UTF-8";
}

//设置编码格式为GB2312
void SimpleNotes::doProcessGB(bool)
{
    this->codeName = "GB2312";
}
//end slots
