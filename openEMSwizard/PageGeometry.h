#ifndef PAGEGEOMETRY_H
#define PAGEGEOMETRY_H

#include <QWizard>
#include <QWizardPage>
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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QDebug>
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>
#include <QScriptEngine>

#include "VariablesEditor.h"



//////////////////////////////////////////////////////////////////////////////////////////////////
/// Parameters of shapes, common to all shapes (specific shapes will be derived)
//////////////////////////////////////////////////////////////////////////////////////////////////
class shape_parameters
{
public:
    QString name;
    QString type;
    QString priority;
    QString material;
    unsigned int id;

    QString transf_scale_x;
    QString transf_scale_y;
    QString transf_scale_z;
    QString transf_rotate_ax;
    QString transf_rotate_ay;
    QString transf_rotate_az;
    QString transf_rotate_angle;
    QString transf_move_x;
    QString transf_move_y;
    QString transf_move_z;
    QString transf_order[3];
};

//////////////////////////////////////////////////////////////////////////////////////////////////
/// Parameters of specific shapes
//////////////////////////////////////////////////////////////////////////////////////////////////
class shape_box_parameters : public shape_parameters
{
public:
    QString x_coord_1;
    QString x_coord_2;
    QString y_coord_1;
    QString y_coord_2;
    QString z_coord_1;
    QString z_coord_2;
};

class shape_cylinder_parameters : public shape_parameters
{
public:
    QString x_coord_1;
    QString x_coord_2;
    QString y_coord_1;
    QString y_coord_2;
    QString z_coord_1;
    QString z_coord_2;
    QString radius;
};



//////////////////////////////////////////////////////////////////////////////////////////////////
/// The page of the wizard that is used to configure geometry
//////////////////////////////////////////////////////////////////////////////////////////////////

class PageGeometry : public QWizardPage
{
    Q_OBJECT
public:
    PageGeometry(QWizard *parent, VariablesEditor *var_edit_main);

    //basic functions of wizard page
    bool validatePage();
    void SaveToSimScriptBuffer(void);
    void ReadFromSimScriptBuffer(void);
    QString text_save_to_simscript;

    //variables defined in variable editor can be used here, variables are processed using QScriptEngine
    VariablesEditor *var_edit;
    QString EvaluateVar(QString var_to_eval);

    QListWidget *shapes_list_widget;
    QVector<shape_parameters *> *shapes_param_list_ptr;

    QHBoxLayout *main_layout_shapes;
    QStackedLayout *stackedLayout;
    QGroupBox *shape_select_groupbox;
    QGroupBox *shape_list_groupbox;
    QGroupBox *transforms_groupbox;
    QGroupBox *groupbox_box_settings;
    QGroupBox *groupbox_cylinder_settings;

    void ShapeSelectLayout(void);
    void ShapeListLayout(void);
    void ShapeTransformsLayout(void);
    void UploadShapesToViewer(void);
    void ShapeBoxSettings(void);
    void ShapeCylinderSettings(void);

    virtual void initializePage(void);


    QRadioButton *rad_but_type_box;
    QRadioButton *rad_but_type_sphere;
    QRadioButton *rad_but_type_spherical_shell;
    QRadioButton *rad_but_type_cylinder;
    QRadioButton *rad_but_type_cylindrical_shell;
    QRadioButton *rad_but_type_curve;
    QRadioButton *rad_but_type_wire;
    QRadioButton *rad_but_type_polygon;
    QRadioButton *rad_but_type_extruded_polygon;
    QRadioButton *rad_but_type_rotational_solid;
    QRadioButton *rad_but_type_polyhedron;


    QLineEdit *sh_box_name;
    QLineEdit *sh_box_priority;
    QComboBox *sh_box_x_coord_1;
    QLineEdit *sh_box_x_coord_2;
    QLineEdit *sh_box_y_coord_1;
    QLineEdit *sh_box_y_coord_2;
    QLineEdit *sh_box_z_coord_1;
    QLineEdit *sh_box_z_coord_2;
    QComboBox *sh_box_material;

    QLineEdit *sh_cylinder_name;
    QLineEdit *sh_cylinder_priority;
    QLineEdit *sh_cylinder_x_coord_1;
    QLineEdit *sh_cylinder_x_coord_2;
    QLineEdit *sh_cylinder_y_coord_1;
    QLineEdit *sh_cylinder_y_coord_2;
    QLineEdit *sh_cylinder_z_coord_1;
    QLineEdit *sh_cylinder_z_coord_2;
    QLineEdit *sh_cylinder_radius;
    QComboBox *sh_cylinder_material;

    QListWidget *transforms_list_widget;
    QPushButton *button_transform_scale;
    QPushButton *button_transform_rotate;
    QPushButton *button_transform_move;
    QPushButton *button_transform_remove;
    QLineEdit *transf_scale_x;
    QLineEdit *transf_scale_y;
    QLineEdit *transf_scale_z;
    QLineEdit *transf_rotate_ax;
    QLineEdit *transf_rotate_ay;
    QLineEdit *transf_rotate_az;
    QLineEdit *transf_rotate_angle;
    QLineEdit *transf_move_x;
    QLineEdit *transf_move_y;
    QLineEdit *transf_move_z;

public slots:
    void OnSetShapeTypeLayout(void);
    void OnAddOrChangeShape(void);
    void OnRemoveShape(void);
    void OnGetSelectedShape(QListWidgetItem* item);
    void UpdateVariableLists(void);
    void OnChangeTransformOrder(void);
};

#endif // PAGEGEOMETRY_H
