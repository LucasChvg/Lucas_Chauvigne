using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {
 
	public int level=1;
	public bool[] clueIsPossesses;
	
	
	//private int sizeOfCluesTab = 3;
	
	public GameObject CluesCanvas;

	public GameObject[] CluesTab = new GameObject[3]; 
	public GameObject CluesNumberUI; 
	
	private bool invIsActive = false;
	private int choixClue = 0;
	private int i = 0;

	public int nbClues = 0;
	//public UnityEngine.UI.Text nbClues_txt; // assign it from inspector
	 
	 
	void Start()
	{
		//nbClues_txt.text = ""+nbClues;	

		clueIsPossesses = new bool[7] {false,false,false,false,false,false,false};

	}
	void Update()
	{
		if (Input.GetKeyDown("r"))
		{
			SavePlayer();
		}
		if (Input.GetKeyDown("l"))
		{
			LoadPlayer();
		}
		if (Input.GetKeyDown("j") && nbClues > 0)
		{	
			invIsActive=true;
			CluesCanvas.SetActive(true);
			InventaryClue();
		}
		if (invIsActive==true){
			InventaryClue();
		}
		
	}
	
	public void InventaryClue()
	{
		for(i = 0; i < CluesTab.Length; i++ ){
			if(i==choixClue && clueIsPossesses[i] == true){
				CluesTab[i].SetActive(true);
				//CluesNumberUI.SetActive(true);
			}else{
				CluesTab[i].SetActive(false);
				//CluesNumberUI.SetActive(false);
			}
		}
		
		
		if (Input.GetKeyDown("q"))
		{
			if(choixClue > 0){
			choixClue--;
			}
		}
		if (Input.GetKeyDown("e"))
		{
			if(choixClue < nbClues-1){
				choixClue++;
			}
		}
		if (Input.GetKeyDown(KeyCode.Escape))
		{
			invIsActive=false;
			CluesCanvas.SetActive(false);
		}	
	}
	
	
	public void SavePlayer()
	{
		SaveSystem.SavePlayer(this);
	}
	public void LoadPlayer()
	{
		PlayerDataSave data = SaveSystem.LoadPlayer();
		level = data.level;
		
		Vector3 position;
		position.x = data.position[0];
		position.y = data.position[1];
		position.z = data.position[2];
		transform.position = position;
	}
}
