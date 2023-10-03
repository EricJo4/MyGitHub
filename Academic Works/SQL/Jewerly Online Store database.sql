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
INSERT INTO Customers (CustomerId, firstName, lastName, phone, address)
VALUES (1, 'John', 'Doe', 1234567890, '123 Main St'),
       (2, 'Jane', 'Smith', 9876543210, '456 Elm St');
       
INSERT INTO ORDERS (OrderId, CustomerId, OrderDate)
VALUES (1001, 1, '2023-10-02'),
       (1002, 2, '2023-10-03');
    
INSERT INTO Products (PRODUCTID, PRICEEACH, DESCRIPTION, COSTTOMAKE)
VALUES (10000001, 19.99, 'Product A', 10.50),
       (10000002, 29.99, 'Product B', 15.75);
       
INSERT INTO ORDERDETAILS (PRODUCTID, OrderId, NUMORDERED, TOTAL, CostToMake)
VALUES (10000001, 1001, 3, 59.97, 31.50),
       (10000002, 1002, 2, 59.98, 31.50);
       
INSERT INTO Suppliers (SupplierId, SUPPLIERNAME, phone, address)
VALUES (1, 'Supplier X', '555-555-5555', '789 Supplier St'),
       (2, 'Supplier Y', '777-777-7777', '123 Supplier Ave');
       
INSERT INTO SuppliersProducts (PRODUCTID, SUPPLIERID)
VALUES (10000001, 1),
       (10000002, 2);
       
INSERT INTO Employees (EmployeeId, firstName, lastName, phone)
VALUES (1001, 'Alice', 'Johnson', '111-222-3333'),
       (1002, 'Bob', 'Smith', '444-555-6666');
       
INSERT INTO Retailers (RetailerId, address, phone)
VALUES (1, '123 Retailer St', '111-111-1111'),
       (2, '456 Retailer Ave', '222-222-2222');
       
INSERT INTO Inventory (RetailerId, ProductId, NumOfProducts)
VALUES (1, 10000001, 50),
       (2, 10000002, 30);