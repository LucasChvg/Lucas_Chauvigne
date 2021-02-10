﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]

public class PlayerDataSave {

	public float[] position;
	public int level;
	
	public PlayerDataSave(Player player)
	{
		level = player.level;
		
		position = new float[3];
		position[0] = player.transform.position.x;
		position[1] = player.transform.position.y;
		position[2] = player.transform.position.z;
	}
}
