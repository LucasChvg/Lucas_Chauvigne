#pragma strict


var fireRate : float = 0.5;
var Repere : GameObject;

private var nextFire : float = 0.0;
private var startAffiche = false;
private var player : PlayerStat;

var clip : int = 30;
private var clipEnMoins : int = 0;

//var shotsound : AudioClip;

//var vectorR : Vector3 = new Vector3(90,30,0);

function Start () {
	player = GameObject.Find("Stat").GetComponent(PlayerStat);
}

function Update () {
	if(Input.GetKeyDown("r") && Time.time > nextFire){ //tirer
		if(player.m_repere >=1){
			nextFire = Time.time + fireRate;
			//Instantiate(animationFeu, transform.position, transform.rotation);
			var bullet : Rigidbody;
			Instantiate(Repere, transform.position, Repere.transform.rotation);
			//bullet.velocity = transform.TransformDirection(Vector3.left * ejectSpeed);
			player.m_repere = player.m_repere - 1;
			//GetComponent.<AudioSource>().PlayOneShot(shotsound);
			//clipEnMoins = clipEnMoins + 1;

			if(startAffiche == false){
				startAffiche = true;
			}
		}
	}

	if (player.m_repere < 0){
		player.m_repere = 0;
	}

	/*if(Input.GetKeyDown("r") && player.m_repere >= 1){
		if(clip != 30){
			GetComponent.<AudioSource>().PlayOneShot(reloadsound);
		}
		clip = Mathf.Min(30, clip + player.m_repere);
		player.m_repere -= clipEnMoins;
		clipEnMoins = 0;
	}*/


}

function OnGUI(){
	if(startAffiche == true){
		GUI.Box(Rect(10,50,170,30), "Ligth left : " + player.m_repere);
	}
}
