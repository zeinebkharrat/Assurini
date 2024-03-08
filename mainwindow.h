#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QRadioButton>
#include <QMainWindow>
#include "agent.h"
#include <QPushButton>
#include <QTabWidget>
#include "client.h"

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

    void on_Agent_clicked();
    void on_Client_clicked();
    void on_Contrat_clicked();
    void on_Reclamation_clicked();
    void on_Evenement_clicked();
    void on_comboBox_5_currentIndexChanged(int index);
    void on_home_clicked();
    void on_radioButton_AJOUT_AGENT_clicked();
    void on_radioButton_Modifier_AGENT_clicked();
    void on_pushButton_AJOUTER_AGENT_clicked();
    void on_pushButton_refresh_clicked();
    void onDeleteButtonClicked(int CIN);
    void onRowUpdateClicked(int CIN);
    void on_pushButton_MODIFIER_AGENT_clicked();
    void UPDATEPLACEHOLDER_RECHERCHE();
    void sort_asc();
    void afficher();
    void on_PDF_clicked();
    void on_radioButton_AJOUT_CLIENT_clicked();
    void on_radioButton_Modifier_CLIENT_clicked();
   void UPDATEPLACEHOLDER_RECHERCHE_CLIENT();
   void on_pushButton_AJOUTER_CLIENT_clicked();
   void onDeleteButtonClicked_CLIENT(int row);
   void onRowUpdateClicked_CLIENT(int row);
   void afficher_CLIENT();

   void on_pushButton_refresh_CLIENT_clicked();

   void on_radioButton_AJOUT_RECLAMTION_clicked();

   void on_radioButton_Modifier_RECLAMATION_clicked();

   void on_radioButton_AJOUT_EV_clicked();

   void on_radioButton_Modifier_EV_clicked();
   void UPDATEPLACEHOLDER_RECHERCHE_EV();
   void on_pushButton_AJOUTER_EVENEMENT_clicked();

   void onRowUpdateClicked_EV(int row);
   void onDeleteButtonClicked_EV(int row);
   void on_pushButton_refresh_EV_clicked();

private:


    Ui::MainWindow *ui;
    QRadioButton *radioButton_AJOUT_AGENT;
    QRadioButton *radioButton_Modifier_AGENT;
    QPushButton *pushButton_SUPPIMER;
    QTabWidget *tableWidget;

};
#endif // MAINWINDOW_H
