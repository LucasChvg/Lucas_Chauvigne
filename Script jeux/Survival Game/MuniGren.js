#pragma strict

var rotation : int = 10;
var temps : float = 0.5;
var temporise : float = 0.0;
private var player : PlayerStat;
private var showGUI : boolean = false;

function Start () {
	player = GameObject.Find("Stat").GetComponent(PlayerStat);
}

function Update () {
	if (Time.time > temporise){
	temporise = Time.time + temps;
	transform.Rotate(0,0,rotation);
	}
	if(showGUI == true){
		if(Input.GetKeyDown("f")){
				player.grenade +=1;
				Destroy(gameObject);
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
		GUI.Box(Rect(Screen.width/2-100, Screen.height/2-12.5,200,25), "F to pick up");
	}
}

