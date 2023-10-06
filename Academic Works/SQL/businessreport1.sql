/* Purpose of the business report is to check the profit that is made on each product so that hte company can make an informed decision regarding whether or not they should
continue a specific product, if a product is very profitable then they can continue to make more of that product*/
CREATE VIEW PROFITPERPODUCT AS
SELECT productid,description,PRICEEACH-COSTTOMAKE AS "profit"
FROM PRODUCTS;