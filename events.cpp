#include "events.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QTableWidget>
#include <QTime>
#include <QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QStandardPaths>



/*
EVENEMENTS::EVENEMENTS()
{
    NOM = "";
    DESCRIPTION = "";
    LIEU_EVENEMENT = "";
    NB_INVITATIONS = '0';
    BUDGET = '0';
}
*/
EVENEMENTS::EVENEMENTS(QString NOM,QString DESCRIPTION,QDate DATE_EVENEMENT,QString LIEU_EVENEMENT,int NB_INVITATIONS,int BUDGET)
{
    this->NOM=NOM;
    this->DESCRIPTION=DESCRIPTION;
    this->DATE_EVENEMENT=DATE_EVENEMENT;
    this->LIEU_EVENEMENT=LIEU_EVENEMENT;
    this->NB_INVITATIONS=NB_INVITATIONS;
    this->BUDGET=BUDGET;

}

bool EVENEMENTS::ajouter()
{
    QSqlQuery query;

       query.prepare("INSERT INTO mahdi.EVENEMENTS( NOM, DESCRIPTION, DATE_EVENEMENT,LIEU_EVENEMENT, NB_INVITATIONS, BUDGET,CIN_AGENT) "
                     "VALUES (:NOM, :DESCRIPTION, :DATE_EVENEMENT, :LIEU_EVENEMENT, :NB_INVITATIONS, :BUDGET,NULL)");

       query.bindValue(":NOM", NOM);
       query.bindValue(":DESCRIPTION", DESCRIPTION);
       query.bindValue(":DATE_EVENEMENT", DATE_EVENEMENT);
       query.bindValue(":LIEU_EVENEMENT", LIEU_EVENEMENT);
       query.bindValue(":NB_INVITATIONS", NB_INVITATIONS);
       query.bindValue(":BUDGET", BUDGET);

       return query.exec();
}

QSqlQueryModel *EVENEMENTS::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Exécutez votre requête SQL pour récupérer les données de la table
    query.prepare("SELECT * FROM EVENEMENTS");
    if (query.exec()) {
        // Chargez le résultat de la requête dans le modèle
        model->setQuery(query);
    } else {
        // Gérez les erreurs d'exécution de la requête si nécessaire
        qDebug() << "Erreur d'exécution de la requête :" << query.lastError().text();
    }

    return model;
}

bool EVENEMENTS::modifier(QString NOM, QString DESCRIPTION, QDate DATE_EVENEMENT, QString LIEU_EVENEMENT, int NB_INVITATIONS, int BUDGET)


{
    QSqlQuery query;

    query.prepare("UPDATE EVENEMENTS SET NOM = :NOM, DESCRIPTION = :DESCRIPTION, DATE_EVENEMENT = :DATE_EVENEMENT, LIEU_EVENEMENT = :LIEU_EVENEMENT, NB_INVITATIONS = :NB_INVITATIONS, BUDGET = :BUDGET WHERE NOM = :NOM");

    query.bindValue(":NOM", NOM);
    query.bindValue(":DESCRIPTION", DESCRIPTION);
    query.bindValue(":DATE_EVENEMENT", DATE_EVENEMENT.toString("yyyy-MM-dd"));
    query.bindValue(":LIEU_EVENEMENT", LIEU_EVENEMENT);
    query.bindValue(":NB_INVITATIONS", NB_INVITATIONS);
    query.bindValue(":BUDGET", BUDGET);

    return query.exec();
}
bool EVENEMENTS::supprimer(QString NOM)
{
    QSqlQuery query;


    query.prepare("DELETE FROM EVENEMENTS WHERE NOM = :NOM");
    query.bindValue(":NOM",NOM);

    return query.exec();
}
/*


  hatha yaffichi el recherche ama myakharajech resultat mtaa recherche pdf tkharej el kol



QSqlQueryModel* EVENEMENTS::rechercher(QString NOM)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM EVENEMENTS WHERE NOM LIKE :NOM");
    query.bindValue(":NOM", "%" + NOM + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête de recherche :" << query.lastError().text();
    }

    return model;
}


void EVENEMENTS::exporterPDF(QSqlQueryModel *model)
{
    // Création du document PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    // Obtenez le répertoire de téléchargement de l'utilisateur
    QString downloadLocation = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);

    // Définir le nom et le chemin complet du fichier PDF
    QString filePath = downloadLocation + "/evenements.pdf";
    printer.setOutputFileName(filePath);

    QTextDocument doc;
    QTextCursor cursor(&doc);

    // Début du document
    cursor.insertText("Liste des événements :\n\n");

    // Création d'un tableau pour afficher les données
    QTextTable *table = cursor.insertTable(model->rowCount() + 1, model->columnCount());
    QTextCursor tableCursor(table);

    // Remplissage du tableau avec les en-têtes de colonne
    for (int col = 0; col < model->columnCount(); ++col) {
        tableCursor.insertText(model->headerData(col, Qt::Horizontal).toString());
        tableCursor.movePosition(QTextCursor::NextCell);
    }

    // Remplissage du tableau avec les données
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            tableCursor.insertText(model->data(model->index(row, col)).toString());
            tableCursor.movePosition(QTextCursor::NextCell);
        }
    }

    // Impression du document
    doc.print(&printer);
}
*/
QSqlQueryModel* EVENEMENTS::rechercher(const QString& nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparez la requête SQL avec un filtre sur le nom
    query.prepare("SELECT * FROM EVENEMENTS WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%"); // Utilisation de %nom% pour rechercher des correspondances partielles

    // Exécutez la requête
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    }

    return model;
}

/*
void EVENEMENTS::exporterPDF(QSqlQueryModel *model)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    QString downloadLocation = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    printer.setOutputFileName(downloadLocation + "/evenements.pdf");

    QTextDocument doc;
    QTextCursor cursor(&doc);

    cursor.insertText("Liste des événements :\n\n");

    QTextTable *table = cursor.insertTable(model->rowCount() + 1, model->columnCount());
    QTextCursor tableCursor(table);

    // Insertion des en-têtes de colonne
    for (int col = 0; col < model->columnCount(); ++col) {
        tableCursor.insertText(model->headerData(col, Qt::Horizontal).toString());
        tableCursor.movePosition(QTextCursor::NextCell);
    }

    // Insertion des données
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            tableCursor.insertText(model->data(model->index(row, col)).toString());
            tableCursor.movePosition(QTextCursor::NextCell);
        }
    }

    doc.print(&printer);
}*/

