#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QWizard>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    QFile *workflowfile;
    QLineEdit *TextWorkflowFilePath;
    ~MainWindow();
public slots:
    void OnSetWorkflowFilePath();
    void OnRunWizard();
};

#endif // MAINWINDOW_H
