#pragma strict

var rotation : int = 2;
var temps : float = 0.01;
var temporise : float = 0.0;
var ouvrir : boolean = false;
var rotate : int = 0;
var actif : boolean = true;
private var showGUI : boolean = false;

function Update () {
	if(actif == true){
		if(ouvrir == true){
			if (Time.time > temporise){
				temporise = Time.time + temps;
				transform.Rotate(0,rotation,0);
				rotate += 2;
				if(rotate > 100){
					ouvrir = false;
					actif = false;
				}
			}
		}
		if(showGUI == true){
			if(Input.GetButton("Fire1")){
				ouvrir = true;
			}
		}
	}
}

function OnTriggerEnter(hit : Collider) {
	if(hit.gameObject.tag == "perso"){
		showGUI = true;
	}
}
function OnTriggerExit(hit : Collider) {
	if(hit.gameObject.tag == "perso"){
		showGUI = false;

	}
}
function OnGUI(){
	if(showGUI == true){
		if(actif == true){
			GUI.Box(Rect(Screen.width/2-100, Screen.height/2-400,200,25), "LEFT CLICK to open");
		}
	}
}