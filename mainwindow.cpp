#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenements.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QSqlRecord>
#include <QString>
#include <QDebug>
#include <QMediaPlayer>
#include <QPixmap>
#include <QTableWidget>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtSql>
#include <QStandardItem>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherEVENEMENTS();
    // Create a fade-out animation
    QPropertyAnimation *fadeOutAnimation = new QPropertyAnimation(ui->sidebar_A, "windowOpacity");
    fadeOutAnimation->setStartValue(1.0);
    fadeOutAnimation->setEndValue(0.0);
    fadeOutAnimation->setDuration(500);

    // Create a fade-in animation
    QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(ui->sidebar_A, "windowOpacity");
    fadeInAnimation->setStartValue(0.0);
    fadeInAnimation->setEndValue(1.0);
    fadeInAnimation->setDuration(500);  // Set the duration in milliseconds

    // Connect the button click to start the fade-out or fade-in animation
    connect(ui->pushButton_2, &QPushButton::clicked, [=]() {
        if (ui->sidebar_A->isVisible()) {
            // If the frame is visible, start fade-out animation
            fadeOutAnimation->start();
            ui->groupBox->move(210,80);
            ui->groupBox_6->move(310,890);
            ui->groupBox_3->move(210,80);

        } else {
            // If the frame is not visible, set opacity to 0 and show the frame, then start fade-in animation
            ui->sidebar_A->setWindowOpacity(0.0);
            ui->sidebar_A->show();
            fadeInAnimation->start();
            ui->groupBox->move(410,80);
            ui->groupBox_6->move(480,890);
            ui->groupBox_3->move(400,150);
        }
    });

    // Connect the finished signal of the fade-out animation to hide the frame
    connect(fadeOutAnimation, &QPropertyAnimation::finished, [&]() {
        ui->sidebar_A->hide();
    });

    // Connect the stateChanged signal to detect when the fade-in animation starts and set opacity to 1.0
    connect(fadeInAnimation, &QPropertyAnimation::stateChanged, [&](QAbstractAnimation::State newState, QAbstractAnimation::State oldState) {
        if (newState == QAbstractAnimation::Running && oldState == QAbstractAnimation::Stopped) {
            ui->sidebar_A->setWindowOpacity(1.0);
        }
    });
    // Connecter le signal currentIndexChanged de comboBox au slot on_comboBox_currentIndexChanged0
   connect(ui->comboBox_5, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));
   //contrat//voyage
   ui->comboBox_voyage->addItem("Standard");
   ui->comboBox_voyage->addItem("Aventure");
   ui->comboBox_voyage->addItem("Affaires");
   ui->comboBox_option->addItem("Tout Risques");
   ui->comboBox_option->addItem("Bagage de valeur");
   //contrat//voiture
   ui->comboBox_voiture->addItem("Véhicules de Luxe");
   ui->comboBox_voiture->addItem("Véhicules Écologiques");
   ui->comboBox_voiture->addItem("Véhicules Anciens/Classique");
   ui->comboBox_voiture->addItem("Véhicule de Sport");
   ui->comboBox_voiture->addItem("Minifourgonnettes");
   ui->comboBox_option_voiture->addItem("Tous Risques");
   ui->comboBox_option_voiture->addItem("Bris de Glace");
   ui->comboBox_option_voiture->addItem("Contre le Vol");
   ui->comboBox_option_voiture->addItem("Catastrophes Naturelles");
   ui->comboBox_option_voiture->addItem("Assistance Routiére");
   //contrat//sante
   ui->comboBox_sante->addItem("Base");
   ui->comboBox_sante->addItem("Intermédiaire");
   ui->comboBox_sante->addItem("Premium");
   ui->comboBox_option_sante->addItem("Assurance Dentaire");
   ui->comboBox_option_sante->addItem("Assurance Vision");
   ui->comboBox_option_sante->addItem("Soins de Maternité");
   ui->comboBox_option_sante->addItem("Assurance Soins à Domicile ");
   ui->comboBox_option_sante->addItem("Assurance Maladies Graves");
   ui->comboBox_option_sante->addItem("Assurance Hospitalisation");
   ui->comboBox_option_sante->addItem("Assurance Soins de Santé Mentale");
   //contrat//habitation
   ui->comboBox_habitation->addItem("Bâtiment Résidentiel");
   ui->comboBox_habitation->addItem("Bâtiment Commercial");
   ui->comboBox_habitation->addItem("Bâtiment Industriel");
   ui->comboBox_habitation->addItem("Bâtiment Agricole");
   ui->comboBox_habitation->addItem("Bâtiment Institutionnel");
   ui->comboBox_habitation->addItem("Bâtiment Historique");
   ui->comboBox_habitation->addItem("Bâtiment Mixte");
   ui->comboBox_option_habitaion->addItem("Frais de Relogement");
   ui->comboBox_option_habitaion->addItem("Assurance pour Objets de Valeur");
   ui->comboBox_option_habitaion->addItem("Couverture des Équipements Électroniques");
   ui->comboBox_option_habitaion->addItem("Service de Protection Juridique ");
   ui->comboBox_option_habitaion->addItem("Couverture des Pertes de Jardin ");
   ui->comboBox_option_habitaion->addItem("Catastrophes Naturelles");
   ui->comboBox_option_habitaion->addItem("Couverture des Animaux de Compagnie");
   ui->comboBox_option_habitaion->addItem("Couverture pour Événements Spéciaux");
   //contrat//combobox
   ui->comboBox_5->addItem(QIcon(":/img/img/voiture.png"),"Voiture");
   ui->comboBox_5->addItem(QIcon(":/img/img/habitation.png"),"Habitation");
   ui->comboBox_5->addItem(QIcon(":/img/img/santé.png"),"Santé");
   ui->comboBox_5->addItem(QIcon(":/img/img/voyage.png"),"Voyage");
    ui->pushButton_MODIFIER_EVENEMET->setVisible(false);

    //combobox_recherche
            QModelIndex index = ui->comb_recherche->model()->index(0, 0);
            QVariant v(0);
            ui->comb_recherche->model()->setData(index, v, Qt::UserRole - 1);
            connect(ui->comb_recherche, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::UPDATEPLACEHOLDER_RECHERCHE);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//******** redirection depuis module Agent *****************//


void MainWindow::on_Agent_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Client_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_Contrat_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
       ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Reclamation_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_Evenement_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
     ui->stackedWidget_2->setCurrentIndex(index);
}

void MainWindow::on_home_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
       player->setMedia(QUrl("qrc:/img/img/click.wav"));
       player->play();
     ui->stackedWidget->setCurrentIndex(1);
}




void MainWindow::afficherEVENEMENTS()
{
    EVENEMENTS e;
    QSqlQueryModel *model = e.afficher();

    //ui->tableWidget->clearContents();  // Nettoyer le contenu existant

    ui->tableWidget_EV->setRowCount(model->rowCount());
    ui->tableWidget_EV->setColumnCount(model->columnCount() + 2);

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_EV->setItem(row, col, item);
        }
        // Ajouter le bouton "Supprimer"
                QPushButton *btnSupprimer = new QPushButton("Supprimer", this);
                connect(btnSupprimer, &QPushButton::clicked, [this, row, &e] {
                    QString EVENEMENTASupprimer = ui->tableWidget_EV->item(row, 0)->text();  // ID_CONTRAT
                    if (e.supprimer(EVENEMENTASupprimer)) {
                        QMessageBox::information(this, "Succès", "Contrat supprimé avec succès.");
                        e.afficher();
                    } else {
                        QMessageBox::warning(this, "Erreur", "Échec de la suppression du contrat.");
                    }
                });

                // Ajouter le bouton "Modifier"
               /* QPushButton *btnModifier = new QPushButton("Modifier", this);
                connect(btnModifier, &QPushButton::clicked, [this, row] {
                  //  on_btnModifierClicked(row);
                });*/
                ui->tableWidget_EV->setCellWidget(row, model->columnCount(), btnSupprimer);
                       // ui->tableWidget_EV->setCellWidget(row, model->columnCount() + 1, btnModifier);
    }
}


void MainWindow::on_pushButton_AJOUTER_EVENEMET_clicked()
{

    QString NOM = ui->lineEdit_NOM_EVENEMENT->text();

    QString DESCRIPTION = ui->lineEdit_DESCRIPTION->text();
    QDate DATE_EVENEMENT = ui->dateEdit_DATE_EVENEMENT->date();
    QString LIEU_EVENEMET = ui->lineEdit_LIEU_EVENEMENT->text();
    int NB_INVITATIONS = ui->spinBox_NB_INVITATION->text().toInt();
    int BUDGET = ui->lineEdit_BUDGET->text().toInt();

    EVENEMENTS EVENEMENT (NOM ,DESCRIPTION, DATE_EVENEMENT, LIEU_EVENEMET, NB_INVITATIONS,BUDGET) ;

    if (EVENEMENT.ajouter()) {
        afficherEVENEMENTS();
    QMessageBox::information(this, "Succès", "evenemet ajouté avec succès.");

    }else {
    QMessageBox::warning(this, "Erreur", "Échec de l'ajout de l'evenemet.");

}
}




void MainWindow::on_pushButton_MODIFIER_EVENEMET_clicked()
{
    // Récupérer les valeurs à partir des éléments d'interface utilisateur
    QString NOM = ui->lineEdit_NOM_EVENEMENT->text();
    QString DESCRIPTION = ui->lineEdit_DESCRIPTION->text();
    QDate DATE_EVENEMENT = ui->dateEdit_DATE_EVENEMENT->date();
    QString LIEU_EVENEMENT = ui->lineEdit_LIEU_EVENEMENT->text();
    int NB_INVITATIONS = ui->spinBox_NB_INVITATION->value();
    int BUDGET = ui->lineEdit_BUDGET->text().toInt();

    // Modifier l'événement dans la base de données
    EVENEMENTS event;
    if (event.modifier(NOM, DESCRIPTION, DATE_EVENEMENT, LIEU_EVENEMENT, NB_INVITATIONS, BUDGET)) {
        QMessageBox::information(this, "Succès", "Événement modifié avec succès.");

        // Réafficher les événements dans le tableau d'affichage
        afficherEVENEMENTS();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification de l'événement.");
    }
}


void MainWindow::on_pushButton_SUPPRIMER_EVENEMET_clicked()
{
    // Récupérer le nom de l'événement à supprimer
    QString nomEvenementASupprimer = ui->lineEdit_NOM_EVENEMENT->text();

    // Supprimer l'événement dans la base de données
    EVENEMENTS event;
    if (event.supprimer(nomEvenementASupprimer)) {
        QMessageBox::information(this, "Succès", "Événement supprimé avec succès.");

        // Réafficher les événements dans le tableau d'affichage
        afficherEVENEMENTS();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de l'événement.");
    }
}


void MainWindow::on_RECHERCHE_EV_clicked()
{
    // Obtenez le texte saisi dans le champ de recherche
    QString NOM = ui->lineEdit_RECH_EV->text();

    // Créez une instance de la classe EVENEMENTS
    EVENEMENTS event;

    // Appelez la fonction rechercher à partir de l'instance EVENEMENTS
    QSqlQueryModel *resultatRecherche = event.rechercher(NOM);

    // Effacer le contenu actuel du QTableWidget
   // ui->dateEdit_DATE_EVENEMENT->clearContents();
    ui->dateEdit_DATE_EVENEMENT->clear();


    // Parcourir le modèle de résultats et remplir le QTableWidget
    if (resultatRecherche) {
        for (int row = 0; row < resultatRecherche->rowCount(); ++row) {
            for (int column = 0; column < resultatRecherche->columnCount(); ++column) {
                QTableWidgetItem *item = new QTableWidgetItem(resultatRecherche->data(resultatRecherche->index(row, column)).toString());
                ui->tableWidget_EV->setItem(row, column, item);
            }
        }
    } else {
        qDebug() << "Aucun résultat trouvé.";
    }
}

/*

void MainWindow::on_PDF_2_clicked()
{
    QString NOM = ui->lineEdit_10->text();
    EVENEMENTS e;
    QSqlQueryModel *resultatRecherche = e.rechercher(NOM);
    e.exporterPDF(resultatRecherche);
    QMessageBox::information(this, "Exportation PDF", "Les événements ont été exportés vers un fichier PDF.");
}
*/

void MainWindow::on_PDF_2_clicked()
{
    QString NOM = ui->lineEdit_10->text();
    EVENEMENTS e;
    QSqlQueryModel *resultatRecherche = e.rechercher(NOM);
    e.exporterPDF(resultatRecherche);
    QMessageBox::information(this, "Exportation PDF", "Les événements ont été exportés vers un fichier PDF.");
}

void MainWindow::on_radioButton_AJOUT_EV_clicked()
{
    ui->pushButton_AJOUTER_EVENEMET->setVisible(true);
    ui->pushButton_MODIFIER_EVENEMET->setVisible(false);
}

void MainWindow::on_radioButton_Modifier_EV_clicked()
{
     ui->pushButton_AJOUTER_EVENEMET->setVisible(false);
     ui->pushButton_MODIFIER_EVENEMET->setVisible(true);
}
void MainWindow::UPDATEPLACEHOLDER_RECHERCHE(){


        if(ui->comb_recherche->currentText()=="Nom"){
       ui->lineEdit_RECH_EV->setPlaceholderText("rechercher un agent à partir de son Nom");
        }
        if(ui->comb_recherche->currentText()=="Budget "){
       ui->lineEdit_RECH_EV->setPlaceholderText("rechercher un agent à partir de son Budget");
        }
        if(ui->comb_recherche->currentText()=="Nombre d'invitation "){
        ui->lineEdit_RECH_EV->setPlaceholderText("rechercher un agent à partir de son Nombre d'invitation");
        }
        if(ui->comb_recherche->currentText()=="Lieu de l'événement "){
        ui->lineEdit_RECH_EV->setPlaceholderText("rechercher un agent à partir de son Lieu de l'événement");
        }
}

void MainWindow::on_pushButton_refresh_EV_clicked()
{
    EVENEMENTS e;
    QSqlQueryModel *model = e.afficher();

    //ui->tableWidget->clearContents();  // Nettoyer le contenu existant

    ui->tableWidget_EV->setRowCount(model->rowCount());
    ui->tableWidget_EV->setColumnCount(model->columnCount());

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_EV->setItem(row, col, item);
        }
    }
}
