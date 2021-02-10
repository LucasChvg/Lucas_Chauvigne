using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickUpClue : MonoBehaviour {
	
	private Player player;
	public GameObject gmplayer;
	private bool showGUI = false;
	
	private GUIContent contentUI;
	
	public int clueNumber = 0;
	
	public Texture aTexture;
	
	void Start()
	{
		player = gmplayer.GetComponent<Player>();
		contentUI = new GUIContent(aTexture);
	}
	void Update()
	{
		if(showGUI==true){
			if(Input.GetKeyDown("e")){
				player.clueIsPossesses[clueNumber] = true;
				player.nbClues += 1;
				Destroy(gameObject);
			}
		}
	}
	void OnTriggerEnter(Collider other)
	{
		if(other.gameObject.tag == "perso"){
			showGUI = true;
		}
	}
	void OnTriggerExit(Collider other)
	{
		if(other.gameObject.tag == "perso"){
			showGUI = false;
		}
	}
	void OnGUI(){
		if(showGUI == true){
			GUI.Box(new Rect((Screen.width/2 - 100), (Screen.height/2 - 40), 200, 80), contentUI);
		}
	}
}