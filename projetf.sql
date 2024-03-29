--------------------------------------------------------
--  Fichier cr�� - mercredi-f�vrier-28-2024   
--------------------------------------------------------
DROP TABLE "MAHDI"."AGENTS";
DROP TABLE "MAHDI"."CLIENTS";
DROP TABLE "MAHDI"."CONTRATS";
DROP TABLE "MAHDI"."EVENEMENTS";
DROP TABLE "MAHDI"."RECLAMATIONS";
--------------------------------------------------------
--  DDL for Table AGENTS
--------------------------------------------------------

  CREATE TABLE "MAHDI"."AGENTS" 
   (	"CIN" VARCHAR2(40 BYTE), 
	"NOM" VARCHAR2(80 BYTE), 
	"PRENOM" VARCHAR2(80 BYTE), 
	"ADRESSE" VARCHAR2(150 BYTE), 
	"TELEPHONE" VARCHAR2(30 BYTE), 
	"MAIL" VARCHAR2(220 BYTE), 
	"DATE_DE_NAISSANCE" DATE, 
	"GENRE" VARCHAR2(30 BYTE), 
	"DEPARTEMENT" VARCHAR2(110 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENTS
--------------------------------------------------------

  CREATE TABLE "MAHDI"."CLIENTS" 
   (	"CIN_CLIENT" VARCHAR2(255 BYTE), 
	"NOM" VARCHAR2(255 BYTE), 
	"PRENOM" VARCHAR2(255 BYTE), 
	"NUM_TEL" VARCHAR2(100 BYTE), 
	"EMAIL" VARCHAR2(255 BYTE), 
	"DATE_DE_NAISSANCE" VARCHAR2(255 BYTE), 
	"GENRE" VARCHAR2(100 BYTE), 
	"PHOTO" VARCHAR2(255 BYTE), 
	"RIB" VARCHAR2(255 BYTE), 
	"JOB" VARCHAR2(100 BYTE), 
	"CREATED" DATE DEFAULT sysdate
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CONTRATS
--------------------------------------------------------

  CREATE TABLE "MAHDI"."CONTRATS" 
   (	"ID_CONTRAT" NUMBER, 
	"TYPE" VARCHAR2(255 BYTE), 
	"CLASSE" VARCHAR2(255 BYTE), 
	"USAGE" VARCHAR2(255 BYTE), 
	"SYSTEME" VARCHAR2(255 BYTE), 
	"OPTIONS" VARCHAR2(255 BYTE), 
	"DATE_D" DATE, 
	"DATE_F" DATE, 
	"CIN_AGENT" VARCHAR2(40 BYTE), 
	"CIN_CLIENT" VARCHAR2(255 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EVENEMENTS
--------------------------------------------------------

  CREATE TABLE "MAHDI"."EVENEMENTS" 
   (	"NOM" VARCHAR2(255 BYTE), 
	"DESCRIPTION" VARCHAR2(255 BYTE), 
	"DATE_EVENEMENT" VARCHAR2(255 BYTE), 
	"LIEU_EVENEMENT" VARCHAR2(255 BYTE), 
	"NB_INVITATIONS" NUMBER, 
	"BUDGET" NUMBER, 
	"CIN_AGENT" VARCHAR2(40 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table RECLAMATIONS
--------------------------------------------------------

  CREATE TABLE "MAHDI"."RECLAMATIONS" 
   (	"ID_RECLAMATION" NUMBER, 
	"DESCRIPTION" VARCHAR2(255 BYTE), 
	"STATUS" VARCHAR2(255 BYTE), 
	"MONTANT_INDEMNISATION" NUMBER, 
	"DATE_DE_SOUMISSION" DATE DEFAULT sysdate, 
	"CIN_AGENT" VARCHAR2(40 BYTE), 
	"CIN_CLIENT" VARCHAR2(255 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into MAHDI.AGENTS
SET DEFINE OFF;
REM INSERTING into MAHDI.CLIENTS
SET DEFINE OFF;
REM INSERTING into MAHDI.CONTRATS
SET DEFINE OFF;
REM INSERTING into MAHDI.EVENEMENTS
SET DEFINE OFF;
REM INSERTING into MAHDI.RECLAMATIONS
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index PK_AGENTS
--------------------------------------------------------

  CREATE UNIQUE INDEX "MAHDI"."PK_AGENTS" ON "MAHDI"."AGENTS" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PK_CLIENTS
--------------------------------------------------------

  CREATE UNIQUE INDEX "MAHDI"."PK_CLIENTS" ON "MAHDI"."CLIENTS" ("CIN_CLIENT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PK_CONTRATS
--------------------------------------------------------

  CREATE UNIQUE INDEX "MAHDI"."PK_CONTRATS" ON "MAHDI"."CONTRATS" ("ID_CONTRAT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PK_EVENEMENTS
--------------------------------------------------------

  CREATE UNIQUE INDEX "MAHDI"."PK_EVENEMENTS" ON "MAHDI"."EVENEMENTS" ("NOM") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PK_RECLAMATIONS
--------------------------------------------------------

  CREATE UNIQUE INDEX "MAHDI"."PK_RECLAMATIONS" ON "MAHDI"."RECLAMATIONS" ("ID_RECLAMATION") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table AGENTS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "CHK_DEPARTEMENT_AGENT" CHECK ((DEPARTEMENT IN ('Ressource Humaines', 'Marketing', 'Technologie de l''Information (TI)', 'Conformite et Juridique'))) ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "CHK_TELEPHONE_AGENT" CHECK ((LENGTH(TELEPHONE) = 8 AND REGEXP_LIKE(TELEPHONE, '^[0-9]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "CHK_PRENOM_AGENT" CHECK ( (REGEXP_LIKE(Prenom, '^[a-zA-Z]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "CHK_NOM_AGENT" CHECK ((REGEXP_LIKE(Nom, '^[a-zA-Z]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "CHK_CIN_AGENT" CHECK ((LENGTH(CIN) = 8 AND REGEXP_LIKE(CIN, '^[0-9]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "CK_AGENTS" CHECK (GENRE IN ('Masculin', 'F�minin')) ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" ADD CONSTRAINT "PK_AGENTS" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MAHDI"."AGENTS" MODIFY ("DEPARTEMENT" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."AGENTS" MODIFY ("PRENOM" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."AGENTS" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."AGENTS" MODIFY ("CIN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CLIENTS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_JOB_CLIENT" CHECK ((REGEXP_LIKE(JOB, '^[a-zA-Z]+$') AND LENGTH(JOB) <= 50)) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_RIB_CLIENT" CHECK ((LENGTH(RIB) = 9 AND REGEXP_LIKE(RIB, '^[0-9]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_GENRE_CLIENT" CHECK ((GENRE IN ('Masculin', 'Feminin'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_EMAIL_CLIENT" CHECK ((REGEXP_LIKE(EMAIL, '^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_NUM_TEL_CLIENT" CHECK ((LENGTH(NUM_TEL) <= 15 AND REGEXP_LIKE(NUM_TEL, '^[0-9]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_PRENOM_CLIENT" CHECK ((REGEXP_LIKE(PRENOM, '^[a-zA-Z]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_NOM_CLIENT" CHECK ((REGEXP_LIKE(NOM, '^[a-zA-Z]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "PK_CLIENTS" PRIMARY KEY ("CIN_CLIENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("JOB" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("RIB" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("PHOTO" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("GENRE" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("DATE_DE_NAISSANCE" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("EMAIL" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("NUM_TEL" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" ADD CONSTRAINT "CHK_CIN_CLIENT" CHECK ((LENGTH(CIN_CLIENT) = 8 AND REGEXP_LIKE(CIN_CLIENT, '^[0-9]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("PRENOM" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CLIENTS" MODIFY ("CIN_CLIENT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CONTRATS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "CHK_OPTION_CONTRAT" CHECK ((OPTIONS IN ('Tous Risques', 'Bris de Glace', 'Contre le Vol', 'Catastrophes Naturelles', 'Assistance Routi�re', 'Assurance Dentaire', 'Assurance Vision', 'Soins de Maternit�', 'Assurance Soins � Domicile', 'Assurance Maladies Graves', 'Assurance Hospitalisation', 'Assurance Soins de Sant� Mentale', 'Frais de Relogement', 'Assurance pour Objets de Valeur', 'Couverture des �quipements �lectroniques', 'Service de Protection Juridique', 'Couverture des Pertes de Jardin', 'Catastrophes Naturelles', 'Couverture des Animaux de Compagnie', 'Couverture pour �v�nements Sp�ciaux'))) ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "CHK_USAGE_CONTRAT" CHECK ((USAGE IN ('Personnel', 'Professionnel'))) ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "CHK_CLASSE_CONTRAT" CHECK ( (CLASSE IN ('Standard', 'Aventure', 'Affaires', 'Tout Risques', 'Bagage de valeur', 'V�hicules de Luxe', 'V�hicules �cologiques', 'V�hicules Anciens/Classique', 'V�hicule de Sport', 'Minifourgonnettes', 'Base', 'Interm�diaire', 'Premium', 'B�timent R�sidentiel', 'B�timent Commercial', 'B�timent Industriel', 'B�timent Agricole', 'B�timent Institutionnel', 'B�timent Historique', 'B�timent Mixte'))) ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "CHK_TYPE_CONTRAT" CHECK ((TYPE IN ('Habitation', 'Sante', 'Voiture', 'Voyage'))) ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "CHK_ID_CONTRAT" CHECK ((ID_CONTRAT >= 0)) ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "PK_CONTRATS" PRIMARY KEY ("ID_CONTRAT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" MODIFY ("OPTIONS" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CONTRATS" MODIFY ("SYSTEME" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CONTRATS" MODIFY ("USAGE" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CONTRATS" MODIFY ("CLASSE" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CONTRATS" MODIFY ("TYPE" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."CONTRATS" MODIFY ("ID_CONTRAT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EVENEMENTS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "CHK_BUDGET_EVENEMENT" CHECK ((BUDGET >= 0)) ENABLE;
  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "CHK_NB_INVITATIONS_EVENEMENT" CHECK ((NB_INVITATIONS >= 0)) ENABLE;
  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "CHK_LIEU_EVENEMENT" CHECK ((LENGTH(LIEU_EVENEMENT) <= 200)) ENABLE;
  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "CHK_DESCRIPTION_EVENEMENT" CHECK ((REGEXP_LIKE(DESCRIPTION, '^[a-zA-Z0-9 ]+$') )) ENABLE;
  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "CHK_NOM_EVENEMENT" CHECK ((REGEXP_LIKE(NOM, '^[a-zA-Z0-9 ]+$'))) ENABLE;
  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "PK_EVENEMENTS" PRIMARY KEY ("NOM")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("CIN_AGENT" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("BUDGET" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("NB_INVITATIONS" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("LIEU_EVENEMENT" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("DATE_EVENEMENT" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("DESCRIPTION" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."EVENEMENTS" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table RECLAMATIONS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "CHK_MONTANT_RECLAMATION" CHECK ((MONTANT_INDEMNISATION >= 0)) ENABLE;
  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "CHK_STATUS_RECLAMATION" CHECK ((STATUS IN ('rejete', 'en cours', 'approuve'))) ENABLE;
  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "CHK_DESCRIPTION_RECLAMATION" CHECK ((REGEXP_LIKE(DESCRIPTION, '^[a-zA-Z0-9 ]+$') AND LENGTH(DESCRIPTION) <= 255)) ENABLE;
  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "CHK_ID_RECLAMATION" CHECK ((ID_RECLAMATION > 0)) ENABLE;
  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "PK_RECLAMATIONS" PRIMARY KEY ("ID_RECLAMATION")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MAHDI"."RECLAMATIONS" MODIFY ("MONTANT_INDEMNISATION" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."RECLAMATIONS" MODIFY ("DESCRIPTION" NOT NULL ENABLE);
  ALTER TABLE "MAHDI"."RECLAMATIONS" MODIFY ("ID_RECLAMATION" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table CONTRATS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "FK_CONTRATS_AGENTS" FOREIGN KEY ("CIN_AGENT")
	  REFERENCES "MAHDI"."AGENTS" ("CIN") ENABLE;
  ALTER TABLE "MAHDI"."CONTRATS" ADD CONSTRAINT "FK_CONTRATS_CLIENTS" FOREIGN KEY ("CIN_CLIENT")
	  REFERENCES "MAHDI"."CLIENTS" ("CIN_CLIENT") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table EVENEMENTS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."EVENEMENTS" ADD CONSTRAINT "FK_EVENEMENTS_AGENTS" FOREIGN KEY ("CIN_AGENT")
	  REFERENCES "MAHDI"."AGENTS" ("CIN") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table RECLAMATIONS
--------------------------------------------------------

  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "FK_RECLAMATIONS_AGENTS" FOREIGN KEY ("CIN_AGENT")
	  REFERENCES "MAHDI"."AGENTS" ("CIN") ENABLE;
  ALTER TABLE "MAHDI"."RECLAMATIONS" ADD CONSTRAINT "FK_RECLAMTIONS_CLIENTS" FOREIGN KEY ("CIN_CLIENT")
	  REFERENCES "MAHDI"."CLIENTS" ("CIN_CLIENT") ENABLE;
