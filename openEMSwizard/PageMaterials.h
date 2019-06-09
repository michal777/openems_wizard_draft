#ifndef PAGEMATERIALS_H
#define PAGEMATERIALS_H

#include <QWizard>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QListWidget>
#include <QVector>
#include <QGroupBox>
#include <QRadioButton>


struct material_parameters_struct
{
    QString name;
    QString type;
    QString epsilon;
    QString mue;
    QString kappa;
    QString sigma;
    QString conductivity;
    QString thickness;
};

class PageMaterials : public QWizardPage
{
    Q_OBJECT
public:
    PageMaterials(QWizard *parent);

    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

    QListWidget *materials_list_widget;
    QVector<material_parameters_struct> *materials_param_list_ptr;

    QGridLayout *grid_material;

    void MaterialsSettings(void);
    void UploadMaterialsToViewer(void);



    QRadioButton *rad_but_type_material;
    QRadioButton *rad_but_type_metal;
    QLineEdit *name;
    QString type;
    QLineEdit *epsilon;
    QLineEdit *mue;
    QLineEdit *kappa;
    QLineEdit *sigma;
    QLineEdit *conductivity;
    QLineEdit *thickness;

public slots:
    void OnAddOrChangeMaterial(void);
    void OnRemoveMaterial(void);
    void OnGetSelectedMaterial(QListWidgetItem* item);
    void OnSetMaterialType(void);

};

#endif // PAGEMATERIALS_H
