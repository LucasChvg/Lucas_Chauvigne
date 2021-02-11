<?php
	include ('connexionbdd.php');
	$IdPlante = $_POST['IdPlante'];
	$sql = "INSERT INTO `cultive` (`id_plant`) VALUES ($IdPlante);";
	$db->query($sql);
	$sql3 = "INSERT INTO `data`(`id_plant_capteur`, `data_eau`, `data_temperature`, `data_humidite`, `data_expo`) VALUES ((SELECT id FROM cultive WHERE id_plant = $IdPlante LIMIT 0,1),0,0,0,0);";
	$db->query($sql3);
?>