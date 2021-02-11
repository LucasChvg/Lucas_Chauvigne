#pragma strict

var x : int;
var y : int;
var z : int;
var direction : Vector3;


function Start() {
	y = Random.Range(-3,3);
	z = Random.Range(-3,3);
	x = Random.Range(-3,3);
	direction = Vector3(x,y,z);
}

function Update () 
{
     transform.Translate(direction * Time.deltaTime); 
}
