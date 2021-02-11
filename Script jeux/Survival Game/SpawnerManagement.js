#pragma strict

var spawners : Transform[]; //list of spawners
private var currentZombies : GameObject[]; //list of zombie on the map

var zombie : Transform; //object zombie

private var leftAmount : int;
private var lastRoundAmount : int; //number of zombie of the last wave
var startAmount : int; //number of zombie for first wave

var currentRound : int; 

var multiplicateur : float; //number of zombie that we add per wave

var delay : float;

function Start () {
	InvokeRepeating("Spawning", 0 , delay);
}

function Update () {
	currentZombies = GameObject.FindGameObjectsWithTag("zombie");
	
	if(currentRound == 0){
		lastRoundAmount = startAmount;
		leftAmount = startAmount;      //initilizing
		currentRound += 1;
	}
}

function Spawning(){
	if(leftAmount > 0){
		var randomNumber : int = Random.Range(0,spawners.Length);
		var randomTransform = spawners[randomNumber];
		
		Instantiate(zombie, randomTransform.transform.position, Quaternion.identity);
		
		leftAmount -= 1;
	}
	if(currentZombies.Length == 0){
		if(currentRound != 0 && leftAmount == 0){
			leftAmount = lastRoundAmount * multiplicateur;
			lastRoundAmount = leftAmount;
			currentRound += 1;
		}
	}
}
function OnGUI(){
	GUI.Box(Rect(190,10,170,30), "Wave n° " + currentRound);	
}