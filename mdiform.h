#ifndef MDIFORM_H
#define MDIFORM_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include "sol.hpp"
#include "sol_assert.hpp"
#include "envstate.h"
#include "mdichild.h"

#define SOL_CHECK_ARGUMENTS 1

QT_BEGIN_NAMESPACE
namespace Ui {
class MdiForm;
}
QT_END_NAMESPACE

class MdiForm : public QMainWindow
{
    Q_OBJECT
public:
    explicit MdiForm(QWidget *parent = nullptr);
    ~MdiForm();


signals:

private slots:
    void onFileOpen();
    void onProjectOpen();
    void newFile();
    void open();
//    void save();
//    void saveAs();
//    void openRecent();
//    void cut();
//    void copy();
//    void paste();
    void onExit();

private:
    Ui::MdiForm *ui;
    EnvState _state;
    bool modified;
    void LoadProject(const QString &path);
    void ShowError(QString &errmsg);
    bool isModified() const;
    bool loadFile(const QString &fileName);
    bool openFile(const QString &fileName);
    MdiChild *createMdiChild();

    QMdiSubWindow *findMdiChild(const QString &fileName) const;
};

#endif // MDIFORM_H
