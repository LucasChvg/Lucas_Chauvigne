#pragma strict

var Arme1 : GameObject;
var Arme2 : GameObject;
var Arme3 : GameObject;

function Start () {
	Arme1.SetActive(true);
	Arme2.SetActive(false);
	Arme3.SetActive(false);
}

function Update () {
	if(Input.GetKeyDown(KeyCode.Alpha1)){
		Arme1.SetActive(true);
		Arme2.SetActive(false);
		Arme3.SetActive(false);
	}
	if(Input.GetKeyDown(KeyCode.Alpha2)){
		Arme1.SetActive(false);
		Arme2.SetActive(true);
		Arme3.SetActive(false);
	}
	if(Input.GetKeyDown(KeyCode.Alpha3)){
		Arme1.SetActive(false);
		Arme2.SetActive(false);
		Arme3.SetActive(true);
	}
}
