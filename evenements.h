#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class EVENEMENTS
{
    QString NOM,LIEU_EVENEMENT,DESCRIPTION;
    int BUDGET, NB_INVITATIONS;
    QDate DATE_EVENEMENT;


public:
    //constructeur


    EVENEMENTS(){}
    EVENEMENTS(QString,QString,QDate,QString,int,int);
    //getters
    QString getNOM(){return NOM;}
    QString getLIEU_EVENEMENT(){return LIEU_EVENEMENT;}
    QString getDESCRIPTION(){return DESCRIPTION;}
    int getBUDGET(){return BUDGET;}
    int getNB_INVITATION(){return NB_INVITATIONS;}
    QDate getDATE_EVENEMENT(){return DATE_EVENEMENT;}
    //setters
    void setNOM(QString nom){NOM=nom;}
    void setLIEU_EVENEMENT(QString lieu){LIEU_EVENEMENT=lieu;}
    void setDESCRIPTION_EVENEMENT(QString description){DESCRIPTION=description;}
    void setBUDGET(int budget){this->BUDGET=budget;}
    void setNB_INVITATION(int nb){this->NB_INVITATIONS=nb;}
    void setDATE_EVENEMENT(QDate date){this->DATE_EVENEMENT=date;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(QString NOM,QString DESCRIPTION,QDate DATE_EVENEMENT,QString LIEU_EVENEMENT,int NB_INVITATIONS,int BUDGET);
    bool supprimer(QString NOM);

    QSqlQueryModel* rechercher(const QString& nom);

    void exporterPDF(QSqlQueryModel *model);


    QSqlQueryModel * tri_NOM();
     QSqlQueryModel * tri_DESCRIPTION();
      QSqlQueryModel * tri_LIEU_EVENEMENT();
      QSqlQueryModel * tri_NB_INVITATIONS();
       QSqlQueryModel * tri_BUDGET();
        QSqlQueryModel * tri_DATE_EVENEMENT();

};





#endif // EVENEMENTS_H
