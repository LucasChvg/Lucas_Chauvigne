#pragma strict

private var player : PlayerStat;

var grenadeCasing : Rigidbody;
var ejectSpeed : int = 12;

function Start () {
	player = GameObject.Find("Stat").GetComponent(PlayerStat);
}

function Update () {
	if(player.grenade > 0){
		if(Input.GetKeyDown("g")){
			var grd : Rigidbody;  //grd = grenade mais faut pas avoir le même nom que les autres
			grd = Instantiate(grenadeCasing, transform.position, transform.rotation);
			grd.velocity = transform.TransformDirection(Vector3.forward * ejectSpeed);
			player.grenade -= 1;
		}
	}
}
