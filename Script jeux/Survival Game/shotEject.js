#pragma strict

var ejectSpeed : int = 100;
var fireRate : float = 0.1;
var bulletCasting : Rigidbody;
var animationFeu : Rigidbody;

private var nextFire : float = 0.0;
private var startAffiche = false;
private var player : PlayerStat;

var clip : int = 30;
private var clipEnMoins : int = 0;

var shotsound : AudioClip;
var reloadsound : AudioClip;

var x : int;
var y : int;
var z : int;
var devi : Vector3 = Vector3(0,0,0);

function Start () {
	player = GameObject.Find("Stat").GetComponent(PlayerStat);
}

function Update () {
	if(Input.GetButton("Fire1") && Time.time > nextFire){ //tirer
		if(clip >=1){
			nextFire = Time.time + fireRate;
			Instantiate(animationFeu, transform.position, transform.rotation);
			var bullet : Rigidbody;
			bullet = Instantiate(bulletCasting, transform.position, transform.rotation);
			bullet.velocity = transform.TransformDirection(Vector3.left * ejectSpeed);
			clip = clip - 1;
			GetComponent.<AudioSource>().PlayOneShot(shotsound);
			clipEnMoins = clipEnMoins + 1;

			if(startAffiche == false){
				startAffiche = true;
			}
		}
	}

	if (player.maxClip < 0){
		player.maxClip = 0;
	}

	if(Input.GetKeyDown("r") && player.maxClip >= 1){
		if(clip != 30){
			GetComponent.<AudioSource>().PlayOneShot(reloadsound);
		}
		clip = Mathf.Min(30, clip + player.maxClip);
		player.maxClip -= clipEnMoins;
		clipEnMoins = 0;
	}


}

function OnGUI(){
	if(startAffiche == true){
		GUI.Box(Rect(10,50,170,30), "Munition : " + clip + " / " + player.maxClip);
	}
}

