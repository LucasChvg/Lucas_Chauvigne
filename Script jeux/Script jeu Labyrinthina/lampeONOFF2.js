#pragma strict

var lumiere : GameObject;
var allume : boolean = false;

private var nextFire : float = 0.0;
var temps : float = 0.5;

function Start () {
	lumiere.SetActive(false);
}

function Update () {
	if(Input.GetKeyDown("f") && Time.time > nextFire){
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
