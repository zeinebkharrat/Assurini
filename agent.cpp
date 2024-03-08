#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agent.h"
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QTableWidget>
#include <QTime>
#include <QSqlError>
AGENT::AGENT() : CIN(0), TELEPHONE(0), DATE_DE_NAISSANCE(QDate())
{
    // Initialise other members if needed
}
AGENT::AGENT(int CIN,int TELEPHONE,QString NOM,QString PRENOM,QString ADRESSE,QString MAIL,QString GENRE,QString DEPARTEMENT ,QDate DATE_DE_NAISSANCE)
{
  this->CIN=CIN;
  this->TELEPHONE=TELEPHONE;
  this->NOM=NOM;
  this->PRENOM=PRENOM;
  this->ADRESSE=ADRESSE;
  this->MAIL=MAIL;
  this->GENRE=GENRE;
  this->DEPARTEMENT=DEPARTEMENT;
  this->DATE_DE_NAISSANCE=DATE_DE_NAISSANCE;
}
bool AGENT::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO mahdi.AGENTS (CIN, TELEPHONE, NOM, PRENOM, ADRESSE, MAIL, GENRE, DEPARTEMENT, DATE_DE_NAISSANCE) "
                     "VALUES (:CIN, :TELEPHONE, :NOM, :PRENOM, :ADRESSE, :MAIL, :GENRE, :DEPARTEMENT, :DATE_DE_NAISSANCE)");
       query.bindValue(":CIN", CIN);
       query.bindValue(":TELEPHONE", TELEPHONE);
       query.bindValue(":NOM", NOM);
       query.bindValue(":PRENOM", PRENOM);
       query.bindValue(":ADRESSE", ADRESSE);
       query.bindValue(":MAIL", MAIL);
       query.bindValue(":GENRE", GENRE);
       query.bindValue(":DEPARTEMENT", DEPARTEMENT);
       query.bindValue(":DATE_DE_NAISSANCE", DATE_DE_NAISSANCE);

       return query.exec();
}
bool AGENT::supprimer(int CIN)
{
    QSqlQuery query;
    query.prepare("DELETE FROM mahdi.AGENTS WHERE CIN = :CIN");
    query.bindValue(":CIN", CIN);
    return query.exec();
}
bool AGENT::modifier(int CIN, int TELEPHONE, QString NOM, QString PRENOM, QString ADRESSE, QString MAIL, QString GENRE, QString DEPARTEMENT, QDate DATE_DE_NAISSANCE)
{
    QSqlQuery query;
    query.prepare("UPDATE mahdi.AGENTS SET TELEPHONE = :TELEPHONE, NOM = :NOM, PRENOM = :PRENOM, ADRESSE = :ADRESSE, MAIL = :MAIL, GENRE = :GENRE, DEPARTEMENT = :DEPARTEMENT, DATE_DE_NAISSANCE = :DATE_DE_NAISSANCE WHERE CIN = :CIN");
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":GENRE", GENRE);
    query.bindValue(":DEPARTEMENT", DEPARTEMENT);
    query.bindValue(":DATE_DE_NAISSANCE", DATE_DE_NAISSANCE);
    query.bindValue(":CIN", CIN);

    return query.exec();
}


