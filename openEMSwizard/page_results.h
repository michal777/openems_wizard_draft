#ifndef PAGE_RESULTS_H
#define PAGE_RESULTS_H

#include <QWizard>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>


class PageResults : public QWizardPage
{
    Q_OBJECT
public:
    PageResults(QWizard *parent);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

};


#endif // PAGE_RESULTS_H
