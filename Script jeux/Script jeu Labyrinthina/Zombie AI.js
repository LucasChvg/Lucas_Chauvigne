#pragma strict

var Distance : float;
var target : Transform;
var lookAtDistance : float = 20;
var chasseDistance : float = 10;
var attaqueDistance : float = 2.5;
var speed : float = 10;
var Damping : float = 6;
var tempsRepetitionAtt : float = 1;
var theDammage : float = 25;
var vieZombie : int = 100;
var waitbeforedesapear : int = 3;
var deathTime : int;

private var attackTime : float;

var controller : CharacterController; 
var gravity : float = 20;

private var moveDir : Vector3 = Vector3.zero; 

var agent : UnityEngine.AI.NavMeshAgent;

function Start () {
	agent = gameObject.GetComponent(UnityEngine.AI.NavMeshAgent);
	attackTime = Time.time;
	FindVie();
}

function Update () {
	Distance = Vector3.Distance(target.position, transform.position);

	if(Distance < lookAtDistance){
		//lookAt();
	}

	if(Distance < attaqueDistance){
		attack();
	}else if(Distance < chasseDistance){
		chasse();
	}
	if(vieZombie <= 0){
		
		Destroy(gameObject);
		
	}

}

function lookAt (){
	var rotation = Quaternion.LookRotation(target.position - transform.position);
	transform.rotation = Quaternion.Slerp(transform.rotation, rotation, Time.deltaTime * Damping);
}

function chasse(){
	GetComponent.<Animator>().Play("Sword And Shield Run");
	/*moveDir = transform.forward;
	moveDir *= speed;
	moveDir.y -= gravity * Time.deltaTime;
	controller.Move(moveDir * Time.deltaTime);*/
	
	agent.destination = target.position;
}

function attack(){
	if(Time.time > attackTime){
		GetComponent.<Animator>().Play("Zombie Scream");
		target.SendMessage("ApplyDammage");
		Debug.Log("L'ennemie attaque");
		attackTime = Time.time + tempsRepetitionAtt;
	}
}

//function ApplyDammage(){
//	chasseDistance += 30;
	//speed += 2;
//	lookAtDistance += 30;
//}

function FindVie(){
	target = GameObject.Find("Stat").GetComponent(PlayerStat).transform;
}


function OnTriggerEnter (hit : Collider){
	if(hit.gameObject.tag == "Bullet"){
		vieZombie -= 10;
	}
}
