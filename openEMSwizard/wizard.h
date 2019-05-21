#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QWizardPage>
#include <QMainWindow>
#include <QFile>

class MyWizard : public QWizard
{
    Q_OBJECT
public:
    MyWizard(QMainWindow *parent, QFile *workflowfile);
    QWizardPage *ReturnWorkflowStep(QWizard *parent, QString workflowname);
};

#endif // WIZARD_H
