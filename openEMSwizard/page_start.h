#ifndef PAGE_START_H
#define PAGE_START_H

#include <QWizard>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>


class PageStart : public QWizardPage
{
    Q_OBJECT
public:
    PageStart(QWizard *parent);

    QLineEdit *TextOpenEMSPath;
    QLineEdit *TextCSXCADPath;
    QLineEdit *TextSimulationPath;

public slots:
    void OnSetOpenEMSPath();
    void OnSetCSXCADPath();
    void OnSetSimulationPath();
};

#endif // PAGE_START_H
