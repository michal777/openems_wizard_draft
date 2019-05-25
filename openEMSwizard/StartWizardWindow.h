#ifndef StartWizardWindow_H
#define StartWizardWindow_H

#include <QMainWindow>
#include <QFile>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QWizard>
#include <QSettings>

class StartWizardWindow : public QMainWindow
{
    Q_OBJECT
public:
    StartWizardWindow(QWidget *parent = 0);
    QFile *workflowfile;
    QLineEdit *TextWorkflowFilePath;

    void SaveSettings();
    void LoadSettings();
    QString file_main_settings;

    ~StartWizardWindow();
public slots:
    void OnSetWorkflowFilePath();
    void OnRunWizard();
};

#endif // StartWizardWindow_H
