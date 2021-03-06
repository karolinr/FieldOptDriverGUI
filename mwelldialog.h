#ifndef MWELLDIALOG_H
#define MWELLDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

#include "modwellcompletionsdialog.h"
#include "modwellcontrolsdialog.h"
#include "modwellvariablesdialog.h"
#include "Utilities/settings/model.h"


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
    // want to use directly .... follow Einar's tip
    void setMWellsVariables(QList<Utilities::Settings::Model::Well> wells); //!< Use when importing, and reset well dialogs to previous state if click 'cancel'.


private slots:

    //Signal methods (reacts to user action).
    void on_mWellDefinitionTypeComboBox_currentTextChanged(const QString &def_type);//!< Enable/disable elements bades in definition type.
    void on_mWellSpecVariablesCheckBox_toggled(bool checked); //!< Enable/disable Variables elements based on user action.
    void on_mWellSetControlsButton_clicked(); //!< Activate Control dialog (setmodal).
    void on_mWellSetCompletionsButton_clicked(); //!< Activate Completion dialog (setmodal).
    void on_mWellSetVariablesButton_clicked(); //!< Activate Variables dialog (setmodal).
    void on_mWellAddBlockButton_clicked(); //!< Run addWellBlock(). Add new well block to the tableWigdet.
    void on_buttonBox_accepted(); // NOT FINISHED //!< Click 'OK', send data to Settings object.
    void on_buttonBox_rejected(); //NOT FINISHED//!< Click 'Cancel', reset GUI-data to previous state.

    void setupMWellDialogs(); //!< Setup ui, and set window title for mwell dialog. Create Controls, Completions, and Variables objects.
    void setToolTips(); //!< Set tool tip for all elements in mwell dialog.
    void initializeMWellDialogElements(); //!< Set, and initialize diverse elements, setHidden, enabled etc.
    void addWellBlock(); //!< Add new well block to Well blocks table widget. Used in on_mWellAddBlockButton_clicked().
    bool isDefinitionTypeWellBlock(); //!< True if the definition type is Well block (false if 'well spline').

private:
    Ui::MWellDialog *uiModWell;

    ModWellCompletionsDialog *mWellCompletionsDialog;
    ModWellControlsDialog *mWellControlsDialog;
    ModWellVariablesDialog *mWellVariablesDialog;

    QList<Utilities::Settings::Model::Well> wells_;
};

#endif // MWELLDIALOG_H
