<?php
            /*$servername = 'localhost';
            $username = 'root';
            $password = '';
            
            //On essaie de se connecter
            try{
                $bdd = new PDO("mysql:host=$servername;dbname=potager_connecte", $username, $password);
                //On définit le mode d'erreur de PDO sur Exception
                $bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            }
            
            /*On capture les exceptions si une exception est lancée et on affiche
             *les informations relatives à celle-ci
            catch(PDOException $e){
              echo "Erreur : " . $e->getMessage();
            }*/
$db = new mysqli("localhost", "root", "", "potager_connecte");
if ($db->connect_errno) {
    echo "Echec lors de la connexion à MySQL : (" . $db->connect_errno . ") " . $db->connect_error;
}


?>
