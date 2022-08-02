#ifndef SIMPLENOTES_H
#define SIMPLENOTES_H

#include "subtext.h"

#include <QMainWindow>
#include <QMdiSubWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleNotes; }
QT_END_NAMESPACE

class SimpleNotes : public QMainWindow
{
    Q_OBJECT

public:
    SimpleNotes(QWidget *parent = nullptr);
    ~SimpleNotes();

private:
    Ui::SimpleNotes *ui;
    QString codeName;

    void Init();

private slots:
    void doProcessNew(bool);

    void doProcessOpen(bool);

    void doProcessSave(bool);

    void doProcessSaveas(bool);

    void doProcessExit(bool);

    void doProcessUTF(bool);

    void doProcessGB(bool);

};
#endif // SIMPLENOTES_H
