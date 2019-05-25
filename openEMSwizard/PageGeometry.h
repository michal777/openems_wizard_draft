#ifndef PAGEGEOMETRY_H
#define PAGEGEOMETRY_H

#include <QWizard>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>


class PageGeometry : public QWizardPage
{
    Q_OBJECT
public:
    PageGeometry(QWizard *parent);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

};

#endif // PAGEGEOMETRY_H
