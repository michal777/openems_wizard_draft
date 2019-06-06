#include "VariablesEditor.h"
#include <QDebug>

VariablesEditor::VariablesEditor(QWizard *parent): QDialog(parent)
{
    var_table = new QTableWidget(this);
    this->resize(QSize(300, 300));
    var_table->setRowCount(100);
    var_table->setColumnCount(3);

    QStringList table_header;
    table_header << "variable" << "expression" << "value";
    var_table->setHorizontalHeaderLabels(table_header);
    var_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVBoxLayout *centralLayout = new QVBoxLayout(this);
    centralLayout->addWidget(var_table);

    connect(var_table, SIGNAL(itemSelectionChanged()), this, SLOT(OnEvaluateVarTable()));

}


void VariablesEditor::OnEvaluateVarTable()
{
    QString line_var;
    QString line_value;
    QScriptEngine expr_eval;
   // QJSEngine myEngine;
    QScriptValue expr_value[tablesize];

    QString table_line;
    QTableWidgetItem *line_var_tmp, *line_value_tmp;
    int i_expr = 0;
    int all_valid = 1;
    int timeout = 1000;

do
{
    for(i_expr = 0; i_expr < tablesize; ++i_expr)
    {

        line_var_tmp = var_table->item(i_expr, 0);
        line_value_tmp = var_table->item(i_expr, 1);
        if((line_var_tmp != NULL) && (line_value_tmp != NULL))
        {
            line_var = line_var_tmp->text();
            line_value = line_value_tmp->text();
            table_line.clear();
            table_line.append(QString("%1 = %2").arg(line_var).arg(line_value));
            expr_value[i_expr] = expr_eval.evaluate(table_line);
            QTableWidgetItem *line_output_val_tmp = new QTableWidgetItem(0);
            line_output_val_tmp->setText(expr_value[i_expr].toString());
            var_table->setItem(i_expr, 2, line_output_val_tmp);
            if(expr_value[i_expr].isError())
                all_valid = 0;
        }
    }
    timeout--;
} while(all_valid == 0 && timeout);

    qDebug("value0=%s", qUtf8Printable(expr_value[0].toString()));
    qDebug("value1=%s", qUtf8Printable(expr_value[1].toString()));
    qDebug("value2=%s", qUtf8Printable(expr_value[2].toString()));
    qDebug("value3=%s", qUtf8Printable(expr_value[3].toString()));
    qDebug("value4=%s", qUtf8Printable(expr_value[4].toString()));

}
