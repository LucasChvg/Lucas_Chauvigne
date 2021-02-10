import smbus
import time

bus=smbus.SMBus(1)
address= 0x12

#list_plant = []
list_data = []

delai = 30 #Temps en seconde
nextTime=0

DB_HOST = '127.0.0.1'
DB_USER = 'root'
DB_PASSWORD = 'root'
DB_SCHEMA = 'potaco_bdd'
#DB_TBL_PREFIX = 'data'

import MySQLdb

db = MySQLdb.connect(host=DB_HOST, user=DB_USER, passwd=DB_PASSWORD, db=DB_SCHEMA)

dbc=db.cursor()

dbc.execute("SELECT id FROM cultive")

list_plant = dbc.fetchall()



plant1 = list_plant[0][0]
plant2 = list_plant[1][0]
    
print(plant1)
print(plant2)
reponse = [0,0,0,0,0,0]

while(True):
    if(time.time() > nextTime):
        nextTime = time.time()+delai

        for i in range(5):
            reponse[i] = bus.read_byte(address)
        
        print("reponse :")
        print(reponse)
        
        
        #x = str(reponse).split(",")
        
        print("Split :")
        print(reponse)
        
        print("TABLEAU :")
        VAL_HTERRE_1 = reponse[0]
        VAL_HTERRE_2 = reponse[1]
        VAL_H = reponse[2]
        VAL_T = reponse[3]
        VAL_LUM = reponse[4]
        VAL_NIV_EAU = reponse[5]

        #print(x)
        #ordre des valeurs : VAL_HTERRE_1,  VAL_HTERRE_2,  VAL_H,  VAL_T,  VAL_LUM,  VAL_NIV_EAU

        #plante gauche

        if(list_plant[0] != ""):
            dbc.execute("UPDATE data SET id_plant_capteur='%s', data_eau='%s', data_temperature='%s', data_humidite='%s', data_expo='%s' WHERE id_plant_capteur = '%s'; ", (plant1,VAL_NIV_EAU,VAL_T,VAL_HTERRE_1,VAL_LUM,plant1))
            db.commit()
            print ("Database update for left plant")
            
        else:
            print ("No plant (left)")
        

        
        #plante droite

        if(list_plant[1] != ""):
            dbc.execute("UPDATE data SET id_plant_capteur='%s', data_eau='%s', data_temperature='%s', data_humidite='%s', data_expo='%s' WHERE id_plant_capteur = '%s'; ", (plant2,VAL_NIV_EAU,VAL_T,VAL_HTERRE_2,VAL_LUM,plant2))
            db.commit()
            print ("Database update for right plant")
            
        else:
            print ("No plant (right)")



db.close()
