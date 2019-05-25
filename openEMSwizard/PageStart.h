#ifndef PAGESTART_H
#define PAGESTART_H

#include <QWizard>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QGridLayout>
#include <QSettings>
#include "WizardInit.h"

class PageStart : public QWizardPage
{
    Q_OBJECT
public:
    PageStart(QWizard *parent);
    void ConfigPaths();

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

    QLineEdit *text_openems_path;
    QLineEdit *text_simulation_path;

    void SaveSettings();
    void LoadSettings();

    WizardInit *parent_tmp;

public slots:
    void OnSetOpenEMSPath();
    void OnSetSimulationPath();
};

#endif // PAGESTART_H
