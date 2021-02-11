#pragma strict

function Start () {
	yield WaitForSeconds(2);
	Destroy (gameObject);
}

function OnTriggerEnter(hit : Collider) {
	if(hit.gameObject.tag == "Boite"){
		hit.gameObject.GetComponent(VieBoite).vieBoite -=50;
	}
}


