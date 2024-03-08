#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>
#include <QPushButton>
#include "ui_mainwindow.h"
class AGENT
{
private:
    int CIN, TELEPHONE;
    QString NOM, PRENOM, ADRESSE, MAIL, GENRE, DEPARTEMENT;
    QDate DATE_DE_NAISSANCE;

    QTableView *tableView;

public:
    AGENT();
    AGENT(int, int, QString, QString, QString, QString, QString, QString, QDate);

    int getCIN() const { return CIN; }
    int getTELEPHONE() const { return TELEPHONE; }
    QString getNOM() const { return NOM; }
    QString getPRENOM() const { return PRENOM; }
    QString getADRESSE() const { return ADRESSE; }
    QString getMAIL() const { return MAIL; }
    QString getGENRE() const { return GENRE; }
    QString getDEPARTEMENT() const { return DEPARTEMENT; }
    QDate getDATE_NAISSANCE() const { return DATE_DE_NAISSANCE; }

    void setCIN(int value) { CIN = value; }
    void setTELEPHONE(int value) { TELEPHONE = value; }
    void setNOM(const QString &value) { NOM = value; }
    void setPRENOM(const QString &value) { PRENOM = value; }
    void setADRESSE(const QString &value) { ADRESSE = value; }
    void setMAIL(const QString &value) { MAIL = value; }
    void setGENRE(const QString &value) { GENRE = value; }
    void setDEPARTEMENT(const QString &value) { DEPARTEMENT = value; }
    void setDATE_NAISSANCE(const QDate &value) { DATE_DE_NAISSANCE = value; }
    bool ajouter();
    bool supprimer(int CIN);
    bool modifier(int CIN, int TELEPHONE, QString NOM, QString PRENOM, QString ADRESSE, QString MAIL, QString GENRE, QString DEPARTEMENT, QDate DATE_DE_NAISSANCE);
    QSqlQueryModel *afficher();


};
#endif // AGENT_H
