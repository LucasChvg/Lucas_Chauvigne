#pragma strict

function Start () {
	yield WaitForSeconds(2);
	Destroy (gameObject);
}

