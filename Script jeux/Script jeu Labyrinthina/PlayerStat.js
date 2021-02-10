#pragma strict

var grenade : int = 2;
var maxClippist : int = 32;
var maxClip : int = 150;
var m_repere = 20;
var Bras : GameObject;
var deathScreen : GameObject;
//private var MouseLock : UnLockMouse;

//var FPC : GameObject;

private var attackTime : float;
var tempsRepetitionAtt : float = 0.1f;

private var currentZombies : GameObject[]; //list of zombie on the map

var vieBase : int = 100;
var vieMax : int = 100;

var canApplyDammage : boolean = true;

var attaque : boolean = false;
var mort : boolean = false;
var compte : float;

private var i : int;

function Start(){
	attackTime = Time.time;
	compte = Bras.transform.rotation.x;
	Bras.SetActive(false);
	//MouseLock = GameObject.Find("FPSController").GetComponent(UnLockMouse);
	//fpsControllerMouse = GameObject.Find("Stat").GetComponent(FirstPersonController);
}
function Update(){
	
	currentZombies = GameObject.FindGameObjectsWithTag("zombie");
	
	if(attaque==true){
		if(Time.time > attackTime && mort==false){
			Bras.transform.Rotate(2.0f, 0.0f, 0.0f, Space.Self);
			attackTime = Time.time + tempsRepetitionAtt;
			compte++;
			compte++;
			if(compte>80){
				mort=true;
				attaque=false;
				compte=0;
			}
		}
	}
	if(mort == true){
		deathScreen.SetActive(true);
		Cursor.visible = true;
		Bras.SetActive(false);

		for(i=0; i<currentZombies.length; i++){
				Destroy(currentZombies[i]);      //on détruit les Monstres présents sur la map
		}
	}
}
function ApplyDammage () {
	if(canApplyDammage==true){
		Bras.SetActive(true);
		attaque=true;
		canApplyDammage = false;	
	}
}

function Respawn(){
	
	mort = false;
	Cursor.visible = false;
	canApplyDammage = true;
	Bras.transform.Rotate(-80.0f, 0.0f, 0.0f, Space.Self);
}
