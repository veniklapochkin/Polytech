--------------------------------------------------------
--  File created - четверг-июня-09-2016   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Sequence ARTICLES_SEQ_ID
--------------------------------------------------------

   CREATE SEQUENCE  "VLAD_BORISOV"."ARTICLES_SEQ_ID"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 41 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Sequence BALANCE_SEQ_ID
--------------------------------------------------------

   CREATE SEQUENCE  "VLAD_BORISOV"."BALANCE_SEQ_ID"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 21 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Sequence OPERATIONS_SEQ_ID
--------------------------------------------------------

   CREATE SEQUENCE  "VLAD_BORISOV"."OPERATIONS_SEQ_ID"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 41 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Table ADMIN
--------------------------------------------------------

  CREATE TABLE "VLAD_BORISOV"."ADMIN" 
   (	"LOGIN" CHAR(30 BYTE), 
	"PASSWORD" CHAR(30 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Table ARTICLES
--------------------------------------------------------

  CREATE TABLE "VLAD_BORISOV"."ARTICLES" 
   (	"ID" NUMBER(*,0), 
	"NAME" VARCHAR2(50 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Table BALANCE
--------------------------------------------------------

  CREATE TABLE "VLAD_BORISOV"."BALANCE" 
   (	"ID" NUMBER(*,0), 
	"DEBIT" NUMBER(18,2), 
	"CREDIT" NUMBER(18,2), 
	"CREATE_DATE_END" DATE, 
	"AMOUNT" NUMBER(18,2), 
	"CREATE_DATE_BEGIN" DATE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Table OPERATIONS
--------------------------------------------------------

  CREATE TABLE "VLAD_BORISOV"."OPERATIONS" 
   (	"ID" NUMBER(*,0), 
	"ARTICLE_ID" NUMBER(*,0), 
	"DEBIT" NUMBER(18,2), 
	"CREDIT" NUMBER(18,2), 
	"CREATE_DATE" DATE, 
	"BALANCE_ID" NUMBER(*,0)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for View ALLART
--------------------------------------------------------

  CREATE OR REPLACE FORCE VIEW "VLAD_BORISOV"."ALLART" ("ID", "NAME") AS 
  SELECT"ID","NAME"FROM ARTICLES WHERE Name Like 'С%';
--------------------------------------------------------
--  DDL for View ALLBAL
--------------------------------------------------------

  CREATE OR REPLACE FORCE VIEW "VLAD_BORISOV"."ALLBAL" ("AMOUNT", "CREATE_DATE_BEGIN", "CREATE_DATE_END", "CREDIT", "DEBIT", "COUNTID") AS 
  SELECT BALANCE.AMOUNT,BALANCE.CREATE_DATE_BEGIN,BALANCE.CREATE_DATE_END,BALANCE.CREDIT,BALANCE.DEBIT,(select count(operations.id) from OPERATIONS where balance_id=1) as countid FROM BALANCE;
--------------------------------------------------------
--  DDL for View ALLOPER
--------------------------------------------------------

  CREATE OR REPLACE FORCE VIEW "VLAD_BORISOV"."ALLOPER" ("ID", "ARTICLE_ID", "DEBIT", "CREDIT", "CREATE_DATE", "BALANCE_ID") AS 
  SELECT"ID","ARTICLE_ID","DEBIT","CREDIT","CREATE_DATE","BALANCE_ID"FROM OPERATIONS;
--------------------------------------------------------
--  DDL for View ARTNOTINOPER
--------------------------------------------------------

  CREATE OR REPLACE FORCE VIEW "VLAD_BORISOV"."ARTNOTINOPER" ("NAME", "CREDIT", "DEBIT") AS 
  SELECT ARTICLES.NAME,OPERATIONS.CREDIT,OPERATIONS.DEBIT FROM ARTICLES left join OPERATIONS on OPERATIONS.ID = ARTICLES.ID WHERE ARTICLES.ID NOT IN(SELECT OPERATIONS.ARTICLE_ID FROM OPERATIONS);
--------------------------------------------------------
--  DDL for View OPERBELONGART
--------------------------------------------------------

  CREATE OR REPLACE FORCE VIEW "VLAD_BORISOV"."OPERBELONGART" ("ID", "ARTICLE_ID", "DEBIT", "CREDIT", "CREATE_DATE", "BALANCE_ID") AS 
  SELECT"ID","ARTICLE_ID","DEBIT","CREDIT","CREATE_DATE","BALANCE_ID"FROM OPERATIONS WHERE ARTICLE_ID IN(SELECT ID FROM ARTICLES WHERE Name LIKE 'С%');
REM INSERTING into VLAD_BORISOV.ADMIN
SET DEFINE OFF;
Insert into VLAD_BORISOV.ADMIN (LOGIN,PASSWORD) values ('Venik_Lapochkin               ','0000                          ');
REM INSERTING into VLAD_BORISOV.ARTICLES
SET DEFINE OFF;
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('2','Поход в кино');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('3','Поход в мазазин за курицей');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('4','Покупка платья жене(');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('5','Купил себе гитару)');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('6','Квартплата');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('7','Оплатил воду (горячую и холодную)');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('8','Поход всей семьей в супермаркет');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('9','Цветы и шампанское жене');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('10','Сходил с сыном на футбол');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('11','Ремонт машины');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('12','Купил новый телевизор');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('13','Оплатил учебу сыну');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('14','Ой, зарплата! Съездил заправиться');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('15','Положил деньги на Webmoney');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('16','Купил игровую консоль');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('17','Подарок на день рождения друга');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('18','Купил новую материнскую плату');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('19','Друг вернул долг');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('20','Сходил в магазин за пивом и фисташками');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('21','Купил себе новый костюм');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('22','Сходили с семьей в театр');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('23','Олатил коммунальный ремонт');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('24','Купил жене новую сумку');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('25','Сын купил SSD');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('26','Дал дочери денег на новые туфли');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('27','Оплатил интернет');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('28','Квартплата');
Insert into VLAD_BORISOV.ARTICLES (ID,NAME) values ('29','Зарплата, наконец-то!');
REM INSERTING into VLAD_BORISOV.BALANCE
SET DEFINE OFF;
Insert into VLAD_BORISOV.BALANCE (ID,DEBIT,CREDIT,CREATE_DATE_END,AMOUNT,CREATE_DATE_BEGIN) values ('2','105500','94900',to_date('30.01.16','DD.MM.RR'),'10600',to_date('01.01.16','DD.MM.RR'));
Insert into VLAD_BORISOV.BALANCE (ID,DEBIT,CREDIT,CREATE_DATE_END,AMOUNT,CREATE_DATE_BEGIN) values ('3','120000','89700',to_date('28.02.16','DD.MM.RR'),'30300',to_date('01.02.16','DD.MM.RR'));
REM INSERTING into VLAD_BORISOV.OPERATIONS
SET DEFINE OFF;
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('2','2','99400','100',to_date('01.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('3','3','99300','300',to_date('03.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('4','4','99000','5000',to_date('05.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('5','5','94000','15000',to_date('07.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('6','6','79000','5000',to_date('10.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('7','7','74000','1000',to_date('13.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('8','8','73000','2500',to_date('15.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('9','9','70500','2000',to_date('18.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('10','10','68500','1000',to_date('20.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('11','11','67500','5000',to_date('22.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('12','12','62500','7000',to_date('23.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('13','13','55500','50000',to_date('25.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('14','14','105500','1000',to_date('31.01.16','DD.MM.RR'),'2');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('15','15','104500','1000',to_date('01.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('16','16','103500','30000',to_date('05.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('17','17','73500','5000',to_date('06.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('18','18','68500','10000',to_date('09.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('19','19','63700','0',to_date('10.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('20','20','63700','700',to_date('12.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('21','21','63000','20000',to_date('15.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('22','22','43000','1000',to_date('16.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('23','23','42000','1000',to_date('17.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('24','24','41000','5000',to_date('19.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('25','25','36000','6000',to_date('21.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('26','26','30000','5000',to_date('22.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('27','27','25000','1000',to_date('23.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('28','28','24000','4000',to_date('25.02.16','DD.MM.RR'),'3');
Insert into VLAD_BORISOV.OPERATIONS (ID,ARTICLE_ID,DEBIT,CREDIT,CREATE_DATE,BALANCE_ID) values ('29','29','120000','0',to_date('28.02.16','DD.MM.RR'),'3');
--------------------------------------------------------
--  DDL for Index ARTICLES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "VLAD_BORISOV"."ARTICLES_PK" ON "VLAD_BORISOV"."ARTICLES" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Index BALANCE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "VLAD_BORISOV"."BALANCE_PK" ON "VLAD_BORISOV"."BALANCE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Index OPERATIONS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "VLAD_BORISOV"."OPERATIONS_PK" ON "VLAD_BORISOV"."OPERATIONS" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  Constraints for Table ARTICLES
--------------------------------------------------------

  ALTER TABLE "VLAD_BORISOV"."ARTICLES" ADD CONSTRAINT "ARTICLES_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
--------------------------------------------------------
--  Constraints for Table OPERATIONS
--------------------------------------------------------

  ALTER TABLE "VLAD_BORISOV"."OPERATIONS" ADD CONSTRAINT "OPERATIONS_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
--------------------------------------------------------
--  Constraints for Table BALANCE
--------------------------------------------------------

  ALTER TABLE "VLAD_BORISOV"."BALANCE" ADD CONSTRAINT "BALANCE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table OPERATIONS
--------------------------------------------------------

  ALTER TABLE "VLAD_BORISOV"."OPERATIONS" ADD CONSTRAINT "FK_OPERATIONS_ARTICLES" FOREIGN KEY ("ARTICLE_ID")
	  REFERENCES "VLAD_BORISOV"."ARTICLES" ("ID") ON DELETE CASCADE ENABLE;
 
  ALTER TABLE "VLAD_BORISOV"."OPERATIONS" ADD CONSTRAINT "FK_OPERATIONS_BALANCE" FOREIGN KEY ("BALANCE_ID")
	  REFERENCES "VLAD_BORISOV"."BALANCE" ("ID") ON DELETE CASCADE ENABLE;
--------------------------------------------------------
--  DDL for Procedure CURSOR1
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."CURSOR1" (fdate in VARCHAR2,sdate in VARCHAR2,fart in int,sart in int,tart in int) is 
CURSOR get_procent(fdate  VARCHAR2,sdate VARCHAR2,fart int,sart int,tart int) IS SELECT article_id,(debit/((SELECT SUM(debit) FROM OPERATIONS where CREATE_DATE between 
fdate and sdate and ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart)))*100 as pdebit,(credit/((SELECT SUM(credit) FROM OPERATIONS where CREATE_DATE between 
fdate and sdate and ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart)))*100 as pcredit,((debit-credit)/((SELECT SUM(debit-CREDIT) FROM OPERATIONS where CREATE_DATE between 
fdate and sdate and ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart)))*100 as pcreditdebit FROM OPERATIONS where ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart;
x get_procent%ROWTYPE;
BEGIN
DBMS_OUTPUT.enable;
        for x in get_procent(fdate,sdate,fart,sart,tart)
        loop
          DBMS_OUTPUT.put_line('ARTICLE_ID: '||x.ARTICLE_ID||'|DEBIT: '||x.pdebit||'|CREDIT: '||x.pCREDIT||'|DEBIT-CREDIT: '||x.pcreditdebit);
        end loop;
END;

/
--------------------------------------------------------
--  DDL for Procedure CURSOR2
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."CURSOR2" (fdate in VARCHAR2,sdate in VARCHAR2,fart in int,sart in int,tart in int) is 
CURSOR get_procent(fdate  VARCHAR2,sdate VARCHAR2,fart int,sart int,tart int) IS SELECT article_id,(1/((SELECT count(debit) FROM OPERATIONS where CREATE_DATE between 
fdate and sdate and ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart)))*100 as pdebit,(1/((SELECT count(credit) FROM OPERATIONS where CREATE_DATE between 
fdate and sdate and ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart)))*100 as pcredit,(1/((SELECT count(debit-CREDIT) FROM OPERATIONS where CREATE_DATE between 
fdate and sdate and ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart)))*100 as pcreditdebit FROM OPERATIONS where ARTICLE_ID=fart or ARTICLE_ID=sart or ARTICLE_ID=tart;
x get_procent%ROWTYPE;
BEGIN
DBMS_OUTPUT.enable;
        for x in get_procent(fdate,sdate,fart,sart,tart)
        loop
          DBMS_OUTPUT.put_line('ARTICLE_ID: '||x.ARTICLE_ID||'|DEBIT: '||x.pdebit||'|CREDIT: '||x.pCREDIT||'|DEBIT-CREDIT: '||x.pcreditdebit);
        end loop;
END;

/
--------------------------------------------------------
--  DDL for Procedure LASTBAL
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."LASTBAL" as 
BEGIN 
  for T IN (SELECT * FROM OPERATIONS)
    loop
    DBMS_OUTPUT.put_line('ID: '||T.ID||'| Debit: '||T.DEBIT||'| Credit: '||T.CREDIT||'|Create_Date: '||T.CREATE_DATE||'| Article_ID: '||T.Article_ID||'|BALANCE_ID: 
'||T.BALANCE_ID);
    end loop;
END LASTBAL;

/
--------------------------------------------------------
--  DDL for Procedure MAXAMOUNT
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."MAXAMOUNT" as 
BEGIN 
  for T IN (SELECT * FROM BALANCE where (CREATE_DATE_BEGIN='01.01.2016' and CREATE_DATE_END='28.02.2016') AND AMOUNT=(SELECT MAX(AMOUNT) FROM BALANCE))
    loop
    DBMS_OUTPUT.put_line('ID: '||T.ID||'| Debit: '||T.DEBIT||'| Credit: '||T.CREDIT||'|Create_Date_Begin: '||T.CREATE_DATE_BEGIN||'|Create_Date_END: '||T.CREATE_DATE_END||'| Amount: '||T.AMOUNT);
    end loop;
END maxamount;

/
--------------------------------------------------------
--  DDL for Procedure PROC
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."PROC" (ARTICLEID IN NUMBER) as 
BEGIN 
for T in (SELECT * FROM BALANCE WHERE ID IN(SELECT Balance_id FROM OPERATIONS where article_id=ARTICLEID))
loop 
DBMS_OUTPUT.put_line('ID: '||T.ID||'| Debit: '||T.DEBIT||'| Credit: '||T.CREDIT||'|Create_Date: '||T.CREATE_DATE||'|AMOUNT:'||T.AMOUNT);
end loop;
END PROC;

/
--------------------------------------------------------
--  DDL for Procedure PROCEXIT2
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."PROCEXIT2" (Bal in NUMBER,particle out varchar2) as
BEGIN
SELECT name INTO particle FROM ARTICLES where ID in (SELECT article_id FROM operations where operations.BALANCE_ID=Bal and credit=(Select max(credit) from operations));
END PROCexit2;

/
--------------------------------------------------------
--  DDL for Procedure PROCEXIT3
--------------------------------------------------------
set define off;

  CREATE OR REPLACE PROCEDURE "VLAD_BORISOV"."PROCEXIT3" (Bal in NUMBER,particle out varchar2,maxdebit out int) as
BEGIN
SELECT article_id,DEBIT into particle,maxdebit from OPERATIONS where (balance_id=Bal and debit=(Select max(debit) from operations));
END PROCexit3;

/
