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
