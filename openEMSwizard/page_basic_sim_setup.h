#ifndef PAGE_BASIC_SIM_SETUP_H
#define PAGE_BASIC_SIM_SETUP_H

#include <QWizard>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>

class PageBasicSimSetup : public QWizardPage
{
    Q_OBJECT
public:
    PageBasicSimSetup(QWizard *parent);
    void ConfigSimPar(void);
    void ConfigSimBox(void);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString *text_save_to_simscript;

    QGroupBox *group_box_sim_par;
    QGridLayout *grid_sim_par;
    QGroupBox *group_box_sim_box;
    QGridLayout *grid_sim_box;

    QComboBox *combo_unit;
    QLineEdit *text_fmin;
    QLineEdit *text_fmax;
    QComboBox *combo_frequnit;

    QLineEdit *text_bb_nx;
    QComboBox *combo_bb_nx;
    QLineEdit *text_bb_px;
    QComboBox *combo_bb_px;
    QLineEdit *text_bb_ny;
    QComboBox *combo_bb_ny;
    QLineEdit *text_bb_py;
    QComboBox *combo_bb_py;
    QLineEdit *text_bb_nz;
    QComboBox *combo_bb_nz;
    QLineEdit *text_bb_pz;
    QComboBox *combo_bb_pz;

    QString GetFreqMultiplier(void) {    if(!QString::compare("GHz", combo_frequnit->currentText())) return "1e9";
                                    else if(!QString::compare("MHz", combo_frequnit->currentText())) return "1e6";
                                    else if(!QString::compare("kHz", combo_frequnit->currentText())) return "1e3";
                                    else if(!QString::compare("Hz", combo_frequnit->currentText())) return "1e0";}

    QString GetUnitMultiplier(void) {    if(!QString::compare("m", combo_unit->currentText())) return "1e0";
                                    else if(!QString::compare("mm", combo_unit->currentText())) return "1e-3";
                                    else if(!QString::compare("um", combo_unit->currentText())) return "1e-6";}
//public slots:
//    void mySlot(int idx);
};

#endif // PAGE_BASIC_SIM_SETUP_H
