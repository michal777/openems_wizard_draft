#include "page_basic_sim_setup.h"
#include <QDebug>
PageBasicSimSetup::PageBasicSimSetup(QWizard *parent)
{
    text_save_to_simscript = new QString;

    QVBoxLayout *layout_page_basic_sim_setup = new QVBoxLayout();
    ConfigSimPar();
    ConfigSimBox();
    layout_page_basic_sim_setup->addWidget(group_box_sim_par);
    layout_page_basic_sim_setup->addWidget(group_box_sim_box);
    setLayout(layout_page_basic_sim_setup);
}

bool PageBasicSimSetup::validatePage()
{
    SaveToSimScriptBuffer();
    return true;
}

void PageBasicSimSetup::SaveToSimScriptBuffer(void)
{
    text_save_to_simscript->clear();

    text_save_to_simscript->append("physical_constants;\n");
    text_save_to_simscript->append(QString("unit = %1;\n").arg(GetUnitMultiplier()));
    text_save_to_simscript->append(QString("fmin = %1 * %2;\n").arg(text_fmin->text()).arg(GetFreqMultiplier()));
    text_save_to_simscript->append(QString("fmax = %1 * %2;\n").arg(text_fmax->text()).arg(GetFreqMultiplier()));

    qDebug("%s", qUtf8Printable(*text_save_to_simscript));
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

    QLabel *statictext_unit = new QLabel("unit", this);
    combo_unit = new QComboBox(this);
    combo_unit->addItem("m");
    combo_unit->addItem("mm");
    combo_unit->addItem("um");

    QLabel *statictext_freq = new QLabel("frequency", this);
    text_fmin = new QLineEdit(this);
    QLabel *statictext_freqhypen = new QLabel(" - ", this);
    text_fmax = new QLineEdit(this);
    combo_frequnit = new QComboBox(this);
    combo_frequnit->addItem("GHz");
    combo_frequnit->addItem("MHz");
    combo_frequnit->addItem("kHz");
    combo_frequnit->addItem("Hz");

    grid_sim_par->addWidget(statictext_unit, 0, 0, Qt::AlignRight);
    grid_sim_par->addWidget(combo_unit, 0, 1, Qt::AlignLeft);
    grid_sim_par->addWidget(statictext_freq, 1, 0, Qt::AlignRight);
    grid_sim_par->addWidget(text_fmin, 1, 1, Qt::AlignLeft);
    grid_sim_par->addWidget(statictext_freqhypen, 1, 2, Qt::AlignLeft);
    grid_sim_par->addWidget(text_fmax, 1, 3, Qt::AlignLeft);
    grid_sim_par->addWidget(combo_frequnit, 1, 4, Qt::AlignLeft);

    group_box_sim_par->setLayout(grid_sim_par);
}


void PageBasicSimSetup::ConfigSimBox(void)
{
    group_box_sim_box = new QGroupBox(tr("simulation box"), this);
    grid_sim_box = new QGridLayout(this);
    grid_sim_box->setSizeConstraint(QLayout::SetFixedSize);
    grid_sim_box->setColumnMinimumWidth(3, 50);

    QLabel *statictext_nx = new QLabel("-x", this);
    text_bb_nx = new QLineEdit(this);
    text_bb_nx->setFixedWidth(50);
    combo_bb_nx = new QComboBox(this);
    combo_bb_nx->addItem("PML8");
    combo_bb_nx->addItem("PEC");
    combo_bb_nx->addItem("MUR");

    QLabel *statictext_px = new QLabel("+x", this);
    text_bb_px = new QLineEdit(this);
    text_bb_px->setFixedWidth(50);
    combo_bb_px = new QComboBox(this);
    combo_bb_px->addItem("PML8");
    combo_bb_px->addItem("PEC");
    combo_bb_px->addItem("MUR");

    QLabel *statictext_ny = new QLabel("-y", this);
    text_bb_ny = new QLineEdit(this);
    text_bb_ny->setFixedWidth(50);
    combo_bb_ny = new QComboBox(this);
    combo_bb_ny->addItem("PML8");
    combo_bb_ny->addItem("PEC");
    combo_bb_ny->addItem("MUR");

    QLabel *statictext_py = new QLabel("+y", this);
    text_bb_py = new QLineEdit(this);
    text_bb_py->setFixedWidth(50);
    combo_bb_py = new QComboBox(this);
    combo_bb_py->addItem("PML8");
    combo_bb_py->addItem("PEC");
    combo_bb_py->addItem("MUR");

    QLabel *statictext_nz = new QLabel("-z", this);
    text_bb_nz = new QLineEdit(this);
    text_bb_nz->setFixedWidth(50);
    combo_bb_nz = new QComboBox(this);
    combo_bb_nz->addItem("PML8");
    combo_bb_nz->addItem("PEC");
    combo_bb_nz->addItem("MUR");

    QLabel *statictext_pz = new QLabel("+z", this);
    text_bb_pz = new QLineEdit(this);
    text_bb_pz->setFixedWidth(50);
    combo_bb_pz = new QComboBox(this);
    combo_bb_pz->addItem("PML8");
    combo_bb_pz->addItem("PEC");
    combo_bb_pz->addItem("MUR");


    grid_sim_box->addWidget(statictext_nx, 0, 0, Qt::AlignLeft);
    grid_sim_box->addWidget(text_bb_nx, 0, 1, Qt::AlignLeft);
    grid_sim_box->addWidget(combo_bb_nx, 0, 2, Qt::AlignLeft);
    grid_sim_box->addWidget(statictext_px, 0, 4, Qt::AlignLeft);
    grid_sim_box->addWidget(text_bb_px, 0, 5, Qt::AlignLeft);
    grid_sim_box->addWidget(combo_bb_px, 0, 6, Qt::AlignLeft);

    grid_sim_box->addWidget(statictext_ny, 1, 0, Qt::AlignLeft);
    grid_sim_box->addWidget(text_bb_ny, 1, 1, Qt::AlignLeft);
    grid_sim_box->addWidget(combo_bb_ny, 1, 2, Qt::AlignLeft);
    grid_sim_box->addWidget(statictext_py, 1, 4, Qt::AlignLeft);
    grid_sim_box->addWidget(text_bb_py, 1, 5, Qt::AlignLeft);
    grid_sim_box->addWidget(combo_bb_py, 1, 6, Qt::AlignLeft);

    grid_sim_box->addWidget(statictext_nz, 2, 0, Qt::AlignLeft);
    grid_sim_box->addWidget(text_bb_nz, 2, 1, Qt::AlignLeft);
    grid_sim_box->addWidget(combo_bb_nz, 2, 2, Qt::AlignLeft);
    grid_sim_box->addWidget(statictext_pz, 2, 4, Qt::AlignLeft);
    grid_sim_box->addWidget(text_bb_pz, 2, 5, Qt::AlignLeft);
    grid_sim_box->addWidget(combo_bb_pz, 2, 6, Qt::AlignLeft);

    group_box_sim_box->setLayout(grid_sim_box);
}
