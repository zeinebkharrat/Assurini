#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QTableWidget>
#include <QTime>
#include <QSqlError>
    RECLAMATIONS::RECLAMATIONS() : ID_RECLAMATION(0), MONTANT_INDEMNISATION(0), DATE_DE_SOUMISSION(QDate())
    {
        // Initialise other members if needed
    }
    RECLAMATIONS::RECLAMATIONS(int ID_RECLAMATION, QString DESCRIPTION, QString STATUS, int MONTANT_INDEMNISATION, QDate DATE_DE_SOUMISSION)
    {
      this-> ID_RECLAMATION = ID_RECLAMATION;
      this-> DESCRIPTION = DESCRIPTION;
      this-> STATUS = STATUS;
      this-> MONTANT_INDEMNISATION = MONTANT_INDEMNISATION;
      this-> DATE_DE_SOUMISSION = DATE_DE_SOUMISSION;

    }
bool RECLAMATIONS::ajouter()
    {
        QSqlQuery query;

        query.prepare("INSERT INTO mahdi.RECLAMATIONS ( ID_RECLAMATION, DESCRIPTION, STATUS, MONTANT_INDEMNISATION, DATE_DE_SOUMISSION, CIN_AGENT) "
                         "VALUES (:ID_RECLAMATION, :DESCRIPTION, :STATUS, :MONTANT_INDEMNISATION, :DATE_DE_SOUMISSION, :NULL)");
           query.bindValue(":ID_RECLAMATION ", ID_RECLAMATION);
           query.bindValue(":DESCRIPTION ", DESCRIPTION);
           query.bindValue(":STATUS ", STATUS);
           query.bindValue(":MONTANT_INDEMNISATION ", MONTANT_INDEMNISATION);
           query.bindValue(":DATE_DE_SOUMISSION ", DATE_DE_SOUMISSION);

           return query.exec();
    }
bool RECLAMATIONS::supprimer(int ID_RECLAMATION)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM mahdi.RECLAMATIONS WHERE ID_RECLAMATION = : ID_RECLAMATION ");
        query.bindValue(":ID_RECLAMATION ", ID_RECLAMATION);
        return query.exec();
    }
bool RECLAMATIONS::modifier(int ID_RECLAMATION, QString DESCRIPTION, QString STATUS, int MONTANT_INDEMNISATION, QDate DATE_DE_SOUMISSION)
    {
        QSqlQuery query;
        query.prepare("UPDATE mahdi.RECLAMATIONS SET ID_RECLAMATION = :ID_RECLAMATION, DESCRIPTION = :DESCRIPTION, STATUS = :STATUS, MONTANT_INDEMNISATION = :MONTANT_INDEMNISATION, DATE_DE_SOUMISSION = : DATE_DE_SOUMISSION, CIN_AGENT = :CIN_AGENT");
        query.bindValue(":ID_RECLAMATION ", ID_RECLAMATION);
        query.bindValue(":DESCRIPTION ", DESCRIPTION);
        query.bindValue(":STATUS ", STATUS);
        query.bindValue(":MONTANT_INDEMNISATION ", MONTANT_INDEMNISATION);
        query.bindValue(":DATE_DE_SOUMISSION ", DATE_DE_SOUMISSION);
        return query.exec();
    }


