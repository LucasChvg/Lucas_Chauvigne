<%-- 
    Document   : index
    Created on : 16 oct. 2020, 17:40:00
    Author     : lucas
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<HTML>
    <HEAD>
        <TITLE>
            Titre
        </TITLE>
    </HEAD>
    <BODY>
        <form action="http://localhost:8080/tp_esaip_jdbc/TestJDBC" method="GET">
            <table>
                <tr>
                    <th><b>Numéro SSN</b></th>
                    <th><b>Multiplicateur</b></th>
                </tr>
                <c:forEach var="i" begin="0" end="3" step="1">
                    <tr>    
                        <td><input type="text" name="ssn"/></td>
                        <td><input type="number" name="multiplier"/></td>
                    </tr>
                </c:forEach>
            </table>
            <BUTTON>Submit</BUTTON>
            <input type="reset" value="Reinitialiser">
            
             <p><a href="/tp_esaip_jdbc/TestJDBC">Voir la liste des beans</a></p>
        </FORM>
    </BODY>
</HTML>