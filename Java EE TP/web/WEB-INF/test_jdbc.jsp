<%-- 
    Document   : test_jdbc
    Created on : 16 oct. 2020, 15:32:02
    Author     : lucas
--%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>Tests JDBC</title>
        <link type="text/css" rel="stylesheet" href="<c:url value="/inc/form.css"/>" />
    </head>
    <body>
        <h1>Résultats BDD</h1>
        <table>
            <tr>
                <th><b>Numéro SSN</b></th>
                <th><b>Multiplicateur</b></th>
            </tr>
            <c:forEach items="${beans}" var="b">
                <tr>    
                    <td>${b.getSsn()}</td>
                    <td>${b.getBonus()}</td>
                </tr>
            </c:forEach>
        </table>

        <p><a href="/tp_esaip_jdbc">Revenir à la page d'accueil</a></p>


        <h1>Messages</h1>

        <c:forEach items="${ messages }" var="message" varStatus="boucle">
            <p>${ boucle.count }. ${ message }</p>
        </c:forEach>
    </body>
</html>