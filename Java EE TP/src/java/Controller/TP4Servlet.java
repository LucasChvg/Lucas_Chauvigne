/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import bdd.TestJDBC;
import java.io.IOException;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import model.Bean;

/**
 *
 * @author lucas
 */
@WebServlet(name = "TP4Servlet", urlPatterns = {"/TestJDBC"})
public class TP4Servlet extends HttpServlet {

    public static final String ATT_MESSAGES = "messages";
    public static final String VUE = "/WEB-INF/test_jdbc.jsp";

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");

        TestJDBC jdbc = new TestJDBC();

        String[] ssns = request.getParameterMap().get("ssn");
        String[] multis = request.getParameterMap().get("multiplier");

        ArrayList<Bean> beans = new ArrayList();

        if (ssns != null) {
            for (int i = 0; i < ssns.length; i++) {
                Bean b = new Bean();
                b.setSsn(ssns[i]);
                if (multis[i] != "") {
                    int multiplier = Integer.parseInt(multis[i]);
                    b.setMultiplier(multiplier);
                    b.setBonus(multiplier * 100);
                } else {
                    b.setMultiplier(0);
                    b.setBonus(0);
                }
                beans.add(b);
            }

            // Ajouter la liste à la BDD 
            jdbc.addBeans(beans);
        }

        // Récupérer la liste complète depuis la BDDD et l'afficher
        request.setAttribute(ATT_MESSAGES, jdbc.getMessages());
        request.setAttribute("beans", jdbc.getBeans());

        // Transmission vers la page en charge de l'affichage des résultats 
        this.getServletContext().getRequestDispatcher(VUE).forward(request, response);
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
