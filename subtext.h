#ifndef SUBTEXT_H
#define SUBTEXT_H

#include <QWidget>
#include <QFile>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>

class subText : public QTextEdit
{
    Q_OBJECT
public:
    explicit subText(QWidget *parent = nullptr);

    void Newfile();

    void Openfile();

    bool Savefile();

    void Saveas();

    void setCodeName(const QString codename);

private slots:
    void doProcessContentsChanged();

private:
    QString filepath;

    QFile *file;

    QString codeName;

};

#endif // SUBTEXT_H
