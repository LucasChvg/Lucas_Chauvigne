import random
import string
## coding: utf8

print("♥♦♣♠")

class Carte:
    nbCarte = 0

    def __init__(self):
        self._find = 0
        Carte.nbCarte += 1

    def Setfind(self,find):
        self._find=find

    def Getfind(self):
        return self._find

    def Getsymbole(self):
        return self._symbole

    def GetsymboleN(self, n):
        return self._symbole[n]


class CarteJeu(Carte):
    def __init__(self, symbole="AAAA"):
        Carte.__init__(self)
        self._symbole = symbole
        if self._symbole[2] == "♥" or self._symbole[2] == "♦":
            self._couleur = "rouge"
        else:
            self._couleur = "noir"

    def Getcouleur(self):
        return self._couleur

class CarteLettre(Carte):
    def __init__(self, symbole="AAAA"):
        Carte.__init__(self)
        self._symbole = symbole

    def Getcouleur(self):
        return 0






#Class correspondant au jeu lui même
class Memory:

    def __init__(self):

        # Tableaux des symboles (Lettre ou paquet de 32 cartes)
        self._tabJeuCarte=[" 1♥ ", " 1♠ ", " 1♦ ", " 1♣ ", " 7♥ ", " 7♦ ",
                     " 7♠ ", " 7♣ ", " 8♥ ", " 8♦ ", " 8♠ ", " 8♣ ",
                     " 9♥ ", " 9♦ ", " 9♠ ", " 9♣ ", "10♥ ", "10♦ ",
                     "10♠ ", "10♣ ", " V♥ ", " V♦ ", " V♠ ", " V♣ ",
                     " D♥ ", " D♦ ", " D♠ ", " D♣ ", " R♥ ", " R♦ ", " R♠ ", " R♣ "]

        self._tabJeuLettre =["AAAA","AAAA","BBBB","BBBB","CCCC","CCCC","DDDD","DDDD","EEEE",\
                      "EEEE","FFFF","FFFF","GGGG","GGGG","HHHH","HHHH","IIII","IIII",\
                      "JJJJ","JJJJ","KKKK","KKKK","LLLL","LLLL",'MMMM',"MMMM","NNNN",\
                      "NNNN","OOOO","OOOO","PPPP","PPPP","QQQQ","QQQQ","RRRR","RRRR"]

        #On creer notre tableau de cartes
        self._tabCarte = []

        print("========================")
        print("♥♠♦♣ JEU DE MEMORY ♥♠♦♣")
        print("========================"); print();  # Message d'accueil

        self._choix = int(self.ChoixTypeCarte()) # Choix du type de carte (Lettre ou paquet de 32 cartes)

        self._nbCarte = self.choix_nb()          # Choix du nombre de carte souhaité

        self.Creationtab()

        self._select=None     #initialisation des variables permettant le fonctionnement du jeu
        self._select2=None
        self._duoTrouve = 0
        self._essaie = 0;




        random.shuffle(self._tabCarte) # Mélange du tableau de façon aléatoire

        duoTrouve = 0 # Variable qui permet de compter le nombre de pairs trouvées
        essaie = 0     # Variable pour compter le nombre d'essaie


    def Creationtab(self):

        # Choix du type de carte (Lettre ou paquet de 32 cartes)
        # Si le joueur a choisi de joueur avec les symboles Lettres, alors on creer toutes les cartes en prenant en compte le tableau de symboles Lettre
        if (self._choix == 1):
            for i in range(0, self._nbCarte):
                self._tabCarte.append(CarteLettre(self._tabJeuLettre[i]));

        # Sinon on fait de même avec le tableau de symboles Jeu
        if (self._choix == 2):
            for i in range(0, self._nbCarte):
                self._tabCarte.append(CarteJeu(self._tabJeuCarte[i]));

        # On affiche une premiere fois la grille
        for i in range(0, self._nbCarte):
            if (i < 10):
                print("0", end='')
            print(str(i) + "[****] ", end=' ')
            if ((i + 1) % 4 == 0 and i != 0):
                print()
    def ChoixTypeCarte(self):
        while True:
            try:
                print("Avec quel type de carte jouer : (1) Lettres, (2) Carte a Jouer :")
                self._choix = int(input())        # Le joueur entre un nombre

                #On verifie que le joueur a bien entré la valeur 1 ou 2
                if self._choix == 1 or self._choix == 2:
                    return int(self._choix)
                else:
                    print("valeur entre 1 et 2 necessaire")

            # si ce n'est pas une nombre
            except ValueError:
                print("le nombre dois etre entre 1 et 2")

    # Choix du nombre de carte souhaité
    def choix_nb(self) :

        # On redemmande une entrée tant que celle-ci n'est pas correcte
        while True:
            try:
                print("avec Combien de cartes voulez-vous jouer ? (min : 6, max: 32)")
                self._nbCarte = int(input())    # Le joueur entre un nombre

                # On verfie que le nombre soit pair, et qu'il soit dans l'intervale [6,32]
                if self._nbCarte < 6 or self._nbCarte > 32 or self._nbCarte % 2 != 0:
                    print("Veuillez entrer une valeur pair comprise entre 6 et 32")
                else:
                    return int(self._nbCarte)

            # si ce n'est pas une nombre
            except ValueError:
                print("Veuillez entrer une valeur pair comprise entre 6 et 32")

    #Selection d'une carte
    def InputCarte(self):

        # On redemmande une entrée tant que celle-ci n'est pas correcte
        while True:
            try:
                print("Entrez n° de la carte (-1 pour quitter)", end=" : ")
                select = int(input())                       # Le joueur entre un nombre

                # On verfie que le nombre correspond bien à une carte, qu'elle n'a pas déja été trouvé
                if select >= -1 and select < self._nbCarte and self._tabCarte[select].Getfind() == 0 :
                    return select
                else:
                    print("Valeur incorrecte")

            # si ce n'est pas une nombre
            except ValueError:
                print("le nombre dois etre entre 1 et " + str(self._nbCarte))

    #Fonction d'affichage
    def Affichage(self):
        for i in range(0, self._nbCarte): # On boucle l'ensemble des cartes

            # Pour les chiffres de 0 à 9, on rajoute un "0" devant pour ne pas créer un décalage à l'affichage
            if (i < 10):
                print("0", end='')

            # On affiche le symbole si la carte a été séléctionné
            if (i == self._select or i == self._select2):
                print(str(i) + "[" + self._tabCarte[i].Getsymbole() + "] ", end=' ')

            # On affiche le symbole si la pair à déja été trouvé
            elif (self._tabCarte[i].Getfind() == 1):
                print(str(i) + "[" + self._tabCarte[i].Getsymbole() + "] ", end=' ')

            # Sinon on affiche pas le symbole, mais "****"
            else:
                print(str(i) + "[****] ", end=' ')

            # retour à la ligne tous les 4 affichages
            if ((i + 1) % 4 == 0 and i != 0):
                print()

    def jeu(self):
        while (self._duoTrouve!=(self._nbCarte/2)): # "tant que toutes les pairs n'ont pas été trouvé"
            print()
            print()
            self._select = None
            self._select2 = None    # On réinitialise les deux variables de selection

            self._fini = False

            print("CARTE N°1 :")
            self._select = self.InputCarte()  # l'utilisateur entre la premiere carte

            if (self._select == -1):     # si la carte séléctionné est "-1" alors on quite le jeu
                break;

            self.Affichage()            # Affichage du tableau

            print()
            print()

            print("CARTE N°2 :")


            while(True):
                self._select2 = self.InputCarte()  # l'utilisateur entre la seconde carte

                #On vérifie que le joueur n'entre pas deux fois la même carte
                if self._select2 != self._select:
                    break;
                else:
                    print("veuillez selectionner deux cartes différentes")


            if (self._select2 == -1):    # si la carte séléctionné est "-1" alors on quite le jeu
                break;

            self.Affichage()            # Affichage du tableau

            self._essaie +=1;            # On compte l'essaie

            # On verifie si les deux cartes sont des pairs
            if(self._tabCarte[self._select].GetsymboleN(1) == self._tabCarte[self._select2].GetsymboleN(1) and self._tabCarte[self._select].Getcouleur() == self._tabCarte[self._select2].Getcouleur()):
                self._tabCarte[self._select].Setfind(1)
                self._tabCarte[self._select2].Setfind(1)
                self._duoTrouve += 1

            # On verifie si toutes les pairs on été trouvé
            if(self._duoTrouve == (self._nbCarte/2)):
                print()
                print()
                print("============================")
                print("           BRAVO !")
                print("Vous avez reussi en " + str(self._essaie) + " coups")
                print("============================")


Memory = Memory()
Memory.jeu()
