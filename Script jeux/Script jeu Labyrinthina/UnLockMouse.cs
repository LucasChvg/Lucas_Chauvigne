using System;
using UnityEngine;
using UnityStandardAssets.CrossPlatformInput;
using UnityStandardAssets.Utility;

public class UnLockMouse : MonoBehaviour {
	
	public GameObject FPSController;
	
	private UnityStandardAssets.Characters.FirstPerson.FirstPersonController fpc; 
	
	void Start(){
		fpc = FPSController.GetComponent<UnityStandardAssets.Characters.FirstPerson.FirstPersonController>();
	}
	void Update(){
		if(gameObject.active == true){
			fpc.enabled = false;
		}	
	}
}