#pragma strict

var grenade : int = 2;
var maxClippist : int = 32;
var maxClip : int = 150;

var vieBase : int = 100;
var vieMax : int = 100;

function ApplyDammage (theDammage : int) {
	vieBase -= theDammage;
	if(vieBase <= 0){
		Dead();
	}
}

function Dead () {
	Debug.Log("You're Dead");
}

function OnGUI(){
	GUI.Box(Rect(10,10,170,30), "PV : " + vieBase);	
}
