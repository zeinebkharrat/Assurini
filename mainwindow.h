#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_label_2_linkActivated(const QString &link);

    void on_Agent_clicked();

    void on_Client_clicked();

    void on_Contrat_clicked();

    void on_Reclamation_clicked();

    void on_Evenement_clicked();

    void on_comboBox_5_currentIndexChanged(int index);

    void on_home_clicked();

   // void on_radioButton_4_clicked();



    void on_pushButton_AJOUTER_EVENEMET_clicked();

    void afficherEVENEMENTS();

    void on_pushButton_MODIFIER_EVENEMET_clicked();

    void on_pushButton_SUPPRIMER_EVENEMET_clicked();

    void on_RECHERCHE_EV_clicked();

    void on_PDF_2_clicked();

    void on_radioButton_AJOUT_EV_clicked();

    void on_radioButton_Modifier_EV_clicked();
    void UPDATEPLACEHOLDER_RECHERCHE();
    void on_pushButton_refresh_EV_clicked();

private:

    Ui::MainWindow *ui;
    QPushButton *pushButton_AJOUTER_EVENEMET ;
    QTableWidget *tableWidget;
    QPushButton *pushButton_MODIFIER_EVENEMET ;
    QPushButton *pushButton_SUPPRIMER_EVENEMET ;
    QPushButton* RECHERCHE_EV;


};
#endif // MAINWINDOW_H
