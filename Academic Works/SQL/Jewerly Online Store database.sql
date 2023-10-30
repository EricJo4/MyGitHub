--create entities 
CREATE TABLE Customers(
    CustomerId NUMBER(7) PRIMARY KEY,
    firstName VARCHAR(25) NOT NULL,
    lastName VARCHAR(25) NOT NULL,
    phone NUMBER(11) NOT NULL,
    address VARCHAR(100) ,
    CHECK(CustomerId >= 1 AND CustomerId <= 999999),
    CHECK(phone >= 2000000000 AND phone <= 9999999999)
    );
    
CREATE TABLE ORDERS(
    OrderId NUMBER(8) PRIMARY KEY,
    CustomerId NUMBER(7) NOT NULL,
    OrderDate DATE NOT NULL,
    CHECK(OrderId >= 1 AND OrderId <= 999999),
    CHECK(CustomerId >= 1 AND CustomerId <= 999999),
    FOREIGN KEY (CUSTOMERID) REFERENCES CUSTOMERS(CUSTOMERID)
);

CREATE TABLE Products(
  PRODUCTID NUMBER(8) PRIMARY KEY CHECK (PRODUCTID >= 10000000 AND PRODUCTID <=99999999),
  PRICEEACH NUMBER (7) NOT NULL  CHECK (PRICEEACH>= 1 AND PRICEEACH <= 9999),
  DESCRIPTION VARCHAR(25) NOT NULL,
  COSTTOMAKE NUMBER(7) NOT NULL  CHECK (COSTTOMAKE>= 1 AND COSTTOMAKE <= 9999)
    );
    
CREATE TABLE ORDERDETAILS(
    PRODUCTID NUMBER(8),
    OrderId NUMBER(8),
    NUMORDERED NUMBER(5) NOT NULL,
    TOTAL NUMBER(11) NOT NULL,
    CostToMake NUMBER(11) NOT NULL,
    FOREIGN KEY(PRODUCTID) REFERENCES PRODUCTS(PRODUCTID),
    FOREIGN KEY(OrderId) REFERENCES ORDERS(OrderId),
    PRIMARY KEY(PRODUCTID,ORDERID)
);

CREATE TABLE Suppliers(
    SupplierId NUMBER(4) PRIMARY KEY,
    SUPPLIERNAME VARCHAR(20),
    phone VARCHAR(12) NOT NULL,
    address VARCHAR(100) NOT NULL,
    CHECK(SupplierId > 0 AND SupplierId < 9999),
    CHECK(phone >= 2000000000 AND phone <= 9999999999)
    );
    
CREATE TABLE SuppliersProducts(
    PRODUCTID NUMBER(8),
    SUPPLIERID NUMBER(4),
    FOREIGN KEY (SUPPLIERID) REFERENCES SUPPLIERS(SUPPLIERID),
    FOREIGN KEY (PRODUCTID) REFERENCES PRODUCTS(PRODUCTID),
    PRIMARY KEY(PRODUCTID,SUPPLIERID)
    );
    
CREATE TABLE Employees(
    EmployeeId NUMBER(4) NOT NULL PRIMARY KEY,
    firstName VARCHAR(25) NOT NULL,
    lastName VARCHAR(25) NOT NULL,
    phone VARCHAR(12) NOT NULL UNIQUE,
    CHECK(EmployeeId > 0 AND EmployeeId < 10000),
    CHECK(phone >= 2000000000 AND phone <= 9999999999)
    );
    
CREATE TABLE Retailers(
    RetailerId NUMBER(4) NOT NULL PRIMARY KEY,
    address VARCHAR(50),
    phone VARCHAR(12) UNIQUE,
    CHECK(RetailerId > 0 AND ProductId < 10000),
    CHECK(REGEXP_LIKE(phone, '^\d{3}-\d{3}-\d{4}$'))
    ); 
    
CREATE TABLE Inventory(
    RetailerId NUMBER(4) NOT NULL PRIMARY KEY,
    ProductId NUMBER(8) NOT NULL PRIMARY KEY,
    NumOfProducts NUMBER(11) NOT NULL,
    Foreign Key(RetailerId) REFERENCES Retailers(RetailerId),
    CHECK(RetailerId > 0 AND ProductId < 10000),
    CHECK(ProductId > 9999999 AND ProductId < 100000000)
    );
    
--insert data
       
SET DEFINE OFF;
INSERT ALL
INTO customers VALUES('1001','Tom','Andes','4368880987','7 Andes Road')
INTO customers VALUES('1002','Jay','Kuo','4567891234','40 Mowt Crt')
INTO customers VALUES('1003','Kelly','Chen','4375678901','67 Bayview Dr')
INTO customers VALUES('1004','Ding','Zhang','6389907890','167 Tec Rd')
INTO customers VALUES('1005','Lay','Dylan','4569081289','1750 finch Ave')
INTO customers VALUES('1006','Jason','Xie','6479084890','95 Whitehorn Cre')
INTO customers VALUES('1007','Hong','Fan','4389086548','625 Seneca hill')
INTO customers VALUES('1008','Wei','Zhang','4562349087','55 Godstone Rd')
INTO customers VALUES('1009','Qing','Wang','3981893894','100 Consilium')
INTO customers VALUES('1010','Dou','Huang','4569081234','75 Goodview Rd')
INTO customers VALUES('1011','Ning','Lei','3896730981','3030 Don Mills Rd')
INTO customers VALUES('1012','Ray','Thomson','4895324960','408 Don Mills Rd')
INTO customers VALUES('1013','Nada','Liu','3209081890','89 Seneca Hill')
INTO customers VALUES('1014','Peyton','Wang','4903901893','1019 Sheppard Ave')
INTO customers VALUES('1015','Daisy','Wood','3001904800','1881 Leslie St')
INTO customers VALUES('1016','Elle','Ding','6009001000','17 Sulgrave Crescent')
INTO customers VALUES('1017','Erica','Lei','9852117980','25 Sulgrave Crescent')
INTO customers VALUES('1018','Dylan','Chen','9852117550','2534 Bayview Ave')
INTO customers VALUES('1019','Dili','lie','6093907788','856 York Milss Rd')
INTO customers VALUES('1020','Lin','Wu','5902349845','935 Queen St E')
SELECT * FROM DUAL;
INSERT ALL
INTO RETAILERS VALUES(1,'123 Maple Street, Toronto, ON M1A 2B3',2156789012)
INTO RETAILERS VALUES(2,'456 Oak Avenue, Toronto, ON M4C 1E2',2290123456)
INTO RETAILERS VALUES(3,'789 Willow Street, Toronto, ON L5X 2A4',2109876543)
INTO RETAILERS VALUES(4,'543 Elm Road, Toronto, ON T2J 7K9',2345678901)
INTO RETAILERS VALUES(5,'678 Cedar Lane, Toronto, ON H3G 8P6',2212345678)
INTO RETAILERS VALUES(6,'321 Pine Avenue, Toronto, ON V6R 2V9',2234567890)
INTO RETAILERS VALUES(7,'987 Birch Lane, Toronto, ON L4T 3E1',2287654321)
INTO RETAILERS VALUES(8,'654 Spruce Drive, Toronto, ON N2L 4T2',2265432109)
INTO RETAILERS VALUES(9,'234 Ash Street, Toronto, ON K7L 5K5',2221098765)
SELECT * FROM DUAL;
INSERT ALL
INTO orders VALUES(9001,1001,2,TO_DATE('2021-01-01','YYYY-MM-DD'))
INTO orders VALUES(9002,1001,1,TO_DATE('2021-01-03','YYYY-MM-DD'))
INTO orders VALUES(9003,1001,4,TO_DATE('2021-01-03','YYYY-MM-DD'))
INTO orders VALUES(9004,1002,3,TO_DATE('2021-01-01','YYYY-MM-DD'))
INTO orders VALUES(9005,1003,2,TO_DATE('2021-01-03','YYYY-MM-DD'))
INTO orders VALUES(9006,1004,2,TO_DATE('2021-01-03','YYYY-MM-DD'))
INTO orders VALUES(9007,1002,1,TO_DATE('2021-01-01','YYYY-MM-DD'))
INTO orders VALUES(9008,1003,5,TO_DATE('2021-01-03','YYYY-MM-DD'))
INTO orders VALUES(9009,1004,6,TO_DATE('2021-01-05','YYYY-MM-DD'))
INTO orders VALUES(9010,1005,7,TO_DATE('2021-01-06','YYYY-MM-DD'))
INTO orders VALUES(9011,1007,5,TO_DATE('2021-01-05','YYYY-MM-DD'))
INTO orders VALUES(9012,1009,3,TO_DATE('2021-01-06','YYYY-MM-DD'))
INTO orders VALUES(9013,1005,2,TO_DATE('2021-01-05','YYYY-MM-DD'))
INTO orders VALUES(9014,1007,2,TO_DATE('2021-01-05','YYYY-MM-DD'))
INTO orders VALUES(9015,1009,1,TO_DATE('2021-01-02','YYYY-MM-DD'))
INTO orders VALUES(9016,1005,4,TO_DATE('2021-01-03','YYYY-MM-DD'))
INTO orders VALUES(9017,1007,3,TO_DATE('2021-01-09','YYYY-MM-DD'))
INTO orders VALUES(9018,1009,4,TO_DATE('2021-01-02','YYYY-MM-DD'))
INTO orders VALUES(9019,1007,3,TO_DATE('2021-01-09','YYYY-MM-DD'))
INTO orders VALUES(9020,1009,4,TO_DATE('2021-01-02','YYYY-MM-DD'))
SELECT * FROM DUAL;
INSERT ALL
INTO PRODUCTS VALUES(10000001,40,'Sapphire Necklace',15)
INTO PRODUCTS VALUES(10000002,85,'Diamond Earrings',20)
INTO PRODUCTS VALUES(10000003,95,'Emerald Ring',15)
INTO PRODUCTS VALUES(10000004,50,'Ruby Bracelet',20)
INTO PRODUCTS VALUES(10000005,60,'Pearl Brooch',15)
INTO PRODUCTS VALUES(10000006,30,'Amethyst Pendant',10)
INTO PRODUCTS VALUES(10000007,75,'Topaz Anklet',15)
INTO PRODUCTS VALUES(10000008,50,'Opal Tiara',5)
INTO PRODUCTS VALUES(10000009,80,'Garnet Cufflinks',15)
INTO PRODUCTS VALUES(10000010,10,'Aquamarine Pin',5)
INTO PRODUCTS VALUES(10000011,65,'Tanzanite Necklace',15)
INTO PRODUCTS VALUES(10000012,30,'Peridot Earrings',5)
INTO PRODUCTS VALUES(10000013,45,'Citrine Ring',10)
INTO PRODUCTS VALUES(10000014,55,'Tourmaline Bracelet',10)
INTO PRODUCTS VALUES(10000015,90,'Onyx Brooch',20)
INTO PRODUCTS VALUES(10000016,35,'Moonstone Pendant',5)
INTO PRODUCTS VALUES(10000017,25,'Silver Bracelet',5)
INTO PRODUCTS VALUES(10000018,70,'Gold Earrings',15)
INTO PRODUCTS VALUES(10000019,55,'Rose Ring',10)
INTO PRODUCTS VALUES(10000020,40,'Platinum Necklace',15)
INTO PRODUCTS VALUES(10000021,65,'Crystal Brooch',15)
INTO PRODUCTS VALUES(10000022,75,'Amber Anklet',20)
INTO PRODUCTS VALUES(10000023,90,'Jade Tiara',20)
INTO PRODUCTS VALUES(10000024,50,'Sapphire Cufflinks',10)
INTO PRODUCTS VALUES(10000025,35,'Pearl Pin',5)
SELECT * FROM DUAL;
INSERT ALL
INTO ORDERDETAILS VALUES(9001,10000001,5,200)
INTO ORDERDETAILS VALUES(9002,10000002,8,680)
INTO ORDERDETAILS VALUES(9003,10000003,3,45)
INTO ORDERDETAILS VALUES(9004,10000004,6,120)
INTO ORDERDETAILS VALUES(9005,10000005,2,30)
INTO ORDERDETAILS VALUES(9006,10000006,4,40)
INTO ORDERDETAILS VALUES(9007,10000007,7,105)
INTO ORDERDETAILS VALUES(9008,10000008,1,5)
INTO ORDERDETAILS VALUES(9009,10000009,9,720)
INTO ORDERDETAILS VALUES(9010,10000010,5,25)
INTO ORDERDETAILS VALUES(9011,10000011,3,45)
INTO ORDERDETAILS VALUES(9012,10000012,7,35)
INTO ORDERDETAILS VALUES(9013,10000013,6,60)
INTO ORDERDETAILS VALUES(9014,10000014,4,40)
INTO ORDERDETAILS VALUES(9015,10000015,2,40)
INTO ORDERDETAILS VALUES(9016,10000016,1,5)
INTO ORDERDETAILS VALUES(9017,10000017,8,40)
INTO ORDERDETAILS VALUES(9018,10000018,5,75)
INTO ORDERDETAILS VALUES(9019,10000019,3,30)
INTO ORDERDETAILS VALUES(9020,10000020,7,105)
SELECT * FROM DUAL;
INSERT ALL
INTO EMPLOYEES VALUES (1,1,'John','Doe','Sales Associate','1234 Jewel Street, Cityville','john.d@example.com','2345678901')
INTO EMPLOYEES VALUES (2,2,'Jane','Smith','Manager','5678 Gem Avenue, Townsville','jane.s@example.com','2345678902')
INTO EMPLOYEES VALUES (3,3,'Michael','Johnson','Jewelry Specialist','789 Diamond Lane, Gemtown','michael.j@example.com','2345678903')
INTO EMPLOYEES VALUES (4,4,'Emily','Williams','Gemstone Expert','456 Sapphire Road, Jewel City','emily.w@example.com','2345678904')
INTO EMPLOYEES VALUES (5,5,'William','Brown','Customer Service','234 Ruby Street, Preciousville','william.b@example.com','2345678905')
INTO EMPLOYEES VALUES (6,6,'Elizabeth','Jones','Sales Associate','789 Gold Boulevard, Diamondville','elizabeth.j@example.com','2345678906')
INTO EMPLOYEES VALUES (7,7,'David','Garcia','Gemologist','123 Silver Lane, Gemstone City','david.g@example.com','2345678907')
INTO EMPLOYEES VALUES (8,8,'Sarah','Martinez','Manager','567 Pearl Avenue, Jeweltown','sarah.m@example.com','2345678908')
INTO EMPLOYEES VALUES (9,9,'James','Hernandez','Sales Associate','890 Crystal Road, Gemville','james.h@example.com','2345678909')
INTO EMPLOYEES VALUES (10,1,'Emma','Lopez','Jewelry Specialist','345 Opal Street, Precious City','emma.l@example.com','2345678910')
INTO EMPLOYEES VALUES (11,2,'Christopher','Gonzalez','Gemstone Expert','678 Amethyst Lane, Jewelville','christopher.g@example.com','2345678911'
)
INTO EMPLOYEES VALUES (12,3,'Olivia','Wilson','Customer Service','901 Topaz Avenue, Gemtown','olivia.w@example.com','2345678912')
INTO EMPLOYEES VALUES (13,4,'Daniel','Taylor','Sales Associate','234 Garnet Road, Preciousville','daniel.t@example.com','2345678913')
INTO EMPLOYEES VALUES (14,5,'Sophia','Lee','Gemologist','567 Jade Street, Diamondville','sophia.l@example.com','2345678914')
INTO EMPLOYEES VALUES (15,6,'Matthew','Evans','Manager','890 Crystal Avenue, Gemstone City','matthew.e@example.com','2345678915')
INTO EMPLOYEES VALUES (16,7,'Ava','Perez','Sales Associate','123 Ruby Lane, Jeweltown','ava.p@example.com','2345678916')
INTO EMPLOYEES VALUES (17,8,'Andrew','Gomez','Jewelry Specialist','456 Gold Street, Gemville','andrew.g@example.com','2345678917')
INTO EMPLOYEES VALUES (18,9,'Isabella','Rivera','Gemstone Expert','789 Pearl Road, Precious City','isabella.r@example.com','2345678918')
INTO EMPLOYEES VALUES (19,1,'William','Reyes','Customer Service','123 Diamond Avenue, Gemtown','william.r@example.com','2345678919')
INTO EMPLOYEES VALUES (20,2,'Mia','Stewart','Sales Associate','567 Sapphire Lane, Jewel City','mia.s@example.com','2345678920')
INTO EMPLOYEES VALUES (21,3,'Ethan','Morales','Manager','890 Silver Avenue, Diamondville','ethan.m@example.com','2345678921')
INTO EMPLOYEES VALUES (22,4,'Victoria','Murphy','Sales Associate','234 Ruby Road, Gemstone City','victoria.m@example.com','2345678922')
INTO EMPLOYEES VALUES (23,5,'Alexander','Cook','Gemologist','567 Gold Lane, Gemville','alexander.c@example.com','2345678923')
INTO EMPLOYEES VALUES (24,6,'Liam','Rogers','Jewelry Specialist','890 Diamond Street, Preciousville','liam.r@example.com','2345678924')
INTO EMPLOYEES VALUES (25,7,'Abigail','Gutierrez','Gemstone Expert','123 Amethyst Avenue, Jeweltown','abigail.g@example.com','2345678925')
SELECT * FROM DUAL;
INSERT ALL
INTO INVENTORY VALUES (1,10000001,25)
INTO INVENTORY VALUES (2,10000002,35)
INTO INVENTORY VALUES (3,10000003,15)
INTO INVENTORY VALUES (4,10000004,45)
INTO INVENTORY VALUES (5,10000005,20)
INTO INVENTORY VALUES (6,10000006,30)
INTO INVENTORY VALUES (7,10000007,40)
INTO INVENTORY VALUES (8,10000008,10)
INTO INVENTORY VALUES (9,10000009,50)
INTO INVENTORY VALUES (1,10000010,30)
INTO INVENTORY VALUES (2,10000011,25)
INTO INVENTORY VALUES (3,10000012,20)
INTO INVENTORY VALUES (4,10000013,15)
INTO INVENTORY VALUES (5,10000014,35)
INTO INVENTORY VALUES (6,10000015,40)
INTO INVENTORY VALUES (7,10000016,10)
INTO INVENTORY VALUES (8,10000017,30)
INTO INVENTORY VALUES (9,10000018,25)
INTO INVENTORY VALUES (1,10000019,50)
INTO INVENTORY VALUES (2,10000020,20)
INTO INVENTORY VALUES (3,10000021,45)
INTO INVENTORY VALUES (4,10000022,15)
INTO INVENTORY VALUES (5,10000023,35)
INTO INVENTORY VALUES (6,10000024,30)
INTO INVENTORY VALUES (7,10000025,40)
INTO INVENTORY VALUES (8,10000001,10)
INTO INVENTORY VALUES (9,10000002,50)
INTO INVENTORY VALUES (1,10000003,25)
INTO INVENTORY VALUES (2,10000004,35)
INTO INVENTORY VALUES (3,10000005,20)
INTO INVENTORY VALUES (4,10000006,30)
INTO INVENTORY VALUES (5,10000007,40)
SELECT * FROM DUAL;
INSERT ALL
INTO SUPPLIERS VALUES (1,'ABC Jewelers',2123456789,'1234 Diamond Street, Cityville')
INTO SUPPLIERS VALUES (2,'Gemstone Emporium',2987654321,'567 Ruby Avenue, Gemtown')
INTO SUPPLIERS VALUES (3,'Golden Charms',2876543210,'789 Gold Lane, Precious City')
INTO SUPPLIERS VALUES (4,'Silver Creations',2654321987,'456 Silver Road, Shimmerland')
INTO SUPPLIERS VALUES (5,'Gems & Pearls',2498765432,'234 Pearl Street, Lustrousville')
INTO SUPPLIERS VALUES (6,'Crystal Dreams',2765432189,'678 Crystal Avenue, Sparkleton')
INTO SUPPLIERS VALUES (7,'JewelCrafters',2912345678,'789 Gemstone Lane, Sparkletown')
INTO SUPPLIERS VALUES (8,'Diamond Delights',2123456789,'345 Diamond Road, Gemcity')
INTO SUPPLIERS VALUES (9,'Opulent Ornaments',2321546879,'567 Gold Avenue, Luxuria')
INTO SUPPLIERS VALUES (10,'Royal Jewels',2548976532,'123 Ruby Street, Crownsville')
INTO SUPPLIERS VALUES (11,'Pearl Palace',2698734502,'789 Pearl Lane, Seashore City')
INTO SUPPLIERS VALUES (12,'Sapphire Shores',2145678902,'345 Sapphire Road, Azuretown')
INTO SUPPLIERS VALUES (13,'Emerald Essence',2512345678,'678 Emerald Avenue, Greenburg')
INTO SUPPLIERS VALUES (14,'Treasure Trove',2765432109,'890 Diamond Street, Richland')
INTO SUPPLIERS VALUES (15,'Crystal Cove',2923456781,'234 Crystal Lane, Crystalline City')
INTO SUPPLIERS VALUES (16,'Gold Rush',2132145678,'345 Gold Road, Goldville')
INTO SUPPLIERS VALUES (17,'Gem Galaxy',2198765432,'678 Gemstone Avenue, Starville')
INTO SUPPLIERS VALUES (18,'Silver Linings',2121345678,'890 Silver Lane, Silverville')
INTO SUPPLIERS VALUES (19,'GemCraft',2154321098,'123 Gemstone Street, Gemford')
INTO SUPPLIERS VALUES (20,'Diamond Haven',2123456780,'345 Diamond Road, Sparkleville')
SELECT * FROM DUAL;
INSERT ALL
INTO SUPPLIERSPRODUCTS VALUES (1,10000001)
INTO SUPPLIERSPRODUCTS VALUES (2,10000002)
INTO SUPPLIERSPRODUCTS VALUES (3,10000003)
INTO SUPPLIERSPRODUCTS VALUES (4,10000004)
INTO SUPPLIERSPRODUCTS VALUES (5,10000005)
INTO SUPPLIERSPRODUCTS VALUES (6,10000006)
INTO SUPPLIERSPRODUCTS VALUES (7,10000007)
INTO SUPPLIERSPRODUCTS VALUES (8,10000008)
INTO SUPPLIERSPRODUCTS VALUES (9,10000009)
INTO SUPPLIERSPRODUCTS VALUES (10,10000010)
INTO SUPPLIERSPRODUCTS VALUES (11,10000011)
INTO SUPPLIERSPRODUCTS VALUES (12,10000012)
INTO SUPPLIERSPRODUCTS VALUES (13,10000013)
INTO SUPPLIERSPRODUCTS VALUES (14,10000014)
INTO SUPPLIERSPRODUCTS VALUES (15,10000015)
INTO SUPPLIERSPRODUCTS VALUES (16,10000016)
INTO SUPPLIERSPRODUCTS VALUES (17,10000017)
INTO SUPPLIERSPRODUCTS VALUES (18,10000018)
INTO SUPPLIERSPRODUCTS VALUES (19,10000019)
INTO SUPPLIERSPRODUCTS VALUES (20,10000020)
SELECT * FROM DUAL;