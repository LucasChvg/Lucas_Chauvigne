#pragma strict

var vieBoite : int = 100;

function OnCollisionEnter (col : Collision){
	if(col.gameObject.tag == "Bullet"){
		vieBoite -= 10;
	}
}

function Update () {
	if(vieBoite <= 0){
		Destroy(gameObject);
	}
}

