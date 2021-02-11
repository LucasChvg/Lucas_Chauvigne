#pragma strict

var rotation : int = 2;
var temps : float = 0.01;
var temporise : float = 0.0;
var ouvrir : boolean = false;
var rotate : int = 0;
var actif : boolean = true;
var m_Collider : MeshCollider;
var m_Collider2 : MeshCollider;
private var showGUI : boolean = false;

function Start () {
	m_Collider = GameObject.Find("Quadd").GetComponent(MeshCollider);
	m_Collider2 = GameObject.Find("Quadd2").GetComponent(MeshCollider);
}

function Update () {
	if(actif == true){
		if(ouvrir == true){
			m_Collider.enabled = false;
			m_Collider2.enabled = false;
			if (Time.time > temporise){
				temporise = Time.time + temps;
				transform.Rotate(0,rotation,0);
				rotate += 2;
				if(rotate > 100){
					ouvrir = false;
					actif = false;
					m_Collider.enabled = true;
					m_Collider2.enabled = true;
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