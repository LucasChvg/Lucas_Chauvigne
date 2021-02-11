#pragma strict

var lumiere : GameObject;
var allume : boolean = true;

private var nextFire : float = 0.0;
var temps : float = 0.5;

function Start () {
	lumiere.SetActive(true);
}

function Update () {
	if(Input.GetButton("Fire2") && Time.time > nextFire){
		nextFire = Time.time + temps;
		allume = !allume;
		if(allume == true){
			lumiere.SetActive(true);
		}
		if(allume == false){
			lumiere.SetActive(false);
		}
	}
}
