#ifndef CLIENT_H
#define CLIENT_H
#include <QTableView>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include "ui_mainwindow.h"
class client
{
    QString NOM , PRENOM , EMAIL , GENRE , RIB , JOB ;
    QDate DATE_DE_NAISSANCE;
    int CIN_CLIENT,NUM_TEL;

    QTableView *tableView;
public:
    client(){};
    client(QString,QString,int,QString,QDate,QString,QString,QString,int);

    //GETTERS
    QString getNOM(){return NOM;}
    QString getPRENOM(){ return PRENOM;}
    QString getGENRE(){return GENRE;}
    QDate getDATE_NAISSANCE(){return DATE_DE_NAISSANCE;}
    int getCIN_CLIENT(){return CIN_CLIENT;}
    int getNUM_TEL(){return NUM_TEL;}
    QString getEMAIL(){return  EMAIL;}
    QString getJOB(){return  JOB;}
    QString getRIB(){return  RIB;}

    //SETTERS
    void setNOM(QString N){NOM=N;}
    void setPRENOM(QString P){PRENOM=P;}
    void setDATE_NAISSANCE(QDate DATE_NAISSANCE){this->DATE_DE_NAISSANCE=DATE_NAISSANCE;}
    void setEMail(QString M){EMAIL=M;}
    void setGENRE(QString GEN){GENRE=GEN;}
    void setNUM_TEL(int NUM_TEL){this->NUM_TEL=NUM_TEL;}
    void setCIN_CLIENT(int CIN_CLIENT){this->CIN_CLIENT=CIN_CLIENT;}
    void setJOB(QString J){JOB=J;}
    void setRIB(QString R){RIB=R;}

    //Fonctionnalités
        bool ajouter();
        bool supprimer_CLIENT(int CIN_CLIENT);
        QSqlQueryModel *afficher();
};
#endif // CLIENT_H
