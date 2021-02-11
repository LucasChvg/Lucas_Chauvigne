#pragma strict

var ejectSpeed : int = 100;
var fireRate : float = 0.5;
var bulletCasting : Rigidbody;
var animationFeu : Rigidbody;
private var player : PlayerStat;

private var nextFire : float = 0.0;
private var startAffiche = false;

var clip : int = 8;

private var clipEnMoins : int = 0;

var shotsound : AudioClip;
var reloadsound : AudioClip;

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

	if (player.maxClippist < 0){
		player.maxClippist = 0;
	}

	if(Input.GetKeyDown("r") && player.maxClippist >= 1){
		if(clip != 8){
			GetComponent.<AudioSource>().PlayOneShot(reloadsound);
		}
		clip = Mathf.Min(8, clip + player.maxClippist);
		player.maxClippist -= clipEnMoins;
		clipEnMoins = 0;
	}

}

function OnGUI(){
	if(startAffiche == true){
		GUI.Box(Rect(10,50,170,30), "Munition : " + clip + " / " + player.maxClippist);
	}
}