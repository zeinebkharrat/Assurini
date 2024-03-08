#include "client.h"
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPushButton>
#include <QTableWidget>
#include <QTime>
#include <QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"
client::client(QString NOM,QString PRENOM,int NUM_TEL,QString EMAIL,QDate DATE_DE_NAISSANCE,QString GENRE,QString RIB,QString JOB,int CIN_CLIENT)
{
    this->CIN_CLIENT=CIN_CLIENT;
    this->NUM_TEL=NUM_TEL;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->JOB=JOB;
    this->EMAIL=EMAIL;
    this->GENRE=GENRE;
    this->RIB=RIB;
    this->DATE_DE_NAISSANCE=DATE_DE_NAISSANCE;

}
bool client::ajouter(){
    QSqlQuery query;

    query.prepare("INSERT INTO mahdi.CLIENTS (CIN_CLIENT, NUM_TEL, NOM, PRENOM, JOB, EMAIL, GENRE, RIB, DATE_DE_NAISSANCE) "
                     "VALUES (:CIN_CLIENT, :NUM_TEL, :NOM, :PRENOM, :JOB, :EMAIL, :GENRE, :RIB, :DATE_DE_NAISSANCE)");

       query.bindValue(":CIN_CLIENT", CIN_CLIENT);
       query.bindValue(":NUM_TEL", NUM_TEL);
       query.bindValue(":NOM", NOM);
       query.bindValue(":PRENOM", PRENOM);
       query.bindValue(":JOB", JOB);
       query.bindValue(":EMAIL", EMAIL);
       query.bindValue(":GENRE", GENRE);
       query.bindValue(":RIB", RIB);
       query.bindValue(":DATE_DE_NAISSANCE", DATE_DE_NAISSANCE);

       return query.exec();
}
bool client::supprimer_CLIENT(int CIN_CLIENT)
{
    QSqlQuery query;
    query.prepare("DELETE FROM mahdi.CLEINTS WHERE CIN_CLIENT = :CIN_CLIENT");
    query.bindValue(":CIN_CLIENT", CIN_CLIENT);
    return query.exec();
}
