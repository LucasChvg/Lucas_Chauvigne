#pragma strict

var timer : int = 3;
var explosionZone : GameObject;
var particuleExplosion : GameObject;

function Start () {
	yield WaitForSeconds(timer);
	apparaitre();
}

function apparaitre() {
	Instantiate(explosionZone, transform.position, transform.rotation);
	Instantiate(particuleExplosion, transform.position, transform.rotation);
	Destroy (gameObject);
}
