#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agent.h"
#include "client.h"
#include "events.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QSqlRecord>
#include <QString>
#include <QDebug>
#include <QMediaPlayer>
#include <QPixmap>
#include <QDate>
#include <QRegExpValidator>
#include <QTabWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{

    ui->setupUi(this);
        //QStandardItemModel *model = new QStandardItemModel(this);
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
            ui->groupBox->move(150,80);
            ui->groupBox_6->move(220,890);
            ui->groupBox_CLIENT->move(150,80);
            ui->groupBox_CLIENT_ajouter->move(220,890);
        } else {
            // If the frame is not visible, set opacity to 0 and show the frame, then start fade-in animation
            ui->sidebar_A->setWindowOpacity(0.0);
            ui->sidebar_A->show();
            fadeInAnimation->start();
            ui->groupBox->move(410,80);
            ui->groupBox_6->move(480,890);
            ui->groupBox_CLIENT->move(390,80);
            ui->groupBox_CLIENT_ajouter->move(480,980);

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



   // Initialize the table widget
       ui->tableWidget_AGENT->setColumnCount(11); // Increase column count to accommodate the delete button
       ui->tableWidget_AGENT->setHorizontalHeaderLabels(QStringList() << "CIN" << "NOM" << "PRENOM" << "ADRESSE" << "EMAIL" << "GENRE" << "TELEPHONE" << "DEPARTEMENT"<< "DATE" << "DELETE" << "UPDATE");
       ui->tableWidget_AGENT->horizontalHeader()->setVisible(true);
       // Set row height
       //int rowHeight = 70; // Adjust this value as needed
       //int rowWidth = 120; // Adjust this value as needed

       ui->tableWidget_AGENT->verticalHeader()->setDefaultSectionSize(100);
      ui->tableWidget_AGENT->horizontalHeader()->setFixedHeight(100);
      // Styles pour les en-têtes
      QString headerStylesheet = "QHeaderView::section { background-color: #4CAF50; color: white; padding: 5px; }";
      ui->tableWidget_AGENT->horizontalHeader()->setStyleSheet(headerStylesheet);

      QFont headerFont = ui->tableWidget_AGENT->horizontalHeader()->font();
      headerFont.setPointSize(14); // Remplacez "taille_voulue" par la taille de police souhaitée
      ui->tableWidget_AGENT->horizontalHeader()->setFont(headerFont);
       // Set individual column widths based on your preferences
       ui->tableWidget_AGENT->setColumnWidth(0,110 );   // CIN
       ui->tableWidget_AGENT->setColumnWidth(1, 110);   // NOM
       ui->tableWidget_AGENT->setColumnWidth(2, 110);   // PRENOM
       ui->tableWidget_AGENT->setColumnWidth(3, 100);   // ADRESSE
       ui->tableWidget_AGENT->setColumnWidth(4, 190);   // MAIL
       ui->tableWidget_AGENT->setColumnWidth(5, 100);   // GENRE
       ui->tableWidget_AGENT->setColumnWidth(6, 120);   // TELEPHONE
       ui->tableWidget_AGENT->setColumnWidth(7, 190);   // DEPARTEMENT
       ui->tableWidget_AGENT->setColumnWidth(8, 130);   // DATE_DE_NAISSANCE
       ui->tableWidget_AGENT->setColumnWidth(9, 140);   // DELETE button
       ui->tableWidget_AGENT->setColumnWidth(10, 140);


       //les buttons par defaut
       ui->pushButton_MODIFIER_AGENT->setVisible(false);
       ui->pushButton_MODIFIER_CLIENT->setVisible(false);
       ui->pushButton_MODIFIER_RECLAMATION->setVisible(false);
       ui->pushButton_MODIFIERR_EVENEMENT->setVisible(false);
        //combobox_recherche agent
        QModelIndex index = ui->comboBox_recherche->model()->index(0, 0);
        QVariant v(0);
        ui->comboBox_recherche->model()->setData(index, v, Qt::UserRole - 1);
        connect(ui->comboBox_recherche, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::UPDATEPLACEHOLDER_RECHERCHE);
        //combobox tri agent
        QModelIndex index1 = ui->TRI->model()->index(0, 0);
        QVariant w(0);
        ui->TRI->model()->setData(index1, w, Qt::UserRole - 1);
       connect(ui->TRI, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::sort_asc);
        //combox recherche client
       QModelIndex index2= ui->comboBox_recherche_CLIENT->model()->index(0, 0);
       QVariant z(0);
       ui->comboBox_recherche_CLIENT->model()->setData(index2, z, Qt::UserRole - 1);
       connect(ui->comboBox_recherche_CLIENT, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::UPDATEPLACEHOLDER_RECHERCHE_CLIENT);
       // combobox tri client
       QModelIndex index3= ui->TRI_CLIENT->model()->index(0, 0);
       QVariant y(0);
       ui->TRI_CLIENT->model()->setData(index3, y, Qt::UserRole - 1);
       //combobox_recherche evenement
               QModelIndex index4 = ui->comb_recherche->model()->index(0, 0);
               QVariant t(0);
               ui->comb_recherche->model()->setData(index4, t, Qt::UserRole - 1);
               connect(ui->comb_recherche, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::UPDATEPLACEHOLDER_RECHERCHE_EV);


       // Initialize the table widget
          ui->tableWidget_CLIENT->setColumnCount(11); // Increase column count to accommodate the delete button
          ui->tableWidget_CLIENT->setHorizontalHeaderLabels(QStringList() << "CIN" << "NOM" << "PRENOM" << "NUM" << "EMAIL" << "DATE" << "GENRE" << "JOB" << "RIB" << "DELETE" << "UPDATE");
          ui->tableWidget_CLIENT->horizontalHeader()->setVisible(true);
           // Set row height
           //int rowHeight = 70; // Adjust this value as needed
           //int rowWidth = 120; // Adjust this value as needed

          ui->tableWidget_CLIENT->verticalHeader()->setDefaultSectionSize(100);
          ui->tableWidget_CLIENT->horizontalHeader()->setFixedHeight(100);
          // Styles pour les en-têtes
          QString headerStylesheet1 = "QHeaderView::section { background-color: #4CAF50; color: white; padding: 5px; }";
          ui->tableWidget_CLIENT->horizontalHeader()->setStyleSheet(headerStylesheet);

          QFont headerFont1 = ui->tableWidget_CLIENT->horizontalHeader()->font();
          headerFont.setPointSize(14);
          ui->tableWidget_CLIENT->horizontalHeader()->setFont(headerFont);
           // Set individual column widths based on your preferences
           ui->tableWidget_CLIENT->setColumnWidth(0,110 );   // CIN
           ui->tableWidget_CLIENT->setColumnWidth(1, 110);   // NOM
           ui->tableWidget_CLIENT->setColumnWidth(2, 110);   // PRENOM
           ui->tableWidget_CLIENT->setColumnWidth(3, 100);   // ADRESSE
           ui->tableWidget_CLIENT->setColumnWidth(4, 190);   // MAIL
           ui->tableWidget_CLIENT->setColumnWidth(5, 100);   // GENRE
           ui->tableWidget_CLIENT->setColumnWidth(6, 120);   // TELEPHONE
           ui->tableWidget_CLIENT->setColumnWidth(7, 190);   // DEPARTEMENT
           ui->tableWidget_CLIENT->setColumnWidth(8, 130);   // DATE_DE_NAISSANCE
           ui->tableWidget_CLIENT->setColumnWidth(9, 120);   // DELETE button
           ui->tableWidget_CLIENT->setColumnWidth(10, 120);


           // Initialize the table widget
               ui->tableWidget_EV->setColumnCount(8); // Increase column count to accommodate the delete button
               ui->tableWidget_EV->setHorizontalHeaderLabels(QStringList()  << "NOM" << "LIEU" << "DATE" << "NB INVI" << "BUDGET" << "DESCRIPTION" << "DELETE" << "UPDATE");
               ui->tableWidget_EV->horizontalHeader()->setVisible(true);
               // Set row height
               //int rowHeight = 70; // Adjust this value as needed
               //int rowWidth = 120; // Adjust this value as needed

               ui->tableWidget_EV->verticalHeader()->setDefaultSectionSize(100);
              ui->tableWidget_EV->horizontalHeader()->setFixedHeight(100);
              // Styles pour les en-têtes
              QString headerStylesheet2 = "QHeaderView::section { background-color: #4CAF50; color: white; padding: 5px; }";
              ui->tableWidget_EV->horizontalHeader()->setStyleSheet(headerStylesheet);

              QFont headerFont2 = ui->tableWidget_EV->horizontalHeader()->font();
              headerFont.setPointSize(12); // Remplacez "taille_voulue" par la taille de police souhaitée
              ui->tableWidget_EV->horizontalHeader()->setFont(headerFont2);
               // Set individual column widths based on your preferences
               ui->tableWidget_EV->setColumnWidth(0,110 );
               ui->tableWidget_EV->setColumnWidth(1, 110);
               ui->tableWidget_EV->setColumnWidth(2, 110);
               ui->tableWidget_EV->setColumnWidth(3, 100);
               ui->tableWidget_EV->setColumnWidth(4, 120);
               ui->tableWidget_EV->setColumnWidth(5, 190);
               ui->tableWidget_EV->setColumnWidth(6, 120);
               ui->tableWidget_EV->setColumnWidth(7, 140);
               ui->tableWidget_EV->setColumnWidth(8, 130);


}
MainWindow::~MainWindow()
{
    delete ui;
}



//******** redirection depuis module Agent *****************//

//sid bar start
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
//sid bar start
void MainWindow::on_radioButton_AJOUT_AGENT_clicked()
{
     ui->pushButton_MODIFIER_AGENT->setVisible(false);
    ui->groupBox->setTitle("Ajouter un Agent");
    ui->lineEdit_CIN->setPlaceholderText("Entrez votre CIN");
    ui->lineEdit_NOM->setPlaceholderText("Entrez votre NOM");
    ui->lineEdit_PRENOM->setPlaceholderText("Entrez votre PRENOM");
    ui->lineEdit_ADRESSE->setPlaceholderText("Entrez votre ADRESSE");
    ui->lineEdit_NUM_TEL->setPlaceholderText("Entrez votre NUM");
    ui->lineEdit_MAIL->setPlaceholderText("Entrez votre MAIL");

}
void MainWindow::on_radioButton_Modifier_AGENT_clicked()
{
    on_pushButton_refresh_clicked();
    ui->pushButton_MODIFIER_AGENT->setVisible(true);
    ui->groupBox->setTitle("Modifier un Agent");
    ui->lineEdit_CIN->setPlaceholderText("");
    ui->lineEdit_NOM->setPlaceholderText("");
    ui->lineEdit_PRENOM->setPlaceholderText("");
    ui->lineEdit_ADRESSE->setPlaceholderText("");
    ui->lineEdit_NUM_TEL->setPlaceholderText("");
    ui->lineEdit_MAIL->setPlaceholderText("");

}
void MainWindow::on_pushButton_AJOUTER_AGENT_clicked()
{
    // Actualiser les données du tableau
    on_pushButton_refresh_clicked();

    // Récupérer les valeurs des champs
    QString cinString = ui->lineEdit_CIN->text().trimmed();
    int CIN = cinString.toInt();
    QString telephoneString = ui->lineEdit_NUM_TEL->text().trimmed();
    int TELEPHONE = telephoneString.toInt();
    QDate DATE_DE_NAISSANCE = ui->dateEdit_AGENT->date();
    QString NOM = ui->lineEdit_NOM->text().trimmed();
    QString PRENOM = ui->lineEdit_PRENOM->text().trimmed();
    QString ADRESSE = ui->lineEdit_ADRESSE->text().trimmed();
    QString MAIL = ui->lineEdit_MAIL->text().trimmed();
    QString GENRE = ui->comboBox_GENRE->currentText();
    QString DEPARTEMENT = ui->comboBox_DEPARTEMENT->currentText();

    // Effectuer des vérifications de saisie
    if (cinString.length() != 8 || cinString.toInt() == 0 || !cinString.toInt()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le CIN doit être composé de 8 chiffres.");
        return;  // Sortir de la fonction si le CIN ne respecte pas les critères
    }

    if (telephoneString.length() != 8 || telephoneString.toInt() == 0 || !telephoneString.toInt()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le numéro de téléphone doit être composé de 9 chiffres.");
        return;  // Sortir de la fonction si le numéro de téléphone ne respecte pas les critères
    }

    if (NOM.isEmpty() || PRENOM.isEmpty() || ADRESSE.isEmpty() || MAIL.isEmpty()) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
        return;  // Sortir de la fonction si les champs obligatoires ne sont pas renseignés
    }

    // Vérifier le format de l'adresse e-mail
    QRegularExpression regex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
    if (!regex.match(MAIL).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Format d'adresse e-mail invalide.");
        return;  // Sortir de la fonction si l'adresse e-mail n'est pas valide
    }

    // Créer l'objet AGENT
    AGENT agent(CIN, TELEPHONE, NOM, PRENOM, ADRESSE, MAIL, GENRE, DEPARTEMENT, DATE_DE_NAISSANCE);

    // Ajouter l'agent
    if (agent.ajouter()) {
        // Succès
        QMessageBox::information(this, "Succès", "Agent ajouté avec succès.");
        // Actualiser le modèle du QTableView pour afficher les nouvelles données
        on_pushButton_refresh_clicked();
    } else {
        // Échec
        QMessageBox::critical(this, "Erreur d'ajout", "Échec de l'ajout de l'agent.");
    }
}
void MainWindow::afficher(){
 QSqlQueryModel *model = new QSqlQueryModel();

        // SELECT statement to retrieve data from the database
        model->setQuery("SELECT CIN,  NOM, PRENOM, ADRESSE, MAIL, GENRE, TELEPHONE, DEPARTEMENT, TO_CHAR(DATE_DE_NAISSANCE, 'YYYY-MM-DD' ) FROM mahdi.AGENTS ");

        // Set the model to the table widget
        ui->tableWidget_AGENT->setRowCount(model->rowCount());
        ui->tableWidget_AGENT->setColumnCount(model->columnCount() + 2); // Add two columns for the delete and update buttons

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem;
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // Make cells read-only

                // Set the text without scientific notation for the CIN and TELEPHONE columns
                if (col == 0 || col == 6) {
                    item->setData(Qt::DisplayRole, QString::number(model->data(model->index(row, col)).toInt()));
                } else {
                    item->setData(Qt::DisplayRole, model->data(model->index(row, col)));
                }

                item->setTextAlignment(Qt::AlignCenter); // Center the text
                ui->tableWidget_AGENT->setItem(row, col, item);
            }

            // Add delete button to the second last column
            QPushButton *deleteButton = new QPushButton("Delete");
            deleteButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: green; }");
            connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            onDeleteButtonClicked(row);
            });
            ui->tableWidget_AGENT->setCellWidget(row, model->columnCount(), deleteButton);

            // Add update button to the last column
            QPushButton *updateButton = new QPushButton("Update");
            updateButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: blue; }");
            connect(updateButton, &QPushButton::clicked, this, [this, row]() {
                onRowUpdateClicked(row); // Call the function to handle row update
            });
            ui->tableWidget_AGENT->setCellWidget(row, model->columnCount() + 1, updateButton);
        }

        delete model;
}
void MainWindow::on_pushButton_refresh_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();

        // SELECT statement to retrieve data from the database
        model->setQuery("SELECT CIN,  NOM, PRENOM, ADRESSE, MAIL, GENRE, TELEPHONE, DEPARTEMENT, TO_CHAR(DATE_DE_NAISSANCE, 'YYYY-MM-DD' ) FROM mahdi.AGENTS ");

        // Set the model to the table widget
        ui->tableWidget_AGENT->setRowCount(model->rowCount());
        ui->tableWidget_AGENT->setColumnCount(model->columnCount() + 2); // Add two columns for the delete and update buttons

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem;
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // Make cells read-only

                // Set the text without scientific notation for the CIN and TELEPHONE columns
                if (col == 0 || col == 6) {
                    item->setData(Qt::DisplayRole, QString::number(model->data(model->index(row, col)).toInt()));
                } else {
                    item->setData(Qt::DisplayRole, model->data(model->index(row, col)));
                }

                item->setTextAlignment(Qt::AlignCenter); // Center the text
                ui->tableWidget_AGENT->setItem(row, col, item);
            }

            // Add delete button to the second last column
            QPushButton *deleteButton = new QPushButton("Delete");
            deleteButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: green; }");
            connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
                onDeleteButtonClicked(row);
            });
            ui->tableWidget_AGENT->setCellWidget(row, model->columnCount(), deleteButton);

            // Add update button to the last column
            QPushButton *updateButton = new QPushButton("Update");
            updateButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: blue; }");
            connect(updateButton, &QPushButton::clicked, this, [this, row]() {
                onRowUpdateClicked(row); // Call the function to handle row update
            });
            ui->tableWidget_AGENT->setCellWidget(row, model->columnCount() + 1, updateButton);
        }

        delete model;
    }
void MainWindow::onDeleteButtonClicked(int row){
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableWidget_AGENT->model());
    QModelIndex index = model->index(row, 0); // Assuming the ID_PRODUIT is in the first column
    int CIN = model->data(index).toInt();

    // Perform deletion from the database
    QSqlQuery query;
    query.prepare("DELETE FROM mahdi.AGENTS WHERE CIN = :CIN");
    query.bindValue(":CIN", CIN);

    if (query.exec()) {
        // Update the table widget after successful deletion
        ui->tableWidget_AGENT->removeRow(row);
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to delete row: ") + query.lastError().text());
    }
}
void MainWindow::onRowUpdateClicked(int row) {

    // Get the ID from the selected row
    int CIN= ui->tableWidget_AGENT->item(row, 0)->text().toInt();
    QString NOM = ui->tableWidget_AGENT->item(row, 1)->text();
    QString PRENOM = ui->tableWidget_AGENT->item(row, 2)->text();
    QString ADRESSE = ui->tableWidget_AGENT->item(row, 3)->text();
    int NUM_TEL = ui->tableWidget_AGENT->item(row, 6)->text().toInt();
    QString EMAIL = ui->tableWidget_AGENT->item(row, 4)->text();
    QDate DATE_DE_NAISSANCE = QDate::fromString(ui->tableWidget_AGENT->item(row, 8)->text(), "yyyy-MM-dd");
    QString GENRE = ui->tableWidget_AGENT->item(row, 6)->text();
    QString DEPARTEMENT = ui->tableWidget_AGENT->item(row, 7)->text();

    // Populate the form fields with the data
    ui->lineEdit_CIN->setText(QString::number(CIN));
    ui->lineEdit_NOM->setText(NOM);
    ui->lineEdit_PRENOM->setText(PRENOM);
    ui->lineEdit_ADRESSE->setText(ADRESSE);
    ui->lineEdit_MAIL->setText(EMAIL);
    int index = ui->comboBox_GENRE->findText(GENRE);
    if (index != -1) {
        ui->comboBox_GENRE->setCurrentIndex(index);
    }
    int index1 = ui->comboBox_DEPARTEMENT->findText(GENRE);
        if (index1 != -1) {
            ui->comboBox_DEPARTEMENT->setCurrentIndex(index1);
        }
    ui->lineEdit_NUM_TEL->setText(QString::number(NUM_TEL));
    ui->dateEdit_AGENT->setDate(DATE_DE_NAISSANCE);
    // Store the selected row for update
    //selectedRowForUpdate = CIN;

}
void MainWindow::UPDATEPLACEHOLDER_RECHERCHE(){


        if(ui->comboBox_recherche->currentText()=="CIN"){
       ui->lineEdit_recherche->setPlaceholderText("rechercher un agent à partir de son CIN");
        }
        if(ui->comboBox_recherche->currentText()=="NOM"){
       ui->lineEdit_recherche->setPlaceholderText("rechercher un agent à partir de son nom");
        }
        if(ui->comboBox_recherche->currentText()=="TELEPHONE"){
        ui->lineEdit_recherche->setPlaceholderText("rechercher un agent à partir de son téléphone");
        }
        if(ui->comboBox_recherche->currentText()=="DEPARTEMENT"){
        ui->lineEdit_recherche->setPlaceholderText("rechercher un agent à partir de son département");
        }
}
void MainWindow::on_pushButton_MODIFIER_AGENT_clicked()
    {

        on_pushButton_refresh_clicked();

        // Récupérer les valeurs des champs
        QString cinString = ui->lineEdit_CIN->text().trimmed();
        int CIN = cinString.toInt();
        QString telephoneString = ui->lineEdit_NUM_TEL->text().trimmed();
        int TELEPHONE = telephoneString.toInt();
        QDate DATE_DE_NAISSANCE = ui->dateEdit_AGENT->date();
        QString NOM = ui->lineEdit_NOM->text().trimmed();
        QString PRENOM = ui->lineEdit_PRENOM->text().trimmed();
        QString ADRESSE = ui->lineEdit_ADRESSE->text().trimmed();
        QString MAIL = ui->lineEdit_MAIL->text().trimmed();
        QString GENRE = ui->comboBox_GENRE->currentText();
        QString DEPARTEMENT = ui->comboBox_DEPARTEMENT->currentText();

        // Effectuer des vérifications de saisie
        if (cinString.length() != 8 || cinString.toInt() == 0 || !cinString.toInt()) {
            QMessageBox::critical(this, "Erreur de saisie", "Le CIN doit être composé de 8 chiffres.");
            return;
        }

        if (telephoneString.length() != 8 || telephoneString.toInt() == 0 || !telephoneString.toInt()) {
            QMessageBox::critical(this, "Erreur de saisie", "Le numéro de téléphone doit être composé de 9 chiffres.");
            return;
        }

        if (NOM.isEmpty() || PRENOM.isEmpty() || ADRESSE.isEmpty() || MAIL.isEmpty()) {
            QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
            return;
        }

        // Vérifier le format de l'adresse e-mail
        QRegularExpression regex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
        if (!regex.match(MAIL).hasMatch()) {
            QMessageBox::critical(this, "Erreur de saisie", "Format d'adresse e-mail invalide.");
            return;
        }

        // Créer l'objet AGENT
        AGENT agent(CIN, TELEPHONE, NOM, PRENOM, ADRESSE, MAIL, GENRE, DEPARTEMENT, DATE_DE_NAISSANCE);

        // Modifier l'agent
        if (agent.modifier(CIN, TELEPHONE, NOM, PRENOM, ADRESSE, MAIL, GENRE, DEPARTEMENT, DATE_DE_NAISSANCE)) {
            // Succès
            QMessageBox::information(this, "Succès", "Agent modifié avec succès.");

            on_pushButton_refresh_clicked();
        } else {
            // Échec
            QMessageBox::critical(this, "Erreur de modification", "Échec de la modification de l'agent.");
        }
    }
void MainWindow::sort_asc() {
    QString sortingColumn;

    if (ui->TRI->currentText().contains(">>")) {
        if (ui->TRI->currentText() == "Date de naissance >>") {
            sortingColumn = "DATE_DE_NAISSANCE";
        }
        if (ui->TRI->currentText() == "CIN >>") {
            sortingColumn = "CIN";
        }
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT CIN,  NOM, PRENOM, ADRESSE, MAIL, GENRE, TELEPHONE, DEPARTEMENT, TO_CHAR(DATE_DE_NAISSANCE, 'YYYY-MM-DD' ) FROM mahdi.AGENTS ORDER BY " + sortingColumn);

        // Set the model to the table widget
        ui->tableWidget_AGENT->setRowCount(model->rowCount());
        ui->tableWidget_AGENT->setColumnCount(model->columnCount() + 2); // Add two columns for the delete and update buttons

        // Styles for headers
        ui->tableWidget_AGENT->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #4CAF50; color: white; }");

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem;
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // Make cells read-only

                // Set the text without scientific notation for the CIN and TELEPHONE columns
                if (col == 0 || col == 6) {
                    item->setData(Qt::DisplayRole, QString::number(model->data(model->index(row, col)).toInt()));
                } else {
                    item->setData(Qt::DisplayRole, model->data(model->index(row, col)));
                }

                item->setTextAlignment(Qt::AlignCenter); // Center the text
                ui->tableWidget_AGENT->setItem(row, col, item);
            }

            // Add delete button to the second last column
            QPushButton *deleteButton = new QPushButton("Delete");
            deleteButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: red; color: white; }");
            connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
                onDeleteButtonClicked(row);
            });
            ui->tableWidget_AGENT->setCellWidget(row, model->columnCount(), deleteButton);

            // Add update button to the last column
            QPushButton *updateButton = new QPushButton("Update");
            updateButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: blue; color: white; }");
            connect(updateButton, &QPushButton::clicked, this, [this, row]() {
                onRowUpdateClicked(row); // Call the function to handle row update
            });
            ui->tableWidget_AGENT->setCellWidget(row, model->columnCount() + 1, updateButton);
        }

        delete model;

        // Set the headers after populating the table with sorted data
        ui->tableWidget_AGENT->setHorizontalHeaderLabels(QStringList() << "CIN" << "NOM" << "PRENOM" << "ADRESSE" << "MAIL" << "GENRE" << "TELEPHONE" << "DEPARTEMENT" << "DATE DE NAISSANCE" << "DELETE" << "UPDATE");
    }
}
bool generatePdf(){

    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/agent.pdf";
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {

        // Retrieve data from the agent table
        QSqlQuery query("SELECT * FROM mahdi.AGENTS");
        QString htmlCode = " <html> <head> <title>Agent Information</title> <style> table { border-collapse: collapse; width: 80%; margin: 0 auto; } th, td { padding: 8px; text-align: left; border-bottom: 1px solid #ddd; } th { background-color: #4caf50; color: white; } </style> </head> <body> <h1 style='text-align:left;'>LISTE DES AGENTS</h1> <table> <tr> <th>Nom & prénom</th> <th>Genre</th> <th>Date de naissance</th> <th>Adresse</th> <th>Mail</th> <th>Département</th> <th>Téléphone</th> <th>CIN</th> </tr>";

        while (query.next()) {
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            QString genre = query.value("GENRE").toString();
            QString dateNaissance = query.value("DATE_DE_NAISSANCE").toDate().toString("yyyy-MM-dd");
            QString adresse = query.value("ADRESSE").toString();
            QString mail = query.value("MAIL").toString();
            QString departement = query.value("DEPARTEMENT").toString();
            QString telephone = query.value("TELEPHONE").toString();
            QString cin = query.value("CIN").toString();

            htmlCode += "<tr> <td>" + nom + " " + prenom + "</td> <td>" + genre + "</td> <td>" + dateNaissance + "</td> <td>" + adresse + "</td> <td>" + mail + "</td> <td>" + departement + "</td> <td>" + telephone + "</td> <td>" + cin + "</td> </tr>";
        }

        htmlCode += "</table> </body> </html>";

        QTextDocument document;
        document.setHtml(htmlCode);

        QPdfWriter writer(&file);
        writer.setPageSize(QPagedPaintDevice::A4); // set page size to A4
        writer.setPageMargins(QMarginsF(50, 0, 0, 0)); // centring page
        document.print(&writer);
        file.close();
        return true;
    }
    else{
        return false;
    }

}
void MainWindow::on_PDF_clicked()
{
    generatePdf();
}
// END OF fonctionnnet agent

//start fonction client
void MainWindow::on_radioButton_AJOUT_CLIENT_clicked()
{
     ui->pushButton_AJOUTER_CLIENT->setVisible(true);
    ui->pushButton_MODIFIER_CLIENT->setVisible(false);

}
void MainWindow::on_radioButton_Modifier_CLIENT_clicked()
{
    ui->pushButton_AJOUTER_CLIENT->setVisible(false);
   ui->pushButton_MODIFIER_CLIENT->setVisible(true);
}
void MainWindow::UPDATEPLACEHOLDER_RECHERCHE_CLIENT()
{
    if(ui->comboBox_recherche_CLIENT->currentText()=="CIN"){
   ui->lineEdit_recherche_Client->setPlaceholderText("rechercher un agent à partir de son CIN");
    }
    if(ui->comboBox_recherche_CLIENT->currentText()=="NOM"){
   ui->lineEdit_recherche_Client->setPlaceholderText("rechercher un agent à partir de son nom");
    }
    if(ui->comboBox_recherche_CLIENT->currentText()=="TELEPHONE"){
    ui->lineEdit_recherche_Client->setPlaceholderText("rechercher un agent à partir de son téléphone");
    }
    if(ui->comboBox_recherche_CLIENT->currentText()=="DEPARTEMENT"){
    ui->lineEdit_recherche_Client->setPlaceholderText("rechercher un agent à partir de son département");
    }
}
void MainWindow::on_pushButton_AJOUTER_CLIENT_clicked()
{
    on_pushButton_refresh_CLIENT_clicked();
    int CIN_CLIENT = ui->lineEdit_CIN_CLIENT->text().toInt();
    int TELEPHONE = ui->lineEdit_NUM_TEL_CLIENT->text().toInt();
    QDate DATE_DE_NAISSANCE = ui->dateEdit_CLIENT->date();
    QString NOM = ui->lineEdit_NOM_CLIENT->text();
    QString PRENOM = ui->lineEdit_PRENOM_CLIENT->text();
    QString MAIL = ui->lineEdit_MAIL_CLIENT->text();
    QString GENRE = ui->comboBox_GENRE_CLIENT->currentText();
    QString JOB = ui->lineEdit_TRAVAIL_CLIENT->text();
    QString RIB = ui->lineEdit_RIB_CLIENT->text();
    client client( NOM, PRENOM, TELEPHONE,MAIL, DATE_DE_NAISSANCE, GENRE, RIB, JOB, CIN_CLIENT);

    if (client.ajouter()) {
        // Succès
        QMessageBox::information(this, "Succès", "Agent ajouté avec succès.");
        // Mettez à jour le modèle du QTableView pour afficher les nouvelles données
        on_pushButton_refresh_CLIENT_clicked();


    } else {
        // Échec
        QMessageBox::critical(this, "Erreur d'ajout", "Échec de l'ajout de l'agent.");
    }
}
void MainWindow::onDeleteButtonClicked_CLIENT(int row){
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableWidget_CLIENT->model());
    QModelIndex index = model->index(row, 0);
    int CIN_CLIENT = model->data(index).toInt();

    // Perform deletion from the database
    QSqlQuery query;
    query.prepare("DELETE FROM mahdi.AGENTS CIN_CLIENT = :CIN_CLIENT");
    query.bindValue(":CIN_CLIENT", CIN_CLIENT);

    if (query.exec()) {
        // Update the table widget after successful deletion
        ui->tableWidget_AGENT->removeRow(row);
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to delete row: ") + query.lastError().text());
    }
}
void MainWindow::onRowUpdateClicked_CLIENT(int row){
    int CIN_CLIENT=ui->tableWidget_CLIENT->item(row, 0)->text().toInt();
    QString NOM = ui->tableWidget_CLIENT->item(row, 1)->text();
    QString PRENOM = ui->tableWidget_CLIENT->item(row, 2)->text();
    QString JOB = ui->tableWidget_CLIENT->item(row, 7)->text();
    int NUM_TEL = ui->tableWidget_CLIENT->item(row, 3)->text().toInt();
    QString MAIL = ui->tableWidget_CLIENT->item(row, 4)->text();
    QDate DATE_DE_NAISSANCE = QDate::fromString(ui->tableWidget_CLIENT->item(row, 5)->text(), "yyyy-MM-dd");
    QString GENRE = ui->tableWidget_CLIENT->item(row, 6)->text();
    QString RIB = ui->tableWidget_CLIENT->item(row, 8)->text();

    // Populate the form fields with the data
    ui->lineEdit_CIN_CLIENT->setText(QString::number(CIN_CLIENT));
    ui->lineEdit_NOM_CLIENT->setText(NOM);
    ui->lineEdit_PRENOM_CLIENT->setText(PRENOM);
    ui->lineEdit_TRAVAIL_CLIENT->setText(JOB);
    ui->lineEdit_MAIL_CLIENT->setText(MAIL);
    int index = ui->comboBox_GENRE->findText(GENRE);
    if (index != -1) {
        ui->comboBox_GENRE_CLIENT->setCurrentIndex(index);
    }
    int index1 = ui->comboBox_GENRE_CLIENT->findText(GENRE);
        if (index1 != -1) {
            ui->comboBox_GENRE_CLIENT->setCurrentIndex(index1);
        }
    ui->lineEdit_NUM_TEL_CLIENT->setText(QString::number(NUM_TEL));
    ui->dateEdit_CLIENT->setDate(DATE_DE_NAISSANCE);
    ui->lineEdit_RIB_CLIENT->setText(RIB);
}
void MainWindow::afficher_CLIENT() {
    QSqlQueryModel *model = new QSqlQueryModel();

       // SELECT statement to retrieve data from the database
       model->setQuery("SELECT CIN_CLIENT,  NOM, PRENOM, NUM_TEL, MAIL, GENRE, JOB, RIB, TO_CHAR(DATE_DE_NAISSANCE, 'YYYY-MM-DD' ) FROM  mahdi.CLIENTS ");

       // Set the model to the table widget
       ui->tableWidget_CLIENT->setRowCount(model->rowCount());
       ui->tableWidget_CLIENT->setColumnCount(model->columnCount() + 11); // Add two columns for the delete and update buttons

       for (int row = 0; row < model->rowCount(); ++row) {
           for (int col = 0; col < model->columnCount(); ++col) {
               // Create a new item
               QTableWidgetItem *item = new QTableWidgetItem;

               // Set the text without scientific notation for the CIN and TELEPHONE columns
               if (col == 0 || col == 3) {
                   item->setData(Qt::DisplayRole, QString::number(model->data(model->index(row, col)).toInt()));
               } else {
                   item->setData(Qt::DisplayRole, model->data(model->index(row, col)));
               }

               item->setTextAlignment(Qt::AlignCenter); // Center the text
               ui->tableWidget_CLIENT->setItem(row, col, item);
           }

           // Add delete button to the second last column
           QPushButton *deleteButton = new QPushButton("Delete");
           deleteButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: green; }");
           connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
               onDeleteButtonClicked_CLIENT(row);
           });
           ui->tableWidget_CLIENT->setCellWidget(row, model->columnCount(), deleteButton);

           // Add update button to the last column
           QPushButton *updateButton = new QPushButton("Update");
           updateButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: blue; }");
           connect(updateButton, &QPushButton::clicked, this, [this, row]() {
               onRowUpdateClicked_CLIENT(row); // Call the function to handle row update
           });
           ui->tableWidget_CLIENT->setCellWidget(row, model->columnCount() + 1, updateButton);
       }

       delete model;
}
void MainWindow::on_pushButton_refresh_CLIENT_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();

       // SELECT statement to retrieve data from the database
       model->setQuery("SELECT CIN_CLIENT,  NOM, PRENOM, NUM_TEL, MAIL, GENRE, JOB, RIB, TO_CHAR(DATE_DE_NAISSANCE, 'YYYY-MM-DD' ) FROM  mahdi.CLIENTS ");

       // Set the model to the table widget
       ui->tableWidget_CLIENT->setRowCount(model->rowCount());
       ui->tableWidget_CLIENT->setColumnCount(model->columnCount() + 11); // Add two columns for the delete and update buttons

       for (int row = 0; row < model->rowCount(); ++row) {
           for (int col = 0; col < model->columnCount(); ++col) {
               // Create a new item
               QTableWidgetItem *item = new QTableWidgetItem;
/*
               // Set the text without scientific notation for the CIN and TELEPHONE columns
               if (col == 0 || col == 3) {
                   item->setData(Qt::DisplayRole, QString::number(model->data(model->index(row, col)).toInt()));
               } else {
                   item->setData(Qt::DisplayRole, model->data(model->index(row, col)));
               }
*/
               item->setTextAlignment(Qt::AlignCenter); // Center the text
               ui->tableWidget_CLIENT->setItem(row, col, item);
           }

           // Add delete button to the second last column
           QPushButton *deleteButton = new QPushButton("Delete");
           deleteButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: green; }");
           connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
               onDeleteButtonClicked_CLIENT(row);
           });
           ui->tableWidget_CLIENT->setCellWidget(row, model->columnCount(), deleteButton);

           // Add update button to the last column
           QPushButton *updateButton = new QPushButton("Update");
           updateButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: blue; }");
           connect(updateButton, &QPushButton::clicked, this, [this, row]() {
               onRowUpdateClicked_CLIENT(row); // Call the function to handle row update
           });
           ui->tableWidget_CLIENT->setCellWidget(row, model->columnCount() + 1, updateButton);
       }

       delete model;
}
//start fonction reclamation
void MainWindow::on_radioButton_AJOUT_RECLAMTION_clicked()
{
    ui->pushButton_AJOUTER_RECLAMATION->setVisible(true);
   ui->pushButton_MODIFIER_RECLAMATION->setVisible(false);
}
void MainWindow::on_radioButton_Modifier_RECLAMATION_clicked()
{
    ui->pushButton_AJOUTER_RECLAMATION->setVisible(false);
   ui->pushButton_MODIFIER_RECLAMATION->setVisible(true);
}


//start fonctions ev

void MainWindow::on_radioButton_AJOUT_EV_clicked()
{
    ui->pushButton_MODIFIERR_EVENEMENT->setVisible(false);
   ui->pushButton_AJOUTER_EVENEMENT->setVisible(true);
}
void MainWindow::on_radioButton_Modifier_EV_clicked()
{
    ui->pushButton_MODIFIERR_EVENEMENT->setVisible(true);
   ui->pushButton_AJOUTER_EVENEMENT->setVisible(false);
}
void MainWindow::UPDATEPLACEHOLDER_RECHERCHE_EV(){
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
void MainWindow::on_pushButton_AJOUTER_EVENEMENT_clicked()
{
    QString NOM = ui->lineEdit_NOM_EVENEMENT->text().trimmed();
    QString DESCRIPTION = ui->lineEdit_DESCRIPTION->text().trimmed();
    QDate DATE_EVENEMENT = ui->dateEdit_DATE_EVENEMENT->date();
    QString LIEU_EVENEMENT = ui->lineEdit_LIEU_EVENEMENT->text().trimmed();
    int NB_INVITATIONS = ui->spinBox_NB_INVITATION->value();
    int BUDGET = ui->lineEdit_BUDGET->text().toInt();

    // Effectuer des vérifications de saisie
    if (NOM.isEmpty() || DESCRIPTION.isEmpty() || LIEU_EVENEMENT.isEmpty() || BUDGET <= 0 || NB_INVITATIONS <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Veuillez remplir tous les champs et assurez-vous que le budget et le nombre d'invitations sont supérieurs à zéro.");
        return;
    }

    // Créer l'objet EVENEMENT
    EVENEMENTS EVENEMENT(NOM, DESCRIPTION, DATE_EVENEMENT, LIEU_EVENEMENT, NB_INVITATIONS, BUDGET);

    // Ajouter l'événement
    if (EVENEMENT.ajouter()) {
        QMessageBox::information(this, "Succès", "Événement ajouté avec succès.");

    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de l'événement.");
    }
}
void MainWindow::onRowUpdateClicked_EV(int row){
    // Get the ID from the selected row
    QString NOM = ui->tableWidget_EV->item(row, 0)->text();
       QString LIEU_EVENEMENT = ui->tableWidget_EV->item(row, 1)->text();
       QString DESCRIPTION = ui->tableWidget_EV->item(row, 5)->text();
       int BUDGET = ui->tableWidget_EV->item(row, 4)->text().toInt();
       int NB_INVITATIONS = ui->tableWidget_EV->item(row, 3)->text().toInt();
       QDate DATE_EVENEMENT = QDate::fromString(ui->tableWidget_EV->item(row, 2)->text(), "yyyy-MM-dd");

    // Populate the form fields with the data
    ui->lineEdit_NOM_EVENEMENT->setText(NOM);
        ui->lineEdit_LIEU_EVENEMENT->setText(LIEU_EVENEMENT);
        ui->lineEdit_DESCRIPTION->setText(DESCRIPTION);
        ui->lineEdit_BUDGET->setText(QString::number(BUDGET));
        ui->spinBox_NB_INVITATION->setValue(NB_INVITATIONS);
        ui->dateEdit_DATE_EVENEMENT->setDate(DATE_EVENEMENT);
}
void MainWindow::onDeleteButtonClicked_EV(int row){
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableWidget_EV->model());
    QModelIndex index = model->index(row, 0); // Assuming the ID_PRODUIT is in the first column
    int NOM = model->data(index).toInt();

    // Perform deletion from the database
    QSqlQuery query;
    query.prepare("DELETE FROM mahdi.EVENEMENTS WHERE NOM = :NOM");
    query.bindValue(":NOM", NOM);

    if (query.exec()) {
        // Update the table widget after successful deletion
        ui->tableWidget_EV->removeRow(row);
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to delete row: ") + query.lastError().text());
    }
}
void MainWindow::on_pushButton_refresh_EV_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();

        // SELECT statement to retrieve data from the database
        model->setQuery("SELECT NOM,DESCRIPTION,LIEU_EVENEMENT,BUDGET,NB_INVITATIONS, TO_CHAR(DATE_EVENEMENT, 'YYYY-MM-DD' ) FROM mahdi.EVENEMENTS ");

        // Set the model to the table widget
        ui->tableWidget_EV->setRowCount(model->rowCount());
        ui->tableWidget_EV->setColumnCount(model->columnCount() + 2); // Add two columns for the delete and update buttons

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem;
                item->setFlags(item->flags() & ~Qt::ItemIsEditable); // Make cells read-only

                // Set the text without scientific notation for the CIN and TELEPHONE columns
                if (col == 3 || col == 4) {
                    item->setData(Qt::DisplayRole, QString::number(model->data(model->index(row, col)).toInt()));
                } else {
                    item->setData(Qt::DisplayRole, model->data(model->index(row, col)));
                }

                item->setTextAlignment(Qt::AlignCenter); // Center the text
                ui->tableWidget_EV->setItem(row, col, item);
            }

            // Add delete button to the second last column
            QPushButton *deleteButton = new QPushButton("Delete");
            deleteButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: green; }");
            connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
                onDeleteButtonClicked(row);
            });
            ui->tableWidget_EV->setCellWidget(row, model->columnCount(), deleteButton);

            // Add update button to the last column
            QPushButton *updateButton = new QPushButton("Update");
            updateButton->setStyleSheet("QPushButton { font: 700 16pt 'Sitka Subheading'; background-color: blue; }");
            connect(updateButton, &QPushButton::clicked, this, [this, row]() {
                onRowUpdateClicked(row); // Call the function to handle row update
            });
            ui->tableWidget_EV->setCellWidget(row, model->columnCount() + 1, updateButton);
        }

        delete model;
}
