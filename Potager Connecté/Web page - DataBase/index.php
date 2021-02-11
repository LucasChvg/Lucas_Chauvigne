<?php
    include ('connexionbdd.php');
?>
<!doctype html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Potager Connecté</title>
	<link rel="icon" type="image/png" href="flavicon_ico.png">
	<link href="bootstrap.min.css" rel="stylesheet" integrity="sha384-giJF6kkoqNQ00vy+HMDP7azOuL0xtbfIcaT9wjKHr8RbDVddVHyTfAAsrekwKmP1" crossorigin="anonymous">
	<script src="jquery.min.js"></script>
	<link href="main.css" rel="stylesheet" >
</head>
<body>
	<header>
	  <div class="navbar navbar-dark bg-dark shadow-sm">
		<div class="container">	
			<a href="pwd.php" class="svg-icon gear" >
				<svg id="gear" >
					<path  fill="white" d="M12,8A4,4 0 0,1 16,12A4,4 0 0,1 12,16A4,4 0 0,1 8,12A4,4 0 0,1 12,8M12,10A2,2 0 0,0 10,12A2,2 0 0,0 12,14A2,2 0 0,0 14,12A2,2 0 0,0 12,10M10,22C9.75,22 9.54,21.82 9.5,21.58L9.13,18.93C8.5,18.68 7.96,18.34 7.44,17.94L4.95,18.95C4.73,19.03 4.46,18.95 4.34,18.73L2.34,15.27C2.21,15.05 2.27,14.78 2.46,14.63L4.57,12.97L4.5,12L4.57,11L2.46,9.37C2.27,9.22 2.21,8.95 2.34,8.73L4.34,5.27C4.46,5.05 4.73,4.96 4.95,5.05L7.44,6.05C7.96,5.66 8.5,5.32 9.13,5.07L9.5,2.42C9.54,2.18 9.75,2 10,2H14C14.25,2 14.46,2.18 14.5,2.42L14.87,5.07C15.5,5.32 16.04,5.66 16.56,6.05L19.05,5.05C19.27,4.96 19.54,5.05 19.66,5.27L21.66,8.73C21.79,8.95 21.73,9.22 21.54,9.37L19.43,11L19.5,12L19.43,13L21.54,14.63C21.73,14.78 21.79,15.05 21.66,15.27L19.66,18.73C19.54,18.95 19.27,19.04 19.05,18.95L16.56,17.95C16.04,18.34 15.5,18.68 14.87,18.93L14.5,21.58C14.46,21.82 14.25,22 14,22H10M11.25,4L10.88,6.61C9.68,6.86 8.62,7.5 7.85,8.39L5.44,7.35L4.69,8.65L6.8,10.2C6.4,11.37 6.4,12.64 6.8,13.8L4.68,15.36L5.43,16.66L7.86,15.62C8.63,16.5 9.68,17.14 10.87,17.38L11.24,20H12.76L13.13,17.39C14.32,17.14 15.37,16.5 16.14,15.62L18.57,16.66L19.32,15.36L17.2,13.81C17.6,12.64 17.6,11.37 17.2,10.2L19.31,8.65L18.56,7.35L16.15,8.39C15.38,7.5 14.32,6.86 13.12,6.62L12.75,4H11.25Z" />
				</svg>
			</a>
			  <a href="index.php"  class="navbar-brand d-flex align-items-center">
				<strong>Potager Connecté</strong>
				  <?php 
					$sql = "SELECT data_temperature FROM data LIMIT 0,1";
						$result = $db -> query($sql);
						while($row = $result -> fetch_assoc())
						{
							echo("<h5 class='temp'>".$row['data_temperature']."°C"."</h5>");			
						}
				  ?>
			  </a>
		</div>
	  </div>
</header>
	<div> 
	<main>
	  <div class="album py-5 bg-light">
		<div class="container">
		 <div class="row row-cols-1 row-cols-sm-2 row-cols-md-3 g-3">
				 <?php 
				$sql = "SELECT COUNT(*) FROM cultive ";
				$sth = $db->query($sql);
				$result=mysqli_fetch_array($sth);
				$max = $result[0];
				if ($max<2)
				{
					echo("<div>");
					echo("<div class='card shadow-sm addingPlant'>");
						echo("<div id='btn'>");
							echo("<svg class='svg-circleplus' viewBox='0 0 100 100'>");
								echo("<circle cx='50' cy='50' r='45' fill='none' stroke-width='7.5'></circle>");
								echo("<line x1='32.5' y1='50' x2='67.5' y2='50' stroke-width='5'></line>");
								echo("<line x1='50' y1='32.5' x2='50' y2='67.5' stroke-width='5'></line>");
							echo("</svg>");
						echo("</div>");
					echo("</div>");
					echo("</div>");
				}
				?>
			
			  <?php
			  	$sql = "SELECT COUNT(*) FROM cultive ";
				$sth = $db->query($sql);
				$result=mysqli_fetch_array($sth);
				$max = $result[0];
					for ($x = 0; $x < $max; $x++) 
					{
						$sql = "SELECT plante.Img_plante FROM plante, cultive WHERE plante.id = cultive.id_plant ORDER BY cultive.id ASC LIMIT $x,1 ";
						$sth = $db->query($sql);
						$result=mysqli_fetch_array($sth);
						echo("<div class='col'>");
							echo("<div class='card shadow-sm'>");
								echo("<div class='flip-card-front'>");
									echo ('<img src="data:image/jpeg;base64,'.base64_encode( $result['Img_plante'] ).' "class="img"/>'); 
									$sql1 = "SELECT plante.Nom_plante, cultive.id_plant , data.data_eau, data.data_humidite, data.data_expo FROM cultive, data, plante WHERE data.id_plant_capteur=cultive.id AND plante.id=cultive.id_plant ORDER BY cultive.id_plant ASC LIMIT $x,1";
									$result1 = $db -> query($sql1);
									while($row1 = mysqli_fetch_array($result1))
									{
										echo("<h5 class='card-text'>"."Caractéristique ".$row1['Nom_plante']."</h5>");
										echo("<p>"."Humidité du sol : ".$row1['data_humidite']."% "."</p>");
										echo("<p>"."Exposition : ".$row1['data_expo']."% "."</p>");
									}
								echo("</div>");
								$sql1 = "SELECT cultive.id, plante.Nom_plante,plante.Img_plante, caracteristique.Besoin_eau,caracteristique.Humidite_sol,caracteristique.Exposition_min,caracteristique.Exposition_max FROM cultive, plante, caracteristique WHERE cultive.id_plant=plante.id AND caracteristique.id=plante.Caract_plante ORDER BY cultive.id ASC LIMIT $x,1";
								$result1 = $db -> query($sql1);
								while($row1 = mysqli_fetch_array($result1))
								{
									echo("<div class='flip-card-back'>");
									echo("<div class='div_close_btn' onclick='deletePlant(".$row1['id'].")'>");
										echo(" <svg class='close_btn'><path  d='M 10,10 L 30,30 M 30,10 L 10,30' /></svg>");
									echo("</div>");					
									echo("<h5 class='card-text'>"."Caractéristique ".$row1['Nom_plante']."</h5>");
									echo("<p>"."Besoin en eau : ".$row1['Besoin_eau']."</p>");
									echo("<p>"."Humidité du sol : ".$row1['Humidite_sol']."</p>");
									echo("<p>"."Exposition minimale : ".$row1['Exposition_min']."% "."</p>");
									echo("<p>"."Exposition maximale : ".$row1['Exposition_max']."% "."</p>");
									echo("</div>");
								}				
							echo("</div>");
						echo("</div>");				
					}
			   ?>
			  </div>
			</div>
		  </div>
		</main>
	</div> 
	<footer class="footer">
    <p>&copy;Potager Connecté</p>
</footer>	
<!-- The Modal -->
<div id="myModal" class="modal">
  <!-- Modal content -->
  <div class="modal-content">
    <span class="close">&times;</span>
    <h3>Quel type de plante voulez vous ajouter ?</h3>
		<select id="selectModal">
			<?php 
				$sql = "SELECT id, Nom_plante FROM plante";
				$result = $db -> query($sql);
				while($row = $result -> fetch_assoc())
				{
					echo("<option value='".$row['id']."'>".$row['Nom_plante']."</option>");				
				}
			?>
		</select>
	  <div id="btn2" onClick="addPlant()">
	  	<svg class="cercle" viewBox="0 0 100 100">
				<circle cx="50" cy="50" r="45" fill="none" stroke-width="7.5"></circle>
				<line x1="32.5" y1="50" x2="67.5" y2="50" stroke-width="5"></line>
				<line x1="50" y1="32.5" x2="50" y2="67.5" stroke-width="5"></line>
		</svg>
	  </div>
  </div>
</div>
</body>
</html>
<script>
// Get the modal
var modal = document.getElementById("myModal");
// Get the button that opens the modal
var btn = document.getElementById("btn");
// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];
// When the user clicks the button, open the modal 
btn.onclick = function() {
  modal.style.display = "block";
}
// When the user clicks on <span> (x), close the modal
span.onclick = function() {
  modal.style.display = "none";
}
// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}
function deletePlant (id){
	var r = confirm("Etes vous certain(e) de vouloir supprimer cette plante  ?");
	if (r == true) 
	{		
		var xhr = new XMLHttpRequest();
		xhr.open("POST", "delete.php", true);
		xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		xhr.send("id=" + escape(id));
	}
	setTimeout(function reload(){location.reload();},500);
}
function addPlant() {
	var r = confirm("Etes vous certain(e) de vouloir ajouter cette plante  ?");
	if (r == true) 
	{
		var IdPlante = document.getElementById("selectModal").value;
		var xhr = new XMLHttpRequest();
		xhr.open("POST", "save.php", true);
		xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		xhr.send("IdPlante=" + escape(IdPlante));
	}
	setTimeout(function reload(){location.reload();},500);
}
</script>