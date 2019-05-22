#ifndef PAGE_GENERAL_GEOMETRY_SETTINGS_H
#define PAGE_GENERAL_GEOMETRY_SETTINGS_H

#include <QWizard>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>

class PageGeneralGeometrySettings : public QWizardPage
{
    Q_OBJECT
public:
    PageGeneralGeometrySettings(QWizard *parent);
    void ConfigSimBox(void);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

    QGroupBox *group_box_sim_par;
    QGridLayout *grid_sim_par;

    QComboBox *combo_unit;

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

    QString GetUnitMultiplier(void) {    if(!QString::compare("m", combo_unit->currentText())) return "1e0";
                                    else if(!QString::compare("mm", combo_unit->currentText())) return "1e-3";
                                    else if(!QString::compare("um", combo_unit->currentText())) return "1e-6";}
};

#endif // PAGE_GENERAL_GEOMETRY_SETTINGS_H
