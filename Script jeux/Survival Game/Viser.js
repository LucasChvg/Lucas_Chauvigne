#pragma strict

var positionNormal : Vector3;
var positionVise : Vector3;
var arme : GameObject;

function Start () {
	transform.localPosition = positionNormal;
}

function Update () {
	if(Input.GetButton("Fire2")){
		transform.localPosition = positionVise;
	}
	if(!Input.GetButton("Fire2")){
		transform.localPosition = positionNormal;
	}
}
