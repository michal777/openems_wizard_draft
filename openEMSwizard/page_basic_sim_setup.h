#ifndef PAGE_BASIC_SIM_SETUP_H
#define PAGE_BASIC_SIM_SETUP_H

#include <QWizard>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>

class PageBasicSimSetup : public QWizardPage
{
    Q_OBJECT
public:
    PageBasicSimSetup(QWizard *parent);
    void ConfigSimPar(void);
    void ConfigFDTDSettings(void);
    QDialog *window_fdtd_setings;
    QString ReturnConfigFDTD(void);
    QString init_fdtd_line;

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

    QGroupBox *group_box_sim_par;
    QGridLayout *grid_sim_par;

    QLineEdit *text_fmin;
    QLineEdit *text_fmax;
    QComboBox *combo_frequnit;

    QLineEdit *init_ftdt_param_NrTS;
    QLineEdit *init_ftdt_param_EndCriteria;
    QLineEdit *init_ftdt_param_MaxTime;
    QLineEdit *init_ftdt_param_OverSampling;
    QLineEdit *init_ftdt_param_CoordSystem;
    QLineEdit *init_ftdt_param_MultiGrid;
    QLineEdit *init_ftdt_param_TimeStep;
    QLineEdit *init_ftdt_param_TimeStepFactor;
    QLineEdit *init_ftdt_param_TimeStepMethod;
    QLineEdit *init_ftdt_param_CellConstantMaterial;

    QString GetFreqMultiplier(void) {    if(!QString::compare("GHz", combo_frequnit->currentText())) return "1e9";
                                    else if(!QString::compare("MHz", combo_frequnit->currentText())) return "1e6";
                                    else if(!QString::compare("kHz", combo_frequnit->currentText())) return "1e3";
                                    else if(!QString::compare("Hz", combo_frequnit->currentText())) return "1e0";}

public slots:
    void OnFDTDSettings();
    void OnCloseFDTDSettings();
};

#endif // PAGE_BASIC_SIM_SETUP_H
