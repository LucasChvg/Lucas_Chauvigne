#pragma strict

var x : int;
var y : int;
var z : int;
var direction : Vector3;


function Start() {
	y = Random.Range(-1,2);
	z = Random.Range(-1,2);
	x = Random.Range(-1,2);
	direction = Vector3(x,y,z);
}

function Update () 
{
     transform.Translate(direction * Time.deltaTime); 
}
