#pragma strict

var player : shotEject;
var tmp : Vector3;

function Start () {
	
	yield WaitForSeconds(0.05);
	Destroy (gameObject);
}
function Update () { 
	tmp = GameObject.Find("Eject").transform.position;
	transform.position = tmp;
}


