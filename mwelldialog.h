#ifndef MWELLDIALOG_H
#define MWELLDIALOG_H

#include <QDialog>
#include <QDebug>

#include "modwellcompletionsdialog.h"
#include "modwellcontrolsdialog.h"
#include "modwellvariablesdialog.h"

namespace Ui {
class MWellDialog;
}

/*!
 * \brief The MWellDialog class
 *
 *
 *
 */

class MWellDialog : public QDialog{
    Q_OBJECT

public:
    explicit MWellDialog(QWidget *parent = 0);
    ~MWellDialog();


private slots:

    //Signal methods (reacts to user action).
    void on_mWellDefinitionTypeComboBox_currentTextChanged(const QString &def_type);//!< Enable/disable elements bades in definition type.
    void on_mWellSpecVariablesCheckBox_clicked(); //!< Enable/disable Variables elements based on user action.
    void on_mWellSetControlsButton_clicked(); //!< Activate Control dialog (setmodal).
    void on_mWellSetCompletionsButton_clicked(); //!< Activate Completion dialog (setmodal).
    void on_mWellSetVariablesButton_clicked(); //!< Activate Variables dialog (setmodal).
    void on_buttonBox_accepted(); // NOT FINISHED //!< Click 'OK', send data to Settings object.
    void on_buttonBox_rejected(); //NOT FINISHED//!< Click 'Cancel', reset GUI-data to previous state.

    void setupMWellDialogs(); //!< Setup ui, and set window title for mwell dialog. Create Controls, Completions, and Variables objects.


private:
    Ui::MWellDialog *uiModWell;

    ModWellCompletionsDialog *mWellCompletionsDialog;
    ModWellControlsDialog *mWellControlsDialog;
    ModWellVariablesDialog *mWellVariablesDialog;

};

#endif // MWELLDIALOG_H
