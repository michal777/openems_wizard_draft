#ifndef PAGERESULTSSPARAM_H
#define PAGERESULTSSPARAM_H

#include <QWizard>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>


class PageResultsSparam : public QWizardPage
{
    Q_OBJECT
public:
    PageResultsSparam(QWizard *parent);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

};


#endif // PAGERESULTSSPARAM_H
