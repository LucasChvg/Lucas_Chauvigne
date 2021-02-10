using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Lever : MonoBehaviour {
	
	//private transform Transform;
	public GameObject Porte;
	private bool showGUI = false;
	
	private int rotation = 1;
	private float temps = 0.01f;
	private float temporise = 0.0f;
	private bool ouvrir = false;
	private int rotate = 0;
	private bool actif = true;
	
	private GUIContent contentUI;
	
	
	public Texture aTexture;
	
	void Start()
	{
		//Transform = Porte.GetComponent<transform>();
		contentUI = new GUIContent(aTexture);
	}
	void Update()
	{
		if(actif == true){
			if(ouvrir == true){
				if (Time.time > temporise){
					temporise = Time.time + temps;
					transform.Rotate(0,0,rotation);
					Porte.transform.position += new Vector3(0.0f,0.0f,0.1f);
					rotate += 2;
					if(rotate > 80){
						ouvrir = false;
						actif = false;
					}
				}
			}
			if(showGUI==true){
				if(Input.GetKeyDown("e")){
					ouvrir = true;
				}
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
			if(actif==true){
				GUI.Box(new Rect((Screen.width/2 - 100), (Screen.height/2 - 40), 200, 80), contentUI);
			}

		}
	}
}