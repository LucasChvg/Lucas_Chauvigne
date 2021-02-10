/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bdd;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import model.Bean;

public class TestJDBC {

    private List<String> messages = new ArrayList();

    public List<String> getMessages() {
        return this.messages;
    }

    public void addBeans(List<Bean> beans) {
        try {
            //Chargement du driver
            Class.forName("org.apache.derby.jdbc.ClientDriver");  //« "org.apache.derby.jdbc.ClientDriver«  for derby    , String ssn, int multiplier
        } catch (ClassNotFoundException e) {
            messages.add("Erreur lors du chargement : le driver n'a pas été trouvé dans le classpath ! <br/>"
                    + e.getMessage());
        }
        /* Connexion à la base de données */
        String url = "jdbc:derby://localhost:1527/test";
        String utilisateur = "test";
        String motDePasse = "test";
        Connection connexion = null;
        Statement statement = null;

        try {
            //Connexion à la base de données
            connexion = DriverManager.getConnection(url, utilisateur, motDePasse);

            /* Création de l'objet gérant les requêtes */
            statement = connexion.createStatement();

            for (Bean b : beans) {
                statement.execute("INSERT INTO jdbctp4 (ssn, bonus) VALUES ('" + b.getSsn() + "', " + b.getBonus() + ")");
                //Objet requête créé
            }

        } catch (SQLException e) {
            messages.add("Erreur lors de la connexion : <br/>"
                    + e.getMessage());
        } finally {
            messages.add("Fermeture de l'objet Statement.");
            if (statement != null) {
                try {
                    statement.close();
                } catch (SQLException ignore) {
                }
            }
            messages.add("Fermeture de l'objet Connection.");
            if (connexion != null) {
                try {
                    connexion.close();
                } catch (SQLException ignore) {
                }
            }
        }
    }

    public List<Bean> getBeans() {
        try {
            //Chargement du driver
            Class.forName("org.apache.derby.jdbc.ClientDriver");  //« "org.apache.derby.jdbc.ClientDriver«  for derby    , String ssn, int multiplier
        } catch (ClassNotFoundException e) {
            messages.add("Erreur lors du chargement : le driver n'a pas été trouvé dans le classpath ! <br/>"
                    + e.getMessage());
        }
        /* Connexion à la base de données */
        String url = "jdbc:derby://localhost:1527/test";
        String utilisateur = "test";
        String motDePasse = "test";
        Connection connexion = null;
        Statement statement = null;
        ResultSet resultat = null;
        
        ArrayList<Bean> beans = new ArrayList();

        try {
            //Connexion à la base de données
            connexion = DriverManager.getConnection(url, utilisateur, motDePasse);

            /* Création de l'objet gérant les requêtes */
            statement = connexion.createStatement();

            /* Exécution d'une requête de lecture */
            resultat = statement.executeQuery("SELECT * FROM jdbctp4");

            messages.add("Requête \"SELECT * FROM jdbctp4;\" effectuée !");
            /* Récupération des données du résultat de la requête de lecture */
            while (resultat.next()) {
                int id = resultat.getInt("id");
                String ssn = resultat.getString("ssn");
                int bonus = resultat.getInt("bonus");
                
                Bean b = new Bean();
                b.setSsn(ssn);
                b.setBonus(bonus);
                beans.add(b);
            }
        } catch (SQLException e) {
            messages.add("Erreur lors de la connexion : <br/>"
                    + e.getMessage());
        } finally {
            messages.add("Fermeture de l'objet ResultSet.");
            if (resultat != null) {
                try {
                    resultat.close();
                } catch (SQLException ignore) {
                }
            }
            messages.add("Fermeture de l'objet Statement.");
            if (statement != null) {
                try {
                    statement.close();
                } catch (SQLException ignore) {
                }
            }
            messages.add("Fermeture de l'objet Connection.");
            if (connexion != null) {
                try {
                    connexion.close();
                } catch (SQLException ignore) {
                }
            }
        }

        return beans;
    }

}
