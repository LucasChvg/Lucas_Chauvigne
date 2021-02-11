<?php
	include ('connexionbdd.php');
	$idDeleted = $_POST['id'];
	$sql = "DELETE FROM cultive WHERE cultive.id = $idDeleted;";
	$db->query($sql);
	$sql2 = "DELETE FROM `data` WHERE `id_plant_capteur`=$idDeleted;";
	$db->query($sql2);
?>