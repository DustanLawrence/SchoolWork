<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>CID Assignment</title>

<!--
CID Name Assignment

What objectives are you demonstrating?
*using GET *using PHP *if statement in PHP *printing to screen with php
--> 

<style>
h1{
	text-align:center;
}
body{
	background-color: #97B4BA;
	}
div {  
width: auto; 
text-align: center;  
padding: 15px;  
border: 3px solid red;  
}  
img {  
max-width: 100%;  
height: auto;  
}  
</style>

</head>
<body>

<?php

	// Show errors, but not all...
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
	
    if(isset($_GET["pic"])) {$pic = $_GET["pic"]; } else {$pic = ""; }
    if($pic == "car")
        {
            print
            "<body>
			<h1>Car</h1>
			<div id='photo'>
            <img id='pic' style='object-fit: cover;' src='https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwallup.net%2Fwp-content%2Fuploads%2F2014%2F08%2Fchevrolet-classic-car.jpg&f=1&nofb=1' />
			</div>
            </body>"
        ;}
    if($pic == "truck")
        {
            print
            "<body>
			<h1>Truck</h1>
			<div id='photo'>
            <img id='pic' src='https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.9to5carwallpapers.com%2Fwp-content%2Fuploads%2F2014%2F02%2FVolvo-Truck-Hd-Wallpapers.jpg&f=1&nofb=1'>
			</div>
            </body>"
        ;}
    if($pic == "motorcycle")
        {
            print
            "<body>
			<h1>Motorcycle</h1>
			<div id='photo'>
            <img id='pic' src='https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.revzilla.com%2Fblog_content_image%2Fimage%2F50778%2Fredline_hero%2Fhonda-003.jpg&f=1&nofb=1'>
			</div>
            </body>"
        ;}
?>
</body>
</html>
