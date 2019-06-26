#ifndef VARIABLESEDITOR_H
#define VARIABLESEDITOR_H

#include <QWizard>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QSettings>
#include <QDialog>
#include <QTableWidget>
#include <QScriptEngine>
#include <QHeaderView>

class VariablesEditor : public QDialog
{
    Q_OBJECT
public:
    VariablesEditor(QWizard *parent);

    QTableWidget *var_table;

    static const int tablesize = 100;
    QScriptEngine *expr_eval;
    QScriptValue expr_value[tablesize];

    QTableWidget *GetVarTable(void) {return var_table;}
    QScriptEngine *GetExprEngine(void) {return expr_eval;}

public slots:
    void OnEvaluateVarTable();

    void qwer(int a);
signals:
    void VarEdit(void);
};

#endif // VARIABLESEDITOR_H
