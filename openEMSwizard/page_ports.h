#ifndef PAGE_PORTS_H
#define PAGE_PORTS_H

#include <QWizard>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>


class PagePorts : public QWizardPage
{
    Q_OBJECT
public:
    PagePorts(QWizard *parent);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

};


#endif // PAGE_PORTS_H
