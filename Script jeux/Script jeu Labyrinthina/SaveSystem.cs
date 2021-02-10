﻿
using UnityEngine;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

public static class SaveSystem {

	public static void SavePlayer (Player player)
	{
		BinaryFormatter formatter = new BinaryFormatter();
		string path = Application.persistentDataPath + "/player.fun";
		FileStream stream = new FileStream(path, FileMode.Create);
		
		PlayerDataSave data = new PlayerDataSave(player);
		
		formatter.Serialize(stream, data);
		stream.Close();
	}
	
	public static PlayerDataSave LoadPlayer()
	{
		string path = Application.persistentDataPath + "/player.fun";
		if(File.Exists(path))
		{
			BinaryFormatter formatter = new BinaryFormatter();
			FileStream stream = new FileStream(path, FileMode.Open);
			
			PlayerDataSave data = formatter.Deserialize(stream) as PlayerDataSave;
			stream.Close();
			
			return data;
		}else{
			Debug.LogError("Save file not found in " + path);
			return null;
		}
	}
}
