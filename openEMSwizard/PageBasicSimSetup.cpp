#include "PageBasicSimSetup.h"
#include <QDebug>

PageBasicSimSetup::PageBasicSimSetup(QWizard *parent): QWizardPage(parent)
{
    ConfigSimPar();
    ConfigFDTDSettings();
}

bool PageBasicSimSetup::validatePage()
{
    SaveToSimScriptBuffer();
    return true;
}

void PageBasicSimSetup::SaveToSimScriptBuffer(void)
{
    text_save_to_simscript.clear();
    text_save_to_simscript.append("##<OUTPUT_AUTOGENERATED_PageBasicSimSetup>##\n");
    text_save_to_simscript.append("physical_constants;\n");
    text_save_to_simscript.append(QString("fmin = %1 * %2;\n").arg(text_fmin->text()).arg(GetFreqMultiplier()));
    text_save_to_simscript.append(QString("fmax = %1 * %2;\n").arg(text_fmax->text()).arg(GetFreqMultiplier()));
    text_save_to_simscript.append(QString("FDTD = InitFDTD(%1);\n").arg(ReturnConfigFDTD()));
    text_save_to_simscript.append("##<END_OUTPUT_AUTOGENERATED_PageBasicSimSetup>##\n");
    qDebug("%s", qUtf8Printable(text_save_to_simscript));
}

void PageBasicSimSetup::ReadFromSimScriptBuffer(void)
{

}

void PageBasicSimSetup::ConfigSimPar(void)
{
    group_box_sim_par = new QGroupBox(tr("simulation parameters"), this);
    grid_sim_par = new QGridLayout(this);
    grid_sim_par->setSizeConstraint(QLayout::SetFixedSize);
    grid_sim_par->setColumnMinimumWidth(3, 50);

    QLabel *statictext_freq = new QLabel("frequency", this);
    text_fmin = new QLineEdit(this);
    QLabel *statictext_freqhypen = new QLabel(" - ", this);
    text_fmax = new QLineEdit(this);
    combo_frequnit = new QComboBox(this);
    combo_frequnit->addItem("GHz");
    combo_frequnit->addItem("MHz");
    combo_frequnit->addItem("kHz");
    combo_frequnit->addItem("Hz");

    QPushButton *button_settings_fdtd = new QPushButton("FDTD settings", this);
    connect(button_settings_fdtd, SIGNAL(released()), this, SLOT(OnFDTDSettings()));

    grid_sim_par->addWidget(statictext_freq, 1, 0, Qt::AlignRight);
    grid_sim_par->addWidget(text_fmin, 1, 1, Qt::AlignLeft);
    grid_sim_par->addWidget(statictext_freqhypen, 1, 2, Qt::AlignLeft);
    grid_sim_par->addWidget(text_fmax, 1, 3, Qt::AlignLeft);
    grid_sim_par->addWidget(combo_frequnit, 1, 4, Qt::AlignLeft);
    grid_sim_par->addWidget(button_settings_fdtd, 2, 1, 1, 2, Qt::AlignLeft);

    group_box_sim_par->setLayout(grid_sim_par);
}

void PageBasicSimSetup::ConfigFDTDSettings(void)
{
    window_fdtd_setings = new QDialog(this);
    QGridLayout *grid_fdtd_par = new QGridLayout(window_fdtd_setings);

    QLabel *statictext_ftdt_nrts = new QLabel("NrTS", window_fdtd_setings);
    init_ftdt_param_NrTS = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_endcriteria = new QLabel("EndCriteria", window_fdtd_setings);
    init_ftdt_param_EndCriteria = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_maxtime = new QLabel("MaxTime", window_fdtd_setings);
    init_ftdt_param_MaxTime = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_oversampling = new QLabel("OverSampling", window_fdtd_setings);
    init_ftdt_param_OverSampling = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_coordsystem = new QLabel("CoordSystem", window_fdtd_setings);
    init_ftdt_param_CoordSystem = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_multigrid = new QLabel("MultiGrid", window_fdtd_setings);
    init_ftdt_param_MultiGrid = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_timestep = new QLabel("TimeStep", window_fdtd_setings);
    init_ftdt_param_TimeStep = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_timestepfactor = new QLabel("TimeStepFactor", window_fdtd_setings);
    init_ftdt_param_TimeStepFactor = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_timestepmethod = new QLabel("TimeStepMethod", window_fdtd_setings);
    init_ftdt_param_TimeStepMethod = new QLineEdit(window_fdtd_setings);
    QLabel *statictext_ftdt_cellconstantmaterial = new QLabel("CellConstantMaterial", window_fdtd_setings);
    init_ftdt_param_CellConstantMaterial = new QLineEdit(window_fdtd_setings);

    QPushButton *button_close_settings_fdtd = new QPushButton("Close", this);
    connect(button_close_settings_fdtd, SIGNAL(released()), this, SLOT(OnCloseFDTDSettings()));

    grid_fdtd_par->addWidget(statictext_ftdt_nrts, 0, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_endcriteria, 1, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_maxtime, 2, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_oversampling, 3, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_coordsystem, 4, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_multigrid, 5, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_timestep, 6, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_timestepfactor, 7, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_timestepmethod, 8, 0, Qt::AlignRight);
    grid_fdtd_par->addWidget(statictext_ftdt_cellconstantmaterial, 9, 0, Qt::AlignRight);

    grid_fdtd_par->addWidget(init_ftdt_param_NrTS, 0, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_EndCriteria, 1, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_MaxTime, 2, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_OverSampling, 3, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_CoordSystem, 4, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_MultiGrid, 5, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_TimeStep, 6, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_TimeStepFactor, 7, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_TimeStepMethod, 8, 1, Qt::AlignRight);
    grid_fdtd_par->addWidget(init_ftdt_param_CellConstantMaterial, 9, 1, Qt::AlignRight);

    grid_fdtd_par->addWidget(button_close_settings_fdtd, 10, 1, Qt::AlignRight);
}

QString PageBasicSimSetup::ReturnConfigFDTD(void)
{
    init_fdtd_line.clear();
    if(!init_ftdt_param_NrTS->text().isEmpty())
        init_fdtd_line.append(QString("NrTS, %1, ").arg(init_ftdt_param_NrTS->text()));
    if(!init_ftdt_param_EndCriteria->text().isEmpty())
        init_fdtd_line.append(QString("EndCriteria, %1, ").arg(init_ftdt_param_EndCriteria->text()));
    if(!init_ftdt_param_MaxTime->text().isEmpty())
        init_fdtd_line.append(QString("MaxTime, %1, ").arg(init_ftdt_param_MaxTime->text()));
    if(!init_ftdt_param_OverSampling->text().isEmpty())
        init_fdtd_line.append(QString("OverSampling, %1, ").arg(init_ftdt_param_OverSampling->text()));
    if(!init_ftdt_param_CoordSystem->text().isEmpty())
        init_fdtd_line.append(QString("CoordSystem, %1, ").arg(init_ftdt_param_CoordSystem->text()));
    if(!init_ftdt_param_MultiGrid->text().isEmpty())
        init_fdtd_line.append(QString("MultiGrid, %1, ").arg(init_ftdt_param_MultiGrid->text()));
    if(!init_ftdt_param_TimeStep->text().isEmpty())
        init_fdtd_line.append(QString("TimeStep, %1, ").arg(init_ftdt_param_TimeStep->text()));
    if(!init_ftdt_param_TimeStepFactor->text().isEmpty())
        init_fdtd_line.append(QString("TimeStepFactor, %1, ").arg(init_ftdt_param_TimeStepFactor->text()));
    if(!init_ftdt_param_TimeStepMethod->text().isEmpty())
        init_fdtd_line.append(QString("TimeStepMethod, %1, ").arg(init_ftdt_param_TimeStepMethod->text()));
    if(!init_ftdt_param_CellConstantMaterial->text().isEmpty())
        init_fdtd_line.append(QString("CellConstantMaterial, %1, ").arg(init_ftdt_param_CellConstantMaterial->text()));
    init_fdtd_line.chop(2);

    return init_fdtd_line;
}


void PageBasicSimSetup::OnFDTDSettings()
{
    window_fdtd_setings->show();
}

void PageBasicSimSetup::OnCloseFDTDSettings()
{
    window_fdtd_setings->close();
}