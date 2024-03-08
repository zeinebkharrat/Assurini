#ifndef RECLAMATION_H
#define RECLAMATION_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>
#include <QPushButton>

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class RECLAMATIONS
{
private:
    int ID_RECLAMATION, MONTANT_INDEMNISATION, CIN_AGENT;
    QString DESCRIPTION, STATUS;
    QDate DATE_DE_SOUMISSION;

    QTableView *tableView;

public:
    RECLAMATIONS();
    RECLAMATIONS(int, QString, QString, int, QDate);

    int getID_RECLAMATION() const { return ID_RECLAMATION; }
    QString getDESCRIPTION () const { return DESCRIPTION; }
    QString getSTATUS () const { return STATUS; }
int getMONTANT_INDEMNISATION () const { return MONTANT_INDEMNISATION; }
    QDate getDATE_DE_SOUMISSION () const { return DATE_DE_SOUMISSION; }



void setID_RECLAMATION (int value) { ID_RECLAMATION = value; }
void setDESCRIPTION (const QString &value) { DESCRIPTION = value; }
void setSTATUS (const QString &value) { STATUS = value; }
void setMONTANT_INDEMNISATION (int value) { MONTANT_INDEMNISATION = value; }
void setDATE_DE_SOUMISSION (const QDate &value) { DATE_DE_SOUMISSION = value; }

//fonction
    bool ajouter();
    bool supprimer(int ID_RECLAMATION);
    bool modifier(int ID_RECLAMATION, QString DESCRIPTION, QString STATUS, int MONTANT_INDEMNISATION, QDate DATE_DE_SOUMISSION);
    QSqlQueryModel *afficher();


};
#endif // RECLAMATION_H
